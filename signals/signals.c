#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int infinito = 1;

void signalHandler(int Signalnumber){
    infinito = 0;
    printf("Signal received %d \n", Signalnumber);
}

int main(){
    int pid;
    signal(10,signalHandler);
    pid = fork();
    if(pid == 0){
        printf("Soy el hijo\n");
        while(infinito){
            printf("dentro del infinito\n");
            sleep(1);
        }
        printf("Ya sali\n");
    }else{
        sleep(1);
        printf("Soy el padre\n");
        kill(pid,10);
        for(;;);
    }
}
