#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
void main(){
    pid_t pid, hijo_pid;
    pid=fork();
    int variable;
    if(pid==-1) //Ha ocurrido un error
    {
        printf("No se ha podido crear el proceso hijo...");
        exit(-1);
    }
    if(pid==0)//Nos encontramos en el proceso hijo
    {
        printf("Soy el proceso hijo: \n\tMi PID es: %d, El PID de mi padre es: %d.\n",getpid(), getppid());
        variable =10;
    }
    else //Nos encontramos en el proceso padre y es el id del hijo
    {
        //hijo_pid = wait(NULL); //Espera la finalización del proceso hijo
        printf("Soy el proceso padre:\n\tMi PID es: %d, El PID de mi padre es: %d.\n\tMi hijo: %d terminó.\n", getpid(), getppid(), pid);
        variable = 1000;
    }

    while (1){
        printf("Soy el proceso %d y la variable es %d\n", getpid(), variable);
        sleep(2);
    }

    exit(0);
}