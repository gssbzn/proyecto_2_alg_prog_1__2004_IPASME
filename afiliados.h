/*********************************** AFILIADOS ********************************/

//Declaracion de estructuras
//Afiliados
typedef struct {   
        char nombre[N], apellido[N];
        int CI;
        char cod[N], coddep[N];
        fecha fechanac;
}paciente;

typedef struct{
	paciente elems[CANT];
	int ultimo;
}lista_p;

// Declaracion de prototipos

//Lista paciente
lista_p vacia_p();
bool es_vacia_p(lista_p );
void insertar_p(lista_p * , int , paciente );
void eliminar_p(lista_p * , int );
paciente consultar_p(lista_p , int );
int longitud_p(lista_p );
int localizar_p(lista_p *, int );
void resto_p(lista_p * );

//Operaciones
paciente anadirpaciente(lista_p , lista_d *);
void mostrarpaciente(paciente );
void eliminarpaciente(lista_p *);
void modificarpaciente(lista_p *);

/************************** Operaciones con los afiliados *********************/

/****************************Añadir un afiliados*******************************/

paciente anadirpaciente(lista_p pacientes, lista_d *dependencias){   
     int a,encontrado;
     paciente p;
     dependencia d;
     
     /*leer nombre*/   
     printf("Introduzca el nombre del Paciente: ");   
     leerchar(p.nombre);   
     /*leer apellidos*/   
     printf("\nIntroduzca los apellidos del cliente: ");   
     leerchar(p.apellido);   
     /*leer CI*/   
     do {      
        printf("\nIntroduzca el n£mero de CI: ");      
        p.CI=leernum();           
        encontrado=0;      
        for(a=0;a<pacientes.ultimo && encontrado==0;a++) {         
                        if (p.CI==pacientes.elems[a].CI) 
                           encontrado=1;
        }             
        if (encontrado==1) 
           printf("\n\nNo puede haber dos CI con  el mismo n£mero");   
     } while (encontrado==1);
     /*leer codigo de afiliacion*/
     do {      
        printf("\nIntroduzca el c¢digo de afiliacion: ");      
        leerchar(p.cod);           
        encontrado=0;      
        for(a=0;a<pacientes.ultimo && encontrado==0;a++) {         
                        if (compararcadenas(p.cod,pacientes.elems[a].cod)==0) 
                           encontrado=1;
        }             
        if (encontrado==1) 
           printf("\n\nNo puede haber dos c¢digos con  el mismo n£mero");   
     } while (encontrado==1);
     /*leer codigo de dependencia*/
     printf("\nIntroduzca el c¢digo dependencia: ");      
     leerchar(p.coddep);
     encontrado=0;
     for(a=0;a<dependencias->ultimo && encontrado==0;a++) {         
		if (compararcadenas(p.coddep, dependencias->elems[a].codigo)) 
			encontrado=1;
    }             
    if (encontrado==0){
		d=anadirdependencia(*dependencias);
		insertar_d(dependencias,longitud_d(*dependencias),d);
	}
    /*leer fecha de nacimiento*/ 
    do{
        printf("\nIntroduzca el d¡a de nacimiento: ");      
        p.fechanac.dia=leernum();
     }while(p.fechanac.dia<1||p.fechanac.dia>31);
     do{
        printf("\nIntroduzca el mes de nacimiento: ");      
        p.fechanac.mes= leernum();
     }while(p.fechanac.mes<1||p.fechanac.mes>12);
     printf("\nIntroduzca el a¤o de nacimiento: ");      
     p.fechanac.ano= leernum();
     return(p);
}
/****************************Mostrar los afiliados*****************************/

void mostrarpaciente(paciente p){   
     
     printf("\n\nNombres: ");puts(p.nombre);
     printf("Apellidos: ");puts(p.apellido);
     printf("Cedula: %d", p.CI);
     printf("\nC¢digo: ");puts(p.cod);
     printf("C¢digo dependencia: ");puts(p.coddep);
     printf("Fecha de nacimiento: %i/%i/%i",p.fechanac.dia,p.fechanac.mes,p.fechanac.ano);
     return;
}

/**********************Modificar la informacion de un afiliado*****************/

void modificarpaciente(lista_p *pacientes){
     
     int encontrado, CI;   
     char modificar;   
     printf("\n\nIntroduzca el n£mero de CI: ");   
     CI=leernum();   
     encontrado=localizar_p(pacientes, CI);   
     if (encontrado==-1) 
        printf("\n\nNo hay ning£n afiliado con esa CI.");   
     else {      
          do {
              printf("\n\n¨Desea modificar el nombre\?");         
              modificar=tolower(getch());      
          } while (modificar!='s' && modificar!='n');      
          if (modificar=='s') {         
             /*coger nombre*/         
             printf("\n\nIntroduzca el nombre: ");         
             leerchar((pacientes->elems[encontrado]).nombre);      
          }      
          do {         
             printf("\n\n¨Desea modificar los apellidos\?");         
             modificar=tolower(getch());      
          } while (modificar!='s' && modificar!='n');      
          if (modificar=='s') {         
             /*Leer apellidos*/         
             printf("\n\nIntroduzca los apellidos: ");
             leerchar((pacientes->elems[encontrado]).apellido);       
          }
                 
     printf("\n\n\nAfiliado modificado con ‚xito");   
     }   
     return;
}
/****************************Eliminar un afiliado******************************/
void eliminarpaciente(lista_p *pacientes){   
     int encontrado, CI;   
     
     printf("\n\nIntroduzca el n£mero de CI: ");   
     CI=leernum();   
     encontrado=localizar_p(pacientes, CI);   
     if (encontrado==-1) 
        printf("\n\nNo hay ning£n afiliado con esa CI.");   
     else {      
          if (confirmar()==1) {      
             eliminar_p(pacientes,encontrado);         
             printf("\n\n\nAfiliado eliminado con ‚xito.");         
          }   
     }   
     return;
}

/*******************************Lista de Pacientes*****************************/

lista_p vacia_p(){
	lista_p a;

	a.ultimo=0;
	return (a);
}

/******************************************************************************/

bool es_vacia_p(lista_p L){
	if (L.ultimo == 0) return(true);
	else return(false);
}

/******************************************************************************/

void insertar_p(lista_p *L, int pos, paciente e){
	int i;
	paciente p;
	if (L->ultimo < N){
		for(i=L->ultimo+1;i>pos+1;i--){
			p=L->elems[i-1];
            L->elems[i]=p;
		}
		L->elems[pos]=e;
		L->ultimo++;
	}
	return;
}

/******************************************************************************/

void eliminar_p(lista_p *L, int pos){
	int i;
	L->ultimo--;
	for(i=pos; i<N; i++){
      L->elems[i]=L->elems[i+1];
	}
	return;
}

/******************************************************************************/

paciente consultar_p(lista_p L, int pos){
	return (L.elems[pos]);
}

/******************************************************************************/

int longitud_p(lista_p L){
	return (L.ultimo);
}

/******************************************************************************/

int localizar_p(lista_p *L, int CI){
	int i;
	if (L->ultimo == 0){
		return(-1);
	}
	else{
        i=0;
		while(i <= L->ultimo && L->elems[i].CI != CI){
			i++;
        }
		if (L->elems[i].CI == CI){
			return(i);
		}	
		else return(-1);
	}
}

/******************************************************************************/

void resto_p(lista_p *L){
	int i;
	L->ultimo--;
    for(i=0;i<L->ultimo;i++){
            L->elems[i]=L->elems[i+1];
	}
	return;
}
