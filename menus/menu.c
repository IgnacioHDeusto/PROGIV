#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

char mostrarMenu(){

	printf("------------------\n");
	printf("DEUSTO IMPERIO MODA\n");
    printf("------------------\n");
    printf("1. Aplicacion cliente \n");
    printf("2. Aplicacion trabajador \n");
    printf("Pulsar 'q' para salir \n");
    printf("\n");
    printf("Opcion: ");
    fflush(stdout);
    char linea[10];
    fgets(linea, 10,stdin);
    return *linea;
}

void menuInicioSesionCliente(){
	printf("\n");
	printf("------------------\n");
    printf("INICIO DE SESION CLIENTE\n");
    printf("------------------\n");
    printf("Nombre de usuario:\n");
    fflush(stdout);
    char linea[20];
    fgets(linea, 20, stdin);
    printf("Constraseña:\n");
    printf("\n");
    fflush(stdout);
    char linea1[20];
    fgets(linea1, 20,stdin);
}

///////////////////////////////////////////////
///////////////MENU GESTOR///////////////////
///////////////////////////////////////////////

char MenuGestor()
{
	printf("\n");
	printf("------------------\n");
	printf("REGISTRO GESTOR\n");
	printf("------------------\n");
	printf("1. Iniciar Sesion como gestor\n");
    printf("2. Registra un nuevo gestor\n");
    printf("Pulsar 'q' para salir \n");
    printf("\n");
    printf("Opcion: ");
    fflush(stdout);
    char linea[10];
    fgets(linea, 10,stdin);
    return *linea;
}

int menuInicioSesionGestor(){
	int resultado = 0;
	printf("\n");
	printf("------------------\n");
    printf("INICIO DE SESION GESTOR\n");
    printf("------------------\n");
    printf("Nombre de usuario:\n");
    fflush(stdout);
    char linea[20];
    fgets(linea, 20, stdin);
    printf("Constraseña:\n");
    printf("\n");
    fflush(stdout);
    char linea1[20];
    fgets(linea1, 20,stdin);
    resultado = comprobarUsuario(linea, linea1);
    return resultado;
}
char menuAplicacionGestor(){
	printf("\n");
	printf("------------------\n");
	printf("MENU GESTOR\n");
	printf("------------------\n");
    printf("1. Gestion de productos\n");
    printf("2. Gestion de usuarios\n");
    printf("3. Borrar base de datos \n");
    printf("Pulsar 'q' para salir \n");
    printf("\n");
    printf("Opcion: ");
    fflush(stdout);
    char linea[10];
    fgets(linea, 10,stdin);
    return* linea;
}

///////////////////////////////////////////////
///////////////MENU CLIENTE/////////////////////
///////////////////////////////////////////////

char menuCliente(){
	printf("\n");
	printf("------------------\n");
	printf("REGISTRO CLIENTE\n");
	printf("------------------\n");
	printf("1. Iniciar sesion como cliente \n");
    printf("2.Registrarse como nuevo cliente \n");
    printf("Pulsar 'q' para salir \n");
    printf("\n");
    printf("Opcion: ");
    fflush(stdout);
    char linea[10];
    fgets(linea, 10,stdin);
    return* linea;
}

char menuAplicacionCliente(){
	printf("\n");
	printf("------------------\n");
	printf("MENU CLIENTE\n");
    printf("------------------\n");
    printf("1. Anadir producto a mi carrito\n");
    printf("2. Ver mi carrito\n");
    printf("3. Lista de pedidos \n");
    printf("Pulsar 'q' para salir \n");
    printf("\n");
    printf("Opcion: ");
    fflush(stdout);
    char linea[10];
    fgets(linea, 10,stdin);

    return *linea;
}

void menuCrearCuentaCliente(){
	printf("\n");
	printf("------------------\n");
    printf("CREAR NUEVA CUENTA\n");
    printf("------------------\n");
    printf("Nombre:\n");
    fflush(stdout);
    char linea[20];
    fgets(linea, 20, stdin);
    printf("Constraseña:\n");
    fflush(stdout);
    char linea1[20];
    fgets(linea1, 20,stdin);
    printf("DNI:\n");
    fflush(stdout);
    char linea2[20];
    fgets(linea2, 20,stdin);
    printf("Direccion:\n");
    fflush(stdout);
    char linea3[20];
    fgets(linea3, 20,stdin);
    printf("Ciudad:\n");
   fflush(stdout);
    char linea4[20];
    fgets(linea4, 20,stdin);
    printf("Telefono:\n");
    fflush(stdout);
    char linea5[20];
    fgets(linea5, 20,stdin);
}

char menuCarrito(){
	printf("\n");
	printf("------------------\n");
    printf("CARRITO\n");
    printf("------------------\n");
    printf("1.Confirmar el pedido\n");
    printf("2. Eliminar producto del carrito\n");
    printf("3. Cancelar \n");
    printf("\n");
    printf("Opcion: ");
    fflush(stdout);
    char linea[10];
    fgets(linea, 10,stdin);
    return *linea;
}

void menuCrearCuentaGestor(){
	printf("\n");
	printf("------------------\n");
    printf("CREAR NUEVA CUENTA DE GESTOR\n");
    printf("------------------\n");
    printf("Cod_Trabajador:\n");
    fflush(stdout);
    char linea[20];
    fgets(linea, 20, stdin);
    printf("Nombre trabajador:\n");
    fflush(stdout);
    char linea1[20];
    fgets(linea1, 20,stdin);
    printf("Apellido:\n");
    fflush(stdout);
    char linea2[20];
    fgets(linea2, 20,stdin);
    printf("Contraseña:\n");
    fflush(stdout);
    char linea3[20];
    fgets(linea3, 20,stdin);
    Trabajador t = {NULL, linea1, linea3};
    crearGestor(t);
}

void menuAnadirProductoCliente(){
		printf("------------------\n");
	    printf("ELIGE UN PRODUCTO\n");
	    printf("------------------\n");
	    printf("Codigo del producto:\n");
	    fflush(stdout);
	    char linea[20];
	    fgets(linea, 20, stdin);

}

char menuGestionProductosGestor(){
	printf("\n");
		printf("------------------\n");
		printf("GESTION PRODUCTOS \n");
	    printf("------------------\n");
	    printf("1. Lista productos\n");
	    printf("2. Anadir productos\n");
	    printf("3. Eliminar productos \n");
	    printf("4. Consultar stock \n");
	    printf("5. Aumentar stock \n");
	    printf("Pulsar 'q' para salir \n");
	    printf("\n");
	    printf("Opcion: ");
	    fflush(stdout);
	    char linea[10];
	    fgets(linea, 10,stdin);
	    return *linea;
}

char menuGestionUsuariosGestor(){
	printf("\n");
			printf("------------------\n");
			printf("GESTION USUARIOS \n");
		    printf("------------------\n");
		    printf("1. Lista usuarios\n");
		    printf("2. Info pedidos\n");
		    printf("3. Enviar pedido \n");
		    printf("4. Consultar stock \n");
		    printf("Pulsar 'q' para salir \n");
		    printf("\n");
		    printf("Opcion: ");
		    fflush(stdout);
		    char linea[10];
		    fgets(linea, 10,stdin);
		    return *linea;
}
void menuAnadirProductoGestor(){
	float precio = 0;
	int categoria = 0;
	printf("\n");
		printf("------------------\n");
	    printf("ANADIR PRODUTO\n");
	    printf("------------------\n");
	    printf("Nombre:\n");
	    fflush(stdout);
	    char linea1[20];
	    fgets(linea1, 20,stdin);
	    printf("Descripcion:\n");
	    fflush(stdout);
	    char linea2[20];
	    fgets(linea2, 20,stdin);
	    printf("Cod_categoria:\n");
	    fflush(stdout);
	    char linea3[20];
	    fgets(linea3, 20,stdin);
	    categoria = atoi(linea3);
	    printf("Precio:\n");
	    fflush(stdout);
	    char linea4[20];
	    fgets(linea4, 20,stdin);
	    precio = atoi(linea4);
	    printf("Tamaño:\n");
	    fflush(stdout);
	    char linea5[20];
	    fgets(linea5, 20,stdin);
	    Producto p = {NULL, linea1, linea2, categoria, precio, linea5};
	   // printf("%i,%i,%s",categoria, precio, linea5);
	    crearProducto(p);
	   // crearProducto(linea1, linea2, categoria, precio, linea5);
}

void menuEliminarProductoGestor(){
	printf("\n");
	printf("------------------\n");
	printf("ELIMINAR PRODUTOS\n");
	printf("------------------\n");
	printf("ID_Producto:\n");
	int id = 0;
	fflush(stdout);
	scanf("%i", &id);
	BorrarProducto(id);
}
