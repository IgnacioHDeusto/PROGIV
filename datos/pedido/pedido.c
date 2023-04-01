#include "pedido.h"
#include <stdio.h>

void imprimirFecha(Fecha f)
{
	printf("%i/%i/%i", f.dia, f.mes, f.anyo);
}

void imprimirPedido(Pedido p){
    printf("Pedido -> N_PEDIDO: %i, FECHA: %i, DNI: %s", p.n_pedido, p.fecha, p.dni);
}
