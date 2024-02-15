#include<thread>
#include<iostream>
#include<sys/time.h>
#include<cstdlib>

#define M 3
#define K 3
#define N 5

int A[M][K] = { {1,3,5},{8,5,2},{2,7,9} };
int B[K][N] = { {1,2,3,4,5},{3,4,5,6,7},{4,5,6,3,2} };
int C[M][N];

struct mat{
    int i;//row
    int j;//col
};

void *runner(void *param); 

int main(int argc,char* argv[]){

    int count=0;
    clock_t start,end;

    double cpu_time_used;
    start = clock();

    for (int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            struct mat  *m = (struct mat*)malloc(sizeof(struct mat));
            m->i = i;
            m->j =j;

            pthread_t tid;
            pthread_attr_t attr;

            pthread_attr_init(&attr);

            pthread_create(&tid,&attr,runner,m);
            pthread_join(tid,NULL);
            count++;
        }
    }
    end = clock();

    cpu_time_used = 1000 * (double)(end - start)/CLOCKS_PER_SEC;

    std::cout << "The matrix :\n"; 
    for(int i =0;i<M;i++){
        for(int j=0;j<N;j++){
            std::cout << C[i][j]<< " ";
        }
        std::cout <<"\n";
    }

    std::cout << "Thread used: " << count;
    std::cout << "\nCPU time used in ms: " << cpu_time_used;

}

void *runner(void *param){
    struct mat  *m = new(mat);
    memcpy(m,param,sizeof(struct mat));

    int n,sum=0;

    for(n = 0;n<K;n++){
        sum += A[m->i][n] * B[n][m->j];
    }
    C[m->i][m->j] = sum;
    std::cout << "Thread completed with C["<<m->i<<"]["<<m->j<<"] = " <<sum<< "\n";

    pthread_exit(0);

}


//clock_t s =clock();