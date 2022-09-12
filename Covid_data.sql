--SELECT *
--FROM Portfolio..coviddeath
--ORDER BY 3,4

--SELECT * 
--FROM Portfolio..covidvaccine
--ORDER BY 3,4

--SELECT location,date,total_cases,new_cases,total_deaths,population
--FROM Portfolio..coviddeath
--ORDER BY 1,2

--TOTAL CASES v/s TOTAL DEATHS

SELECT location,date,total_cases,total_deaths, (total_Deaths/total_cases)*100 AS DEATH_PERCENTAGE
FROM Portfolio..coviddeath
WHERE location like 'indi%'
ORDER BY 1,2

--TOTAL CASES v/s POPULATION

SELECT location,date,total_cases,population, (total_cases/population)*100 AS INFECTED_POPULATION
FROM Portfolio..coviddeath
--WHERE location like 'indi%'
ORDER BY 1,2

--highest infection rate compared to population

SELECT location,population,MAX(total_cases)AS INFECTION_COUNT, MAX(total_cases/population)*100 AS INFECTED_POPULATION
FROM Portfolio..coviddeath
--WHERE location like 'india%'
GROUP BY location,population
ORDER BY INFECTED_POPULATION DESC

-- highest death rates acc to location

SELECT location,MAX(cast(total_deaths as int))AS MAX_DEATHS
FROM Portfolio..coviddeath
WHERE continent is not null
GROUP BY location
ORDER BY MAX_DEATHS DESC

-- highest death rates acc to continent
SELECT continent,MAX(cast(total_deaths as int))AS TOTAL_DEATHS
FROM Portfolio..coviddeath
WHERE continent is not null
GROUP BY continent
ORDER BY TOTAL_DEATHS DESC

--globally daily numbers (datewise)
SELECT date,SUM(new_cases) AS TOTAL_CASES,SUM(new_deaths) AS TOTAL_DEATHS,(SUM(new_Deaths)/SUM(new_cases))*100 AS DEATH_PERCENTAGE
FROM Portfolio..coviddeath
--WHERE location like 'indi%'
WHERE continent is not null
GROUP BY date
ORDER BY 1,2

-- GLOBAL NUMBER
SELECT SUM(new_cases) AS TOTAL_CASES,SUM(new_deaths) AS TOTAL_DEATHS,(SUM(new_Deaths)/SUM(new_cases))*100 AS DEATH_PERCENTAGE
FROM Portfolio..coviddeath
--WHERE location like 'indi%'
WHERE continent is not null
ORDER BY 1,2


SELECT dea.continent,dea.location,dea.date,dea.population,vac.new_vaccinations
FROM Portfolio..coviddeath dea
JOIN  Portfolio..covidvaccine vac
	on dea.location = vac.location
	and dea.date = vac.date
WHERE dea.continent is not null
ORDER BY 2,3


SELECT dea.continent,dea.location,dea.date,dea.population,vac.new_vaccinations,
SUM(CONVERT(int,vac.new_vaccinations)) OVER (PARTITION BY dea.location order by dea.location, dea.date) AS PEOPLE_VACCINATED
FROM Portfolio..coviddeath dea
JOIN  Portfolio..covidvaccine vac
	on dea.location = vac.location
	and dea.date = vac.date
WHERE dea.continent is not null
ORDER BY 2,3

-- use CTE

with PopvsVac(continent,location,date,population,new_vaccinations,PEOPLE_VACCINATED)
AS
(
SELECT dea.continent,dea.location,dea.date,dea.population,vac.new_vaccinations,
SUM(CONVERT(int,vac.new_vaccinations)) OVER (PARTITION BY dea.location order by dea.location, dea.date) AS PEOPLE_VACCINATED
FROM Portfolio..coviddeath dea
JOIN  Portfolio..covidvaccine vac
	on dea.location = vac.location
	and dea.date = vac.date
WHERE dea.continent is not null
--ORDER BY 2,3
)
SELECT *,(PEOPLE_VACCINATED/population)*100 AS PEOPLE_VACCINATED_PERCENTAGE
FROM PopvsVac

--TEMP TABLE

DROP TABLE IF exists PERCENT_POPULATION_VACCINATED
CREATE TABLE PERCENT_POPULATION_VACCINATED
(
Continent varchar(50),
location varchar(50),
date datetime,
population numeric,
new_vaccinations numeric,
PEOPLE_VACCINATED numeric
)

INSERT INTO PERCENT_POPULATION_VACCINATED
SELECT dea.continent,dea.location,dea.date,dea.population,vac.new_vaccinations,
SUM(CONVERT(int,vac.new_vaccinations)) OVER (PARTITION BY dea.location order by dea.location, dea.date) AS PEOPLE_VACCINATED
FROM Portfolio..coviddeath dea
JOIN  Portfolio..covidvaccine vac
	on dea.location = vac.location
	and dea.date = vac.date
WHERE dea.continent is not null
ORDER BY 2,3

SELECT *,(PEOPLE_VACCINATED/population)*100 AS PEOPLE_VACCINATED_PERCENTAGE
FROM PERCENT_POPULATION_VACCINATED


-- create view to store data for visualisation

CREATE VIEW PERCENT_POPULATION_VACCINATED1 as
SELECT dea.continent,dea.location,dea.date,dea.population,vac.new_vaccinations,
SUM(CONVERT(int,vac.new_vaccinations)) OVER (PARTITION BY dea.location order by dea.location, dea.date) AS PEOPLE_VACCINATED
FROM Portfolio..coviddeath dea
JOIN  Portfolio..covidvaccine vac
	on dea.location = vac.location
	and dea.date = vac.date
WHERE dea.continent is not null
--ORDER BY 2,3

select * from PERCENT_POPULATION_VACCINATED1