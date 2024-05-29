#include <stdio.h>
#include <string.h>
#include "inventario.h"

void cleanStdinBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ingresarProducto(char productos[MAX_PRODUCTOS][NUM_CAMPOS][MAX_STR_LEN], int *numProductos) {
    if (*numProductos >= MAX_PRODUCTOS) {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingrese el modelo del producto: ");
    scanf("%s", productos[*numProductos][MODELO]);
    cleanStdinBuffer();

    printf("Ingrese la marca del producto: ");
    scanf("%s", productos[*numProductos][MARCA]);
    cleanStdinBuffer();

    printf("Ingrese las especificaciones técnicas del producto: ");
    scanf("%s", productos[*numProductos][ESPECIFICACIONES]);
    cleanStdinBuffer();

    printf("Ingrese el estado del producto: ");
    scanf("%s", productos[*numProductos][ESTADO]);
    cleanStdinBuffer();

    (*numProductos)++;
}

void editarProducto(char productos[MAX_PRODUCTOS][NUM_CAMPOS][MAX_STR_LEN], int numProductos) {
    if (numProductos == 0) {
        printf("No hay productos para editar.\n");
        return;
    }

    int index;
    printf("Ingrese el índice del producto a editar (0 a %d): ", numProductos - 1);
    scanf("%d", &index);
    cleanStdinBuffer();

    if (index < 0 || index >= numProductos) {
        printf("Índice inválido.\n");
        return;
    }

    char opcion;
    printf("¿Desea editar el producto? (s/n): ");
    scanf("%c", &opcion);
    cleanStdinBuffer();

    if (opcion == 'n' || opcion == 'N') {
        printf("Regresando al menú principal...\n");
        return;
    }

    if (opcion == 's' || opcion == 'S') {
        printf("Ingrese el nuevo modelo del producto: ");
        scanf("%s", productos[index][MODELO]);
        cleanStdinBuffer();

        printf("Ingrese la nueva marca del producto: ");
        scanf("%s", productos[index][MARCA]);
        cleanStdinBuffer();

        printf("Ingrese las nuevas especificaciones técnicas del producto: ");
        scanf("%s", productos[index][ESPECIFICACIONES]);
        cleanStdinBuffer();

        printf("Ingrese el nuevo estado del producto: ");
        scanf("%s", productos[index][ESTADO]);
        cleanStdinBuffer();
    } else {
        printf("Opción no válida. Regresando al menú principal...\n");
    }
}

void eliminarProducto(char productos[MAX_PRODUCTOS][NUM_CAMPOS][MAX_STR_LEN], int *numProductos) {
    if (*numProductos == 0) {
        printf("No hay productos para eliminar.\n");
        return;
    }

    int index;
    printf("Ingrese el índice del producto a eliminar (0 a %d): ", *numProductos - 1);
    scanf("%d", &index);
    cleanStdinBuffer();

    if (index < 0 || index >= *numProductos) {
        printf("Índice inválido.\n");
        return;
    }

    for (int i = index; i < *numProductos - 1; i++) {
        for (int j = 0; j < NUM_CAMPOS; j++) {
            strcpy(productos[i][j], productos[i + 1][j]);
        }
    }

    (*numProductos)--;
}

void listarProductos(char productos[MAX_PRODUCTOS][NUM_CAMPOS][MAX_STR_LEN], int numProductos) {
    if (numProductos == 0) {
        printf("No hay productos para listar.\n");
        return;
    }

    for (int i = 0; i < numProductos; i++) {
        printf("Producto %d:\n", i);
        printf("  Modelo: %s\n", productos[i][MODELO]);
        printf("  Marca: %s\n", productos[i][MARCA]);
        printf("  Especificaciones Técnicas: %s\n", productos[i][ESPECIFICACIONES]);
        printf("  Estado: %s\n", productos[i][ESTADO]);
    }
}