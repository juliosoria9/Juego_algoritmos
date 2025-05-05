#include <iostream>
#include <string>
#include "Lector_cartas.cpp"
#include "ListaCircular.cpp"
#include "Carta.h"
#include <ctime>
#include <cstdlib>
using namespace std;


class Partida {
private:

	Carta* array_cartas; // Array dinámico de cartas de ejemplo
	int contador = 0; // Contador de cartas
	lector_cartas lector; // Objeto lector_cartas para leer las cartas
	ListaCircular lista_jugador1; // Lista circular para el jugador 1
	ListaCircular lista_jugador2; // Lista circular para el jugador 2
	float puntos_total_j1 = 0;
	float puntos_total_j2 = 0;
	float puntos_ronda_j1 = 0;
	float puntos_ronda_j2 = 0;
	int rondas_j1 = 0;
	int rondas_j2 = 0;

public:
	//main de la partida
	int partida() {
		// setup
		array_cartas = lector.leer_cartas(); //lee el txt y guarda las cartas en el array
		if (array_cartas == nullptr) {
			printf("No se pudo leer el archivo de cartas.\n");
			return -1;
		}
		contador = lector.get_contador(); 
		printf("Bienvenidos es hora de jugar\n");
		instrucciones(); // muestra las instrucciones
		printf("Se asignaran 10 cartas aleatorias a la lista de cada jugador\n");
		printf("pulsa enter para empezar la partida\n");
		getchar();
		system("cls");
		asignar_cartas(lista_jugador1); // asigna cartas al jugador 1
		printf("pulsa enter para ver las cartas de jugador 1 (asegurate que jugador2 no las vea)\n");
		getchar(); 
		lista_jugador1.mostrar();
		printf("pulsa para borrar las cartas de la pantalla\n");
		getchar();
		system("cls");
		//----------------------------------------------//
		asignar_cartas(lista_jugador2); // asigna cartas al jugador 2
		printf("pulsa enter para ver las cartas de jugador 2 (asegurate que jugador1 no las vea)\n");
		getchar(); 
		lista_jugador2.mostrar();
		printf("pulsa para borrar las cartas de la pantalla y empezar la partida\n");
		getchar();
		system("cls");
		

		//-------------------COMIENZO DE PARTIDA---------------------------//
		printf("pulsa enter para empezar la ronda1\n");
		ronda(); // empieza la ronda
		printf("pulsa enter para empezar la ronda2\n");
		ronda(); // empieza nueva ronda
		if (verificar_ganador() == 1) {
			return 0;
		}
		else {
			ronda();
		}
		if (verificar_ganador() == 1) {
			return 0;
		}
		else {
			if(puntos_total_j1 > puntos_total_j2){
				printf("gana el jugador 1\n");
				return 0;
			}
			else if (puntos_total_j1 < puntos_total_j2) {
				printf("gana el jugador 2\n");
				return 0;
			}
			else {
				printf("Empate (se ha comparado puntos totales y ambos teneis los mismos\n");
				return 0;

			}
		}
		


		return 0;
	}

	int asignar_cartas(ListaCircular& lista) {
		srand(time(0));  // Inicializar la semilla aleatoria 

		for (int i = 0; i < 10; i++) {
			int indice_aleatorio = rand() % contador;
			Carta copia = array_cartas[indice_aleatorio];
			lista.insertar(i, copia);
		}

		return 0;
	}
	//esta funcion es la que se encarga de jugar una ronda y las mecanicas de las cartas
	int ronda() {
		printf("Es hora de jugar una ronda\n");
		int carta_seleccionada;
		int usar_carta = 1;
		int i = 0;
		while(i<=3){

			//ronda jugador 1
			printf("Jugador 1, elige una carta solo puedes saltar 1 carta por ronda esta la podras usar en siguientes rondas\n");
			printf("------------------CARTAS----------------------\n");
			if (i == 3) {
				printf("elige si quieres usar una carta o no\n");
				printf("si quieres usar una carta pulsa 1, si no quieres usar una carta pulsa 0\n");
				do {
					cin >> usar_carta;

					if (usar_carta != 0 && usar_carta != 1) {
						printf("Error: selecciona 0 o 1.\n");
					}

				} while (usar_carta != 0 && usar_carta != 1);
				
			}
			// muestra las cartas de esa mano
			for (int j = 0; j < 4-i; j++) { 
				printf("Carta %d: ", j + 1);
				lista_jugador1.getCarta(j).mostrar();
			}
			if (usar_carta == 1) {
				printf("selecciona que carta quieres usar: ");
				do {
					cin >> carta_seleccionada;
					carta_seleccionada--; // restamos 1 para usar índice base 0
					if (carta_seleccionada < 0 || carta_seleccionada >= 4 - i) {
						printf("Error: selecciona una carta válida entre 1 y %d\n", 4 - i);
					}
				} while (carta_seleccionada < 0 || carta_seleccionada >= 4 - i);
				puntos_ronda_j1 = puntos_ronda_j1 + lista_jugador1.getCarta(carta_seleccionada).get_puntos();
				habilidades(lista_jugador1.getCarta(carta_seleccionada), lista_jugador1, i);
				lista_jugador1.eliminar(carta_seleccionada);
				puntos_ronda_j1 += lista_jugador1.getCarta(i).get_puntos();

				}
				usar_carta = 1; // para que vuelva a entrar en escojer la carta
				printf("pulsa enter para borrar la pantalla y pasar al turno de jugador2");
				getchar();
				system("cls");




				printf("Jugador 2, elige una carta solo puedes saltar 1 carta por ronda esta la podras usar en siguientes rondas\n");
				if (i == 3) {
					printf("elige si quieres usar una carta o no\n");
					printf("si quieres usar una carta pulsa 1, si no quieres usar una carta pulsa 0\n");
					do {
						cin >> usar_carta;

						if (usar_carta != 0 && usar_carta != 1) {
							printf("error, selecciona una carta valida\n");
						}

					} while (usar_carta != 0 && usar_carta != 1);
				}
				for (int j = 0; j < 4 - i; j++) {
					printf("Carta %d: ", j + 1);
					lista_jugador2.getCarta(j).mostrar();
				}
				if (usar_carta == 1) {
					printf("selecciona que carta quieres usar: ");
					do {
						cin >> carta_seleccionada;
						carta_seleccionada--; // restamos 1 para usar índice base 0

						if (carta_seleccionada < 0 || carta_seleccionada >= 4 - i) {
							printf("Error: selecciona una carta válida entre 1 y %d\n", 4 - i);
						}

					} while (carta_seleccionada < 0 || carta_seleccionada >= 4 - i);
					puntos_ronda_j2 = puntos_ronda_j2 + lista_jugador2.getCarta(carta_seleccionada).get_puntos();
					habilidades(lista_jugador2.getCarta(carta_seleccionada), lista_jugador2, i);
					lista_jugador2.eliminar(carta_seleccionada);
					puntos_ronda_j2 += lista_jugador2.getCarta(i).get_puntos();

				}
				usar_carta = 1;

				printf("pulsa enter para borrar la pantalla y pasar al turno de jugador2");
				getchar();
				system("cls");

				i++;
			
		}
	
		
		if (puntos_ronda_j1 > puntos_ronda_j2) {
			printf("Jugador 1 ha ganado la ronda\n");
			rondas_j1++;
		}
		else if (puntos_ronda_j1 < puntos_ronda_j2) {
			printf("Jugador 2 ha ganado la ronda\n");
			rondas_j2++;
		}
		else {
			printf("Empate\n");
		}
		puntos_total_j1 += puntos_ronda_j1;
		puntos_total_j2 += puntos_ronda_j2;
		return 0;
	}
	int habilidades(Carta carta,ListaCircular& lista,int i) {
		
		string habilidad = carta.get_nombre();

		//duplica los puntos de tu mejor carta (busca el indice de la carta con mas puntos y multiplica los puntos de una copia por 2 despues la reemplaza)
		if (habilidad == "duplicador mayor") 
		{

			int pos = buscar_indice_max(lista);      //buscar el indice
			Carta c = lista.getCarta(pos);
			//duplicamos los puntos de la carta
			c = Carta(c.get_nombre(), c.get_puntos() * 2, c.get_habilidad_especial());

			//reemplaza la carta en la lista
			lista.setCarta(pos, c);
		}
		
		//duplica los puntos de tu peor carta
		else if (habilidad == "duplicador menor") 
		{
			int pos = buscar_indice_min(lista);                                    //buscar posicion
			Carta c = lista.getCarta(pos);											//saca la carta
			c = Carta(c.get_nombre(), c.get_puntos() * 2, c.get_habilidad_especial());		//duplicamos los puntos de la carta	
			lista.setCarta(pos, c);                                                //reemplaza la carta en la lista
			

		}
		//divide los puntos de la mejor carta del oponente (busca su mejor carta(de toda la pila) y divide los puntos a la mitad)
		else if (habilidad == "divisor") 
		{
			int pos = buscar_indice_max(lista);      //buscar el indice
			Carta c = lista.getCarta(pos);
			c = Carta(c.get_nombre(), c.get_puntos() / 2, c.get_habilidad_especial());          //dividimos los puntos de la carta

			//reemplaza la carta en la lista
			lista.setCarta(pos, c);
		
		}
		// cambia tus cartas por cartas de tu pila por lo que vamos a girarla el numero de cartas que queden si solo queda una se quedara la misma
		else if(habilidad == "removedor")
		{
			lista.girar(4 - i); //gira la lista el numero de cartas que queden
		}
		//ordena tus cartas de mayor a menor con el metodo burbuja
		else if(habilidad == "ordenador")
		{
			lista.ordenar();
		}
		else {

		}
		

	}
	//busca el indice de la carta con mas puntos
	int buscar_indice_max(ListaCircular& lista) {
		int pos_max = 0;
		int max_puntos = lista.getCarta(0).get_puntos();

		for (int i = 1; i < lista.getN(); ++i) {
			int puntos = lista.getCarta(i).get_puntos();
			if (puntos > max_puntos) {
				max_puntos = puntos;
				pos_max = i;
			}
		}
		return pos_max;
	}
	//busca el indice de la carta con menos puntos y es mayor a 0 (para no tocar las cartas especiales)
	int buscar_indice_min(ListaCircular& lista) {
		int pos_min = -1;
		int min_puntos = 1;

		for (int i = 0; i < lista.getN(); ++i) {
			int puntos = lista.getCarta(i).get_puntos();
			if (puntos > 0 && puntos < min_puntos) {
				min_puntos = puntos;
				pos_min = i;
			}
		}

		return pos_min;
	}
	int verificar_ganador() {
		if (rondas_j1 > rondas_j2) {
			printf("Jugador 1 ha ganado la partida\n");
			return 1;
		}
		else if (rondas_j1 < rondas_j2) {
			printf("Jugador 2 ha ganado la partida\n");
			return 1;
		}
		else if(rondas_j1 == rondas_j2) {
			return 0;
		}
	}
	void instrucciones() {
		printf("============================================================\n");
		printf("                  INSTRUCCIONES DEL JUEGO DE CARTAS         \n");
		printf("============================================================\n");
		printf("Objetivo:\n");
		printf("- Jugar hasta 3 rondas.\n");
		printf("- Gana quien gana 2 rondas o tiene más puntos totales.\n\n");

		printf("Turno de ronda:\n");
		printf("- Cada jugador verá 4 cartas.\n");
		printf("- En cada turno puedes jugar 1 carta.\n");
		printf("- En el cuarto turno puedes decidir si jugar o no.\n");
		printf("- Algunas cartas tienen habilidades especiales.\n\n");

		printf("Habilidades posibles:\n");
		printf("- duplicador mayor: duplica tu mejor carta.\n");
		printf("- duplicador menor: duplica tu peor carta (>0).\n");
		printf("- divisor: divide por 2 la mejor carta del oponente.\n");
		printf("- removedor: baraja tu mazo (gira tu lista circular).\n");
		printf("- ordenador: ordena tus cartas de mayor a menor.\n");

		printf("============================================================\n");
		printf("Presiona ENTER para comenzar...\n");
		getchar();
	}


};