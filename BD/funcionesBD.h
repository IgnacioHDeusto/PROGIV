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

void crearProducto(Producto p);

int comprobarUsuario(char* usuario, char* contrasena);

void Mostrarusuarios();

void ListaProductos();

void BorrarProducto(int id);

void insertarAlmacen(Almacen al);

void BorrarAlmacen(int id);

//void crearProducto(char* nombre, char* descripcion, int categoria, int precio, char* tamanyo);

#endif /* BD_FUNCIONESBD_H_ */
