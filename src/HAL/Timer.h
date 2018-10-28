#ifndef TIMER_H
#define TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// Esta función sirve para medir tiempos. En un momento dado se obtiene el número de ticks en ms
// que podemos llamar tick1, y un poco más adelante, se vuelve a llamar está función para obtener
// el valor tick2. El tiempo transcurrido sería la diferencia (tick2 - tick1). Nótese que esta
// diferencia funciona incluso en caso de desborde del contador de ticks. La única limitación
// existente es el tiempo máximo que se puede medir que sería (2^32 - 1) ms
// La implementación de esta función dentro de HAL depende del microcontrolador, pero resulta
// sencillo mediante el uso de timers, que habrá que ajustar para contar ms e incrementar los ticks
uint32_t GetTickMs();

#ifdef __cplusplus
}
#endif

#endif
