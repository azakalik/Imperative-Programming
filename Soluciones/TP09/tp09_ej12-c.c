int
balance(const char * texto)
{
	if (*texto == 0)
		return 0;
 
	int count=0;
	switch (*texto)
	{
		case '(': count = -1; break;
		case ')': count = 1;  break;
	}
	return count + balance (texto+1);
}
