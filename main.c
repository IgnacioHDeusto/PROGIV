#include <stdlib.h>
#include <stdio.h>
#include "menus/menu.h"
#include "datos/cliente/cliente.h"
#include "datos/pedido/pedido.h"
#include "datos/producto/producto.h"
#include "datos/sucursal/sucursal.h"
#include "datos/trabajador/trabajador.h"
#include "sqlite/sqlite3.h"
#include <string.h>

sqlite3 *db;

int main(void) {
	Trabajador t1 = {1,"Ignacio", "123"};
	crearGestor(t1);



	char opcion;
	char opcion2;
	char opcion3;
	char opcion6;
	char opcion7;
	char opcion8;
	char opcion9;



	do{
		opcion = mostrarMenu();
		switch(opcion){
		case '1':
			//ACEDE AL MENU DE CLIENTE
			//menuCliente();

			do{

				opcion2 = menuCliente();
				switch(opcion2 ){
				case '1':
					//Inicio sesion cliente
					menuInicioSesionCliente();

					//menuAplicacionCliente();

					do{
						opcion3 = menuAplicacionCliente();

						switch(opcion3){

						case '1':
							//añadir producto al carrito

							menuAnadirProductoCliente();
							break;

						case '2':
							//Ver mi carrito
							//imprimirCarrito(c);
							printf("Se imprime el carrito \n");
							break;
//							//funcion
//							do{
//								opncion4 = funcion
//										switch(opcion4){
//										case '1':
//											//CONFIRMAR
											//FUNCION CONFIRMAR
//										case '2';
//											//ELIMINAR PROD
												//FUNCION ELIMINAR
//													do{
//														opncion5 = funcion
//														switch(opcion4){
//															//funcion eliminar
//														}
//													}while(opcion != 'q');
//
//										}
//							}while(opcion != 'q');

						case '3':
							//Lista de mis pedidos
							printf("Se imprimen los pedidos \n");
							break;

							//funcion
							//							do{
							//								opncion4 = funcion
							//										switch(opcion4){
							//										case '1':
							//											//IMPRIMIR LISTA DE PEDIDOS

							//										case '2';
							//											//ELIMINAR PEDIDO
																			//FUNCION ELIMINAR
							//													do{
							//														opncion5 = funcion
							//														switch(opcion4){
							//															//funcion eliminar
							//														}
							//													}while(opcion != 'q');
							//
							//										}
							//							}while(opcion != 'q');


						case 'q':
							break;

						}



					}while(opcion3 != 'q');
					break;
				case '2':
					//Crear cuenta de cliente

					menuCrearCuentaCliente();


				case 'q':
					break;
				}

			//break;
			}while(opcion2 != 'q');
			break;
		case '2':
			//ACEDE AL MENU DE TRABAJADOR
			//MenuGestor();
			do{
				opcion6 = MenuGestor();
				switch(opcion6){
				case '1':
					menuInicioSesionGestor();

					do{
						opcion7 = menuAplicacionGestor();
						switch(opcion7){
						case '1':
							//GESTIONAR PRODUCTOS
							//menuGestionProductosGestor();

							do{
								opcion8 = menuGestionProductosGestor();
								switch(opcion8){
								case '1':
									//LISTA PRODUCTOS
									printf("LISTA DE PRODUCTOS:");

									break;
								case '2':
									//ANADIR PRODUCTOS
									menuAnadirProductoGestor();
									break;
								case '3':
									//ELIMINAR PRODUCTOS
									menuEliminarProductoGestor();
									break;
								case '4':
									//CONSULTAR ALMACENES´
									printf("LISTA DE ALMACENES:");
									break;
								case '5':
									//CONSULTAR STOCK
									printf("LISTA DE STOCK:");
									break;
								case '6':
									//AUMENTAR STOCK
									printf("AUMENTAR DE STOCK:");
									break;

								case 'q':

									break;
								}

							}while(opcion8 != 'q');
							break;
						case '2':
							//GESTIONAR USUARIOS
							menuGestionUsuariosGestor();
							do{
								opcion9 = menuGestionUsuariosGestor();
								switch(opcion9){

								case '1':
									//LISTA USUARIOS
									printf("LISTA DE USUARIOS:");
									break;

								case '2':
									//INRFORMACION PEDIDO
									printf("INFORMACION DE PEDIDOS:");
									break;

								case '3':
									//ENVIAR PEDIDO
									printf("AUMENTAR DE STOCK:");
									break;

								case 'q':
									break;
								}
							}while(opcion9 != 'q');
							break;


						case '3':
							//BORRAR BD
							printf("Borrar bd");

						case 'q':
							break;

						}

					}while(opcion7 != 'q');
					break;

				case '2':
					printf("caso 2");

				case 'q':
					break;

				}


			}while(opcion6 != 'q');
			break;

		}
	}while(opcion != 'q');
	return 0;
}
