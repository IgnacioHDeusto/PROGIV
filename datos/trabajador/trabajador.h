#ifndef DATOS_TRABAJADOR_TRABAJADOR_H_
#define DATOS_TRABAJADOR_TRABAJADOR_H_

typedef struct {
	int cod_trab;
	char* Nombre_trab;
	char* Contrasena_trab;
}Trabajador;

void imprimirTrabajador(Trabajador t);
#endif
