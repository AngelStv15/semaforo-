#include <stdio.h>
#include <time.h>
#include <windows.h> // Biblioteca para cambiar los colores en Windows

// Definimos los códigos ANSI para colores de fuente
#define AMARILLO_T "\x1b[33m"
#define ROJO_T     "\x1b[31m"
#define VERDE_T    "\x1b[32m"
#define RESET_T    "\x1b[0m"

// Definimos una estructura para representar el estado del semáforo
struct Semaforo {
	int tiempo_verde;
	int tiempo_amarillo;
	int tiempo_rojo;
};

// Función para esperar el tiempo especificado en segundos
void esperar(int segundos) {
	clock_t inicio = clock();
	while ((clock() - inicio) / CLOCKS_PER_SEC < segundos) {}
}

int main() {
	// Inicializamos la estructura del semáforo con los tiempos de cada estado
	struct Semaforo semaforo = {18, 15, 30};
	
	int contador = 0; // Contador estático inicializado en cero
	
	while (contador <= semaforo.tiempo_rojo) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Rojo
		printf("%sALTO [%d segundos]%s\n", ROJO_T, contador, RESET_T);
		esperar(1); // Contador avanza un segundo a la vez
		contador++;
	}
	
	contador = 0; // Reiniciamos el contador
	
	while (contador <= semaforo.tiempo_amarillo) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Amarillo
		printf("%sPRECAUCION [%d segundos]%s\n", AMARILLO_T, contador, RESET_T);
		esperar(1);
		contador++;
	}
	
	contador = 0; // Reiniciamos el contador
	
	while (contador <= semaforo.tiempo_verde) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Verde
		printf("%sPUEDE CONTINUAR [%d segundos]%s\n", VERDE_T, contador, RESET_T);
		esperar(1);
		contador++;
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Restablecer el color a blanco
	printf("\nPrograma terminado.\n");
	
	return 0;
}
