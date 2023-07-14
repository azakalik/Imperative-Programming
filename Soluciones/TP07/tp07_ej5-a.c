/* Cantidad máxima de alumnos */
#define MAX_ALUMNOS 40

/* Máxima longitud del nombre de los alumnos */
#define MAX_LARGO 25

typedef char TAlumnos[MAX_ALUMNOS][MAX_LARGO];
typedef char TCurso[];

/* Recibe un arreglo con los alumnos y otro con el curso al que pertenecen
** y devuelve dos arreglos con los alumnos separados por curso */
void separaCursos(TAlumnos alumnos, TCurso cursos, TAlumnos cursoG,
                  TAlumnos cursoH);

void separaCursos(TAlumnos alumnos, TCurso cursos, TAlumnos cursoG,
                  TAlumnos cursoH)
{
    int i = 0;
    int indG = 0, indH = 0; /* índices de cursoG y cursoH */

    while (alumnos[i][0] != 0)
    {
        if (cursos[i] == 'G')
            strcpy(cursoG[indG++], alumnos[i]);
        else
            strcpy(cursoH[indH++], alumnos[i]);
        i++;
    }
    /* Marcar el final del vector con un string vacío */
    cursoG[indG][0] = 0;
    cursoH[indH][0] = 0;
}
