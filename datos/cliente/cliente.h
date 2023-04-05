
#ifndef DATOS_CLIENTE_CLIENTE_H_
#define DATOS_CLIENTE_CLIENTE_H_

typedef struct {
    char* dni;
    char* nombre;
    char* direccion;
    int telefono;
    int cod_ciudad;
    char* contrasena;
} Cliente;

void imprimirCliente();

void imprimirCarrito();

#endif /* DATOS_CLIENTE_CLIENTE_H_ */
