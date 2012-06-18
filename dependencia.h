/********************************* dependencis *****************************/
//declaracion de estructuras
//Dependencias
typedef struct {
        char codigo[N],nombre[N], direccion[N];   
}dependencia;

typedef struct{
	dependencia elems[CANT];
	int ultimo;
}lista_d;

//declaracion de prototipos
dependencia anadirdependencia(lista_d );
void mostrardependencia(dependencia );
void eliminardependencia(lista_d *dependencias);   
void modificardependencia(lista_d *dependencias);
//Lista Dependencias
lista_d vacia_d();
bool es_vacia_d(lista_d );
void insertar_d(lista_d * , int , dependencia );
void eliminar_d(lista_d * , int );
dependencia consultar_d(lista_d , int );
int longitud_d(lista_d );
int localizar_d(lista_d *, char *);
void resto_d(lista_d * );

/********************** Operaciones con las dependencia *******************/

dependencia anadirdependencia(lista_d dependencias){   
     int a,encontrado;
     dependencia d;
     /*leer codigo de la dependencia*/
	 do {      
        printf("\n\nC¢digo de la dependencia: ");
        gets(d.codigo);           
        encontrado=0;      
        for(a=0;a<dependencias.ultimo && encontrado==0;a++) {         
                        if (compararcadenas(d.codigo,dependencias.elems[a].codigo)==0) 
                           encontrado=1;
        }             
        if (encontrado==1) 
           printf("\n\nNo puede haber dos Dependencias con  el mismo codigo");   
     } while (encontrado==1);
     /*leer nombtre de la dependencia*/
     printf("\n\nNombre de la dependencia: ");
     gets(d.nombre);
     printf("\n\nDireccion de la dependencia: ");
     gets(d.direccion);
     /*leer nombre*/
     
     return(d);
}

void mostrardependencia(dependencia d){   
     
     printf("\n\nCodigo de la dependencia: ");
     puts(d.codigo);
     printf("Nombre de la dependencia: ");
     puts(d.nombre);
     printf("Direccion de la dependencia: ");
     puts(d.direccion);
     return;
}

/**********************Modificar la informacion de una dependencia*****************/

void modificardependencia(lista_d *dependencias){
     
     int encontrado;   
     char modificar, codigo[N];   
     
     printf("\n\nCodigo de la dependencia: ");
     gets(codigo);
	 encontrado=localizar_d(dependencias, codigo);  
     if (encontrado==-1) 
        printf("\n\nDependencia no encontrada");   
     else {          
          do {
              printf("\n\n¨Desea modificar Nombre\?");         
              modificar=tolower(getch());      
          } while (modificar!='s' && modificar!='n');      
          if (modificar=='s') {         
             /*leer nombre*/         
             printf("\n\nNombre de la dependencia: ");
             gets(dependencias->elems[encontrado].nombre);     
          }      
          do {         
             printf("\n\n¨Desea modificar la direccion\?");         
             modificar=tolower(getch());      
          } while (modificar!='s' && modificar!='n');      
          if (modificar=='s') {         
             /*Leer direccion*/         
             printf("\n\nDireccion de la dependencia: ");
             gets(dependencias->elems[encontrado].direccion);       
          }          
     printf("\n\n\nDependencia modificada con ‚xito");   
     }   
     return;
}

/****************************Eliminar una dependencia******************************/

void eliminardependencia(lista_d *dependencias){   
     int encontrado;
     char codigo[N];
     
     printf("\n\nCodigo de la dependencia: ");
     gets(codigo);
	 encontrado=localizar_d(dependencias, codigo);  
     if (encontrado==-1) 
        printf("\n\nDependencia no encontrada");   
     else {      
          if (confirmar()==1) {      
             eliminar_d(dependencias,encontrado);         
             printf("\n\n\nDependencia eliminada con ‚xito.");         
          }   
     }   
     return;
}

/********************************listas*******************************/

lista_d vacia_d(){
	lista_d a;

	a.ultimo=0;
	return (a);
}

bool es_vacia_d(lista_d L){
	if (L.ultimo == 0) return(true);
	else return(false);
}

void insertar_d(lista_d *L, int pos, dependencia d){
	int i;
	if (L->ultimo < N){
		for(i=L->ultimo+1;i>pos+1;i--){
			L->elems[i] = L->elems[i-1];
		}
		L->elems[pos]=d;
		L->ultimo++;
	}
	return;
}

void eliminar_d(lista_d *L, int pos){
	int i;
	L->ultimo--;
	for(i=pos; i<N; i++){
      L->elems[i]=L->elems[i+1];
	}
	return;
}

dependencia consultar_d(lista_d L, int pos){
	return (L.elems[pos]);
}

int longitud_d(lista_d L){
	return (L.ultimo);
}

int localizar_d(lista_d *L, char *codigo){
	int i;
	if (L->ultimo == 0){
		return(-1);
	}
	else{
        i=0;
		while(i <= L->ultimo && compararcadenas(codigo,L->elems[i].codigo)!=0){
			i++;
        }
		if (compararcadenas(codigo,L->elems[i].codigo)==0){
			return(i);
		}	
		else return(-1);
	}
}

void resto_d(lista_d *L){
	int i;
	L->ultimo--;
    for(i=0;i<L->ultimo;i++){
            L->elems[i]=L->elems[i+1];
	}
	return;
}
