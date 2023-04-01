#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

char mostrarMenu(){
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
    return linea;
}

void menuInicioSesion(){
	printf("------------------\n");
    printf("INICIO DE SESION\n");
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
///////////////MENU GESTOR/////////////////////
///////////////////////////////////////////////

char MenuGestor()
{
    printf("1. Iniciar Sesion\n");
    printf("2. Registra un nuevo gestor\n");
    printf("Pulsar 'q' para salir \n");
    printf("\n");
    printf("Opcion: ");
    fflush(stdout);
    char linea[10];
    fgets(linea, 10,stdin);
    return linea;
}

char menuAplicacionGestor(){
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
    return linea;
}

///////////////////////////////////////////////
///////////////MENU CLIENTE/////////////////////
///////////////////////////////////////////////

char menuCliente(){
    printf("1. Iniciar sesion como cliente \n");
    printf("2.Registrarse como nuevo cliente \n");
    printf("Pulsar 'q' para salir \n");
    printf("\n");
    printf("Opcion: ");
    fflush(stdout);
    char linea[10];
    fgets(linea, 10,stdin);
    return linea;
}

char menuAplicacionCliente(){
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
    printf("----------\n");
    printf("CARRITO\n");
    printf("----------\n");
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


