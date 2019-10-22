#include <stdio.h>

int main(int argc, char * argv[]){
    int leftNumber;
    int i;
    scanf("%d", &leftNumber);
    fprintf(stderr, "%d\n", leftNumber);
    scanf("%d", &i);
    while(i != -1){
        if(i % leftNumber != 0){
            fprintf(stdout, "%d\n", i);
        }
        scanf("%d", &i);
    }
    printf("%d\n", -1);
}