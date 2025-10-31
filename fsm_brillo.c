#include "fsm_brillo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variables de configuración
uint8_t BRILLO_MIN = 50;
uint8_t BRILLO_MED = 150;
uint8_t BRILLO_MAX = 255;
uint16_t ADC_SUBIR_A_MEDIO = 410;
uint16_t ADC_BAJAR_A_MINIMO = 250;
uint16_t ADC_SUBIR_A_MAXIMO = 800;
uint16_t ADC_BAJAR_A_MEDIO = 700;

//  Función para cargar config.conf 
void cargar_configuracion(const char *archivo)
{
    FILE *fp = fopen(archivo, "r");
    if (!fp) return; // si no encuentra el archivo, usa valores por defecto

    char nombre[32];
    int valor;

    while (fscanf(fp, "%31s %d", nombre, &valor) == 2)
    {
        if (strcmp(nombre, "BRILLO_MIN") == 0) BRILLO_MIN = valor;
        else if (strcmp(nombre, "BRILLO_MED") == 0) BRILLO_MED = valor;
        else if (strcmp(nombre, "BRILLO_MAX") == 0) BRILLO_MAX = valor;
        else if (strcmp(nombre, "ADC_SUBIR_A_MEDIO") == 0) ADC_SUBIR_A_MEDIO = valor;
        else if (strcmp(nombre, "ADC_BAJAR_A_MINIMO") == 0) ADC_BAJAR_A_MINIMO = valor;
        else if (strcmp(nombre, "ADC_SUBIR_A_MAXIMO") == 0) ADC_SUBIR_A_MAXIMO = valor;
        else if (strcmp(nombre, "ADC_BAJAR_A_MEDIO") == 0) ADC_BAJAR_A_MEDIO = valor;
    }

    fclose(fp);
}

// FSM
estados_t f_brillo_minimo(uint16_t lectura)
{
    if (lectura >= ADC_SUBIR_A_MEDIO) return BRILLO_MEDIO;
    return BRILLO_MINIMO;
}

estados_t f_brillo_medio(uint16_t lectura)
{
    if (lectura < ADC_BAJAR_A_MINIMO) return BRILLO_MINIMO;
    if (lectura >= ADC_SUBIR_A_MAXIMO) return BRILLO_MAXIMO;
    return BRILLO_MEDIO;
}

estados_t f_brillo_maximo(uint16_t lectura)
{
    if (lectura < ADC_BAJAR_A_MEDIO) return BRILLO_MEDIO;
    return BRILLO_MAXIMO;
}

