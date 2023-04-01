#ifndef DATOS_PEDIDO_PEDIDO_H_
#define DATOS_PEDIDO_PEDIDO_H_

typedef struct {
    int dia;
    int mes;
    int anyo;
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

void imprimirFecha(Fecha f);

void imprimirPedido(Pedido p);

#endif /* DATOS_PEDIDO_PEDIDO_H_ */
