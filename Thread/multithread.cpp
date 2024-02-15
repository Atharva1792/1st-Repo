#include<iostream>
#include<thread>
#define NUM_THREADS 5

using namespace std;
void *PrintHello(void *threadid) {
   int *tid;
   tid = (int*)threadid;
   cout << "Hello World! Thread ID, " << *tid << endl;
   pthread_exit(NULL);
}

int main(){
    pthread_t th[NUM_THREADS];
    int thread_id[NUM_THREADS];
    int rc;
    int i;
    
    for(int j=0;j<NUM_THREADS;j++){
        thread_id[j] = j;
    }
    for( i = 0; i < NUM_THREADS; i++ ) {
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&th[i], NULL, PrintHello, &thread_id[i]);
        
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);

    return 0;
}