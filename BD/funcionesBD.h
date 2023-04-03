#ifndef BD_FUNCIONESBD_H_
#define BD_FUNCIONESBD_H_

void insertarCategoria(Categoria c);

void insertarCiudades(Ciudad ci);

void insertarProvincias(Provincia prov);

void selectCategoria(int ct);

//int selectCategoria(sqlite3 *db, int ct);

void selectProvincia(int pr);

#endif /* BD_FUNCIONESBD_H_ */
