/// Fechas
#include <stdio.h>

int calendario(){
	//Variables para trabajar con los segundos 
	long segundos;
	int conver_segundos,conver_minutos,conver_horas,conver_dias,conver_mes,conver_anio;
	int sobrante_segundos,sobrante_minuto,sobrante_hora,sobrante_dias,sobrante_mes,sobrante_anio;
	long regreso_segundos;
	
	//Fecha inicial
	int diaI=1;
	int mesI=1;
	int anioI=2000;
	//Se usara un formato de 24 horas
	int horaI,minutoI,segundoI=0;
	
	int mes =1; 	//Declaramos una variabale iteradora que representa a los meses
	int numdias  = 0; // Usamos esta variable para asignaler los dias que se tendran dependiendo del mes
	int sobrante_dias2;
	
	//Variables para sumar los resultados a las fechas iniciales
	int sumar_seg,sumar_min,sumar_hora,sumar_dias,sumar_mes,sumar_anio;
		
	printf("Inserta los segundos: ");
	scanf("%i",&segundos);
	conver_anio = segundos/31536000; //Convertimos de segundos a años
	sobrante_anio = segundos % 31536000; //El residuo servira para calcular los dias
	printf("\n Anio: %i",conver_anio);
	
	conver_dias = sobrante_anio /  86400; // Obtenemos los dias apartir de los segundos
	sobrante_dias= sobrante_anio % 86400; // El residuo servira para calcular los años
	regreso_segundos = (conver_dias * 86400) + (conver_anio * 31557600);
	printf("\n Dias: %i",conver_dias);
		
	sobrante_dias2 = conver_dias;
			
	while (mes <=12 )
	{
		//Meses con 31 dias 
		if  (mes == 1 || mes == 3 || mes == 5 || mes ==7 || mes == 8 || mes ==10 || mes == 12 ){
			numdias = 31;
		}
		//Meses con 30 dias
		if( mes == 4 || mes == 6 || mes == 9 || mes == 11  ){
			numdias = 30;
		}
		// Mes de febrero
		if (mes == 2){
			numdias = 28;
		}	
		sobrante_dias2 = sobrante_dias2 - numdias;
		if (sobrante_dias2 < 30 && mes !=2 )
		{
			break;
		} 
		  mes++;  //Aumenta en 1 la cantidad de meses
	}
	mes=mes+1;
	printf("\n Mes:  %i",mes); 	 //mes hasta el que llegue mas 1
	regreso_segundos = segundos - regreso_segundos;
		
	//printf("\n cantidad sobrabnte:  %d", regreso_segundos ); 	 //mes hasta el que llegue 
	
	conver_horas = regreso_segundos / 3600; //Me da las horas
	sobrante_hora = regreso_segundos % 3600; // Con este sobrante se calcula los minutos
	conver_minutos = sobrante_hora / 60 ; //Con esto obtenemos los minutos
	sobrante_segundos = sobrante_hora % 60; //Este sobrante me da los segundos
	printf("\n Horas: %d",conver_horas);
	printf("\n Minutos: %d",conver_minutos);
	printf("\n Segundos: %i",sobrante_segundos);
		
	
	printf("\n\nFecha inicial: 01/01/2000  0:0:0 ");
	sumar_seg = sobrante_segundos+segundoI;
	sumar_min = conver_minutos+minutoI;
	sumar_hora = conver_horas+horaI;
	sumar_dias = sobrante_dias2+diaI;
	sumar_mes = mes+mesI;
	sumar_anio = conver_anio+anioI;
	printf("\nTiempo transcurrido: %d/%d/%d %d:%d:%d",sumar_dias,sumar_mes,sumar_anio,sumar_hora,sumar_min,sumar_seg);
}


