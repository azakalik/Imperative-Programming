#ifndef COMPLEJO_ADT_H
#define COMPLEJO_ADT_H

/* ----- Definición del tipo de dato -------- */
typedef struct complejoCDT *complejoADT;

/* ----- Operaciones disponibles sobre el TAD ------- */

/* Función: inicializa el número complejo
 * Uso: numComp= nuevoComp(pReal, pImag);
 * Crea un nuevo complejo e inicializa su partes real e imaginaria.
 */
complejoADT nuevoComp (float real, float im);

/* Función: Realiza la suma de dos números complejos
 * Uso: suma = sumaComp(num1, num2);
 * Como esta función devuelve el resultado en su nombre, crea una nueva
 * instancia de un complejo y por lo tanto al dejar de usarlo se debe
 * liberar invocando a la función liberaComp. En caso de no poder crear
 * un nuevo complejo, retorna NULL.
 */
complejoADT  sumaComp (complejoADT num1, complejoADT num2);

/* Función: Realiza la resta de dos números complejos
 * Uso: resta = restaComp(num1, num2);
 * Como esta función devuelve el resultado en su nombre, crea una nueva
 * instancia de un complejo y por lo tanto al dejar de usarlo se debe
 * liberar invocando a la función liberaComp.  En caso de no poder crear
 * un nuevo complejo, retorna NULL.
 */
complejoADT  restaComp (complejoADT num1, complejoADT num2);

/* Función: Realiza la multiplicación de dos números complejos
 * Uso: multi = multiplicaComp(num1, num2);
 * Como esta función devuelve el resultado en su nombre, crea una nueva
 * instancia de un complejo y por lo tanto al dejar de usarlo se debe
 * liberar invocando a la función liberaComp.  En caso de no poder crear
 * un nuevo complejo, retorna NULL.
 */

complejoADT  multiplicaComp (complejoADT num1, complejoADT num2);
/* Función: Realiza la división de dos números complejos
 * Uso: div = divideComp(num1, num2);
 */
complejoADT  divideComp (complejoADT num1, complejoADT num2);

/* Función: Obtiene el conjugado de un número complejo
 * Uso: conjugado = conjugadoComp(num);
 */
complejoADT  conjugadoComp (complejoADT num);

/* Función: Permite obtener la parte real del número complejo
 * Uso: real = parteRealComp(num);
 */
float parteRealComp (complejoADT num);

/* Función: Permite obtener la parte imaginaria del número complejo
 * Uso: imag = parteImagComp(num);
 */
float parteImagComp (complejoADT num);

/* Función: Permite mostrar el número complejo completo
 * Uso: mostrar(num);
 */
void mostrarComp(complejoADT num);
/* Función: Destruye el número complejo
 * Uso: liberaComp(num);
 * Debe invocarse al dejar de usar una variable de tipo complejoADT
 */
void liberaComp(complejoADT);
#endif