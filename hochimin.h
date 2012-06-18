/*
  Name: Proyecto 2
  Copyright: 2005 
  Author: Gustavo Bazan & Armando bracho
  Date: //
  Description: 
*/


//Librerias
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h> 

//Declaracion de constantes
#define CANT 100 
#define N 20

//contadores
int mg=0,ob=0,ca=0,mi=0,gi=0,pe=0,ne=0,tra=0,od=0,rx=0;

//Declaracion de estructuras

// Formato de fecha
typedef struct{
    int dia;
    int mes;
    int ano;
}fecha;
fecha hoy_d;
typedef struct{
    int dia;
    int turno;
	int ano;
}fecha2;
fecha2 hoy;


//Declaracion de prototipos
//VARIOS
void tecla();         /*Pausa*/
int compararcadenas(char *, char *);/*Compara si 2 cadenas son iguales*/
void leerchar(char *);/*Valida un entero*/
int leernum();/*valida una cadena*/
int menu();          /*menu*/
int confirmar();
int menu(); /*menu*/


/*************************************FUNCIONES DE TIPOS*********************************/
void leerchar(char *resultado){
    
    fflush(stdin);   
    do {      gets(resultado);   
    } while (strlen(resultado)==0);   
    return;
}

int leernum(){
    
    char buffer[15];   
    fflush(stdin);   
    do {      gets(buffer);   
    } while (strlen(buffer)==0);   
    return atoi(buffer);
}
    
int compararcadenas(char *cad1, char *cad2){
    /*compara cadenas caracter a caracter con tolower*/   
    int i;   
    int resultado;   
    resultado=0;   
    
    if (strlen(cad1)!=strlen(cad2)) resultado=-1;   
    
    for (i=0;(unsigned)i<(unsigned)strlen(cad1) && resultado==0;i++) {      
        if (tolower(cad1[i])!=tolower(cad2[i])) resultado=-1;   
    }   
    return resultado;/*devuelve 0 si son iguales, -1 si son distintos*/
}
/*****************************************VARIOS*******************************************/

void tecla(){   
     printf("\n\n\tPresione cualquier tecla para continuar el programa...\n\a");   
     getch();   
     system("cls");   
     return;
}

int confirmar(){
       
    char a;   
    do {      
       printf("\n\n\t¨Est s seguro \"s\"/\"n\"\?");     
       a=tolower(getch());   
    } while (a!='s' && a!='n');   
    if (a=='s') return 1;   
    else return 0;
}

/******************************************************************************/


