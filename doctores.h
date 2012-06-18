/*********************************** MEDICOS **********************************/

//Declaracion de estructuras
//Medicos
typedef struct {   
	int CI, Nomb_esp;
	char nombre[N], apellido[N];         
} medico;

typedef struct{
	medico elems[N];
	int ultimo;
}lista_m;

//Horario
typedef struct {   
	int Nomb_esp, CI[9];        
} horario;

typedef struct{
	horario elems[10];
	int ultimo;
}lista_h;

//Declaracion de prototipos
medico anadirmedico(lista_m medicos, lista_h *horarios);
void mostrarmedico(medico m);
void eliminarmedico(lista_m *medicos, lista_h *);
void modificarmedico(lista_m *medicos);
//Lista Medicos
lista_m vacia_m();
bool es_vacia_m(lista_m );
void insertar_m(lista_m * , int , medico );
void eliminar_m(lista_m * , int );
medico consultar_m(lista_m , int );
int longitud_m(lista_m );
int localizar_m(lista_m *, int );
void resto_m(lista_m * );

//Lista Horarios
lista_h vacia_h();
bool es_vacia_h(lista_h );
void insertar_h(lista_h * , int , horario );
void eliminar_h(lista_h * , int );
horario consultar_h(lista_h , int );
int longitud_h(lista_h );
int localizar_h(lista_h *, int );
void resto_h(lista_h * );

/************************** Operaciones con los Medicos ***********************/
/*Añadir medico*/
medico anadirmedico(lista_m medicos, lista_h *horarios){   
     int i, a, encontrado;
     medico m;
     int turno, dia;
     horario h;
          
     /*leer nombre*/   
     printf("\n\nIntroduzca el nombre del M‚dico: ");   
     leerchar(m.nombre);   
     /*leer apellidos*/   
     printf("\nIntroduzca los apellidos del M‚dico: ");   
     leerchar(m.apellido);   
     /*leer CI*/   
     do {      
        printf("\nIntroduzca el n£mero de CI: ");      
        m.CI=leernum();           
        encontrado=0;      
        for(a=0;a<medicos.ultimo && encontrado==0;a++) {         
                        if (m.CI == medicos.elems[a].CI) 
                           encontrado=1;
        }             
        if (encontrado==1) 
           printf("\n\nNo puede haber dos CI con  el mismo n£mero");   
     } while (encontrado==1);
     /*leer especialidad*/
	 do{
        printf("\nIndique el nombre de su especialidad: ");
	    printf("\n1- Medicina general");
	    printf("\n2- Obstetricia");
	    printf("\n3- Cardiolog¡a");
	    printf("\n4- Medicina interna");
	    printf("\n5- Ginecolog¡a");
	    printf("\n6- Pediatr¡a");
	    printf("\n7- Neumonolog¡a");
	    printf("\n8- Traumatolog¡a");
	    printf("\n9- Odontolog¡a");
	    printf("\n10- Rayos X\n");
        printf("\nElija su opci¢n (1-10): \n");
	    m.Nomb_esp = leernum();
	 }while(m.Nomb_esp < 1 || m.Nomb_esp > 10 );
     /*leer el horario de trabajo*/       
     do{
        do{
           printf("\nIntroduzca el dia de la semana en el que atiende: ");
           printf("\n0- Lunes");
		   printf("\n1- Martes");
		   printf("\n2- Miercoles");
		   printf("\n3- Jueves");
		   printf("\n4- Viernes: ");
           dia=leernum();
        }while(dia<0 || dia>4);
        do{
           printf("\nIntroduzca el turno en el cual presta servicio(0-Ma¤ana o 1-Tarde): ");      
           turno=leernum();
        }while(turno!=0 && turno!=1);
        i=(dia*2)+turno;
        horarios->elems[m.Nomb_esp-1].CI[i]=m.CI;
        horarios->ultimo++;
        printf("\n¨Otro horario\?\n");      
        printf("\n(s/n) ");
     }while(getch()=='s');
           
     return(m);
}

/*Mostrar informacion del Medico*/
void mostrarmedico(medico m){   
     
     printf("\n\nNombres: ");puts(m.nombre);
     printf("Apellidos: ");puts(m.apellido);
     printf("Cedula: %d", m.CI);
     printf("\nEspecialidad: ");
     switch(m.Nomb_esp)
     {
        case 1: printf("Medicina general"); break;
        case 2: printf("Obstetricia"); break;
        case 3: printf("Cardiolog¡a"); break;
        case 4: printf("Medicina interna"); break;
        case 5: printf("Ginecolog¡a"); break;
        case 6: printf("Pediatr¡a"); break;
        case 7: printf("Neumonolog¡a"); break;
        case 8: printf("Traumatolog¡a"); break;
        case 9: printf("Odontolog¡a"); break;
        case 10: printf("Rayos X"); break;
     }
     
     return;
}

/**********************Modificar la informacion de un medico*****************/

void modificarmedico(lista_m *medicos){
     
     int encontrado, CI;   
     char modificar;   
     printf("\n\nIntroduzca el n£mero de CI: ");   
     CI=leernum();   
     encontrado=localizar_m(medicos, CI);   
     if (encontrado==-1) 
        printf("\n\nNo hay ning£n m‚dico con esa CI.");   
     else {      
          do {
              printf("\n\n¨Desea modificar el nombre\?");         
              modificar=tolower(getch());      
          } while (modificar!='s' && modificar!='n');      
          if (modificar=='s') {         
             /*leer nombre*/         
             printf("\n\nIntroduzca el nombre: ");         
             leerchar((medicos->elems[encontrado]).nombre);      
          }      
          do {         
             printf("\n\n¨Desea modificar los apellidos\?");         
             modificar=tolower(getch());      
          } while (modificar!='s' && modificar!='n');      
          if (modificar=='s') {         
             /*Leer apellidos*/         
             printf("\n\nIntroduzca los apellidos: ");
             leerchar((medicos->elems[encontrado]).apellido);       
          }
          do {         
             printf("\n\n¨Desea modificar la especialidad\?");         
             modificar=tolower(getch());      
          } while (modificar!='s' && modificar!='n');      
          if (modificar=='s') {
             /*leer nombre especialidad*/
             do{
                printf("\nIndique el nombre de su especialidad: ");
	            printf("\n1- Medicina general");
	            printf("\n2- Obstetricia");
	            printf("\n3- Cardiolog¡a");
	            printf("\n4- Medicina interna");
	            printf("\n5- Ginecolog¡a");
	            printf("\n6- Pediatr¡a");
	            printf("\n7- Neumonolog¡a");
	            printf("\n8- Traumatolog¡a");
	            printf("\n9- Odontolog¡a");
	            printf("\n10- Rayos X\n");
                printf("\nElija su opci¢n (1-10): \n");
	            medicos->elems[encontrado].Nomb_esp = leernum();
             }while((medicos->elems[encontrado]).Nomb_esp < 1 || (medicos->elems[encontrado]).Nomb_esp > 10 );
          }          
     printf("\n\n\nM‚dico modificado con ‚xito");   
     }   
     return;
}

/****************************Eliminar un medico******************************/

void eliminarmedico(lista_m *medicos, lista_h *horarios){   
     int encontrado, CI, i;   
     
     printf("\n\nIntroduzca el n£mero de CI: ");   
     CI=leernum();   
     encontrado=localizar_m(medicos, CI);   
     if (encontrado==-1) 
        printf("\n\nNo hay ning£n m‚dico con esa CI.");   
     else {      
          if (confirmar()==1) {      
             eliminar_m(medicos,encontrado);
             for(i=0;i<10;i++) {
				if(medicos->elems[encontrado].CI == horarios->elems[medicos->elems[encontrado].Nomb_esp-1].CI[i]){
                   horarios->elems[medicos->elems[encontrado].Nomb_esp-1].CI[i]=-1;
                }
             }          
             printf("\n\n\nM‚dico eliminado con ‚xito.");         
          }   
     }   
     return;
}

/******************************Listas Medicos*************************/

lista_m vacia_m(){
	lista_m m;

	m.ultimo=0;
	return (m);
}

bool es_vacia_m(lista_m L){
	if (L.ultimo == 0) return(true);
	else return(false);
}

void insertar_m(lista_m *L, int pos, medico m){
	int i;
	if (L->ultimo < N){
		for(i=L->ultimo+1;i>pos+1;i--){
			L->elems[i] = L->elems[i-1];
		}
		L->elems[pos]=m;
		L->ultimo++;
	}
	return;
}

void eliminar_m(lista_m *L, int pos){
	int i;
	L->ultimo--;
	for(i=pos; i<N; i++){
      L->elems[i]=L->elems[i+1];
	}
	return;
}

medico consultar_m(lista_m L, int pos){
	return (L.elems[pos]);
}

int longitud_m(lista_m L){
	return (L.ultimo);
}

int localizar_m(lista_m *L, int CI){
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

void resto_m(lista_m *L){
	int i;
	L->ultimo--;
    for(i=0;i<L->ultimo;i++){
            L->elems[i]=L->elems[i+1];
	}
	return;
}

/******************************Listas horarios*************************/

lista_h vacia_h(){
	lista_h h;
    h.ultimo=0;
	
	return (h);
}

bool es_vacia_h(lista_h L){
	if (L.ultimo == 0) return(true);
	else return(false);
}

void insertar_h(lista_h *L, int pos, horario h){
	int i;
	if (L->ultimo < N){
		for(i=L->ultimo+1;i>pos+1;i--){
			L->elems[i] = L->elems[i-1];
		}
		L->elems[pos]=h;
		L->ultimo++;
	}
	return;
}

void eliminar_h(lista_h *L, int pos){
	int i;
	L->ultimo--;
	for(i=pos; i<N; i++){
      L->elems[i]=L->elems[i+1];
	}
	return;
}

horario consultar_h(lista_h L, int pos){
	return (L.elems[pos]);
}

int longitud_h(lista_h L){
	return (L.ultimo);
}

void resto_h(lista_h *L){
	int i;
	L->ultimo--;
    for(i=0;i<L->ultimo;i++){
            L->elems[i]=L->elems[i+1];
	}
	return;
}
