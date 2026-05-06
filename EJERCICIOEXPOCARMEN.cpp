/**
 * @file expocarmen.cpp
 * @brief Sistema simple de ventas para una chicharronería.
 * @author Carmen Aida  Valiente Quiroz -  Abigail Amira Bautista Aguirre - Andre  Jesus gomez Linares  
 * @date 05-05-2026
 * 
 * Este programa permite gestionar la venta de productos utilizando contenedores
 * de tipo map para asociar IDs con nombres y precios. Incluye validación de pago.
 */

#include <iostream>
#include <map>
#include <string>
#include <limits> // Para limpiar el búfer

using std::cout;
using std::cin;
using std::string;
using std::map;

int main() {
    // Definición del Mapa (Nuestra Base de Datos)
    map<int, string> nombres;
    map<int, double> precios;

    nombres[1] = "Pan con Chicharron"; precios[1] = 12.50;
    nombres[2] = "Tamal Especial";     precios[2] = 5.00;
    nombres[3] = "Chicharron por Kilo"; precios[3] = 48.00;
    nombres[4] = "Camote Frito";       precios[4] = 3.50;

    cout << "--- SISTEMA DE VENTAS: C++hicharroneria ---\n";
    for (const auto& par : nombres) {
        cout << par.first << ") " << par.second << " - S/ " << precios[par.first] << "\n";
    }
    cout << "5) Salir\n";

    // 1. ELECCIÓN POR OPCIÓN
    int opcion;
    cout << "\nSeleccione una opcion (1-5): ";
    cin >> opcion; 

    if (opcion >= 1 && opcion <= 4) {
        string plato = nombres[opcion];
        double precio = precios[opcion];
        double pago;

        cout << "\nHas elegido: " << plato << "\n";
        cout << "Total a pagar: S/ " << precio << "\n";
        
        // 2. LÓGICA DE PAGO
        do {
            cout << "Ingrese su pago: S/ ";
            cin >> pago;
            if (pago < precio) {
                cout << "Monto insuficiente. Falta: S/ " << precio - pago << "\n";
            }
        } while (pago < precio);

        // 3. GENERACIÓN DE BOLETA
        cout << "\n========= BOLETA DE VENTA =========\n";
        cout << " PRODUCTO: " << plato << "\n";
        cout << " TOTAL:    S/ " << precio << "\n";
        cout << " VUELTO:   S/ " << pago - precio << "\n";
        cout << "===================================\n";

        // 4. ESTADOS FINALES
        cout << "\n[COCINA]: Preparando      su " << plato << "...\n";
        cout << "[SISTEMA]: ¡Pedido entregado! Vuelva pronto.\n";

    } else if (opcion == 5) {
        cout << "Saliendo del sistema...\n";
    } else {
        cout << "Opcion no valida.\n";
    }

    return 0;
}
