#ifndef AGENDA_H
#define AGENDA_H

#define MAXIMO_DE_CONTACTOS 100

typedef struct {
    char nombre[20];
    int telefono;
    int tipo_tel;
} contacto;

typedef struct {
    contacto lista[MAXIMO_DE_CONTACTOS];
    int cantidad;
} agenda;

void inicia_la_agenda(agenda *a);
void leer_contacto(contacto *c);
void mostrar_al_contacto(contacto *c);
void agrega_contactos(agenda *a, contacto c);
int busca_el_contacto(agenda *a, char nombre[]);
int buscar_contacto_x_telefono(agenda *a, int numero);
void imprimir_agenda(agenda a);
void ordenan_contactos(agenda *a);
void ordenan_contactos_inversamente(agenda *a);
void guardar_contactos(char *filename, agenda a);
void cargar_contactos(char *filename, agenda *a);

#endif
