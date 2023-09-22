#include <stdio.h> //importar entre otras cosas printf, scanf
#include <stdlib.h>
int main(){
    printf("Hola mundo");
    return 0;
}


// int a; float b; double c; char c;
// operadores && || ! ==
// hay conversores de tipo (float), (int), ...
// podemos imprimir variables con printf
// print("Hola, me llamo Pablo y tengo %d años\n", edad) 
// %d enteros, %f flotantes, %c carácter, %s cadena
// \n para poner un salto de línea
// leer datos lo hacemos con scanf
// scanf("%d", &edad)
// scanf("%f", &precio)
// el & es obligatorio para variables de tipo escalar
// scanf necesita una dirección de memoria 

//BUCLES
/* if (condición){
    bloque de instrucciones;
}*/ 

/*
if(condición){
    bloque;
}
else if (condición){
    bloque;
}
else if(condición){
    bloque;
}
else{
    bloque;
}
*/
/*
while(condición){
    bloque;
}
*/
//podemos usar break; para salir de un bucle
/*for (int i=0;i<=a;i++){
    bloque;
}*/
//los módulos en C reciben el nombre de bibliotecas y se importan con la 
//sentencia #include 
//#define se usa para definir constantes
//#define CONSTANTE valor
//#define PI 3.14
//también se puede usar const


//IMPORTANTE: para usar funciones matemáticas hay que importar
//con #include <math.h> y a la hora de compilar 
//usar gcc programa.c -lm -o ejecutable
//usar -lm
/*
switch(expresión){
    case valor1:
        bloque;
        break;
    case valor2:
        bloque;
        break;
    case valor3:
        bloque;
        break;
    default:
        bloque;
        break;
}
*/

/*
do{

}while(condición);

*/


//VECTORES Y ARRAYS

//tipo nombre[];
//tipo nombre[] = {valores};
//importante: los vectores no necesitan el & antes al pasarlos por
//scanf
//no podemos comparar vectores
//cadenas: char nombre[];
//cadenas: char nombre[]="cadena";
//al pasar las cadenas por print o scanf usaremos %s
//se pasan sin & también
