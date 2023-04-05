#include <stdio.h>
#include <string.h>
#include "../datos/sucursal/sucursal.h"
#include "../sqlite/sqlite3.h"
#include "../datos/producto/producto.h"
#include "../datos/trabajador/trabajador.h"
#include "../datos/pedido/pedido.h"
#include "../datos/cliente/cliente.h"
#include <stdlib.h>

sqlite3 *db;
sqlite3_stmt *stmt;
int result;

char* load_config(char* filename, char* buscar) {
    FILE* archivo;
    char linea[100];
    char* igual;
    char buscar2[20];
    fflush(stdout);
    archivo = fopen(filename, "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return NULL;
    }
    fflush(stdout);
    char* resultado = NULL;
    while (fgets(linea, 100, archivo)) {
        int i = 0;
        while (linea[i] != '=') {
            buscar2[i] = linea[i];
            i++;
        }
        buscar2[i] = '\0';

        if (strcmp(buscar, buscar2) == 0) {
            igual = strchr(linea, '=');
            if (igual != NULL) {
                int longitud = strlen(igual + 1);
                resultado = (char*) realloc(resultado, longitud * sizeof(char));
                if (resultado == NULL) {
                    printf("Error al asignar memoria.\n");
                    return NULL;
                }
                fflush(stdout);
                strncpy(resultado, igual + 1, longitud);
                resultado[longitud - 1] = '\0';
            }
        }
    }

    fclose(archivo);
    fflush(stdout);
    return resultado;
}
void iniciarBD(){

    char*ruta=load_config("ficheros/Config.txt","ruta");

    sqlite3_open(ruta, &db);
    free(ruta);

}

void insertarCategoria(Categoria c) {
	char* error = 0;
	int rc;

    char sql[] = "insert into CATEGORIA (Codigo_cat, Nombre_cat ) values (?, ?)";

   	            char query[400];
   	            sprintf(query, "INSERT INTO CATEGORIA ( Codigo_cat, Nombre_cat) VALUES ('%d', '%s')", c.codigo, c.nombre);

   	            rc = sqlite3_exec(db, query, 0, 0, &error);

   	            if (rc == SQLITE_OK) {
   	                printf("Categoria insertada correctamente\n");
   	            } else {
   	                printf("Error al insertar Categoria: %s\n", error);
   	            }

   	        sqlite3_finalize(stmt);
}
void insertarCiudad(Ciudad ciu) {

	 char* error = 0;
	 int rc;



	            char query[400];
	            sprintf(query, "INSERT INTO CIUDAD ( Codigo_ciu, Nombre_ciu, Codigo_prov) VALUES ('%d', '%s', '%d')", ciu.codigo, ciu.nombre, ciu.cod_provincia);

	            rc = sqlite3_exec(db, query, 0, 0, &error);

	            if (rc == SQLITE_OK) {
	                printf("Ciudad insertada correctamente\n");
	            } else {
	                printf("Error al insertar ciudad: %s\n", error);
	            }
	        sqlite3_finalize(stmt);


	}

void insertarProvincia(Provincia prov) {

	 char* error = 0;
	 int rc;



	            char query[400];
	            sprintf(query, "INSERT INTO PROVINCIA ( Codigo_prov, Nombre_prov) VALUES ('%d', '%s')", prov.codigo, prov.nombre);

	            rc = sqlite3_exec(db, query, 0, 0, &error);

	            if (rc == SQLITE_OK) {
	                printf("Provincia insertada correctamente\n");
	            } else {
	                printf("Error al insertar provincia: %s\n", error);
	            }
	        sqlite3_finalize(stmt);
	}

void insertarCliente(Cliente clt) {

	char* error = 0;
	int rc;

	char query[400];
	sprintf(query, "INSERT INTO CLIENTE ( DNI_clt, Nombre_clt, Direccion, Tlf_clt, Codigo_ciu, Contrasena_clt) VALUES ('%s', '%s', '%s', '%d', '%d', '%s')", clt.dni, clt.nombre, clt.direccion, clt.telefono, clt.cod_ciudad, clt.contrasena);

	rc = sqlite3_exec(db, query, 0, 0, &error);

	if (rc == SQLITE_OK) {
		printf("Cliente insertado correctamente\n");
	} else {
		printf("Error al insertar cliente: %s\n", error);
	}
	        sqlite3_finalize(stmt);
	}

void BorrarProvincia(int id){
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
		sqlite3_finalize(stmt);

}

void crearGestor(Trabajador t) {
	char* error = 0;
	int rc;

	char query[400];
	sprintf(query, "INSERT INTO TRABAJADOR ( Cod_trab, Usuario_trab, Contrasena_trab) VALUES (NULL, '%s', '%s')", t.Nombre_trab, t.Contrasena_trab);

	rc = sqlite3_exec(db, query, 0, 0, &error);

	if (rc == SQLITE_OK) {
		printf("Trabajador insertado correctamente\n");
	} else {
		printf("Error al insertar trabajador: %s\n", error);
	}

	sqlite3_finalize(stmt);
}

void crearProducto(Producto p){
	char* error = 0;
		 	int rc;
		 	sqlite3_close(db);
			rc = sqlite3_open("Tienda.db", &db);

			if (rc == SQLITE_OK) {

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

}

int comprobarUsuario(char usuario[], char contrasena[]) {
	int resultado = 0;

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

    sqlite3_finalize(stmt);

    return resultado;
}


void MostrarTrabajadores() {
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

void MostrarClientes() {
    char sql[] = "SELECT * FROM CLIENTE";

        sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

        printf("\n");
        printf("Mostrando clientes:\n");

        do {
            result = sqlite3_step(stmt) ;
            if (result == SQLITE_ROW) {
                printf("%s con DNI %s con residencia en %s y teléfono %i\n", (char*) sqlite3_column_text(stmt, 1), (char*) sqlite3_column_text(stmt, 0), (char*) sqlite3_column_text(stmt, 2), (int) sqlite3_column_int(stmt, 3));
            }
        } while (result == SQLITE_ROW);
        printf("\n");

        sqlite3_finalize(stmt);
}

void BorrarTrabajador(int id)
{
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
	sqlite3_finalize(stmt);
}

void ListaProductos() {
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

	sqlite3_finalize(stmt);
}
void BorrarAlmacen(int id)
{
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
	sqlite3_finalize(stmt);
}
void insertarAlmacen(Almacen al) {
    char error = 0;
    int rc;
    comprobarCiudad(al.cod_ciu);
    char query[400];
    sprintf(query, "INSERT INTO ALMACEN ( Id_alm, Nombre, Direccion, Tlf_alm, Codigo_ciu) VALUES (NULL, '%s', '%s', '%i', '%i')", al.nombre, al.direccion, al.telefono, al.cod_ciu);

    rc = sqlite3_exec(db, query, 0, 0, &error);

    if (rc == SQLITE_OK) {
    	printf("Almacen insertado correctamente\n");
    } else {
        printf("Error al insertar el almacen: %s\n", error);
    }

    sqlite3_finalize(stmt);

}

void ListaAlmacenes() {
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
    char error = 0;
    int rc;

    int resultado = comprobarStock(id_prod, id_alm);
    if (resultado == 1) {
    	char sql[] = "UPDATE EXISTENCIAS SET Stock = Stock + ? WHERE Id_prod = ? AND Id_alm = ?";
		sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

		sqlite3_bind_int(stmt, 1, stock);
		sqlite3_bind_int(stmt, 2, id_prod);
		sqlite3_bind_int(stmt, 3, id_alm);

		result = sqlite3_step(stmt);
		if (stock > 0) {
			if (result != SQLITE_DONE)
			{
				printf("Error añadiendo stock \n");
			}else
			{
				printf("%i unidades del producto %i en el almacen %i añadidas\n", stock, id_prod, id_alm);
			}
		}

	} else {
		char query[400];
		sprintf(query, "INSERT INTO EXISTENCIAS (Stock, Id_prod, Id_alm) VALUES ('%i', '%i', '%i')", stock, id_prod, id_alm);

		rc = sqlite3_exec(db, query, 0, 0, &error);

			if (rc == SQLITE_OK) {
				printf("Stock insertado correctamente\n");
			} else {
				printf("Error al insertar el stock: %s\n", error);
			}
		}

        sqlite3_finalize(stmt);

}
int comprobarStock(int id_prod, int id_alm) {
	int resultado = 0;

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

    return resultado;
}

void ConsultarStock() {
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

void BorrarStock(int id_prod){
	char sql[] = "delete from EXISTENCIAS where Id_prod = ?";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, id_prod);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error borrando stock\n");
	}else
	{
		printf("Stock del producto %i en el almacen %i borrado\n", id_prod);
	}
	sqlite3_finalize(stmt);
}

void borrarStock(int id_prod, int id_alm){
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
		sqlite3_finalize(stmt);
}

void insertarPedido(Pedido ped){
	    char error = 0;
	    int rc;

	    char query[400];
	    char* fecha = fechaToChar(ped.fecha);
	    sprintf(query, "INSERT INTO PEDIDO ( N_PEDIDO, Fecha, DNI_clt) VALUES (NULL, '%s', '%s')", fecha, ped.dni);

	    rc = sqlite3_exec(db, query, 0, 0, &error);

	    if (rc == SQLITE_OK) {
	    printf("Pedido insertado correctamente\n");
	        } else {
	        printf("Error al insertar el almacen: %s\n", error);
	                }


	        sqlite3_finalize(stmt);
}

void listaPedidos(){
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

void EnviarPedido(int id)
{
	char sql[] = "delete from PEDIDO where N_PEDIDO = ?";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, id);

	result = sqlite3_step(stmt);

	sqlite3_finalize(stmt);
}

int comprobarPedido(int n_ped) {
	int resultado = 0;

	char sql[] = "SELECT * FROM PEDIDO WHERE N_PEDIDO = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, n_ped);

	result = sqlite3_step(stmt);

	if(result == SQLITE_ROW) {
		resultado = 1;
	} else {
		resultado = 0;
	}

    sqlite3_finalize(stmt);

    return resultado;
}
int comprobarAlmacen(int id_alm){
	int resultado = 0;

	char sql[] = "SELECT * FROM ALMACEN WHERE Id_alm = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, id_alm);

	result = sqlite3_step(stmt);

	if(result == SQLITE_ROW) {
		resultado = 1;
	} else {
		resultado = 0;
	}

	sqlite3_finalize(stmt);

	return resultado;
}
int comprobarProducto(int id_prod){
	int resultado = 0;

	char sql[] = "SELECT * FROM PRODUCTO WHERE ID_prod = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, id_prod);

	result = sqlite3_step(stmt);

	if(result == SQLITE_ROW) {
		resultado = 1;
	} else {
		resultado = 0;
	}

	sqlite3_finalize(stmt);

	return resultado;
}
int comprobarCiudad(int cod_ciu){
	int resultado = 0;

	char sql[] = "SELECT * FROM CIUDAD WHERE Codigo_ciu = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, cod_ciu);

	result = sqlite3_step(stmt);

	if(result == SQLITE_ROW) {
		resultado = 1;
	} else {
		resultado = 0;
	}

	sqlite3_finalize(stmt);

	return resultado;
}
int comprobarCategoria(int cod_cat){
	int resultado = 0;

	char sql[] = "SELECT * FROM CATEGORIA WHERE Codigo_cat = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, cod_cat);

	result = sqlite3_step(stmt);

	if(result == SQLITE_ROW) {
		resultado = 1;
	} else {
		resultado = 0;
	}

	sqlite3_finalize(stmt);

	return resultado;
}
int productosPedido(int n_ped){
	char sql[] = "SELECT P.N_PEDIDO, P.Fecha, P.DNI_clt, CP.ID_prod, CP.Cantidad FROM COMPRA_PRDCT CP, PEDIDO P WHERE CP.N_PEDIDO = ? AND CP.N_PEDIDO = P.N_PEDIDO" ;
	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, n_ped);
	printf("Mostrando productos del pedido %i:\n", n_ped);
	int i = 0;
	int j[100];
	do {
		result = sqlite3_step(stmt);

		if (i == 0) {
			printf("Pedido: %i, Fecha: %s, DNI: %s (  ", (int)sqlite3_column_int(stmt, 0), (char*)sqlite3_column_text(stmt, 1), (char*)sqlite3_column_text(stmt, 2));
		}
		if (result == SQLITE_ROW) {
			int id_prod = (int)sqlite3_column_int(stmt, 3);
			j[i] = id_prod;
			printf("Producto: %i --> Cantidad: %i  ", id_prod, (int)sqlite3_column_int(stmt, 4));

		}
		i++;

	} while (result == SQLITE_ROW);
	i--;
	printf(")\n");

	sqlite3_finalize(stmt);
	int f = 0;
	for (int k = 0; k < i; ++k) {
		f = ComprobarStockPedido(j[k], n_ped, i, f);
	}
	if (f == i) {
		for (int k = 0; k < i; ++k) {
			if (k == i-1) {
				ComprobarStockPedido(j[k], n_ped, -1, -1);
			} else {
				ComprobarStockPedido(j[k], n_ped, -1, 0);
			}

		}
	} else {
		printf("Falta stock para los productos del pedido nº%i\n", n_ped);
	}
	return i;
}

void insertarCompraProd(CompraProducto cp) {
    char error = 0;
    int rc;

    char query[400];
    sprintf(query, "INSERT INTO COMPRA_PRDCT ( ID_prod, N_PEDIDO, Cantidad) VALUES ('%i', '%i', '%i')", cp.id_producto, cp.n_pedido, cp.cant);

    rc = sqlite3_exec(db, query, 0, 0, &error);

    if (rc == SQLITE_OK) {
    printf("Compra de producto insertado correctamente\n");
        } else {
        printf("Error al insertar el compra de producto: %s\n", error);
                }
        sqlite3_finalize(stmt);
}
void BorrarCompraProd(int id_prod, int n_ped){
			char sql[] = "delete from COMPRA_PRDCT WHERE ID_prod = ? AND N_PEDIDO = ?";
			sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

			sqlite3_bind_int(stmt, 1, id_prod);
			sqlite3_bind_int(stmt, 2, n_ped);

			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE)
			{
				printf("Error borrando compra de producto\n");
			}
			sqlite3_finalize(stmt);
}
void BorrarProdCompra(int id_prod){
	char sql[] = "delete from COMPRA_PRDCT WHERE ID_prod = ?";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, id_prod);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error borrando compra de producto\n");
	}
	sqlite3_finalize(stmt);
}
int ComprobarStockPedido(int id_prod, int n_ped, int j, int i){
		char sql[] = "SELECT CP.ID_prod, CP.Cantidad, E.Id_alm, E.Stock FROM COMPRA_PRDCT CP, EXISTENCIAS E WHERE CP.N_PEDIDO = ? AND CP.ID_prod = ? AND CP.ID_prod = E.Id_prod AND CP.Cantidad <= E.Stock GROUP BY CP.Id_prod" ;
		int cant = 0;
		int id_alm = 0;
		sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
		sqlite3_bind_int(stmt, 1, n_ped);
		sqlite3_bind_int(stmt, 2, id_prod);
		do {
			result = sqlite3_step(stmt);
			if (result == SQLITE_ROW) {
				if (j == -1) {
					cant = -(int)sqlite3_column_int(stmt, 1);
					id_alm = (int)sqlite3_column_int(stmt, 2);
				}else{
					printf("%i unidades del producto %i listas para enviar\n", (int)sqlite3_column_int(stmt, 1), id_prod);
					i++;
				}
			}


		} while (result == SQLITE_ROW);
		sqlite3_finalize(stmt);
		if (j == -1) {
			aumentarStock(cant, id_prod, id_alm);
			comprobarStockEs0(id_prod, id_alm);
			BorrarCompraProd(id_prod, n_ped);
			EnviarPedido(n_ped);
			if (i == -1){
				printf("Enviando pedido...\n");
				printf("Pedido con Nº %i enviado.\n", n_ped);
			}

		}
		return i;
}
void comprobarStockEs0(int id_prod, int id_alm){
			char sql[] = "delete from EXISTENCIAS where Id_prod = ? AND Id_alm = ? AND Stock <= 0";
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
			sqlite3_finalize(stmt);
}
void editarPrecio(int id_prod, int precio){
	if (precio > 0) {
		char sql[] = "UPDATE PRODUCTO SET Precio = ? WHERE ID_prod = ?";
		sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

		sqlite3_bind_int(stmt, 1, precio);
		sqlite3_bind_int(stmt, 2, id_prod);

		result = sqlite3_step(stmt);

		if (result != SQLITE_DONE)
		{
			printf("Error editando precio \n");
		}else
		{
			printf("El nuevo precio del producto %i es %i\n", id_prod, precio);
		}
	} else{
		printf("El precio tiene que ser positivo");
	}
	sqlite3_finalize(stmt);
}

void listaCategorias(){
	char sql[] = "select * from CATEGORIA";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

	printf("Mostrando Categorias:\n");
	printf("\n");

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("ID: %i --> %s\n", (int) sqlite3_column_int(stmt, 0), (char*) sqlite3_column_text(stmt, 1));
		}
	} while (result == SQLITE_ROW);

	sqlite3_finalize(stmt);
}

