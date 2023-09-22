#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
void main(){
    pid_t id_actual, id_padre;
    id_actual = getpid();
    id_padre = getppid();
    printf("PID de este proceso %d \n", id_actual);
    printf("PID de procesopadre %d \n", id_padre);


}