void buscarmedico(lista_m medicos, lista_h horarios);
void buscarespecialidad(lista_m medicos);
void buscardia(lista_m medicos, lista_h horarios);

/*********************************************************************************************/

void buscarmedico(lista_m medicos, lista_h horarios)
{
    int a,b,encontrado=0, especialidad,c;
	char nombre[N];
    
    printf("Introduzca el nombre del medico a buscar: ");
    leerchar(nombre);
	do{
        printf("Introduzca el nombre de la especialidad a buscar: ");
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
	    especialidad = leernum();
	}while(especialidad < 1 || especialidad > 10 );
    for(a=0;a<medicos.ultimo && encontrado==0;a++) {         
		if (compararcadenas(nombre, medicos.elems[a].nombre) == 0 && especialidad == medicos.elems[a].Nomb_esp ){ 
			encontrado=1;
		}

	}
	if(encontrado == 1){
		encontrado=0;
		for(c=0;c<10;c++) {
				if(medicos.elems[a-1].CI == horarios.elems[especialidad-1].CI[c] ){ 
					encontrado = 1;
					switch(c)
					{
					case 0:
						printf("\nEl doctor %s presta servicio los Lunes en la Ma¤ana",nombre);
					break;
					case 1:
						printf("\nEl doctor %s presta servicio los Lunes en la Tarde",nombre);
					break;
					case 2:
						printf("\nEl doctor %s presta servicio los Martes en la Ma¤ana",nombre);
					break;
					case 3:
						printf("\nEl doctor %s presta servicio los Martes en la Tarde",nombre);
					break;
					case 4:
						printf("\nEl doctor %s presta servicio los Miercoles en la Ma¤ana",nombre);
					break;
					case 5:
						printf("\nEl doctor %s presta servicio los Miercoles en la Tarde",nombre);
					break;
					case 6:
						printf("\nEl doctor %s presta servicio los Jueves en la Ma¤ana",nombre);
					break;
					case 7:
						printf("\nEl doctor %s presta servicio los Jueves en la Tarde",nombre);
					break;
					case 8:
						printf("\nEl doctor %s presta servicio los Viernes en la Ma¤ana",nombre);
					break;
					case 9:
						printf("\nEl doctor %s presta servicio los Viernes en la Ma¤ana",nombre);
					break;
					}
				}
			}
		}
		if(encontrado == 0) printf("El doctor %s No presta servicio en la semana...",nombre);

	/*}
	else printf("No se encuentra el doctor o la especialidad solicitada...");*/
}
/**************************EXTRA #2**************************************************/

void buscarespecialidad(lista_m medicos)
{
	int a,especialidad;

	do{
        printf("Introduzca el nombre de la especialidad a buscar: ");
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
	    especialidad = leernum();
	}while(especialidad < 1 || especialidad > 10 );
	for(a=0;a<medicos.ultimo ;a++) {         
		if (especialidad == medicos.elems[a].Nomb_esp ){ 
			printf("\nEl Doctor %s Atiende la especialidad buscada...",medicos.elems[a].nombre);
		}

	}
}

/****************************** EXTRA #3 **********************************************/

void buscardia(lista_m medicos, lista_h horarios)
{
	int dia,i,especialidad,a,b,encontrado=0,reencontrado=0;

	do{
		printf("\nPor favor introduzca el dia de la semana que desea buscar: ");
		printf("\n0- Lunes");
		printf("\n1- Martes");
		printf("\n2- Miercoles");
		printf("\n3- Jueves");
		printf("\n4- Viernes: ");
		dia=leernum();
    }while(dia < 0 || dia > 4 );

	do{
        printf("Introduzca el nombre de la especialidad a buscar: ");
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
	    especialidad = leernum();
	}while(especialidad < 1 || especialidad > 10 );

	for(a=0;a<horarios.ultimo ;a++) {         
		for(i=0;i<2;i++){
			if(horarios.elems[a].CI[dia*2+i] > 0){
				encontrado=1;
				for(b=0;b<medicos.ultimo ;b++){
					if(medicos.elems[b].CI == horarios.elems[a].CI[dia*2+i] && medicos.elems[b].Nomb_esp == especialidad ){
						reencontrado=1;
						printf("\nEl Doctor %s presta servicios el dia solicitado...",medicos.elems[b].nombre);
					}
				}
				if(reencontrado == 0){
						printf("\nNo hay medicos disponibles para el dia y especialidad solicitada...");
					}
			}
		}

	}
	if(encontrado == 0){
				printf("\nNo hay medicos disponibles para el dia solicitado...");
	}
}



