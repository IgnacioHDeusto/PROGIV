#ifndef BD_FUNCIONESBD_H_
#define BD_FUNCIONESBD_H_

#include "../datos/sucursal/sucursal.h"
#include "../sqlite/sqlite3.h"
#include "../datos/producto/producto.h"
#include "../datos/trabajador/trabajador.h"
#include "../datos/pedido/pedido.h"

char* load_config(char* filename, char* buscar);

void iniciarBD();

void insertarCategoria(Categoria c);

void insertarCiudad(Ciudad ci);

void insertarProvincia(Provincia prov);

void BorrarProvincia(int id);

void selectCategoria(int ct);

void selectProvincia(int pr);

void crearGestor(Trabajador t);

void crearProducto(Producto p);

int comprobarUsuario(char* usuario, char* contrasena);

void MostrarTrabajadores();

void ListaProductos();

void BorrarProducto(int id);

void insertarAlmacen(Almacen al);

void BorrarAlmacen(int id);

void ListaAlmacenes();

void aumentarStock(int stock, int id_prod, int id_alm);

void borrarStock(int id_prod, int id_alm);

int comprobarStock(int id_prod, int id_alm);

void ConsultarStock();

void insertarPedido(Pedido ped);

void listaPedidos();

void EnviarPedido(int id);

int comprobarPedido(int n_ped);

void BorrarCompraProd(int id_prod, int n_ped);

void ComprobarStockPedido(int id_prod, int n_ped, int j, int i);

void ComprobarStockPedido();

void comprobarStockEs0(int id_prod, int id_alm);
//void crearProducto(char* nombre, char* descripcion, int categoria, int precio, char* tamanyo);
void editarPrecio(int id_prod, int precio);



#endif /* BD_FUNCIONESBD_H_ */
