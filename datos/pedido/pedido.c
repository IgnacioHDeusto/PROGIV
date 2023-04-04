#include "pedido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirFecha(Fecha f)
{
	printf("%s/%s/%s", f.dia, f.mes, f.anyo);
}

char* fechaToChar(Fecha f){
	char* fecha = malloc(sizeof(char)*11);
	strcpy(fecha, f.dia);
	strcat(fecha, "/");
	strcat(fecha, f.mes);
	strcat(fecha, "/");
	strcat(fecha, f.anyo);
	printf("%s", fecha);
	return fecha;
}

void imprimirPedido(Pedido p){
	char* fecha = fechaToChar(p.fecha);
    printf("Pedido -> N_PEDIDO: %i, FECHA: %s, DNI: %s \n", p.n_pedido, fecha, p.dni);
}

void imprimirCarrito(Carrito* c)
{
	int i;
	for (i = 0; i < c->numPedidos; ++i) {
		imprimirPedido(c->pedido[i]);
	}

}
