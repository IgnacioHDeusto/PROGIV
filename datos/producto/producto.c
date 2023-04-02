#include "producto.h"
#include <stdio.h>

Categoria tipos[5];
//tipos[0].id = "0";

void imprimirProducto(Producto p){
    printf("Producto -> ID: %i, NOMBRE: %s, PRECIO: %f", p.id_prod, p.nombre, p.precio);
}

void imprimirCategoria(Categoria c) {
	printf("Categoria -> Codigo: %i, Nombre: %s", c.codigo, c.nombre);
}

