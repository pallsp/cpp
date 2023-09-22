#include <stdio.h>
#include <unistd.h>
void main(){
    printf("Ejemplo de uso de exec():");
    printf("\nLos archivos en el directorio son:\n");
    execl("/bin/ls","ls", "-l", (char*)NULL);
    printf("¡¡Esto no se ejecuta!!!\n");


}