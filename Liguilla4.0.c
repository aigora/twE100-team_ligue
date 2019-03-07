//Trabajo Liguilla 
//ASM

#include <stdio.h>
#include <stdlib.h>
#define n 25

//Estructura de equipo para que lea el fichero.
typedef struct 
{
	char nombre [n];
	int ganados ;
	int empatados; 
	int perdidos ;
	int puntos;
	
}equipo;

//Prototipos Funciones.
void presentacion();
void leer_datos_a(equipo *liga, int num, FILE *pa);
void imprimir_datos(equipo *liga,int num,FILE *pa);
void leer_datos(equipo *liga, int num, FILE *pf);
void imprimir_datos_jornada1(equipo *liga,int num,FILE *pf1);
void imprimir_datos_jornada2(equipo *liga,int num,FILE *pf2);
void imprimir_datos_jornada3(equipo *liga,int num,FILE *pf3);

main ()
{	
	char opcion,bucle,J1,J2,J3,n_archivo[n], auxn;
	int i=0,j=0, num=0, N=0,aux=0;
	int gol1=0,gol2=0,gol3=0,gol4=0;
	equipo *liga;
	FILE *pf, *pf1, *pf2, *pf3, *pa;
	
	//Presentacion
	presentacion();
	
	do{	
		
		printf ("Elige una opcion entre las siguentes: \n");
		printf ("\tA- Empezar la Liguilla\n");
		printf ("\tB- Mostrar la clasificacion de una Jornada\n");
		printf ("\tC-Continuar con la Jornada 1\n");
		printf ("\tD-Continuar con la Jornada 2\n");
		printf ("\tE-Continuar con la Jornada 3\n");
		printf ("\tF-Clasificacion Final\n");
		printf ("\nLa opcion es: ");
		scanf ( "%c", &opcion);
		fflush(stdin);
	
		switch(opcion)
		{
			case 'A': case 'a':	
				
				//Empezar la liguilla.
				//Leer los datos y guardar espacio de memoria.
				pf = fopen("equipos.txt", "r");
				if(pf == NULL){
					printf("\nNo se ha encontrado el archivo.");
					exit(1);	
				}
				else{
					//Escanea el primer numero del fichero y lo guarda.
					fscanf(pf, "%d", &N);
					//Reserva el espacio de memoria que se va a utilizar.
					liga = malloc(N*sizeof(equipo));
					
					//Lee los datos.
					for(i=0; i<N; i++)	leer_datos(liga, i, pf);
					
					printf("Introduce los nombres de los equipos.");
					for(i=0;i<N;i++){
						printf("\nNombre del equipo %d: ", i+1);
						gets(liga[i].nombre);
					}
			
					for(i=0; i<N; i++){
						printf ("\n\t%s", liga[i].nombre);
						printf("\t\t\t%d\t%d\t%d\t\t%d\n",liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);
					}
					
					fclose(pf);
								
					printf("\n¿Desea continuar con la Jornada 1?");
					scanf("%c",&J1);
					fflush(stdin);
					if((J1=='n')||(J1=='N'))break;
				}
				
				//Jornada 1
				pf1 = fopen("Jornada1.txt", "w");
				if(pf1 == NULL){
					printf("\nNo se ha encontrado el archivo.");
					exit(1);	
				}
				else{	
					
					printf("\n\n\t\tJORNADA 1\n\n");
					printf("Partido %s VS %s \n",liga[0].nombre,liga[1].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[0].nombre);
					scanf("%d",&gol1);
					printf("Introduce el n\247\ goles del %s :\n",liga[1].nombre);
					scanf("%d",&gol2);
					fflush(stdin);
			
					if (gol1>gol2){
						printf("El %s gana.\n",liga[0].nombre);
						liga[0].ganados++,liga[0].puntos+=3;
						liga[1].perdidos++;
					}
					else if(gol1==gol2){
						printf ("Empate\n");
						liga[0].empatados++,liga[0].puntos++;
						liga[1].empatados++,liga[1].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[1].nombre);
						liga[1].ganados++,liga[1].puntos+=3;
						liga[0].perdidos++;
					}
					
					printf("Partido %s VS %s \n",liga[2].nombre,liga[3].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[2].nombre);
					scanf("%d",&gol3);
					printf("Introduce el n\247\ goles del %s :\n",liga[3].nombre);
					scanf("%d",&gol4);
					fflush(stdin);
			
					if (gol3>gol4){
						printf("El %s gana.\n",liga[2].nombre);
						liga[2].ganados++,liga[2].puntos+=3;
						liga[3].perdidos++;
					}
					else if(gol3==gol4){
						printf ("Empate\n");
						liga[2].empatados++,liga[2].puntos++;
						liga[3].empatados++,liga[3].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[3].nombre);
						liga[3].ganados++,liga[3].puntos+=3;
						liga[2].perdidos++;
					}
					
					
					printf("\n\tCLASIFICACION JORNADA 1");
					printf("\n\tNombre\t\t\tGanados\tEmpatados\tPerdidios\t\tPuntos");
					for(i=0; i<N; i++)
					{
						printf ("\n\t%s", liga[i].nombre);
						printf("\t\t\t%d   \t%d     \t%d    \t\t%d\n",liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);
					}
					
					//Guardar datos jornada 1.
					int basura=4;
					fprintf (pf1, "%d\n", basura);
					
					for (i=0;i<N;i++) imprimir_datos_jornada1 (liga , i , pf1);
				
					fclose(pf1);
					
					printf("\n¿Desea continuar con la Jornada 2?");
					scanf("%c",&J2);
					fflush(stdin);
					if((J2=='n')||(J2=='N'))break;
				}
				
				//Jornada 2
				pf2 = fopen("Jornada2.txt", "w");
				if(pf2 == NULL){
					printf("\nNo se ha encontrado el archivo.");
					exit(1);	
				}
				else{	
					
					printf("\n\n\t\tJORNADA 2\n\n");
					printf("Partido %s VS %s \n",liga[0].nombre,liga[2].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[0].nombre);
					scanf("%d",&gol1);
					printf("Introduce el n\247\ goles del %s :\n",liga[2].nombre);
					scanf("%d",&gol3);
					fflush(stdin);
			
					if (gol1>gol3){
						printf("El %s gana.\n",liga[0].nombre);
						liga[0].ganados++,liga[0].puntos+=3;
						liga[2].perdidos++;
					}
					else if(gol1==gol3){
						printf ("Empate\n");
						liga[0].empatados++,liga[0].puntos++;
						liga[2].empatados++,liga[2].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[2].nombre);
						liga[2].ganados++,liga[2].puntos+=3;
						liga[0].perdidos++;
					}
					
					printf("Partido %s VS %s \n",liga[1].nombre,liga[3].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[1].nombre);
					scanf("%d",&gol2);
					printf("Introduce el n\247\ goles del %s :\n",liga[3].nombre);
					scanf("%d",&gol4);
					fflush(stdin);
			
					if (gol2>gol4){
						printf("El %s gana.\n",liga[1].nombre);
						liga[1].ganados++,liga[1].puntos+=3;
						liga[3].perdidos++;
					}
					else if(gol2==gol4){
						printf ("Empate\n");
						liga[1].empatados++,liga[1].puntos++;
						liga[3].empatados++,liga[3].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[3].nombre);
						liga[3].ganados++,liga[3].puntos+=3;
						liga[1].perdidos++;
					}
					
					
					printf("\n\tCLASIFICACION JORNADA 2");
					printf("\n\tNombre\t\t\tGanados\tEmpatados\tPerdidios\t\tPuntos");
					for(i=0; i<N; i++)
					{
						printf ("\n\t%s", liga[i].nombre);
						printf("\t\t\t%d   \t%d     \t%d    \t\t%d\n",liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);
					}
					
					//Guardar datos jornada 2.
					int basura=4;
					fprintf (pf2, "%d\n", basura);
					
					for (i=0;i<N;i++) imprimir_datos_jornada2 (liga , i , pf2);
				
					fclose(pf2);
					
					printf("\n¿Desea continuar con la Jornada 3?");
					scanf("%c",&J3);
					fflush(stdin);
					if((J3=='n')||(J3=='N'))break;
				}
				
				//Jornada 3
				pf3 = fopen("Jornada3.txt", "w");
				if(pf3 == NULL){
					printf("\nNo se ha encontrado el archivo.");
					exit(1);	
				}
				else{	
					
					printf("\n\n\t\tJORNADA 3\n\n");
					printf("Partido %s VS %s \n",liga[0].nombre,liga[3].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[0].nombre);
					scanf("%d",&gol1);
					printf("Introduce el n\247\ goles del %s :\n",liga[3].nombre);
					scanf("%d",&gol4);
					fflush(stdin);
			
					if (gol1>gol4){
						printf("El %s gana.\n",liga[0].nombre);
						liga[0].ganados++,liga[0].puntos+=3;
						liga[3].perdidos++;
					}
					else if(gol1==gol4){
						printf ("Empate\n");
						liga[0].empatados++,liga[0].puntos++;
						liga[3].empatados++,liga[3].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[3].nombre);
						liga[3].ganados++,liga[3].puntos+=3;
						liga[0].perdidos++;
					}
					
					printf("Partido %s VS %s \n",liga[2].nombre,liga[1].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[2].nombre);
					scanf("%d",&gol3);
					printf("Introduce el n\247\ goles del %s :\n",liga[1].nombre);
					scanf("%d",&gol2);
					fflush(stdin);
			
					if (gol3>gol2){
						printf("El %s gana.\n",liga[2].nombre);
						liga[2].ganados++,liga[2].puntos+=3;
						liga[1].perdidos++;
					}
					else if(gol3==gol2){
						printf ("Empate\n");
						liga[2].empatados++,liga[2].puntos++;
						liga[1].empatados++,liga[1].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[1].nombre);
						liga[1].ganados++,liga[1].puntos+=3;
						liga[2].perdidos++;
					}
					
					
					printf("\n\tCLASIFICACION JORNADA 3");
					printf("\n\tNombre\t\t\tGanados\tEmpatados\tPerdidios\t\tPuntos");
					for(i=0; i<N; i++)
					{
						printf ("\n\t%s", liga[i].nombre);
						printf("\t\t\t%d   \t%d     \t%d    \t\t%d\n",liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);
					}
					
					//Guardar datos jornada 3.
					int basura=4;
					fprintf (pf3, "%d\n", basura);
					
					for (i=0;i<N;i++) imprimir_datos_jornada3 (liga , i , pf3);
				
					fclose(pf3);
					
					break;
				}
				
			case 'B': case 'b':
				
				//Pedir un archivo.
				printf("Jornada 1 = Jornada1.txt\n");
				printf("Jornada 2 = Jornada2.txt\n");
				printf("Jornada 3 = Jornada3.txt\n\n");
				printf ("Pedir nombre archivo:");
				gets(n_archivo);
				pa = fopen(n_archivo, "r");
				if(pa == NULL){
					printf("\nNo se ha encontrado el archivo.\n");
					break;	
				}
				else{
					fscanf(pa, "%d", &N);
					liga = malloc(N*sizeof(equipo));
					for(i=0; i<N; i++)	leer_datos_a(liga, i, pa); //Leer datos fichero
					
					for(i=0; i<N; i++){ //Mostar los datos del fichero
						printf("\n%d\t%s\t\t\t%d\t%d\t%d\t\t%d\n",i+1,liga[i].nombre,liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);
					}
				
					fclose(pa);//Cerrrar datos fichero
					break;
				}
			
			case 'C': case 'c':
			
				/*if(!fclose(pf){
					printf("Falta leer la jornada 0.");
					break;
				}
				*/
				//Jornada 1
				pf1 = fopen("Jornada1.txt", "w");
				if(pf1 == NULL){
					printf("\nNo se ha encontrado el archivo.");
					exit(1);	
				}
				else{	
					
					printf("\n\n\t\tJORNADA 1\n\n");
					printf("Partido %s VS %s \n",liga[0].nombre,liga[1].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[0].nombre);
					scanf("%d",&gol1);
					printf("Introduce el n\247\ goles del %s :\n",liga[1].nombre);
					scanf("%d",&gol2);
					fflush(stdin);
			
					if (gol1>gol2){
						printf("El %s gana.\n",liga[0].nombre);
						liga[0].ganados++,liga[0].puntos+=3;
						liga[1].perdidos++;
					}
					else if(gol1==gol2){
						printf ("Empate\n");
						liga[0].empatados++,liga[0].puntos++;
						liga[1].empatados++,liga[1].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[1].nombre);
						liga[1].ganados++,liga[1].puntos+=3;
						liga[0].perdidos++;
					}
					
					printf("Partido %s VS %s \n",liga[2].nombre,liga[3].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[2].nombre);
					scanf("%d",&gol3);
					printf("Introduce el n\247\ goles del %s :\n",liga[3].nombre);
					scanf("%d",&gol4);
					fflush(stdin);
			
					if (gol3>gol4){
						printf("El %s gana.\n",liga[2].nombre);
						liga[2].ganados++,liga[2].puntos+=3;
						liga[3].perdidos++;
					}
					else if(gol3==gol4){
						printf ("Empate\n");
						liga[2].empatados++,liga[2].puntos++;
						liga[3].empatados++,liga[3].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[3].nombre);
						liga[3].ganados++,liga[3].puntos+=3;
						liga[2].perdidos++;
					}
					
					
					printf("\n\tCLASIFICACION JORNADA 1");
					printf("\n\tNombre\t\t\tGanados\tEmpatados\tPerdidios\t\tPuntos");
					for(i=0; i<N; i++)
					{
						printf ("\n\t%s", liga[i].nombre);
						printf("\t\t\t%d   \t%d     \t%d    \t\t%d\n",liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);
					}
					
					//Guardar datos jornada 1.
					int basura=4;
					fprintf (pf1, "%d\n", basura);
					
					for (i=0;i<N;i++) imprimir_datos_jornada1 (liga , i , pf1);
				
					fclose(pf1);
					
					printf("\n¿Desea continuar con la Jornada 2?");
					scanf("%c",&J2);
					fflush(stdin);
					if((J2=='n')||(J2=='N'))break;
				}
				
				//Jornada 2
				pf2 = fopen("Jornada2.txt", "w");
				if(pf2 == NULL){
					printf("\nNo se ha encontrado el archivo.");
					exit(1);	
				}
				else{	
					
					printf("\n\n\t\tJORNADA 2\n\n");
					printf("Partido %s VS %s \n",liga[0].nombre,liga[2].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[0].nombre);
					scanf("%d",&gol1);
					printf("Introduce el n\247\ goles del %s :\n",liga[2].nombre);
					scanf("%d",&gol3);
					fflush(stdin);
			
					if (gol1>gol3){
						printf("El %s gana.\n",liga[0].nombre);
						liga[0].ganados++,liga[0].puntos+=3;
						liga[2].perdidos++;
					}
					else if(gol1==gol3){
						printf ("Empate\n");
						liga[0].empatados++,liga[0].puntos++;
						liga[2].empatados++,liga[2].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[2].nombre);
						liga[2].ganados++,liga[2].puntos+=3;
						liga[0].perdidos++;
					}
					
					printf("Partido %s VS %s \n",liga[1].nombre,liga[3].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[1].nombre);
					scanf("%d",&gol2);
					printf("Introduce el n\247\ goles del %s :\n",liga[3].nombre);
					scanf("%d",&gol4);
					fflush(stdin);
			
					if (gol2>gol4){
						printf("El %s gana.\n",liga[1].nombre);
						liga[1].ganados++,liga[1].puntos+=3;
						liga[3].perdidos++;
					}
					else if(gol2==gol4){
						printf ("Empate\n");
						liga[1].empatados++,liga[1].puntos++;
						liga[3].empatados++,liga[3].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[3].nombre);
						liga[3].ganados++,liga[3].puntos+=3;
						liga[1].perdidos++;
					}
					
					
					printf("\n\tCLASIFICACION JORNADA 2");
					printf("\n\tNombre\t\t\tGanados\tEmpatados\tPerdidios\t\tPuntos");
					for(i=0; i<N; i++)
					{
						printf ("\n\t%s", liga[i].nombre);
						printf("\t\t\t%d   \t%d     \t%d    \t\t%d\n",liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);
					}
					
					//Guardar datos jornada 2.
					int basura=4;
					fprintf (pf2, "%d\n", basura);
					
					for (i=0;i<N;i++) imprimir_datos_jornada2 (liga , i , pf2);
				
					fclose(pf2);
					
					printf("\n¿Desea continuar con la Jornada 3?");
					scanf("%c",&J3);
					fflush(stdin);
					if((J3=='n')||(J3=='N'))break;
				}
				
				//Jornada 3
				pf3 = fopen("Jornada3.txt", "w");
				if(pf3 == NULL){
					printf("\nNo se ha encontrado el archivo.");
					exit(1);	
				}
				else{	
					
					printf("\n\n\t\tJORNADA 3\n\n");
					printf("Partido %s VS %s \n",liga[0].nombre,liga[3].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[0].nombre);
					scanf("%d",&gol1);
					printf("Introduce el n\247\ goles del %s :\n",liga[3].nombre);
					scanf("%d",&gol4);
					fflush(stdin);
			
					if (gol1>gol4){
						printf("El %s gana.\n",liga[0].nombre);
						liga[0].ganados++,liga[0].puntos+=3;
						liga[3].perdidos++;
					}
					else if(gol1==gol4){
						printf ("Empate\n");
						liga[0].empatados++,liga[0].puntos++;
						liga[3].empatados++,liga[3].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[3].nombre);
						liga[3].ganados++,liga[3].puntos+=3;
						liga[0].perdidos++;
					}
					
					printf("Partido %s VS %s \n",liga[2].nombre,liga[1].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[2].nombre);
					scanf("%d",&gol3);
					printf("Introduce el n\247\ goles del %s :\n",liga[1].nombre);
					scanf("%d",&gol2);
					fflush(stdin);
			
					if (gol3>gol2){
						printf("El %s gana.\n",liga[2].nombre);
						liga[2].ganados++,liga[2].puntos+=3;
						liga[1].perdidos++;
					}
					else if(gol3==gol2){
						printf ("Empate\n");
						liga[2].empatados++,liga[2].puntos++;
						liga[1].empatados++,liga[1].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[1].nombre);
						liga[1].ganados++,liga[1].puntos+=3;
						liga[2].perdidos++;
					}
					
					
					printf("\n\tCLASIFICACION JORNADA 3");
					printf("\n\tNombre\t\t\tGanados\tEmpatados\tPerdidios\t\tPuntos");
					for(i=0; i<N; i++)
					{
						printf ("\n\t%s", liga[i].nombre);
						printf("\t\t\t%d   \t%d     \t%d    \t\t%d\n",liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);
					}
					
					//Guardar datos jornada 3.
					int basura=4;
					fprintf (pf3, "%d\n", basura);
					
					for (i=0;i<N;i++) imprimir_datos_jornada3 (liga , i , pf3);
				
					fclose(pf3);
					
					break;
				}
				
			case 'D': case 'd':
				//leer jornada 1
			/*	if(!fclose(pf1)
					printf("Falta leer la jornada 1.");
					break;
				}*/
			
				//Jornada 2
				pf2 = fopen("Jornada2.txt", "w");
				if(pf2 == NULL){
					printf("\nNo se ha encontrado el archivo.");
					exit(1);	
				}
				else{	
					
					printf("\n\n\t\tJORNADA 2\n\n");
					printf("Partido %s VS %s \n",liga[0].nombre,liga[2].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[0].nombre);
					scanf("%d",&gol1);
					printf("Introduce el n\247\ goles del %s :\n",liga[2].nombre);
					scanf("%d",&gol3);
					fflush(stdin);
			
					if (gol1>gol3){
						printf("El %s gana.\n",liga[0].nombre);
						liga[0].ganados++,liga[0].puntos+=3;
						liga[2].perdidos++;
					}
					else if(gol1==gol3){
						printf ("Empate\n");
						liga[0].empatados++,liga[0].puntos++;
						liga[2].empatados++,liga[2].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[2].nombre);
						liga[2].ganados++,liga[2].puntos+=3;
						liga[0].perdidos++;
					}
					
					printf("Partido %s VS %s \n",liga[1].nombre,liga[3].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[1].nombre);
					scanf("%d",&gol2);
					printf("Introduce el n\247\ goles del %s :\n",liga[3].nombre);
					scanf("%d",&gol4);
					fflush(stdin);
			
					if (gol2>gol4){
						printf("El %s gana.\n",liga[1].nombre);
						liga[1].ganados++,liga[1].puntos+=3;
						liga[3].perdidos++;
					}
					else if(gol2==gol4){
						printf ("Empate\n");
						liga[1].empatados++,liga[1].puntos++;
						liga[3].empatados++,liga[3].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[3].nombre);
						liga[3].ganados++,liga[3].puntos+=3;
						liga[1].perdidos++;
					}
					
					
					printf("\n\tCLASIFICACION JORNADA 2");
					printf("\n\tNombre\t\t\tGanados\tEmpatados\tPerdidios\t\tPuntos");
					for(i=0; i<N; i++)
					{
						printf ("\n\t%s", liga[i].nombre);
						printf("\t\t\t%d   \t%d     \t%d    \t\t%d\n",liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);
					}
					
					//Guardar datos jornada 2.
					int basura=4;
					fprintf (pf2, "%d\n", basura);
					
					for (i=0;i<N;i++) imprimir_datos_jornada2 (liga , i , pf2);
				
					fclose(pf2);
					
					printf("\n¿Desea continuar con la Jornada 3?");
					scanf("%c",&J3);
					fflush(stdin);
					if((J3=='n')||(J3=='N'))break;
				}
				
				//Jornada 3
				pf3 = fopen("Jornada3.txt", "w");
				if(pf3 == NULL){
					printf("\nNo se ha encontrado el archivo.");
					exit(1);	
				}
				else{	
					
					printf("\n\n\t\tJORNADA 3\n\n");
					printf("Partido %s VS %s \n",liga[0].nombre,liga[3].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[0].nombre);
					scanf("%d",&gol1);
					printf("Introduce el n\247\ goles del %s :\n",liga[3].nombre);
					scanf("%d",&gol4);
					fflush(stdin);
			
					if (gol1>gol4){
						printf("El %s gana.\n",liga[0].nombre);
						liga[0].ganados++,liga[0].puntos+=3;
						liga[3].perdidos++;
					}
					else if(gol1==gol4){
						printf ("Empate\n");
						liga[0].empatados++,liga[0].puntos++;
						liga[3].empatados++,liga[3].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[3].nombre);
						liga[3].ganados++,liga[3].puntos+=3;
						liga[0].perdidos++;
					}
					
					printf("Partido %s VS %s \n",liga[2].nombre,liga[1].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[2].nombre);
					scanf("%d",&gol3);
					printf("Introduce el n\247\ goles del %s :\n",liga[1].nombre);
					scanf("%d",&gol2);
					fflush(stdin);
			
					if (gol3>gol2){
						printf("El %s gana.\n",liga[2].nombre);
						liga[2].ganados++,liga[2].puntos+=3;
						liga[1].perdidos++;
					}
					else if(gol3==gol2){
						printf ("Empate\n");
						liga[2].empatados++,liga[2].puntos++;
						liga[1].empatados++,liga[1].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[1].nombre);
						liga[1].ganados++,liga[1].puntos+=3;
						liga[2].perdidos++;
					}
					
					
					printf("\n\tCLASIFICACION JORNADA 3");
					printf("\n\tNombre\t\t\tGanados\tEmpatados\tPerdidios\t\tPuntos");
					for(i=0; i<N; i++)
					{
						printf ("\n\t%s", liga[i].nombre);
						printf("\t\t\t%d   \t%d     \t%d    \t\t%d\n",liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);
					}
					
					//Guardar datos jornada 3.
					int basura=4;
					fprintf (pf3, "%d\n", basura);
					
					for (i=0;i<N;i++) imprimir_datos_jornada3 (liga , i , pf3);
				
					fclose(pf3);
					
					break;
				}
				
			case 'E': case 'e':
				//Leer la jornada 2
				/*if(!fclose(pf2){
					printf("Falta leer la jornada 2.");
					break;
				}*/
				
				//Jornada 3
				pf3 = fopen("Jornada3.txt", "w");
				if(pf3 == NULL){
					printf("\nNo se ha encontrado el archivo.");
					exit(1);	
				}
				else{	
					
					printf("\n\n\t\tJORNADA 3\n\n");
					printf("Partido %s VS %s \n",liga[0].nombre,liga[3].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[0].nombre);
					scanf("%d",&gol1);
					printf("Introduce el n\247\ goles del %s :\n",liga[3].nombre);
					scanf("%d",&gol4);
					fflush(stdin);
			
					if (gol1>gol4){
						printf("El %s gana.\n",liga[0].nombre);
						liga[0].ganados++,liga[0].puntos+=3;
						liga[3].perdidos++;
					}
					else if(gol1==gol4){
						printf ("Empate\n");
						liga[0].empatados++,liga[0].puntos++;
						liga[3].empatados++,liga[3].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[3].nombre);
						liga[3].ganados++,liga[3].puntos+=3;
						liga[0].perdidos++;
					}
					
					printf("Partido %s VS %s \n",liga[2].nombre,liga[1].nombre);
					printf("Introduce el n\247\ goles del %s :\n",liga[2].nombre);
					scanf("%d",&gol3);
					printf("Introduce el n\247\ goles del %s :\n",liga[1].nombre);
					scanf("%d",&gol2);
					fflush(stdin);
			
					if (gol3>gol2){
						printf("El %s gana.\n",liga[2].nombre);
						liga[2].ganados++,liga[2].puntos+=3;
						liga[1].perdidos++;
					}
					else if(gol3==gol2){
						printf ("Empate\n");
						liga[2].empatados++,liga[2].puntos++;
						liga[1].empatados++,liga[1].puntos++;
					}
					else{
						printf("El %s gana.\n",liga[1].nombre);
						liga[1].ganados++,liga[1].puntos+=3;
						liga[2].perdidos++;
					}
					
					
					printf("\n\tCLASIFICACION JORNADA 3");
					printf("\n\tNombre\t\t\tGanados\tEmpatados\tPerdidios\t\tPuntos");
					for(i=0; i<N; i++)
					{
						printf ("\n\t%s", liga[i].nombre);
						printf("\t\t\t%d   \t%d     \t%d    \t\t%d\n",liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);
					}
					
					//Guardar datos jornada 3.
					int basura=4;
					fprintf (pf3, "%d\n", basura);
					
					for (i=0;i<N;i++) imprimir_datos_jornada3 (liga , i , pf3);
				
					fclose(pf3);
					
					break;
				}
				
			case 'F': case 'f':
				
				/*if(!fclose(pf3){
					printf("Falta leer la jornada 3.");
					break;
				}*/
				
				//Clasificacion final
		
			
				
				for(i=0;i<N;i++){
					for(j=0;j<N;j++){
						if(liga[i].puntos>=liga[j].puntos){
							aux=liga[i].puntos;
							liga[i].puntos=liga[j].puntos;
							liga[j].puntos=aux;
							
							aux=liga[i].ganados;
							liga[i].ganados=liga[j].ganados;
							liga[j].ganados=aux;
							
							aux=liga[i].perdidos;
							liga[i].perdidos=liga[j].perdidos;
							liga[j].perdidos=aux;
							
							aux=liga[i].empatados;
							liga[i].empatados=liga[j].empatados;
							liga[j].empatados=aux;
							
						/*	auxn=liga[i].nombre;
							liga[i].nombre=liga[j].nombre;
							liga[j].nombre=auxn;	*/
						}		
					}
				}
			
				
				
				printf("\n\tNombre\t\t\tGanados\tEmpatados\tPerdidios\t\tPuntos");
				for(i=0; i<N; i++) printf("\n%d\t%s\t\t\t%d\t%d\t%d\t\t%d\n",i+1,liga[i].nombre,liga[i].ganados,liga[i].empatados,liga[i].perdidos,liga[i].puntos);	
				
			
	
		}
				
	//Bucle 
	printf("\n¿Desea hacer algo mas?");
	scanf("%c",&bucle);
	fflush(stdin);
	}while((bucle=='s')||(bucle=='S'));
	return 1;

}

void presentacion(){
	
	printf("Programa para hacer una liguilla de 4 equipos.\n\n");	
}

 void leer_datos(equipo *liga, int num, FILE *pf)
 {
 	int basura;
 	fscanf (pf, "%d", &basura);
 	
 	fgets(liga[num].nombre, 50, pf);
 	
 	fscanf(pf,"%d", &liga[num].ganados);
 	
 	fscanf(pf,"%d", &liga[num].empatados);
 	
 	fscanf(pf,"%d", &liga[num].perdidos);
 	
 	fscanf(pf,"%d", &liga[num].puntos);
 	
 }

void leer_datos_a(equipo *liga, int num, FILE *pa)
{
 	int basura;
 	fscanf (pa, "%d", &basura);
 	
 	fgets(liga[num].nombre, 25, pa);
 	
 	fscanf(pa,"%d", &liga[num].ganados);
 	
 	fscanf(pa,"%d", &liga[num].empatados);
 	
 	fscanf(pa,"%d", &liga[num].perdidos);
 	
 	fscanf(pa,"%d", &liga[num].puntos);
 	
}

void imprimir_datos(equipo *liga,int num,FILE *pa)
{
 	fprintf(pa,"%s\t" , liga[num].nombre);
 	
 	fprintf(pa,"%d\t", liga[num].ganados);
 	
 	fprintf(pa,"%d\t", liga[num].empatados);
 	
 	fprintf(pa,"%d\t", liga[num].perdidos);
 	
 	fprintf(pa,"%d\n", liga[num].puntos);	
 	
}


 
void imprimir_datos_jornada1(equipo *liga,int num,FILE *pf1)
{
 	fprintf(pf1,"%s\t" , liga[num].nombre);
 	
 	fprintf(pf1,"%d\t", liga[num].ganados);
 	
 	fprintf(pf1,"%d\t", liga[num].empatados);
 	
 	fprintf(pf1,"%d\t", liga[num].perdidos);
 	
 	fprintf(pf1,"%d\n", liga[num].puntos);	
 	
}
 
void imprimir_datos_jornada2(equipo *liga,int num,FILE *pf2)
{
 	fprintf(pf2,"%s\t" , liga[num].nombre);
 	
 	fprintf(pf2,"%d\t", liga[num].ganados);
 	
 	fprintf(pf2,"%d\t", liga[num].empatados);
 	
 	fprintf(pf2,"%d\t", liga[num].perdidos);
 	
 	fprintf(pf2,"%d\n", liga[num].puntos);	
 	
}

void imprimir_datos_jornada3(equipo *liga,int num,FILE *pf3)
{
 	fprintf(pf3,"%s\t" , liga[num].nombre);
 	
 	fprintf(pf3,"%d\t", liga[num].ganados);
 	
 	fprintf(pf3,"%d\t", liga[num].empatados);
 	
 	fprintf(pf3,"%d\t", liga[num].perdidos);
 	
 	fprintf(pf3,"%d\n", liga[num].puntos);	
 	
}
 
