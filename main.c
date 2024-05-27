#include <stdio.h>
#include "inventario.h"

int main() {
    Producto productos[MAX_PRODUCTOS][4];

    int numProductos = 0;
    int opcion;

    do {
        printf("Sistema de Inventarios de Productos Tecnológicos \n");

        printf("1. Ingresar producto\n");

        printf("2. Editar producto\n");

        printf("3. Eliminar producto\n");

        printf("4. Listar productos\n");

        printf("5. Salir\n");

        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

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
                printf("Saliendo del sistema.\n");
                break;

            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 5);

    return 0;
}