#include <stdio.h>
#include <string.h>
#include "../datos/sucursal/sucursal.h"
#include "../sqlite/sqlite3.h"
#include "../datos/producto/producto.h"
#include "../datos/trabajador/trabajador.h"
#include "../datos/pedido/pedido.h"
#include <stdlib.h>

sqlite3 *db;
sqlite3_stmt *stmt;
int result;

void insertarCategoria(Categoria c) {
	sqlite3 *db;
	char* error = 0;
	int rc;

    char sql[] = "insert into CATEGORIA (Codigo_cat, Nombre_cat ) values (?, ?)";

    rc = sqlite3_open("Tienda.db", &db);

   	        if (rc == SQLITE_OK) {
   	            printf("Conexión establecida\n");

   	            char query[400];
   	            sprintf(query, "INSERT INTO CATEGORIA ( Codigo_cat, Nombre_cat) VALUES ('%d', '%s')", c.codigo, c.nombre);

   	            rc = sqlite3_exec(db, query, 0, 0, &error);

   	            if (rc == SQLITE_OK) {
   	                printf("Categoria insertada correctamente\n");
   	            } else {
   	                printf("Error al insertar Categoria: %s\n", error);
   	            }
   	        } else {
   	            printf("Error al conectar a la base de datos: %s\n", sqlite3_errmsg(db));
   	        }

   	        sqlite3_finalize(stmt);
   	        sqlite3_close(db);
}
void insertarCiudad(Ciudad ciu) {
	 sqlite3 *db;
	 char* error = 0;
	 int rc;

	        rc = sqlite3_open("Tienda.db", &db);

	        if (rc == SQLITE_OK) {
	            printf("Conexión establecida\n");

	            char query[400];
	            sprintf(query, "INSERT INTO CIUDAD ( Codigo_ciu, Nombre_ciu, Codigo_prov) VALUES ('%d', '%s', '%d')", ciu.codigo, ciu.nombre, ciu.cod_provincia);

	            rc = sqlite3_exec(db, query, 0, 0, &error);

	            if (rc == SQLITE_OK) {
	                printf("Ciudad insertada correctamente\n");
	            } else {
	                printf("Error al insertar ciudad: %s\n", error);
	            }
	        } else {
	            printf("Error al conectar a la base de datos: %s\n", sqlite3_errmsg(db));
	        }

	        sqlite3_finalize(stmt);
	        sqlite3_close(db);

	}

void insertarProvincia(Provincia prov) {
	 sqlite3 *db;
	 char* error = 0;
	 int rc;

	        rc = sqlite3_open("Tienda.db", &db);

	        if (rc == SQLITE_OK) {
	            printf("Conexión establecida\n");

	            char query[400];
	            sprintf(query, "INSERT INTO PROVINCIA ( Codigo_prov, Nombre_prov) VALUES ('%d', '%s')", prov.codigo, prov.nombre);

	            rc = sqlite3_exec(db, query, 0, 0, &error);

	            if (rc == SQLITE_OK) {
	                printf("Provincia insertada correctamente\n");
	            } else {
	                printf("Error al insertar provincia: %s\n", error);
	            }
	        } else {
	            printf("Error al conectar a la base de datos: %s\n", sqlite3_errmsg(db));
	        }

	        sqlite3_finalize(stmt);
	        sqlite3_close(db);

	}

void BorrarProvincia(int id){
	sqlite3_open("Tienda.db", &db);
		char sql[] = "delete from PROVINCIA where Codigo_prov = ?";
		sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

		sqlite3_bind_int(stmt, 1, id);

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			printf("Error borrando provincia\n");
		}else
		{
			printf("Provincia con ID %i borrado\n", id);
		}

}

void crearGestor(Trabajador t) {
	 sqlite3 *db;
	 char* error = 0;
	 int rc;

		        rc = sqlite3_open("Tienda.db", &db);

		        if (rc == SQLITE_OK) {
		            printf("Conexión establecida\n");

		            char query[400];
		            sprintf(query, "INSERT INTO TRABAJADOR ( Cod_trab, Usuario_trab, Contrasena_trab) VALUES (NULL, '%s', '%s')", t.Nombre_trab, t.Contrasena_trab);

		            rc = sqlite3_exec(db, query, 0, 0, &error);

		            if (rc == SQLITE_OK) {
		                printf("Trabajador insertado correctamente\n");
		            } else {
		                printf("Error al insertar trabajador: %s\n", error);
		            }
		        } else {
		            printf("Error al conectar a la base de datos: %s\n", sqlite3_errmsg(db));
		        }

		        sqlite3_finalize(stmt);
		        sqlite3_close(db);
}

void crearProducto(Producto p){
	     sqlite3 *db;
		 char* error = 0;
		 int rc;

			        rc = sqlite3_open("Tienda.db", &db);

			        if (rc == SQLITE_OK) {
			            printf("Conexión establecida\n");

			            char query[400];
			            sprintf(query, "INSERT INTO PRODUCTO ( ID_prod, Nombre_prod, Descripcion, Codigo_cat, Precio, Tamaño) VALUES (NULL, '%s', '%s', '%i', '%i', '%s')", p.nombre, p.descripcion, p.categoria, p.precio, p.tamayo);
			            rc = sqlite3_exec(db, query, 0, 0, &error);

			            if (rc == SQLITE_OK) {
			                printf("Producto insertado correctamente\n");
			            } else {
			                printf("Error al insertar producto: %s\n", error);
			            }
			        } else {
			            printf("Error al conectar a la base de datos: %s\n", sqlite3_errmsg(db));
			        }

			        sqlite3_finalize(stmt);
			        fflush(stdout);
			        sqlite3_close(db);
}

int comprobarUsuario(char usuario[], char contrasena[]) {
	Trabajador t;
	int resultado = 0;

	sqlite3_open("Tienda.db", &db);

	char sql[] = "SELECT * FROM TRABAJADOR WHERE Usuario_trab = ? AND Contrasena_trab = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, usuario, strlen(usuario), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, contrasena, strlen(contrasena), SQLITE_STATIC);

	result = sqlite3_step(stmt);

	if(result == SQLITE_ROW) {
		resultado = 1;
	} else {
		resultado = 0;
	}

	t.cod_trab = (int) sqlite3_column_int(stmt, 0);
	t.Nombre_trab = (char*) sqlite3_column_text(stmt, 1);
	t.Contrasena_trab = (char*)  sqlite3_column_text(stmt, 2);

    sqlite3_finalize(stmt);

    sqlite3_close(db);

    return resultado;
}

//ARREGLAR
void MostrarTrabajadores() {
    sqlite3_open("Tienda.db", &db);
    char sql[] = "SELECT * FROM TRABAJADOR";

        sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

        printf("\n");
        printf("Mostrando empleados:\n");

        do {
            result = sqlite3_step(stmt) ;
            if (result == SQLITE_ROW) {
                printf("Trabajador: %i %s, con contrasena : %s\n", (int) sqlite3_column_int(stmt, 0), (char*) sqlite3_column_text(stmt, 1),(char*) sqlite3_column_text(stmt, 2));
            }
        } while (result == SQLITE_ROW);
        printf("\n");

        sqlite3_finalize(stmt);
}

void BorrarTrabajador(int id)
{
	sqlite3_open("Tienda.db", &db);
	char sql[] = "delete from TRABAJADOR where Cod_trab = ?";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, id);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error borrando trabajador\n");
	}else
	{
		printf("Trabajador con ID %i borrado\n", id);
	}

}

void ListaProductos() {
	sqlite3_open("Tienda.db", &db);
		char sql[] = "select * from PRODUCTO";

			sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
			printf("\n");
			printf("Mostrando Productos:\n");

			do {
				result = sqlite3_step(stmt) ;
				if (result == SQLITE_ROW) {
					printf("Producto -> ID: %i --> (%i€) %s\n", (int) sqlite3_column_int(stmt, 0),(int) sqlite3_column_int(stmt, 4), (char*) sqlite3_column_text(stmt, 1));
				}
			} while (result == SQLITE_ROW);

			sqlite3_finalize(stmt);
}

void BorrarProducto(int id)
{
	sqlite3_open("Tienda.db", &db);
	char sql[] = "delete from PRODUCTO where ID_prod = ?";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, id);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error borrando producto\n");
	}else
	{
		printf("Producto con ID %i borrado\n", id);
	}

}
void BorrarAlmacen(int id)
{
	sqlite3_open("Tienda.db", &db);
	char sql[] = "delete from ALMACEN where Id_alm = ?";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, id);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error borrando almacen\n");
	}else
	{
		printf("Almacen con ID %i borrado\n", id);
	}

}
void insertarAlmacen(Almacen al) {
    sqlite3* db;
    char error = 0;
    int rc;

    rc = sqlite3_open("Tienda.db", &db);

    if (rc == SQLITE_OK) {
    printf("Conexión establecida\n");

    char query[400];
    sprintf(query, "INSERT INTO ALMACEN ( Id_alm, Nombre, Direccion, Tlf_alm, Codigo_ciu) VALUES (NULL, '%s', '%s', '%i', '%i')", al.nombre, al.direccion, al.telefono, al.cod_ciu);

    rc = sqlite3_exec(db, query, 0, 0, &error);

    if (rc == SQLITE_OK) {
    printf("Almacen insertado correctamente\n");
        } else {
        printf("Error al insertar el almacen: %s\n", error);
                }
        } else {
        printf("Error al conectar a la base de datos: %s\n", sqlite3_errmsg(db));
               }

        sqlite3_finalize(stmt);
        sqlite3_close(db);

}

void ListaAlmacenes() {
	sqlite3_open("Tienda.db", &db);
		char sql[] = "select * from ALMACEN";

			sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

			printf("Mostrando Almacenes:\n");
			printf("\n");

			do {
				result = sqlite3_step(stmt) ;
				if (result == SQLITE_ROW) {
					printf("Almacen -> ID: %i --> %s (Dirección: %s, TLF: %i)\n", (int) sqlite3_column_int(stmt, 0), (char*) sqlite3_column_text(stmt, 1), (char*) sqlite3_column_text(stmt, 2),(int) sqlite3_column_int(stmt, 3));
				}
			} while (result == SQLITE_ROW);

			sqlite3_finalize(stmt);
}

void aumentarStock(int stock, int id_prod, int id_alm) {
    sqlite3* db;
    char error = 0;
    int rc;

    rc = sqlite3_open("Tienda.db", &db);

    if (rc == SQLITE_OK) {
    printf("Conexión establecida\n");
    int resultado = comprobarStock(id_prod, id_alm);
    if (resultado == 1) {
    	printf("WORKING");
	} else {
		char query[400];
			sprintf(query, "INSERT INTO EXISTENCIAS (Stock, Id_prod, Id_alm) VALUES (%i, '%i', '%i')", stock, id_prod, id_alm);

			rc = sqlite3_exec(db, query, 0, 0, &error);

			if (rc == SQLITE_OK) {
			printf("Stock insertado correctamente\n");
				} else {
				printf("Error al insertar el stock: %s\n", error);
						}
				}
	} else {
        printf("Error al conectar a la base de datos: %s\n", sqlite3_errmsg(db));
               }

        sqlite3_finalize(stmt);
        sqlite3_close(db);

}
int comprobarStock(int id_prod, int id_alm) {
	int resultado = 0;

	sqlite3_open("Tienda.db", &db);

	char sql[] = "SELECT * FROM EXISTENCIAS WHERE Id_prod = ? AND Id_alm = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, id_prod);
	sqlite3_bind_int(stmt, 2, id_alm);

	result = sqlite3_step(stmt);

	if(result == SQLITE_ROW) {
		resultado = 1;
	} else {
		resultado = 0;
	}

    sqlite3_finalize(stmt);

    sqlite3_close(db);

    return resultado;
}

void ConsultarStock() {
		sqlite3_open("Tienda.db", &db);
		char sql[] = "select * from EXISTENCIAS";

			sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

			printf("Mostrando Stock:\n");
			printf("\n");

			do {
				result = sqlite3_step(stmt) ;
				if (result == SQLITE_ROW) {
					printf("%i unidades del producto %i en el almacen %i\n", (int) sqlite3_column_int(stmt, 0), (int) sqlite3_column_int(stmt, 1), (int) sqlite3_column_int(stmt, 2));
				}
			} while (result == SQLITE_ROW);

			sqlite3_finalize(stmt);
}

void borrarStock(int id_prod, int id_alm){
		sqlite3_open("Tienda.db", &db);
		char sql[] = "delete from EXISTENCIAS where Id_prod = ? AND Id_alm = ?";
		sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

		sqlite3_bind_int(stmt, 1, id_prod);
		sqlite3_bind_int(stmt, 2, id_alm);

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			printf("Error borrando stock\n");
		}else
		{
			printf("Stock del producto %i en el almacen %i borrado\n", id_prod, id_alm);
		}

}

void insertarPedido(Pedido ped){
	sqlite3* db;
	    char error = 0;
	    int rc;

	    rc = sqlite3_open("Tienda.db", &db);

	    if (rc == SQLITE_OK) {
	    printf("Conexión establecida\n");

	    char query[400];
	    char* fecha = fechaToChar(ped.fecha);
	    sprintf(query, "INSERT INTO PEDIDO ( N_PEDIDO, Fecha, DNI_clt) VALUES (NULL, '%s', '%s')", fecha, ped.dni);

	    rc = sqlite3_exec(db, query, 0, 0, &error);

	    if (rc == SQLITE_OK) {
	    printf("Pedido insertado correctamente\n");
	        } else {
	        printf("Error al insertar el almacen: %s\n", error);
	                }
	        } else {
	        printf("Error al conectar a la base de datos: %s\n", sqlite3_errmsg(db));
	               }

	        sqlite3_finalize(stmt);
	        sqlite3_close(db);

}

void listaPedidos(){
			sqlite3_open("Tienda.db", &db);
			char sql[] = "select * from PEDIDO";

				sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

				printf("Mostrando pedidos:\n");

				do {
					result = sqlite3_step(stmt) ;
					if (result == SQLITE_ROW) {
						printf("El pedido %i hecho el %s por %s\n", (int) sqlite3_column_int(stmt, 0), (char*) sqlite3_column_text(stmt, 1), (char*) sqlite3_column_text(stmt, 2));
					}
				} while (result == SQLITE_ROW);

				sqlite3_finalize(stmt);
}

void BorrarPedido(int id)
{
	sqlite3_open("Tienda.db", &db);
	char sql[] = "delete from PEDIDO where N_PEDIDO = ?";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, id);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error borrando pedido\n");
	}else
	{
		printf("Pedido con ID %i borrado\n", id);
	}

}
//void isWorker(char nombre[], char contrasena[]){
//    Empleado emp;
//
//    sqlite3_open("DeustoAventura.db", &db);
//
//    char sql[] = "select * from EMPLEADO where NOMBRE_EMP = ? and CONTRASENA = ?";
//
//    sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
//    sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
//    sqlite3_bind_text(stmt, 2, contrasena, strlen(contrasena), SQLITE_STATIC);
//
//    result = sqlite3_step(stmt);
//
//
//    emp.DNI = (char) sqlite3_column_text(stmt, 1);
//    emp.nombre = (char) sqlite3_column_text(stmt, 2);
//    emp.apellido = (char) sqlite3_column_text(stmt, 3);
//    emp.tfno = (int) sqlite3_column_int(stmt, 4);
//    emp.correo = (char) sqlite3_column_text(stmt, 5);
//    emp.contrasena = (char) sqlite3_column_text(stmt, 6);
//    emp.estatus = (char) sqlite3_column_text(stmt, 7);
//    emp.cod_park = (int) sqlite3_column_text(stmt, 8);
//    printf("%s\n",emp.estatus);
//
//
//    if(emp.estatus[0] == 'J')
//        {
//            printf("Se ha iniciado sesion como JEFE con el alias ");
//            puts(nombre);
//
//            printf("\n");
//
//            menuJefe();
//        } else if(emp.estatus[0] == 'E'){
//            printf("Se ha iniciado sesion como EMPLEADO con el alias ");
//            puts(nombre);
//
//            printf("\n");
//
//            menuEmpleado();
//        } else {
//            printf("Empleado no encontrado");
//            main();
//        }
//
//    sqlite3_finalize(stmt);
//
//    sqlite3_close(db);
//}
//void selectCategoria(int ct){
//	sqlite3 *db;
//	sqlite3_stmt *stmt;
//	Categoria cat1;
//	int result;
//
//	printf("%i", ct);
//
//    sqlite3_open("../Tienda.db", &db);
//
//    char sql[] = "SELECT * FROM CATEGORIA WHERE Codigo_cat = ?";
//
//    sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
//    sqlite3_bind_int(stmt, 1, ct);
//
//    result = sqlite3_step(stmt);
//
//    printf("%i", (int) sqlite3_column_int(stmt, 0));
//
//    	cat1.codigo = (int) sqlite3_column_int(stmt, 0);
//    	//cat1.nombre = malloc(sizeof(char)*(strlen((char*) sqlite3_column_text(stmt, 1))+1));
//    	//strcpy(cat1.nombre, (char*) sqlite3_column_text(stmt, 1));
//    	//printf("%s\n", cat1.nombre);
//
//
//    sqlite3_finalize(stmt);
//
//    sqlite3_close(db);
//}


//void selectProvincia(int pr) {
//    sqlite3 *db;
//    sqlite3_stmt*stmt;
//    const char tail;
//    char sql[100];
//
//    // Abrir conexión con la base de datos
//    int rc = sqlite3_open("../Tienda.db", &db);
//    if (rc != SQLITE_OK) {
//        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
//        return;
//    }
//
//    // Crear la consulta SQL para seleccionar datos de la tabla de provincias
//    sprintf(sql, "SELECT FROM PROVINCIA WHERE Codigo_prov = %d", pr);
//
//    // Preparar la consulta SQL para su ejecución
//    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, &tail);
//    if (rc != SQLITE_OK) {
//        fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(db));
//        sqlite3_close(db);
//        return;
//    }
//
//    // Ejecutar la consulta SQL
//    rc = sqlite3_step(stmt);
//
//        // Leer los datos de la fila devuelta por la consulta
//        int id = sqlite3_column_int(stmt, 0);
//        char *nombre = sqlite3_column_text(stmt, 1);
//        printf("tus muertos");
//        // Imprimir los datos leídos
//        printf("ID: %d, Nombre: %s\n", id, nombre);
//
//        // Leer la siguiente fila, si existe
//        rc = sqlite3_step(stmt);
//
//
//    // Finalizar la consulta
//    sqlite3_finalize(stmt);
//
//    // Cerrar la conexión con la base de datos
//    sqlite3_close(db);
//}

