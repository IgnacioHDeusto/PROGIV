#include "menu.h"
void MenuGestor()
{
	printf("1. Iniciar Sesion\n");
	printf("2. Registra un nuevo gestor\n");
	printf("3. Salir\n");
	printf("\n");
	printf("Opcion: ");
	fflush(stdout);
	char leerCaracteres[1];
	fgets(leerCaracteres, 1, stdin);
	clearIfNeeded(leerCaracteres, 1);
}


char mostrarMenu(){
    printf("1. Aplicacion cliente \n");
        printf("2. Aplicacion trabajador \n");
        printf("Pulsar 'q' para salir \n");
        printf("Opci�n: ");
        fflush(stdout);
        char linea[10];
        fgets(linea, 10,stdin);
        return *linea;
}

char menuCliente(){
            printf("1. Iniciar sesion como cliente \n");
            printf("2.Registrarse como nuevo cliente \n");
            printf("Pulsar 'q' para salir \n");
            printf("Opci�n: ");
            fflush(stdout);
            char linea[10];
            fgets(linea, 10,stdin);
            return *linea;
}
