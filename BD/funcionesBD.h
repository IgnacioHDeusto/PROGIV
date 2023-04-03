#ifndef BD_FUNCIONESBD_H_
#define BD_FUNCIONESBD_H_

#include "../datos/sucursal/sucursal.h"
#include "../sqlite/sqlite3.h"
#include "../datos/producto/producto.h"
#include "../datos/trabajador/trabajador.h"

void insertarCategoria(Categoria c);

void insertarCiudades(Ciudad ci);

void insertarProvincias(Provincia prov);

void selectCategoria(int ct);

void selectProvincia(int pr);

void crearGestor(Trabajador t);

#endif /* BD_FUNCIONESBD_H_ */
