#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    pid_t pid,pid2,hijoPid;
    int fd1[2];
    int fd2[2];
    char buf[50];
    pipe(fd1);
    pipe(fd2);

    pid=fork();

    if(pid==-1){
        printf("No se ha podido crear el hijo\n");
        exit(-1);
    }
    else if(pid==0){
        pid2=fork();
        if(pid2==-1){
            printf("No se ha podido crear el nieto\n");
            exit(-1);
        }
        else if(pid2==0){
            //printf("Estoy en el proceso nieto\n");
            read(fd2[0], buf, sizeof(buf));
            printf("Nieto: mensaje de padre leido: %s\n", buf);
            write(fd1[1], "Soy el nieto", sizeof("Soy el nieto"));
            printf("Nieto: mensaje a padre escrito.\n");
        }
        else{
            //printf("Estoy en el proceso hijo\n");
            //close(fd2[0]);
            read(fd1[0], buf, sizeof(buf));
            printf("Padre: mensaje de abuelo leido: %s\n", buf);
            write(fd2[1], "Soy el padre", sizeof("Soy el padre"));
            printf("Padre: mensaje a nieto escrito.\n");
            wait(NULL);
            read(fd1[0], buf, sizeof(buf));
            printf("Padre: mensaje de nieto leido: %s\n", buf);
            write(fd2[1], "Soy tu hijo y el padre", sizeof("Soy tu hijo y el padre"));
            printf("Padre: mensaje escrito al abuelo\n");
        }
    }
    else{
        //printf("Estoy en el proceso abuelo\n");
        //close(fd1[0]);
        write(fd1[1], "Soy el abuelo", sizeof("Soy tu abuelo"));
        printf("Abuelo: mensaje a padre escrito.\n");
        wait(NULL);
        read(fd2[0], buf, sizeof(buf));
        printf("Abuelo: mensaje de padre leido: %s\n", buf);
    }



    return 0;
}