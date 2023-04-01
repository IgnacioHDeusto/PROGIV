#ifndef DATOS_SUCURSAL_SUCURSAL_H_
#define DATOS_SUCURSAL_SUCURSAL_H_

typedef struct {
    int id;
    char* nombre;
    char* direccion;
    char* telefono;
}Almacen;

typedef struct {
	char* codigo;
	char* nombre;
    int cod_provincia;
} Ciudad;

typedef struct {
    int codigo;
    char* nombre;
}Provincia;


typedef struct {
    int stock;
    int id_prod;
    int id_alm;
}Existencias;

#endif /* DATOS_SUCURSAL_SUCURSAL_H_ */
