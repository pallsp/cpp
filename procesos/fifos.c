#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd;
    int p, bytesleidos;
    char buf[] = "Mensaje a escribir en la FIFO";
    p=mkfifo("Fifo", "0666");

    if(p==-1){
        printf("Ha ocurrido un error..\n");
        exit(0);
    }
    else{
        fd=open("Fifo", O_WRONLY);
        write(fd, buf,sizeof(buf));
        close(fd);
        exit(0);
    }

    return 0;
}

int main(){
    int fd,n;
    char buf[1024];
    fd=open("Fifo", O_RDONLY);
    n= read(fd, buf,sizeof(buf));
    printf("El número de bytes escritos es %d \n",n);
    printf("El mensaje enviado es %s \n", buf);
    close (fd);
    return 0;
}