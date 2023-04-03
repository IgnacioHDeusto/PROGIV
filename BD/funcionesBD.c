#include <stdio.h>
#include <string.h>
#include "../datos/sucursal/sucursal.h"
#include "../sqlite/sqlite3.h"
#include "../datos/producto/producto.h"
#include "../datos/trabajador/trabajador.h"
#include <stdlib.h>

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

void insertarProvincias(Provincia prov) {
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
	                printf("Provincia insertado correctamente\n");
	            } else {
	                printf("Error al insertar provincia: %s\n", error);
	            }
	        } else {
	            printf("Error al conectar a la base de datos: %s\n", sqlite3_errmsg(db));
	        }

	        sqlite3_finalize(stmt);
	        sqlite3_close(db);

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
			        sqlite3_close(db);
}



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

