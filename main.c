#include <stdlib.h>
#include <stdio.h>

int main() {

	return 1;
}

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
