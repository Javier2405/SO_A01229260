#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define NUM_FILOS 5
pthread_mutex_t tenedores[NUM_FILOS];

void actividad(){
    sleep(1+rand()%5);
}

void * vida(void *id){
    long tid;
    tid = (long)id;
    srand(tid * time(NULL));
    //PIENSAN
    while(1){
        printf("Soy el hilo %ld, y estoy pensando \n",tid);
        if(tid % 2 == 0){
            pthread_mutex_lock(&tenedores[tid]);
            pthread_mutex_lock(&tenedores[(tid+1) % NUM_FILOS]);
            //COMER
            printf("Soy el hijo de mi papa %ld, y voy a comer \n",tid);
            actividad();
            pthread_mutex_unlock(&tenedores[tid]);
            pthread_mutex_unlock(&tenedores[(tid+1) % NUM_FILOS]);
        }else{
            pthread_mutex_lock(&tenedores[(tid+1) % NUM_FILOS]);
            pthread_mutex_lock(&tenedores[tid]);
            //COMER
            printf("Soy el hijo de mi papa %ld, y voy a comer \n",tid);
            actividad();
            pthread_mutex_unlock(&tenedores[tid]);
            pthread_mutex_unlock(&tenedores[(tid+1) % NUM_FILOS]);
        }
    }
}
int main (int argc, char *argv[])
 {
    pthread_t threads[NUM_FILOS];
    int rc;
    long t;
    for(t=0; t<NUM_FILOS; t++){
       printf("In main: creating thread %ld\n", t);
       rc = pthread_create(&threads[t], NULL, vida, (void *)t);
       if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
       }
    }
    pthread_exit(NULL);
 }
