#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
void main(){
    pid_t pid, hijo_pid, pid2, nieto_pid;
    pid=fork();
    
    if(pid==-1) //Ha ocurrido un error
    {
        printf("No se ha podido crear el proceso hijo...");
        exit(-1);
    }
    if(pid==0)//Nos encontramos en el proceso hijo
    {
        pid2=fork();

        if(pid2==-1){
            printf("Ha ocurrido un error");
            exit(-1);
        }
        if(pid2==0){
            printf("Soy el proceso nieto:\n\t Mi PID es: %d, El PID de mi padre es: %d", getpid(), getppid());
        }
        else{
            printf("Estoy en el proceso hijo\n\t Mi PID es: %d, El PID de mi padre es: %d", getpid(), getppid());
        }
    }
    else //Nos encontramos en el proceso padre y es el id del hijo
    {
        //hijo_pid = wait(NULL); //Espera la finalización del proceso hijo
        printf("Soy el proceso padre:\n\tMi PID es: %d, El PID de mi padre es: %d.\n\tMi hijo: %d terminó.\n", getpid(), getppid(), pid);
        
    }


    while (1){
        printf("Soy el proceso %d ", getpid());
        sleep(2);
    }

    exit(0);
}