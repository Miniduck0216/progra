#include <stdio.h>
#include <string.h>
#include "inventario.h"

void ingresarProducto(Producto productos[][4], int *numProductos) {

    if (*numProductos >= MAX_PRODUCTOS) {

        printf("No se pueden agregar más productos.\n");
        return;

    }

    printf("Ingrese el tipo del producto: ");
    scanf("%s", productos[*numProductos][0].modelo);

    printf("Ingrese la marca del producto: ");
    scanf("%s", productos[*numProductos][1].marca);

    printf("Ingrese las especificaciones técnicas del producto: ");
    scanf("%s", productos[*numProductos][2].especificaciones);

    printf("Ingrese el estado del producto: ");
    scanf("%s", productos[*numProductos][3].estado);

    (*numProductos)++;
}

void editarProducto(Producto productos[][4], int numProductos) {

    if (numProductos == 0) {

        printf("No hay productos para editar.\n");
        return;
    }

    int index;

    printf("Ingrese el índice del producto a editar (0 a %d): ", numProductos - 1);
    scanf("%d", &index);

    if (index < 0 || index >= numProductos) {

        printf("Índice inválido.\n");
        return;
    }

    printf("Ingrese el nuevo modelo del producto: ");
    scanf("%s", productos[index][0].modelo);

    printf("Ingrese la nueva marca del producto: ");
    scanf("%s", productos[index][1].marca);

    printf("Ingrese las nuevas especificaciones técnicas del producto: ");
    scanf("%s", productos[index][2].especificaciones);

    printf("Ingrese el nuevo estado del producto: ");
    scanf("%s", productos[index][3].estado);
}

void eliminarProducto(Producto productos[][4], int *numProductos) {

    if (*numProductos == 0) {

        printf("No hay productos para eliminar.\n");
        return;
    }

    int index;

    printf("Ingrese el índice del producto a eliminar (0 a %d): ", *numProductos - 1);
    scanf("%d", &index);

    if (index < 0 || index >= *numProductos) {

        printf("Índice inválido.\n");
        return;
    }

    for (int i = index; i < *numProductos - 1; i++) {

        productos[i][0] = productos[i + 1][0];

        productos[i][1] = productos[i + 1][1];

        productos[i][2] = productos[i + 1][2];

        productos[i][3] = productos[i + 1][3];
    }

    (*numProductos)--;
}

void listarProductos(Producto productos[][4], int numProductos) {

    if (numProductos == 0) {

        printf("No hay productos para listar.\n");
        return;
    }

    for (int i = 0; i < numProductos; i++) {
        printf("Producto %d:\n", i);

        printf("  Modelo: %s\n", productos[i][0].modelo);

        printf("  Marca: %s\n", productos[i][1].marca);

        printf("  Especificaciones Técnicas: %s\n", productos[i][2].especificaciones);

        printf("  Estado: %s\n", productos[i][3].estado);
    }
}