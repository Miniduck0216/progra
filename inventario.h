#ifndef INVENTARIO_H
#define INVENTARIO_H

#define MAX_PRODUCTOS 100
#define MAX_CADENA 50

typedef struct {
    char modelo[MAX_CADENA];

    char marca[MAX_CADENA];

    char especificaciones[MAX_CADENA];

    char estado[MAX_CADENA];
} Producto;

void ingresarProducto(Producto productos[][4], int *numProductos);

void editarProducto(Producto productos[][4], int numProductos);

void eliminarProducto(Producto productos[][4], int *numProductos);

void listarProductos(Producto productos[][4], int numProductos);

#endif