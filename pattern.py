def pattern1(rows):   
    for i in range(rows):
        for j in range(i):
            print("*",end=" ")
        print()

#pattern1(7)     

def pattern2(rows,coloumn):
    for i in range(rows):
        for j in range(coloumn):
            print("*",end=' ')
        print()    

#pattern2(5,6)

def pattern3(rows):
    for i in range(rows,0,-1):
        for j in range(i):
            print("* ",end=' ')
        print()    

#pattern3(7)        

def pattern4(rows):
    for i in range(1,rows+1):
        for j in range(1,i+1):
            print(j,end=' ')    
        print()

#pattern4(6)       

def pattern5(n):
    for i in range(2*n):
        if i > n:
            col = 2*n - i 
        else :
            col = i
        for j in range(col):
            print("*",end=' ')
        print()                       


#pattern5(5)        

def pattern28(rows):
    for i in range(2*rows):
        if i > rows:
            col = 2*rows - i
        else:
            col = i   
        space = rows - col
        for x in range(space):
            print(end=' ')
        for j in range(col):
            print("*",end=' ')
        print()

pattern28(6)