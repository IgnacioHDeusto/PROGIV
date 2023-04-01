
#ifndef DATOS_CLIENTE_CLIENTE_H_
#define DATOS_CLIENTE_CLIENTE_H_

typedef struct {
    char* dni;
    char* nombre;
    char* direccion;
    char* telefono;
    int cod_ciudad;
} Cliente;

void imprimirCliente();

#endif /* DATOS_CLIENTE_CLIENTE_H_ */
