// Nos aseguramos que el % se haga entre positivos
#define DIVISOR(a,b) ( (b) != 0 && ((a)<0 ? -(a) : (a)) % ((b) < 0 ? -(b) : (b)) == 0)