int 
dcm (int a, int b) {
	int auxi = a;		

	while (auxi > 0) {	
		a = b;
        b = auxi;
        auxi = a % b ;
	}
	return b;
}