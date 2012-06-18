/********************************* ESTADISTICAS *******************************/

//Estadisticas
typedef struct {
	fecha hoy; 
	int Nomb_esp, turno, n_aten, n_pend;                 
}estadistica;

typedef struct{
	estadistica elems[19];
	int ultimo;
}lista_est;

typedef struct {
	char coddep[N]; 
	int CAA;                 
}estadistica2;

typedef struct{
	estadistica2 elems[61];
	int ultimo;
}lista_est2;


void insertar_est(lista_est *, int , estadistica );
void resto_est(lista_est *);
estadistica consultar_est(lista_est , int );

lista_est2 vacia_est2();
bool es_vacia_est2(lista_est2 );
void insertar_est2(lista_est2 * , int , estadistica2 );
void eliminar_est2(lista_est2 * , int );
estadistica2 consultar_est2(lista_est2 , int );
int longitud_est2(lista_est2 );
int localizar_est2(lista_est2 *, int );
void resto_est2(lista_est2 * );

void insertar_est(lista_est *L, int pos, estadistica e){
	int i;
	estadistica c;
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
void resto_est(lista_est *L){
	int i;
	L->ultimo--;
    for(i=0;i<L->ultimo;i++){
            L->elems[i]=L->elems[i+1];
	}
	return;
}
estadistica consultar_est(lista_est L, int pos){
	return (L.elems[pos]);
}

/******************************************************************************/

lista_est2 vacia_est2(){
	lista_est2 a;

	a.ultimo=0;
	return (a);
}

bool es_vacia_est2(lista_est2 L){
	if (L.ultimo == 0) return(true);
	else return(false);
}

void insertar_est2(lista_est2 *L, int pos, estadistica2 e){
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

void eliminar_est2(lista_est2 *L, int pos){
	int i;
	L->ultimo--;
	for(i=pos; i<N; i++){
      L->elems[i]=L->elems[i+1];
	}
	return;
}

estadistica2 consultar_est2(lista_est2 L, int pos){
	return (L.elems[pos]);
}

int longitud_est2(lista_est2 L){
	return (L.ultimo);
}

int localizar_est2(lista_est2 *L, char *codigo){
	int i;
	if (L->ultimo == 0){
		return(-1);
	}
	else{
        i=0;
		while(i <= L->ultimo && compararcadenas(codigo,L->elems[i].coddep)!=0){
			i++;
        }
		if (compararcadenas(codigo,L->elems[i].coddep)==0){
			return(i);
		}	
		else return(-1);
	}
}

void resto_est2(lista_est2 *L){
	int i;
	L->ultimo--;
    for(i=0;i<L->ultimo;i++){
            L->elems[i]=L->elems[i+1];
	}
	return;
}
