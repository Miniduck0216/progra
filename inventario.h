#ifndef INVENTARIO_H
#define INVENTARIO_H

#define MAX_PRODUCTOS 100
#define MAX_STR_LEN 100
#define NUM_CAMPOS 4

#define MODELO 0
#define MARCA 1
#define ESPECIFICACIONES 2
#define ESTADO 3

void cleanStdinBuffer();
void ingresarProducto(char productos[MAX_PRODUCTOS][NUM_CAMPOS][MAX_STR_LEN], int *numProductos);
void editarProducto(char productos[MAX_PRODUCTOS][NUM_CAMPOS][MAX_STR_LEN], int numProductos);
void eliminarProducto(char productos[MAX_PRODUCTOS][NUM_CAMPOS][MAX_STR_LEN], int *numProductos);
void listarProductos(char productos[MAX_PRODUCTOS][NUM_CAMPOS][MAX_STR_LEN], int numProductos);

#endif // INVENTARIO_H