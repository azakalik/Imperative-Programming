int main(void)
{
    TipoCarton *cartones;
    int bolillero[BOLILLAS];
    int i, jugadores;

    int bingo;

    /* setear la semilla */
    randomize();

    for (i = 0; i < BOLILLAS; i++)
        bolillero[i] = i + 1;

    /* Preguntar la cantidad de jugadores */
    do
    {
        jugadores = getint("Cantidad de jugadores :");
    } while (jugadores < 1);

    /* Crea el arreglo dinÃ¡mico de cartones */
    if ((cartones = malloc(sizeof(TipoCarton) * jugadores))) == NULL)
        {
            printf("Hubo un error al reservar memoria.\n");
            return 1;
        }

    /* generar los cartones */
    for (i = 0; i < jugadores; i++)
        generarCarton(cartones[i]);

    bingo = jugar(bolillero, cartones, jugadores);

    for (i = 0; i < jugadores; i++)
        if (bingo & (1 << i))
            printf("El jugador %d hizo bingo\n", i + 1);
    free(cartones);
    return 0;
}
