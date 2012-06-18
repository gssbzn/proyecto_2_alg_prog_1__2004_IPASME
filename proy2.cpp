//librerias

#include "hochimin.h"
#include "dependencia.h"
#include "afiliados.h"
#include "especialidades.h"
#include "doctores.h"
#include "estadisticas.h"
#include "citas.h"
#include "salvar.h"
#include "extras.h"

int main(){
	
	//LISTAS
    lista_p pacientes;
    lista_e especialidades;
    lista_m medicos;
	lista_d dependencias;
	lista_c citas,pendientes;
	lista_h horarios;
	lista_est estadisticas;
	lista_est2 estadisticas2;

    paciente p;
    especialidad e;
    medico m;
	dependencia d;
	cita c;
    char Nconsul[N];
	int i, j, respuesta, opc, encontrado, viejo=0;
    bool r;
    
    //VACIADO DE LISTAS
    especialidades = vacia_e();
    pacientes = vacia_p();
	citas = vacia_c();
	pendientes = vacia_c();
    medicos = vacia_m();
    horarios = vacia_h();
	dependencias = vacia_d();
    
    for(i=0;i<9;i++){
		horarios.elems[i].Nomb_esp=i+1;
        for(j=0;j<9;j++){
			horarios.elems[i].CI[j]=-1;
       }
    }
    estadisticas.ultimo=19;
    for(i=0;i<estadisticas.ultimo;i++){
       if ((i%2)==0)
          estadisticas.elems[i].turno=0;
       else
          estadisticas.elems[i].turno=1;
       
    }
    cargar(&especialidades, &pacientes, &medicos, &horarios, &dependencias, &citas, &estadisticas, &estadisticas2);

    printf("\t\n\nPor favor introduzca la fecha actual: ");
      /*coger mes actual*/
      do{
        printf("\nIntroduzca el mes: ");
        hoy_d.mes=leernum();
        if(hoy_d.mes<1||hoy_d.mes>12) printf("\nMes Invalido");
     }while(hoy_d.mes<1||hoy_d.mes>12);
     /*coger dia actual*/
     do{
        r=true;
        printf("\nIntroduzca el dia: ");
        hoy_d.dia=leernum();
        if(hoy_d.mes==1||hoy_d.mes==3||hoy_d.mes==5||hoy_d.mes==7||hoy_d.mes==8||hoy_d.mes==10||hoy_d.mes==12){
           if(hoy_d.dia<1||hoy_d.dia>31){
              printf("\nDia Invalido");
              r=false;
           }
        }
        else if(hoy_d.mes==4||hoy_d.mes==6||hoy_d.mes==9||hoy_d.mes==11){
           if(hoy_d.dia<1||hoy_d.dia>30){
              printf("\nDia Invalido");
              r=false;
           }
        }
        else{
           if(hoy_d.dia<1||hoy.dia>29){
              printf("\nDia Invalido");
              r=false;
           }
        } 
     }while(r==false);
    do{
		printf("\nPor favor introduzca el dia de la semana: ");
		printf("\n0- Lunes");
		printf("\n1- Martes");
		printf("\n2- Miercoles");
		printf("\n3- Jueves");
		printf("\n4- Viernes: ");
		hoy.dia=leernum();
    }while(hoy.dia < 0 || hoy.dia > 4 );
    
	do{
		printf("\nIntroduzca el turno en el que trabaja(Ma¤ana o Tarde): ");      
        hoy.turno=leernum();
	}while(hoy.turno!=0 && hoy.turno!=1);

	hoy.ano=2005;
	
    do{
        tecla();      
        respuesta=menu();/*menu*/      
        system("cls");      
        switch(respuesta) {     
                          case 0:         
                               if (confirmar()==1) {            
                                  printf("\n\nSaliendo del programa...");
                                  guardar(especialidades, pacientes, medicos, horarios, dependencias, citas, estadisticas, estadisticas2);         
                               }         
                               else respuesta=-1;         
                          break;      
                          
                          case 1:/*Añadir Afiliado*/     
                              if(longitud_p(pacientes)<CANT){    
                              p=anadirpaciente(pacientes, &dependencias);
                              insertar_p(&pacientes,longitud_p(pacientes),p);
                              }
                              else printf("\n\nNo se pueden insertar mas afiliados...");
						  break;      
                          
                          case 2:/*Eliminar Afiliado*/         
                              eliminarpaciente(&pacientes);
                          break;   
                             
                          case 3:/*modificar un Afiliado*/         
                              modificarpaciente(&pacientes);
                          break;
                                
                          case 4:/*Añadir Medico*/ 
                              if(longitud_m(medicos)<CANT){
							  m=anadirmedico(medicos, &horarios);
                              insertar_m(&medicos,longitud_m(medicos),m);
                              }
                              else printf("\n\nNo se pueden insertar mas medicos...");
                          break;
                                
                          case 5:/*Eliminar Medico*/        
                              eliminarmedico(&medicos, &horarios);
                          break;
                                
                          case 6:/*Modificar Medico*/         
                              modificarmedico(&medicos);
                          break;
                                
                          case 7:/*Añadir Especialidad*/
							  e=anadirespecialidad(especialidades);
                              insertar_e(&especialidades,longitud_e(especialidades),e);
                          break;
                                
                          case 8:/*Eliminar Especialidad*/         
                              eliminarespecialidad(&especialidades);
                          break;      
                                           
                          case 9:/*Modificar Especialidad*/         
                              modificarespecialidad(&especialidades);
                          break;      
                          
                          case 10:/*consultar Afiliados*/         
                              for(i=0;i<pacientes.ultimo;i++){
                                 p=consultar_p(pacientes,i);
                                 mostrarpaciente(p);
                              }                              
                          break;      
                          
                          case 11:/*consultar Especialidades*/         
                              for(i=0;i<especialidades.ultimo;i++){
                                 e=consultar_e(especialidades,i);
                                 mostrarespecialidad(e);
                              }                              
                          break;      
                          
                          case 12:/*consultar Medicos*/         
                              for(i=0;i<medicos.ultimo;i++){
                                 m=consultar_m(medicos,i);
                                 mostrarmedico(m);
                              }                              
                          break;

						  case 13:/*Añadir Cita*/         
                              c=anadiratendido(&pacientes, &dependencias, especialidades, medicos, horarios,&pendientes,&estadisticas ,&estadisticas2);
							  if(c.CI!=-1)
                              insertar_c(&citas,longitud_c(citas),c);                         
                          break;

						  case 14:/*Eliminar Cita*/         
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
								opc = leernum();
							  }while(opc < 1 || opc > 10 );
							  switch(opc)
							  {
								  
								  case 1:
									  encontrado=0;
									  for(j=0;j<especialidades.ultimo && encontrado==0;j++) {         
										  if (1 == especialidades.elems[j].Nomb_esp) 
											  encontrado=1;
									  }
									  if (encontrado==1){
										  strcpy(Nconsul, especialidades.elems[j-1].Nconsul);
									  }
									  else
									  {
										  printf("\nLa especialidd seleccionada no esta siendo atendida...");
										  break;
									  }
									  i=siguiente_p(&citas, pacientes, Nconsul, &viejo);
									  if(i == -1){
										  printf("\nNo hay personas esperando ser atendidas...");
										  break;
									  }
									  c=consultar_c(citas,i);
									  printf("%s %s", c.nombre, c.apellido);
									  eliminar_c(&citas,i);
									  mg--;									  
								  break;

								  case 2:
									  encontrado=0;
									  for(j=0;j<especialidades.ultimo && encontrado==0;j++) {         
										  if (2 == especialidades.elems[j].Nomb_esp) 
											  encontrado=1;
									  }
									  if (encontrado==1){
										  strcpy(Nconsul, especialidades.elems[j-1].Nconsul);
									  }
									  else
									  {
										  printf("\nLa especialidd seleccionada no esta siendo atendida...");
										  break;
									  }
									  i=siguiente_p(&citas, pacientes, Nconsul, &viejo);
									  if(i == -1){
										  printf("\nNo hay personas esperando ser atendidas...");
										  break;
									  }
									  c=consultar_c(citas,i);
									  printf("%s %s", c.nombre, c.apellido);
									  eliminar_c(&citas,i);
									  ob--;
								  break;

								  case 3:
									  encontrado=0;
									  for(j=0;j<especialidades.ultimo && encontrado==0;j++) {         
										  if (3 == especialidades.elems[j].Nomb_esp) 
											  encontrado=1;
									  }
									  if (encontrado==1){
										  strcpy(Nconsul, especialidades.elems[j-1].Nconsul);
									  }
									  else
									  {
										  printf("\nLa especialidd seleccionada no esta siendo atendida...");
										  break;
									  }
									  i=siguiente_p(&citas, pacientes,Nconsul, &viejo);
									  if(i == -1){
										  printf("\nNo hay personas esperando ser atendidas...");
										  break;
									  }
									  c=consultar_c(citas,i);
									  printf("%s %s", c.nombre, c.apellido);
									  eliminar_c(&citas,i);
									  ca--;
							      break;

								  case 4:
									  encontrado=0;
									  for(j=0;j<especialidades.ultimo && encontrado==0;j++) {         
										  if (4 == especialidades.elems[j].Nomb_esp) 
											  encontrado=1;
									  }
									  if (encontrado==1){
										  strcpy(Nconsul, especialidades.elems[j-1].Nconsul);
									  }
									  else
									  {
										  printf("\nLa especialidd seleccionada no esta siendo atendida...");
										  break;
									  }
									  i=siguiente_p(&citas, pacientes,Nconsul, &viejo);
									  if(i == -1){
										  printf("\nNo hay personas esperando ser atendidas...");
										  break;
									  }
									  c=consultar_c(citas,i);
									  printf("%s %s", c.nombre, c.apellido);
									  eliminar_c(&citas,i);
									  mi--;
							      break;

							      case 5:
									  encontrado=0;
									  for(j=0;j<especialidades.ultimo && encontrado==0;j++) {         
										  if(5 == especialidades.elems[j].Nomb_esp) 
											  encontrado=1;
									  }
									  if (encontrado==1){
										  strcpy(Nconsul, especialidades.elems[j-1].Nconsul);
									  }
									  else
									  {
										  printf("\nLa especialidd seleccionada no esta siendo atendida...");
										  break;
									  }
									  i=siguiente_p(&citas, pacientes,Nconsul, &viejo);
									  if(i == -1){
										  printf("\nNo hay personas esperando ser atendidas...");
										  break;
									  }
									  c=consultar_c(citas,i);
									  printf("%s %s", c.nombre, c.apellido);
									  eliminar_c(&citas,i);
									  gi--;
								  break;

								  case 6:
									  encontrado=0;
									  for(j=0;j<especialidades.ultimo && encontrado==0;j++) {         
										  if (6 == especialidades.elems[j].Nomb_esp) 
											  encontrado=1;
									  }
									  if (encontrado==1){
										  strcpy(Nconsul, especialidades.elems[j-1].Nconsul);
									  }
									  else
									  {
										  printf("\nLa especialidd seleccionada no esta siendo atendida...");
										  break;
									  }
									  i=siguiente_p(&citas, pacientes,Nconsul, &viejo);
									  if(i == -1){
										  printf("\nNo hay personas esperando ser atendidas...");
										  break;
									  }
									  c=consultar_c(citas,i);
									  printf("%s %s", c.nombre, c.apellido);
									  eliminar_c(&citas,i);
									  pe--;
								  break;

								  case 7:
									  encontrado=0;
									  for(j=0;j<especialidades.ultimo && encontrado==0;j++) {         
										  if (7 == especialidades.elems[j].Nomb_esp) 
											  encontrado=1;
									  }
									  if (encontrado==1){
										  strcpy(Nconsul, especialidades.elems[j-1].Nconsul);
									  }
									  else
									  {
										  printf("\nLa especialidd seleccionada no esta siendo atendida...");
										  break;
									  }
									  i=siguiente_p(&citas, pacientes,Nconsul, &viejo);
									  if(i == -1){
										  printf("\nNo hay personas esperando ser atendidas...");
										  break;
									  }
									  c=consultar_c(citas,i);
									  printf("%s %s", c.nombre, c.apellido);
									  eliminar_c(&citas,i);
									  ne--;
								  break;

								  case 8:
									  encontrado=0;
									  for(j=0;j<especialidades.ultimo && encontrado==0;j++) {         
										  if (8 == especialidades.elems[j].Nomb_esp) 
											  encontrado=1;
									  }
									  if (encontrado==1){
										  strcpy(Nconsul, especialidades.elems[j-1].Nconsul);
									  }
									  else
									  {
										  printf("\nLa especialidd seleccionada no esta siendo atendida...");
										  break;
									  }
									  i=siguiente_p(&citas, pacientes,Nconsul, &viejo);
									  if(i == -1){
										  printf("\nNo hay personas esperando ser atendidas...");
										  break;
									  }
									  c=consultar_c(citas,i);
									  printf("%s %s", c.nombre, c.apellido);
									  eliminar_c(&citas,i);
									  tra--;
								  break;

								  case 9:
									  encontrado=0;
									  for(j=0;j<especialidades.ultimo && encontrado==0;j++) {         
										  if (9 == especialidades.elems[j].Nomb_esp) 
											  encontrado=1;
									  }
									  if (encontrado==1){
										  strcpy(Nconsul, especialidades.elems[j-1].Nconsul);
									  }
									  else
									  {
										  printf("\nLa especialidd seleccionada no esta siendo atendida...");
										  break;
									  }
									  i=siguiente_p(&citas,pacientes, Nconsul, &viejo);
									  if(i == -1){
										  printf("\nNo hay personas esperando ser atendidas...");
										  break;
									  }
									  c=consultar_c(citas,i);
									  printf("%s %s", c.nombre, c.apellido);
									  eliminar_c(&citas,i);
									  od--;
								  break;

								  case 10:
									  encontrado=0;
									  for(j=0;j<especialidades.ultimo && encontrado==0;j++) {         
										  if (10 == especialidades.elems[j].Nomb_esp) 
											  encontrado=1;
									  }
									  if (encontrado==1){
										  strcpy(Nconsul, especialidades.elems[j-1].Nconsul);
									  }
									  else
									  {
										  printf("\nLa especialidd seleccionada no esta siendo atendida...");
										  break;
									  }
									  i=siguiente_p(&citas, pacientes, Nconsul, &viejo);
									  if(i == -1){
										  printf("\nNo hay personas esperando ser atendidas...");
										  break;
									  }
									  c=consultar_c(citas,i);
									  printf("%s %s", c.nombre, c.apellido);
									  eliminar_c(&citas,i);
									  rx--;
								  break;
							  }

                          break;

						  case 15:/*Añadir Cita*/         
                                                          
                          break;

						  case 16:/*Añadir Dependencia*/  
                              if(longitud_d(dependencias)<61){       
                              d=anadirdependencia(dependencias);
                              insertar_d(&dependencias,longitud_d(dependencias),d);
                              }
                              else printf("\n\nNo se pueden insertar mas dependencias..."); 
                          break;

						  case 17:/*Eliminar Dependencia*/         
                              eliminardependencia(&dependencias);                            
                          break;

						  case 18:/*Modificar Dependencia*/         
                              modificardependencia(&dependencias);                            
                          break;
                          
						  case 19:/*Extra #1*/         
                              buscarmedico(medicos,horarios);
                          break;

						  case 20:/*Extra #2*/         
							  buscarespecialidad(medicos);                           
                          break;

						  case 21:/*Extra #3*/         
                              buscardia(medicos,horarios);
                          break;
                          
                           case 22:/*Estadisticas*/         
                              printf("\n\nFecha: %d/%d/%d",estadisticas.elems[0].hoy.dia,estadisticas.elems[0].hoy.mes,estadisticas.elems[0].hoy.ano);                                      
                              for(i=0;i<estadisticas.ultimo;i++){
                                 printf("\n\nNombre de la especialidad: ");
                                 switch(estadisticas.elems[i].Nomb_esp)
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
                                 if(estadisticas.elems[i].turno==0)printf("\nManana");
                                 else printf("\nTarde");
                                 printf("\npacientes atendidos: %d", estadisticas.elems[i].n_aten);
                                 printf("\npacientes atendidos: %d", estadisticas.elems[i].n_pend);
                              }
                          break;
                          case 23:/*Estadisticas*/         
                              for(i=0;i<estadisticas2.ultimo;i++){
                                 printf("\n\nCodigo de la dependencia: ");
                                 puts(estadisticas2.elems[i].coddep);
                                 printf("\nPacientes atendidos: %d", estadisticas2.elems[i].CAA);                                 
                              }
                          break;

                          default:         
                                           printf("\n\n\n****ERROR****");
                                           tecla();         
                          break;
        }   
     }while (respuesta!=0);/*CUANDO SE INTRODUCE 0 SE SALE DEL PROGRAMA*/   
      
     
	 printf("\n\n\n\n\n\n\n\n\t\t\t\tFIN DEL PROGRAMA\n\n\n\n\n\n\n\n");   
     tecla();
     return(0);
}


int menu(){
    /*devuelve un numero entero entre 0 y 15*/   
    int resultado, principal, sub;   
    do {      
       system("cls");      
       printf("\n\n\n\n");      
       printf("\n\tÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");      
       printf("\n\tÛÛ                                                          ÛÛ");      
       printf("\n\tÛÛ                       Centro IPASME                      ÛÛ");      
       printf("\n\tÛÛ                                                          ÛÛ");      
       printf("\n\tÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");      
       printf("\n\tÛÛ                                                          ÛÛ");      
       printf("\n\tÛÛ                1.-  Men£ de los Afiliados                ÛÛ");      
       printf("\n\tÛÛ                2.-  Men£ de los Medicos                  ÛÛ");      
       printf("\n\tÛÛ                3.-  Men£ de las Especialidades           ÛÛ");      
       printf("\n\tÛÛ                4.-  Men£ de las consultas                ÛÛ");
	   printf("\n\tÛÛ                5.-  Men£ de las citas                    ÛÛ");
       printf("\n\tÛÛ                6.-  Men£ de las Dependencias             ÛÛ");
	   printf("\n\tÛÛ                7.-  Men£ de Extras                       ÛÛ");
	   printf("\n\tÛÛ                                                          ÛÛ");
       printf("\n\tÛÛ                0.-  Salir del programa                   ÛÛ");      
       printf("\n\tÛÛ                                                          ÛÛ");      
       printf("\n\tÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ\n\n");      
       printf("\n¨Qu‚ opci¢n elige\?\n");     
       principal=getch();      
       
       if (principal=='0') return 0;/*devuelve 00*/      
       
       if (principal!='1' && principal!='2' && principal!='3' && principal!='4' && principal!='5' && principal!='6' && principal!='7' && principal!='8') {
          printf("\nElige una opci¢n valida");         
          tecla();         
          continue;      
       }      
       do {         
          system("cls");         
          printf("\n\n\n");         
          printf("\n\tÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");         
          printf("\n\tÛÛ                                                          ÛÛ");         
          switch(principal) {         
                            case '1':            
                                 printf("\n\tÛÛ                      Men£ de los Afiliado                ÛÛ");            
                                 printf("\n\tÛÛ        1.-  A¤adir un Afiliado                           ÛÛ");/*devuelve 01*/            
                                 printf("\n\tÛÛ        2.-  Eliminar un Afiliado                         ÛÛ");/*devuelve 02*/            
                                 printf("\n\tÛÛ        3.-  Modificar los datos de un Afiliado           ÛÛ");/*devuelve 03*/           
                            break;         
           
                            case '2':           
                                 printf("\n\tÛÛ                      Men£ de los Medicos                 ÛÛ");            
                                 printf("\n\tÛÛ        1.-  A¤adir un Medico                             ÛÛ");/*devuelve 04*/            
                                 printf("\n\tÛÛ        2.-  Eliminar un Medico                           ÛÛ");/*devuelve 05*/            
                                 printf("\n\tÛÛ        3.-  Modificar los datos de un Medico             ÛÛ");/*devuelve 06*/            
                            break;         
           
                            case '3':            
                                 printf("\n\tÛÛ                 Men£ de las Especialidades               ÛÛ");            
                                 printf("\n\tÛÛ        1.-  A¤adir una Especialidad                      ÛÛ");/*devuelve 07*/            
                                 printf("\n\tÛÛ        2.-  Eliminar una Especialidad                    ÛÛ");/*devuelve 08*/            
                                 printf("\n\tÛÛ        3.-  Confirmar una Especialidad                   ÛÛ");/*devuelve 09*/            
                            break;         
           
                            case '4':            
                                 printf("\n\tÛÛ                      Men£ de las consultas               ÛÛ");            
                                 printf("\n\tÛÛ        1.-  Consultar Afiliados                          ÛÛ");/*devuelve 10*/            
                                 printf("\n\tÛÛ        2.-  Consultar Especialidades                     ÛÛ");/*devuelve 11*/           
                                 printf("\n\tÛÛ        3.-  Consultar Medicos                            ÛÛ");/*devuelve 12*/            
                            break; 

							case '5':            
                                 printf("\n\tÛÛ                      Men£ de las citas                   ÛÛ");            
                                 printf("\n\tÛÛ        1.-  A¤adir  una Cita                             ÛÛ");/*devuelve 10*/            
                                 printf("\n\tÛÛ        2.-  Eliminar una cita                            ÛÛ");/*devuelve 11*/           
                                 printf("\n\tÛÛ        3.-  Consultar Medicos                            ÛÛ");/*devuelve 12*/            
                            break;
							
							case '6':            
                                 printf("\n\tÛÛ                      Men£ de las Dependencias            ÛÛ");            
                                 printf("\n\tÛÛ        1.-  A¤adir  una dependencia                      ÛÛ");/*devuelve 10*/            
                                 printf("\n\tÛÛ        2.-  Eliminar una dependencia                     ÛÛ");/*devuelve 11*/           
                                 printf("\n\tÛÛ        3.-  modificar dependencia                        ÛÛ");/*devuelve 12*/            
                            break;

							case '7':            
                                 printf("\n\tÛÛ                      Men£ de Extras                      ÛÛ");            
                                 printf("\n\tÛÛ        1.-  Busqueda por Medico y Especialidad           ÛÛ");/*devuelve 10*/            
                                 printf("\n\tÛÛ        2.-  Busquda de Horario Por Especialidad          ÛÛ");/*devuelve 11*/           
                                 printf("\n\tÛÛ        3.-  Busqueda por Dia y Especialidad              ÛÛ");/*devuelve 12*/            
                            break;
                            
                            case '8':            
                                 printf("\n\tÛÛ                      Men£ de Estadisticas                ÛÛ");            
                                 printf("\n\tÛÛ        1.-  ver las estadisticas por especialidades      ÛÛ");/*devuelve 10*/            
                                 printf("\n\tÛÛ        2.-  ver las estadisticas por dependencia         ÛÛ");/*devuelve 11*/           
                                 printf("\n\tÛÛ        3.-  Busqueda por Dia y Especialidad              ÛÛ");/*devuelve 12*/            
                            break;

                            default:            printf("\nElige una opci¢n v lida");tecla();            
                             sub='1';/*para que no repita el do{ }while() principal*/            
                            break;         
           }         
           printf("\n\tÛÛ        0.-  Salir del submenu                            ÛÛ");         
           printf("\n\tÛÛ                                                          ÛÛ");         
           printf("\n\tÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ\n\n");         
           printf("\nElige una opci¢n del submenu\n\n");         
           sub=getch();         
           if (sub!='1' && sub!='2' && sub!='3' && sub!='0') {            
              printf("\n\n\nIntroduzca una opci¢n v lida");
              tecla();         
           }      
       } while (sub!='1' && sub!='2' && sub!='3' && sub!='0');   
    } while ((principal!='1' && principal!='2' && principal!='3' && principal!='4' && principal!='5' && principal!='6' && principal!='7' && principal!='8' && principal!='0') || sub=='0');   
    resultado=(principal-'1')*3+(sub-'1')+1;   
    return resultado;
}	 


