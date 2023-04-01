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

typedef struct {
	char* abreviatura;
	char* nombre;
}Tamayo;

typedef struct {
	char* abreviatura;
    int id_prod;
    int cant;
}Talla;

#endif /* DATOS_PRODUCTO_PRODUCTO_H_ */
