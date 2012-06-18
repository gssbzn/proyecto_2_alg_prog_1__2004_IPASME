/*********************************** CITAS **********************************/
//Declaracion de estructuras
//Citas
typedef struct {
        int CI,turno;
        char nombre[N], apellido[N], NConsul[N], cod[N];
} cita;  

typedef struct{
	cita elems[N];
	int ultimo;
}lista_c;

//Declaracion de prototipos

cita anadiratendido(lista_p *pacientes, lista_d *dependencias,lista_e especialidades, lista_m medicos, lista_h horarios, lista_c *pendientes, lista_est *estadisticas, lista_est2 *estadisticas2);
//Lista Citas
lista_c vacia_c();
bool es_vacia_c(lista_c );
void insertar_c(lista_c * , int , cita );
void eliminar_c(lista_c * , int );
cita consultar_c(lista_c , int );
int longitud_c(lista_c );
int localizar_c(lista_c *, int );
void resto_c(lista_c * );

/************************** Operaciones con las Citas ***********************/
cita anadiratendido(lista_p *pacientes, lista_d *dependencias, lista_e especialidades, lista_m medicos, lista_h horarios, lista_c *pendientes, lista_est *estadisticas, lista_est2 *estadisticas2)
{
	int a,b,encontrado,Nomb_esp, CI;
    cita c;
	paciente p;
    estadistica2 esta2;
    
    /*leer CI*/   
    printf("\nIntroduzca el n£mero de CI: ");      
    c.CI=leernum();           
    encontrado=0;      
    for(a=0;a<pacientes->ultimo && encontrado==0;a++) {         
		if (c.CI==pacientes->elems[a].CI) 
			encontrado=1;
    }             
    if (encontrado==1){
		printf("Paciente Encontrado");
		strcpy(c.nombre , pacientes->elems[a-1].nombre);
		strcpy(c.apellido , pacientes->elems[a-1].apellido);
		strcpy(c.cod , pacientes->elems[a-1].cod);
	}
	else{
		p=anadirpaciente(*pacientes, dependencias);
		insertar_p(pacientes,longitud_p(*pacientes),p);
		strcpy(c.nombre,p.nombre);
		strcpy(c.apellido,p.apellido);
		strcpy(c.cod , p.cod);
	}
	/*Leer especialidad*/
	do{
        printf("\nIndique la especialidad en la que desea ser atendido: ");
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
	    Nomb_esp = leernum();
	}while(Nomb_esp < 1 || Nomb_esp > 10 );
	encontrado=0;      
    for(b=0;b<especialidades.ultimo && encontrado==0;b++) {         
		if (Nomb_esp == especialidades.elems[b].Nomb_esp) 
			encontrado=1;
    }             
	if (encontrado==1){
		strcpy(c.NConsul, especialidades.elems[b-1].Nconsul);
	}
	else{
		printf("Especialidad no atendida");
		c.CI=-1;
		c.turno=-1;
		strcpy(c.nombre," ");
		strcpy(c.apellido," ");
		strcpy(c.cod," ");
		strcpy(c.NConsul," ");
		return(c);
	}
	encontrado=0;
	if(horarios.elems[Nomb_esp-1].CI[(hoy.dia*2)+hoy.turno]!=-1){
		CI=horarios.elems[Nomb_esp-1].CI[(hoy.dia*2)+hoy.turno];
		encontrado=localizar_m(&medicos, CI);
		
	}
	else{
		printf("No hay medico en ese horario");
		c.CI=-1;
		c.turno=-1;
		strcpy(c.nombre," ");
		strcpy(c.apellido," ");
		strcpy(c.cod," ");
		strcpy(c.NConsul," ");
		return(c);
	}
     c.turno=hoy.turno;
	 switch(Nomb_esp)
	 {
	 case 1:
		 
		 if(especialidades.elems[b-1].lim_man <= mg && hoy.turno == 0 || hoy.turno == 1 && especialidades.elems[b-1].lim_tar <= mg)
		 {
			 printf("Se ha alcanzado el limite, cita agragada a la  lista de espera...");
			 insertar_c(pendientes,longitud_c(*pendientes),c);
			 if(hoy.turno==0) estadisticas->elems[0].n_pend++;
             else estadisticas->elems[1].n_pend++;
			 c.CI=-1;
			 c.turno=-1;
			 strcpy(c.nombre," ");
			 strcpy(c.apellido," ");
			 strcpy(c.cod," ");
			 strcpy(c.NConsul," ");
			 return(c);

		 }
		 printf("\nEl paciente tiene %d personas por delante...",mg);
		 mg++;
		 if(hoy.turno==0) estadisticas->elems[0].n_aten++;
         else estadisticas->elems[1].n_aten++;
	 break;
	 case 2:
		 if(especialidades.elems[b-1].lim_man <= ob && hoy.turno == 0 || hoy.turno == 1 && especialidades.elems[b-1].lim_tar <= ob)
		 {
			 printf("Se ha alcanzado el limite, cita agragada a la  lista de espera...");
			 insertar_c(pendientes,longitud_c(*pendientes),c);
			 if(hoy.turno==0) estadisticas->elems[2].n_pend++;
             else estadisticas->elems[3].n_pend++;
             c.CI=-1;
			 c.turno=-1;
			 strcpy(c.nombre," ");
			 strcpy(c.apellido," ");
			 strcpy(c.cod," ");
			 strcpy(c.NConsul," ");
			 return(c);

		 }
		 printf("\nEl paciente tiene %d personas por delante...",ob);
		 ob++;
		 if(hoy.turno==0) estadisticas->elems[2].n_aten++;
         else estadisticas->elems[3].n_aten++;
	 break;
	 case 3:
		 if(especialidades.elems[b-1].lim_man <= ca && hoy.turno == 0 || hoy.turno == 1 && especialidades.elems[b-1].lim_tar <= ca)
		 {
			 printf("Se ha alcanzado el limite, cita agragada a la  lista de espera...");
			 insertar_c(pendientes,longitud_c(*pendientes),c);
			 if(hoy.turno==0) estadisticas->elems[4].n_pend++;
             else estadisticas->elems[5].n_pend++;
			 c.CI=-1;
			 c.turno=-1;
			 strcpy(c.nombre," ");
			 strcpy(c.apellido," ");
			 strcpy(c.cod," ");
			 strcpy(c.NConsul," ");
			 return(c);

		 }
		 printf("\nEl paciente tiene %d personas por delante...",ca);
		 ca++;
		 if(hoy.turno==0) estadisticas->elems[4].n_aten++;
         else estadisticas->elems[5].n_aten++;
	 break;
	 case 4:
		 if(especialidades.elems[b-1].lim_man <= mi && hoy.turno == 0 || hoy.turno == 1 && especialidades.elems[b-1].lim_tar <= mi)
		 {
			 printf("Se ha alcanzado el limite, cita agragada a la  lista de espera...");
			 insertar_c(pendientes,longitud_c(*pendientes),c);
			 if(hoy.turno==0) estadisticas->elems[6].n_pend++;
             else estadisticas->elems[7].n_pend++;
			 c.CI=-1;
			 c.turno=-1;
			 strcpy(c.nombre," ");
			 strcpy(c.apellido," ");
			 strcpy(c.cod," ");
			 strcpy(c.NConsul," ");
			 return(c);

		 }
		 printf("\nEl paciente tiene %d personas por delante...",mi);
		 mi++;
		 if(hoy.turno==0) estadisticas->elems[6].n_aten++;
         else estadisticas->elems[7].n_aten++;
	 break;
	 case 5:
		 if(especialidades.elems[b-1].lim_man <= gi && hoy.turno == 0 || hoy.turno == 1 && especialidades.elems[b-1].lim_tar <= gi)
		 {
			 printf("Se ha alcanzado el limite, cita agragada a la  lista de espera...");
			 insertar_c(pendientes,longitud_c(*pendientes),c);
			 if(hoy.turno==0) estadisticas->elems[8].n_pend++;
             else estadisticas->elems[9].n_pend++;
			 c.CI=-1;
			 c.turno=-1;
			 strcpy(c.nombre," ");
			 strcpy(c.apellido," ");
			 strcpy(c.cod," ");
			 strcpy(c.NConsul," ");
			 return(c);

		 }
		 printf("\nEl paciente tiene %d personas por delante...",gi);
		 gi++;
		 if(hoy.turno==0) estadisticas->elems[8].n_aten++;
         else estadisticas->elems[9].n_aten++;
	 break;
	 case 6:
		 if(especialidades.elems[b-1].lim_man <= pe && hoy.turno == 0 || hoy.turno == 1 && especialidades.elems[b-1].lim_tar <= pe)
		 {
			 printf("Se ha alcanzado el limite, cita agragada a la  lista de espera...");
			 insertar_c(pendientes,longitud_c(*pendientes),c);
			 if(hoy.turno==0) estadisticas->elems[10].n_pend++;
             else estadisticas->elems[11].n_pend++;
			 c.CI=-1;
			 c.turno=-1;
			 strcpy(c.nombre," ");
			 strcpy(c.apellido," ");
			 strcpy(c.cod," ");
			 strcpy(c.NConsul," ");
			 return(c);

		 }
		 printf("\nEl paciente tiene %d personas por delante...",pe);
		 pe++;
		 if(hoy.turno==0) estadisticas->elems[10].n_aten++;
         else estadisticas->elems[11].n_aten++;
	 break;
	 case 7:
		 if(especialidades.elems[b-1].lim_man <= ne && hoy.turno == 0 || hoy.turno == 1 && especialidades.elems[b-1].lim_tar <= ne)
		 {
			 printf("Se ha alcanzado el limite, cita agragada a la  lista de espera...");
			 insertar_c(pendientes,longitud_c(*pendientes),c);
			 if(hoy.turno==0) estadisticas->elems[12].n_pend++;
             else estadisticas->elems[13].n_pend++;
             c.CI=-1;
			 c.turno=-1;
			 strcpy(c.nombre," ");
			 strcpy(c.apellido," ");
			 strcpy(c.cod," ");
			 strcpy(c.NConsul," ");
			 return(c);

		 }
		 printf("\nEl paciente tiene %d personas por delante...",ne);
		 ne++;
		 if(hoy.turno==0) estadisticas->elems[12].n_aten++;
         else estadisticas->elems[13].n_aten++;
	 break;
	 case 8:
		 if(especialidades.elems[b-1].lim_man <= tra && hoy.turno == 0 || hoy.turno == 1 && especialidades.elems[b-1].lim_tar <= tra)
		 {
			 printf("Se ha alcanzado el limite, cita agragada a la  lista de espera...");
			 insertar_c(pendientes,longitud_c(*pendientes),c);
			 if(hoy.turno==0) estadisticas->elems[14].n_pend++;
             else estadisticas->elems[15].n_pend++;
			 c.CI=-1;
			 c.turno=-1;
			 strcpy(c.nombre," ");
			 strcpy(c.apellido," ");
			 strcpy(c.cod," ");
			 strcpy(c.NConsul," ");
			 return(c);

		 }
		 printf("\nEl paciente tiene %d personas por delante...",tra);
		 tra++;
		 if(hoy.turno==0) estadisticas->elems[14].n_aten++;
         else estadisticas->elems[15].n_aten++;
	 break;
	 case 9:
		 if(especialidades.elems[b-1].lim_man <= od && hoy.turno == 0 || hoy.turno == 1 && especialidades.elems[b-1].lim_tar <= od)
		 {
			 printf("Se ha alcanzado el limite, cita agragada a la  lista de espera...");
			 insertar_c(pendientes,longitud_c(*pendientes),c);
			 if(hoy.turno==0) estadisticas->elems[16].n_pend++;
             else estadisticas->elems[17].n_pend++;
             c.CI=-1;
			 c.turno=-1;
			 strcpy(c.nombre," ");
			 strcpy(c.apellido," ");
			 strcpy(c.cod," ");
			 strcpy(c.NConsul," ");
			 return(c);

		 }
		 printf("\nEl paciente tiene %d personas por delante...",od);
		 od++;
		 if(hoy.turno==0) estadisticas->elems[16].n_aten++;
         else estadisticas->elems[17].n_aten++;
	 break;
	 case 10:
		 if(especialidades.elems[b-1].lim_man <= rx && hoy.turno == 0 || hoy.turno == 1 && especialidades.elems[b-1].lim_tar <= rx)
		 {
			 printf("Se ha alcanzado el limite, cita agragada a la  lista de espera...");
			 insertar_c(pendientes,longitud_c(*pendientes),c);
			 if(hoy.turno==0) estadisticas->elems[18].n_pend++;
             else estadisticas->elems[19].n_pend++;
			 c.CI=-1;
			 c.turno=-1;
			 strcpy(c.nombre," ");
			 strcpy(c.apellido," ");
			 strcpy(c.cod," ");
			 strcpy(c.NConsul," ");
			 return(c);

		 }
		 printf("\nEl paciente tiene %d personas por delante...",rx);
		 rx++;
		 if(hoy.turno==0) estadisticas->elems[18].n_aten++;
         else estadisticas->elems[19].n_aten++;
	 break;
	 }
	 printf("\nSera atendido en el consultorio #: ");fflush(stdout);
	 puts(c.NConsul);fflush(stdout);
	 printf("Medico por el cual va a ser atendido %s ",medicos.elems[encontrado].nombre);fflush(stdout);
	 puts(medicos.elems[encontrado].apellido);fflush(stdout);
     encontrado=0;
     for(a=0;a<pacientes->ultimo && encontrado==0;a++) {         
		if (c.CI==pacientes->elems[a].CI) 
			encontrado=1;
     }
     encontrado=localizar_est2(estadisticas2,pacientes->elems[a-1].coddep);
     if(encontrado==-1){
               esta2.CAA=0;
               strcpy(esta2.coddep,pacientes->elems[a-1].coddep);
               esta2.CAA++;
               insertar_est2(estadisticas2,longitud_est2(*estadisticas2), esta2);
     }
     else{
          estadisticas2->elems[encontrado].CAA++;
     }
     return(c);
}

bool es_viejo(lista_p pacientes, int CI){
	int i, encontrado=-1;

	for(i=0;i<longitud_p(pacientes) && encontrado==-1;i++){
		if(pacientes.elems[i].CI==CI) encontrado=i;
	}
	if(encontrado!=-1){
		if(hoy.ano - pacientes.elems[encontrado].fechanac.ano>=65)return(true);
		else return(false);
	}
	else return(false);
}

int siguiente_p(lista_c *citas, lista_p pacientes, char *especialidad, int *viejo){
	int i;
	if (citas->ultimo == 0){
		return(-1);
	}
	else{
        i=0;
		if(*viejo < 2)
		{
			while(i <= citas->ultimo){
				
				if (compararcadenas(citas->elems[i].NConsul, especialidad)==0 && es_viejo(pacientes,citas->elems[i].CI)){
				   *viejo=*viejo+1;
			       return(i);
			    }
			    i++;
			}			
		}
		if(*viejo >= 2 || i==-1){
			i=0;
			while(i <= citas->ultimo && compararcadenas(citas->elems[i].NConsul, especialidad)==1){
				i++;
			}
			if (compararcadenas(citas->elems[i].NConsul, especialidad)==0){
				*viejo = 0;
				return(i);
			}	
			else return(-1);	

		}
	}
}
	
void eliminarcita(lista_c *citas){   
     int encontrado, CI;   
     
     printf("\n\nIntroduzca el n£mero de CI: ");   
     CI=leernum();   
     encontrado=localizar_c(citas, CI);   
     if (encontrado==-1) 
        printf("\n\nNo hay ninguna cita con esa CI.");   
     else {      
          if (confirmar()==1) {      
             eliminar_c(citas,encontrado);         
             printf("\n\n\nCita eliminada con ‚xito.");         
          }   
     }   
     return;
}
/*******************************Lista de Citas*****************************/

lista_c vacia_c(){
	lista_c c;

	c.ultimo=0;
	return (c);
}

/******************************************************************************/

bool es_vacia_c(lista_c L){
	if (L.ultimo == 0) return(true);
	else return(false);
}

/******************************************************************************/

void insertar_c(lista_c *L, int pos, cita e){
	int i;
	cita c;
	if (L->ultimo < N){
		for(i=L->ultimo+1;i>pos+1;i--){
			c=L->elems[i-1];
            L->elems[i]=c;
		}
		L->elems[pos]=e;
		L->ultimo++;
	}
	return;
}

/******************************************************************************/

void eliminar_c(lista_c *L, int pos){
	int i;
	L->ultimo--;
	for(i=pos; i<N; i++){
      L->elems[i]=L->elems[i+1];
	}
	return;
}

/******************************************************************************/

cita consultar_c(lista_c L, int pos){
	return (L.elems[pos]);
}

/******************************************************************************/

int longitud_c(lista_c L){
	return (L.ultimo);
}

/******************************************************************************/

int localizar_c(lista_c *L, int CI){
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

void resto_c(lista_c *L){
	int i;
	L->ultimo--;
    for(i=0;i<L->ultimo;i++){
            L->elems[i]=L->elems[i+1];
	}
	return;
}

/******************************************************************************/


