#include <stdio.h>
#include <string.h>
#include "agenda-equipo-ñ.h"

int main() {
    agenda a;
    inicia_la_agenda(&a);

    int opcion;
    char nombre_buscado[20];
    int tel_buscado;
    contacto c;

    do {
        printf("\n--- MENU AGENDA ---\n");
        printf("1. Agregar contacto\n");
        printf("2. Buscar por nombre\n");
        printf("3. Buscar por telefono\n");
        printf("4. Mostrar agenda\n");
        printf("5. Ordenar A-Z\n");
        printf("6. Ordenar Z-A\n");
        printf("7. Guardar agenda\n");
        printf("8. Cargar agenda\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {

        case 1:
            leer_contacto(&c);
            agrega_contactos(&a, c);
            break;

        case 2:
            printf("Nombre a buscar: ");
            scanf("%19s", nombre_buscado);

            int idx;
            idx = busca_el_contacto(&a, nombre_buscado);

            if (idx >= 0)
                mostrar_al_contacto(&a.lista[idx]);
            else
                printf("No encontrado.\n");

            break;

        case 3:
            printf("Telefono a buscar: ");
            scanf("%d", &tel_buscado);

            idx = buscar_contacto_x_telefono(&a, tel_buscado);

            if (idx >= 0)
                mostrar_al_contacto(&a.lista[idx]);
            else
                printf("No encontrado.\n");

            break;

        case 4:
            imprimir_agenda(a);
            break;

        case 5:
            ordenan_contactos(&a);
            printf("Agenda ordenada A-Z.\n");
            break;

        case 6:
            ordenan_contactos_inversamente(&a);
            printf("Agenda ordenada Z-A.\n");
            break;

        case 7:
            guardar_contactos("agenda.dat", a);
            break;

        case 8:
            cargar_contactos("agenda.dat", &a);
            break;

        case 0:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opcion invalida.\n");
        }

    } while (opcion != 0);

    return 0;
}