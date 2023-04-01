#include "producto.h"
#include <stdio.h>

void imprimirProducto(Producto p){
    printf("Producto -> ID: %i, NOMBRE: %s, PRECIO: %f", p.id_prod, p.nombre, p.precio);
}
void imprimirPedido(Pedido p){
    printf("Pedido -> N_PEDIDO: %i, FECHA: %i, DNI: %s", p.n_pedido, p.fecha, p.dni);
}
