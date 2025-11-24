#include <stdio.h>
#include <string.h>
#include "agenda-equipo-ñ.h" // <<--- ¡CORRECCIÓN: Nuevo nombre de cabecera!

void inicia_la_agenda(agenda *a) {
    a->cantidad = 0;
}

void leer_contacto(contacto *c) {
    printf("Nombre: ");
    scanf("%19s", c->nombre);

    printf("Telefono: ");
    scanf("%d", &c->telefono);

    printf("Tipo (1 casa, 2 trabajo, 3 cel, 4 fax): ");
    scanf("%d", &c->tipo_tel);
}

void mostrar_al_contacto(contacto *c) {
    printf("Nombre: %s\n", c->nombre);
    printf("Telefono: %d\n", c->telefono);
    printf("Tipo: %d\n", c->tipo_tel);
}

void agrega_contactos(agenda *a, contacto c) {
    if (a->cantidad < MAXIMO_DE_CONTACTOS) {
        a->lista[a->cantidad] = c;
        a->cantidad++;
    } else {
        printf("La agenda está llena, no se pueden agregar mas.\n");
    }
}

int busca_el_contacto(agenda *a, char nombre[]) {
    for (int i = 0; i < a->cantidad; i++)
        if (strcmp(a->lista[i].nombre, nombre) == 0)
            return i;
    return -1;
}

int buscar_contacto_x_telefono(agenda *a, int numero) {
    for (int i = 0; i < a->cantidad; i++)
        if (a->lista[i].telefono == numero)
            return i;
    return -1;
}

void imprimir_agenda(agenda a) {
    printf("\n--- CONTACTOS ---\n");
    for (int i = 0; i < a.cantidad; i++)
        mostrar_al_contacto(&a.lista[i]);
}

void ordenan_contactos(agenda *a) {
    for (int i = 0; i < a->cantidad - 1; i++)
        for (int j = i + 1; j < a->cantidad; j++)
            if (strcmp(a->lista[i].nombre, a->lista[j].nombre) > 0) {
                contacto tmp = a->lista[i];
                a->lista[i] = a->lista[j];
                a->lista[j] = tmp;
            }
}

void ordenan_contactos_inversamente(agenda *a) {
    for (int i = 0; i < a->cantidad - 1; i++)
        for (int j = i + 1; j < a->cantidad; j++)
            if (strcmp(a->lista[i].nombre, a->lista[j].nombre) < 0) {
                contacto tmp = a->lista[i];
                a->lista[i] = a->lista[j];
                a->lista[j] = tmp;
            }
}

void guardar_contactos(char *filename, agenda a) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        printf("No se pudo guardar el archivo.\n");
        return;
    }
    fwrite(&a, sizeof(agenda), 1, f);
    fclose(f);
    printf("Agenda guardada!\n");
}

void cargar_contactos(char *filename, agenda *a) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("No se pudo leer el archivo.\n");
        return;
    }
    fread(a, sizeof(agenda), 1, f);
    fclose(f);
    printf("Agenda cargada!\n");
}