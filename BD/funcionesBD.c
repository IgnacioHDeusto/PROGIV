#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
#include "./datos/producto/producto.h"
#include "./datos/sucursal/sucursal.h"

sqlite3 *db;
sqlite3_stmt *stmt;
int result;

void insertarCategoria(Categoria c) {
    char sql[] = "insert into Categoria (Codigo_cat, Nombre_cat ) values (NULL, ?)";

    sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
    sqlite3_bind_text(stmt, 1, c.nombre, strlen(c.nombre), SQLITE_STATIC);

    result = sqlite3_step(stmt);
        if (result != SQLITE_DONE) {
            printf("Error insertando la categoria\n");
        }else{
            printf("Categoria INSERTADA\n");
            imprimirCategoria(c);
        }

        sqlite3_finalize(stmt);
}

void insertarCiudades(Ciudad ci) {
	char sql[] = "insert into CIUDAD (Codigo_ciu, Nombre_ciu, Codigo_prov) values (NULL, ?,?)";

	    sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	    sqlite3_bind_text(stmt, 1, ci.nombre, strlen(ci.nombre), SQLITE_STATIC);
	    sqlite3_bind_int(stmt, 2, ci.cod_provincia);

	    result = sqlite3_step(stmt);
	        if (result != SQLITE_DONE) {
	            printf("Error insertando la Ciudad\n");
	        }else{
	            printf("Ciudad INSERTADA\n");
	            imprimirCiudad(ci);
	        }

	        sqlite3_finalize(stmt);
}

void insertarProvincias(Provincia prov) {
	char sql[] = "insert into PROVINCIA (Codigo_prov, Nombre_prov) values (NULL, ?)";

		    sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
		    sqlite3_bind_text(stmt, 1, prov.nombre, strlen(prov.nombre), SQLITE_STATIC);

		    result = sqlite3_step(stmt);
		        if (result != SQLITE_DONE) {
		            printf("Error insertando la Provincia\n");
		        }else{
		            printf("Provincia INSERTADA\n");
		            imprimirProvincia(prov);
		        }

		        sqlite3_finalize(stmt);
}




