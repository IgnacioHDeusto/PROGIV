#ifndef DATOS_PRODUCTO_PRODUCTO_H_
#define DATOS_PRODUCTO_PRODUCTO_H_



typedef struct {
	int id_prod;
	char* nombre;
	char* descripcion;
	char* categoria;
    float precio;
    char* tamayo;
} Producto;

typedef struct {
    int codigo;
    char* nombre;
}Categoria;


void imprimirProducto(Producto p);

#endif /* DATOS_PRODUCTO_PRODUCTO_H_ */
