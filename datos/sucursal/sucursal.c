#include "sucursal.h"
#include <stdio.h>
#include <stdlib.h>


void imprimirAlmacen (Almacen a)
{
    printf("[Almacen : %s, TLF: %i, DIR: %i]",a.nombre, a.telefono, a.direccion);
}

void imprimirCiudad (Ciudad ci) {
	printf("[Ciudad : %i %s, Prov: %i]",ci.codigo, ci.nombre, ci.cod_provincia);
}

void imprimirProvincia (Provincia prov) {
	printf("[Provincia: %i %s]",prov.codigo, prov.nombre);
}
