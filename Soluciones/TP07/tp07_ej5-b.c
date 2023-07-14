#define MAX_ALUMNOS 40

typedef char *TAlumnos[MAX_ALUMNOS];
typedef char TCurso[];

void separaCursos(TAlumnos alumnos, TCurso cursos, TAlumnos cursoG, TAlumnos cursoH)
{
    int i = 0;
    int indG = 0, indH = 0; /* indices de cursoG y cursoH */

    while (alumnos[i][0] != 0)
    {
        if (cursos[i] == 'G')
            cursoG[indG++] = alumnos[i];
        else
            cursoH[indH++] = alumnos[i];
        i++;
    }
    cursoG[indG] = alumnos[i]; /* Ambas opciones son correctas ya que */
    cursoH[indH] = "";         /* representan el string nulo */
}
