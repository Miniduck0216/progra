#include <stdio.h>
#include "inventario.h"

int main() {
    char productos[MAX_PRODUCTOS][NUM_CAMPOS][MAX_STR_LEN];
    int numProductos = 0;
    int opcion;

    while (1) {
        printf("\nMenú de Inventario:\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        cleanStdinBuffer();

        switch (opcion) {
            case 1:
                ingresarProducto(productos, &numProductos);
                break;
            case 2:
                editarProducto(productos, numProductos);
                break;
            case 3:
                eliminarProducto(productos, &numProductos);
                break;
            case 4:
                listarProductos(productos, numProductos);
                break;
            case 5:
                printf("Saliendo...\n");
                return 0;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}