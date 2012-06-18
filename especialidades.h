/********************************* ESPECIALIDADES *****************************/
//Declaracion de estructuras
//Especialidades
typedef struct {
	char Nconsul[N]; 
	int Nomb_esp, lim_man, lim_tar;                 
}especialidad;


typedef struct{
	especialidad elems[9];
	int ultimo;
}lista_e;

//declaracion de prototipos
especialidad anadirespecialidad(lista_e );
void mostrarespecialidad(especialidad );
void eliminarespecialidad(lista_e *especialidades);   
void modificarespecialidad(lista_e *especialidades);
//Lista especialidades
lista_e vacia_e();
bool es_vacia_e(lista_e );
void insertar_e(lista_e * , int , especialidad );
void eliminar_e(lista_e * , int );
especialidad consultar_e(lista_e , int );
int longitud_e(lista_e );
int localizar_e(lista_e *, int );
void resto_e(lista_e * );

/********************** Operaciones con las Especilalidades *******************/

especialidad anadirespecialidad(lista_e especialidades){   
     int a,encontrado;
     especialidad e;
     
     /*leer nombre*/
     do {      
        do{
           printf("Indique el nombre de la especialidad: ");
	       printf("\n1- Medicina general");
	       printf("\n2- Obstetricia");
	       printf("\n3- Cardiología");
	       printf("\n4- Medicina interna");
	       printf("\n5- Ginecolog¡a");
	       printf("\n6- Pediatr¡a");
	       printf("\n7- Neumonolog¡a");
	       printf("\n8- Traumatolog¡a");
	       printf("\n9- Odontolog¡a");
	       printf("\n10- Rayos X\n");
           printf("\nElija su opci¢n (1-10): \n");
	       e.Nomb_esp = leernum();
	    }while(e.Nomb_esp < 1 || e.Nomb_esp > 10 );
        encontrado=0;         
        for(a=0;a<especialidades.ultimo && encontrado==0;a++) {         
           if (e.Nomb_esp == especialidades.elems[a].Nomb_esp) 
              encontrado=1;
        }             
        if (encontrado==1) 
           printf("\n\nEspecialidad ya es atendida");   
     } while (encontrado==1);
     
      
     /*leer consultorio*/
     do {   
        printf("\nIntroduzca el consultorio: ");   
        leerchar(e.Nconsul);
        encontrado=0;         
        for(a=0;a<especialidades.ultimo && encontrado==0;a++) {         
           if (compararcadenas(e.Nconsul,especialidades.elems[a].Nconsul)==0) 
              encontrado=1;
        }             
        if (encontrado==1) 
           printf("\n\nConsultorio Ocupado");   
     } while (encontrado==1);
     /*leer limite en la mañana*/
     do{
          printf("\nIntroduzca el l¡mite de pacientes en la ma¤ana: ");   
          e.lim_man=leernum();     
     }while(e.lim_man>CANT);
     /*leer limite en la mañana*/
     do{
         printf("\nIntroduzca el l¡mite de pacientes en la tarde: ");   
         e.lim_tar =leernum();          
     }while(e.lim_tar>CANT);
     return(e);
}

void mostrarespecialidad(especialidad e){   
     
     printf("\n\nNombre de la especialidad: ");
     switch(e.Nomb_esp)
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
     printf("\nNumero consultorio:");puts(e.Nconsul);
     printf("Limite en la ma¤ana: %d", e.lim_man);
     printf("\nL¡mite en la tarde: %d", e.lim_tar);
     return;
}

/**********************Modificar la informacion de un medico*****************/

void modificarespecialidad(lista_e *especialidades){
     
     int encontrado, nomb_esp;   
     char modificar;   
     do{
        printf("Indique el nombre de la especialidad: ");
	    printf("\n1- Medicina general");
	    printf("\n2- Obstetricia");
	    printf("\n3- Cardiología");
	    printf("\n4- Medicina interna");
	    printf("\n5- Ginecolog¡a");
	    printf("\n6- Pediatr¡a");
	    printf("\n7- Neumonolog¡a");
	    printf("\n8- Traumatolog¡a");
	    printf("\n9- Odontolog¡a");
	    printf("\n10- Rayos X\n");
        printf("\nElija su opci¢n (1-10): \n");
	    nomb_esp = leernum();
	 }while(nomb_esp < 1 || nomb_esp > 10 );   
     encontrado=localizar_e(especialidades, nomb_esp);   
     if (encontrado==-1) 
        printf("\n\nEsa especialidad no es atendida");   
     else {      
          do {
              printf("\n\n¨Desea modificar el consultorio\?");         
              modificar=tolower(getch());      
          } while (modificar!='s' && modificar!='n');      
          if (modificar=='s') {         
             /*coger nombre*/         
             printf("\n\nIntroduzca el consultorio: ");         
             leerchar((especialidades->elems[encontrado]).Nconsul);      
          }      
          do {         
             printf("\n\n¨Desea modificar el limite de la ma¤ana\?");         
             modificar=tolower(getch());      
          } while (modificar!='s' && modificar!='n');      
          if (modificar=='s') {         
             /*Leer apellidos*/         
             printf("\n\nIntroduzca el limite de la ma¤ana: ");
             (especialidades->elems[encontrado]).lim_man=leernum();       
          }
          do {         
             printf("\n\n¨Desea modificar el limite de la tarde\?");         
             modificar=tolower(getch());      
          } while (modificar!='s' && modificar!='n');      
          if (modificar=='s') {
             printf("\n\nIntroduzca el limite de la tarde: ");
             (especialidades->elems[encontrado]).lim_tar=leernum();
          }
          
     printf("\n\n\nEspecialidad modificada con ‚xito");   
     }   
     return;
}

/****************************Eliminar un medico******************************/

void eliminarespecialidad(lista_e *especialidades){   
     int encontrado, nomb_esp;   
     
     do{
        printf("Indique el nombre de la especialidad: ");
	    printf("\n1- Medicina general");
	    printf("\n2- Obstetricia");
	    printf("\n3- Cardiología");
	    printf("\n4- Medicina interna");
	    printf("\n5- Ginecolog¡a");
	    printf("\n6- Pediatr¡a");
	    printf("\n7- Neumonolog¡a");
	    printf("\n8- Traumatolog¡a");
	    printf("\n9- Odontolog¡a");
	    printf("\n10- Rayos X\n");
        printf("\nElija su opci¢n (1-10): \n");
	    nomb_esp = leernum();
	 }while(nomb_esp < 1 || nomb_esp > 10 );   
     encontrado=localizar_e(especialidades, nomb_esp);  
     if (encontrado==-1) 
        printf("\n\nEsa especialidad no es atendida");   
     else {      
          if (confirmar()==1) {      
             eliminar_e(especialidades,encontrado);         
             printf("\n\n\nEspecialidad eliminada con ‚xito.");         
          }   
     }   
     return;
}

/********************************listas*******************************/

lista_e vacia_e(){
	lista_e a;

	a.ultimo=0;
	return (a);
}

bool es_vacia_e(lista_e L){
	if (L.ultimo == 0) return(true);
	else return(false);
}

void insertar_e(lista_e *L, int pos, especialidad e){
	int i;
	if (L->ultimo < N){
		for(i=L->ultimo+1;i>pos+1;i--){
			L->elems[i] = L->elems[i-1];
		}
		L->elems[pos]=e;
		L->ultimo++;
	}
	return;
}

void eliminar_e(lista_e *L, int pos){
	int i;
	L->ultimo--;
	for(i=pos; i<N; i++){
      L->elems[i]=L->elems[i+1];
	}
	return;
}

especialidad consultar_e(lista_e L, int pos){
	return (L.elems[pos]);
}

int longitud_e(lista_e L){
	return (L.ultimo);
}

int localizar_e(lista_e *L, int Nomb_esp){
	int i;
	if (L->ultimo == 0){
		return(-1);
	}
	else{
        i=0;
		while(i <= L->ultimo && L->elems[i].Nomb_esp != Nomb_esp){
			i++;
        }
		if (L->elems[i].Nomb_esp == Nomb_esp){
			return(i);
		}	
		else return(-1);
	}
}

void resto_e(lista_e *L){
	int i;
	L->ultimo--;
    for(i=0;i<L->ultimo;i++){
            L->elems[i]=L->elems[i+1];
	}
	return;
}

