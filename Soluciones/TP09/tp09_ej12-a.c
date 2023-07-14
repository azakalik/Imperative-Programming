int balance(const char *texto)
{
    if (*texto == 0)
        return 0;

    switch (*texto)
    {
    case '(':
        return -1 + balance(texto + 1);
    case ')':
        return 1 + balance(texto + 1);
    default:
        return balance(texto + 1);
    }
}
