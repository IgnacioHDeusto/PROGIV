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
