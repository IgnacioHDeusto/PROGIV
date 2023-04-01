#include "sucursal.h"
#include <stdio.h>
#include <stdlib.h>


void imprimirAlmacen (Almacen a)
{
    printf("[Almacen : %s, TLF: %s, DIR: %i]",a.nombre, a.telefono, a.direccion);
}
