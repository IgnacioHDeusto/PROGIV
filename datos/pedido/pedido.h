#ifndef DATOS_PEDIDO_PEDIDO_H_
#define DATOS_PEDIDO_PEDIDO_H_

typedef struct {
    char* dia;
    char* mes;
    char* anyo;
}Fecha;

typedef struct {
    int n_pedido;
    Fecha fecha;
    char* dni;
} Pedido;

typedef struct {
    int n_pedido;
    int id_producto;
    int cant;
} CompraProducto;

typedef struct {
    int id;
    Pedido* pedido;
    int numPedidos;
} Carrito;

char* fechaToChar(Fecha f);

void imprimirFecha(Fecha f);

void imprimirPedido(Pedido p);

void imprimirCarrito(Carrito* c);

#endif /* DATOS_PEDIDO_PEDIDO_H_ */
