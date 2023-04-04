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
//	CompraProducto cp = {3, 5, 1};
//	CompraProducto cp1 = {3, 6, 1};
//	CompraProducto cp2 = {3, 7, 1};
//	insertarCompraProd(cp);
//	insertarCompraProd(cp1);
//	insertarCompraProd(cp2);
	comprobarStockEs0(3, 5);

	char opcion;
	char opcion2;
	char opcion3;
	char opcion6;
	char opcion7;
	char opcion8;
	char opcion9;
	int opcionInicioSesionGestor;



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
					opcionInicioSesionGestor = menuInicioSesionGestor();
					if(opcionInicioSesionGestor == 1) {
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
															printf("\n-------------------\n");
															printf("LISTA DE PRODUCTOS:\n");
															printf("-------------------\n");
															ListaProductos();
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
															printf("\n");
															printf("-------------------\n");
															printf("LISTA DE ALMACENES:\n");
															printf("-------------------\n");
															ListaAlmacenes();
															break;
														case '5':
															//CONSULTAR STOCK
															printf("\n-------------------\n");
															printf("LISTA DE STOCK:");
															printf("-------------------\n");
															ConsultarStock();
															break;
														case '6':
															//AUMENTAR STOCK
															menuAumentarStock();
															break;

														case 'q':

															break;
														}

													}while(opcion8 != 'q');
													break;
												case '2':
													//GESTIONAR USUARIOS
													do{
														opcion9 = menuGestionUsuariosGestor();
														switch(opcion9){

														case '1':
															printf("\n------------------\n");
															printf("LISTA DE USUARIOS:\n");
															printf("------------------\n");
															MostrarTrabajadores();
															break;

														case '2':
															//INRFORMACION PEDIDO
															printf("\n");
															printf("INFORMACION DE PEDIDOS:\n");
															listaPedidos();
															break;

														case '3':
															//ENVIAR PEDIDO
															menuEnviarPedido();
															break;
														case '4':
															//CONSULTAR STOCK
															printf("\n");
															printf("-------------------\n");
															printf("LISTA DE STOCK:\n");
															printf("-------------------\n");
															ConsultarStock();
															break;

														case 'q':
															break;
														}
													}while(opcion9 != 'q');
													break;

												case 'q':
													break;

												}

											}while(opcion7 != 'q');
											break;
					} else {
						printf("Error iniciando sesion, usuario o contraseña incorrectos");
						break;
					}



				case '2':
					menuCrearCuentaGestor();
					break;
				case 'q':
					break;

				}


			}while(opcion6 != 'q');
			break;

		}
	}while(opcion != 'q');
	return 0;
}
