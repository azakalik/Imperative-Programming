int
maximo (int a, int b, int c) {
	int m;
    m = (a > b)? ((a > c)? a : c) : ((b > c)? b : c);
	return m;
}


int
maximo (int a, int b, int c) {
    return (a > b)? ((a > c)? a : c) : ((b > c)? b : c);
}

int
maximo (int a, int b, int c) {
	int m;
    m = ( a > b )? a : b;
	return ( m > c )? m : c;
}