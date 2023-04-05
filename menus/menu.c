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
    char nom[20];
    fflush(stdout);
    scanf("%s", nom);
    printf("Constraseña:\n");
    char contr[20];
    fflush(stdout);
    scanf("%s", contr);
    fflush(stdin);
    resultado = comprobarUsuario(nom, contr);
    return resultado;
}
char menuAplicacionGestor(){
	printf("\n");
	printf("------------------\n");
	printf("MENU GESTOR\n");
	printf("------------------\n");
    printf("1. Gestion de productos\n");
    printf("2. Gestion de usuarios\n");
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
    printf("1. Confirmar el pedido\n");
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
    printf("Nombre trabajador:\n");
    char nombre[20];
    fflush(stdout);
    scanf("%s", nombre);
    printf("Contraseña trabajador:\n");
    char contrasena[20];
    fflush(stdout);
    scanf("%s", contrasena);
    Trabajador t = {NULL, nombre, contrasena};
    fflush(stdin);
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
	    printf("3. Editar precios\n");
	    printf("4. Eliminar productos \n");
	    printf("5. Consultar Almacenes \n");
	    printf("6. Consultar stock \n");
	    printf("7. Aumentar stock \n");
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
		printf("\n");
		printf("------------------\n");
	    printf("ANADIR PRODUCTO\n");
	    printf("------------------\n");
	    printf("Nombre:\n");
	    fflush(stdout);
	    char nombre[20];
	    scanf("%s", nombre);
	    printf("Descripcion:\n");
	    fflush(stdout);
	    char desc[20];
	    scanf("%s", desc);
	    printf("Cod_categoria:\n");
	    fflush(stdout);
	    int categoria = 0;
	    scanf("%i", &categoria);
	    printf("Precio:\n");
	    float precio = 0;
	    fflush(stdout);
	    scanf("%f", &precio);
	    printf("Tamaño:\n");
	    char tamanyo[20];
	    fflush(stdout);
	   	scanf("%s", tamanyo);

	    Producto p = {NULL, nombre, desc, categoria, precio, tamanyo};
	   // printf("%i,%i,%s",categoria, precio, linea5);
	    crearProducto(p);
	   // crearProducto(linea1, linea2, categoria, precio, linea5);
}

void menuEliminarProductoGestor(){
	printf("\n");
	printf("------------------\n");
	printf("ELIMINAR PRODUCTOS\n");
	printf("------------------\n");
	printf("ID_Producto:\n");
	int id = 0;
	fflush(stdout);
	scanf("%i", &id);
	fflush(stdin);
	BorrarProducto(id);
}

void menuAumentarStock(){
	printf("\n-------------------\n");
	printf("AUMENTAR STOCK:\n");
	printf("-------------------\n");
	printf("Stock:\n");
	fflush(stdout);
	int stock = 0;
	scanf("%i", &stock);
	printf("ID de producto::\n");
	fflush(stdout);
	int id_prod = 0;
	scanf("%i", &id_prod);
	printf("ID de almacen:\n");
	fflush(stdout);
	int id_alm = 0;
	scanf("%i", &id_alm);

	fflush(stdin);
	aumentarStock(stock, id_prod, id_alm);
}

void menuEnviarPedido(){
	fflush(stdin);
	listaPedidos();

	printf("\n-------------------\n");
	printf("ENVIAR PEDIDO:\n");
	printf("-------------------\n");

	printf("Introduce el Nº que quieres enviar:\n");
	int n_ped = 0;
	fflush(stdout);
	scanf("%i", &n_ped);
	printf("¿Confirmar envio? (s/n)\n");
	char conf[20];
	fflush(stdout);
	scanf("%s", conf);
	fflush(stdin);
	if (strcmp(conf, "s") == 0) {
		int comp = comprobarPedido(n_ped);
		if (comp == 0){
				printf("No existe ese pedido");
		}else {
			int numProd = productosPedido(n_ped);
		}

	}
}
void menuEditarPrecio(){
	fflush(stdin);
	ListaProductos();
	printf("\n-------------------\n");
	printf("EDITAR PRECIO:\n");
	printf("-------------------\n");
	printf("Introduce el ID del producto que quieras editar el precio:\n");
	int id_prod = 0;
	fflush(stdout);
	scanf("%i", &id_prod);
	printf("Introduce el nuevo precio del producto %i:\n", id_prod);
	fflush(stdout);
	int precio = 0;
	scanf("%i", &precio);
	fflush(stdin);
	editarPrecio(id_prod, precio);
}
