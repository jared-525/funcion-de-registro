#include <stdio.h>
#include <stdlib.h>

float saldo = 0.0; // Saldo inicial

void mostrar_menu_principal() {
    printf("Seleccione una opcion:\n");
    printf("1. Usuario\n");
    printf("2. Administrador\n");
}

void mostrar_menu_usuario() {
    printf("Seleccione una opcion:\n");
    printf("1. Depositar dinero\n");
    printf("2. Retirar dinero\n");
    printf("3. Ver saldo\n");
    printf("4. Salir\n");
}

void mostrar_menu_administrador() {
    printf("Seleccione una opcion:\n");
    printf("1. Ver saldo total\n");
    printf("2. Salir\n");
}

void depositar_dinero() {
    float cantidad;
    printf("Ingrese la cantidad a depositar: ");
    scanf("%f", &cantidad);
    if (cantidad > 0) {
        saldo += cantidad;
        printf("Se han depositado %.2f. Nuevo saldo: %.2f\n", cantidad, saldo);
    } else {
        printf("La cantidad a depositar debe ser positiva.\n");
    }
}

void retirar_dinero() {
    float cantidad;
    printf("Ingrese la cantidad a retirar: ");
    scanf("%f", &cantidad);
    if (cantidad > 0 && cantidad <= saldo) {
        saldo -= cantidad;
        printf("Se han retirado %.2f. Nuevo saldo: %.2f\n", cantidad, saldo);
    } else if (cantidad > saldo) {
        printf("No hay suficiente saldo para retirar esa cantidad.\n");
    } else {
        printf("La cantidad a retirar debe ser positiva.\n");
    }
}

int main() {
    while (1) {
        mostrar_menu_principal();
        int opcion;
        printf("Seleccione una opcion (1 o 2): ");
        scanf("%d", &opcion);
        
        if (opcion == 1) { // Modo Usuario
            while (1) {
                mostrar_menu_usuario();
                int opcion_usuario;
                printf("Seleccione una opcion (1-4): ");
                scanf("%d", &opcion_usuario);
                
                if (opcion_usuario == 1) {
                    depositar_dinero();
                } else if (opcion_usuario == 2) {
                    retirar_dinero();
                } else if (opcion_usuario == 3) {
                    printf("Saldo actual: %.2f\n", saldo);
                } else if (opcion_usuario == 4) {
                    printf("Saliendo del modo usuario...\n");
                    break; // Salir del modo usuario
                } else {
                    printf("Opción no válida, por favor seleccione entre 1 y 4.\n");
                }
            }
        } else if (opcion == 2) { // Modo Administrador
            while (1) {
                mostrar_menu_administrador();
                int opcion_admin;
                printf("Seleccione una opcion (1-2): ");
                scanf("%d", &opcion_admin);
                
                if (opcion_admin == 1) {
                    printf("Saldo total del sistema: %.2f\n", saldo);
                } else if (opcion_admin == 2) {
                    printf("Saliendo del modo administrador...\n");
                    break; // Salir del modo administrador
                } else {
                    printf("Opcion no válida, por favor seleccione entre 1 y 2.\n");
                }
            }
        } else {
            printf("Opcion no válida, por favor seleccione 1 o 2.\n");
        }
    }

    return 0;
}



