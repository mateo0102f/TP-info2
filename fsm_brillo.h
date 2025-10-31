#ifndef FSM_BRILLO_H
#define FSM_BRILLO_H

#include <stdint.h>

// Estados de la FSM
typedef enum {
    BRILLO_MINIMO = 0,
    BRILLO_MEDIO = 1,
    BRILLO_MAXIMO = 2
} estados_t;

// Variables de configuración (carga desde config.conf)
extern uint8_t BRILLO_MIN;
extern uint8_t BRILLO_MED;
extern uint8_t BRILLO_MAX;
extern uint16_t ADC_SUBIR_A_MEDIO;
extern uint16_t ADC_BAJAR_A_MINIMO;
extern uint16_t ADC_SUBIR_A_MAXIMO;
extern uint16_t ADC_BAJAR_A_MEDIO;

// Prototipos
void cargar_configuracion(const char *archivo);
estados_t f_brillo_minimo(uint16_t lectura);
estados_t f_brillo_medio(uint16_t lectura);
estados_t f_brillo_maximo(uint16_t lectura);

#endif
