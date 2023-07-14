int
balance(const char * texto)
{
	if (*texto == 0)
		return 0;
	
switch (*texto)
	{
		case '(': return -1 + balance (texto++);
		case ')': return 1 + balance (texto++);
		default: return balance (texto++);	
	}
}
 
