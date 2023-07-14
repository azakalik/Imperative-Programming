#include <stdio.h>
#include <assert.h>

unsigned long netMask(unsigned char bitsNet);
void ipWithFormat(unsigned long ip);
void printip(unsigned long ip, unsigned char bitsNet);

int main(void)
{
    unsigned long ip = 0x10FF1112;

    printip(ip, 16);
    printip(ip, 24);
    printip(ip, 23);
    printip(ip, 25);

    return 0;
}

void printip(unsigned long ip, unsigned char bitsNet)
{
    unsigned long mask;
    unsigned long net;
    unsigned long host;

    /* Obtención de mascara de red*/
    mask = netMask(bitsNet);
    /* Calculo de direcciones de red y host*/
    net = ip & mask;
    host = ip & ~mask;

    /* Impresión en formato apropiado*/
    printf("Red = ");
    ipWithFormat(net);
    printf("\nHost = ");
    ipWithFormat(host);
    putchar('\n');
}

unsigned long
netMask(unsigned char bitsNet)
{
    unsigned long aux = 1;
    unsigned char bitsHost = 32 - bitsNet;

    assert(bitsNet != 0);

    while (--bitsHost > 0)
        aux = aux << 1 | 1; /*Todos 1 en la porcion de host*/
    return ~aux;            /*Se complementa*/
}

void ipWithFormat(unsigned long ip)
{
    /* Obtener los 4 octetos o bytes */
    unsigned char b1, b2, b3, b4;
    unsigned long mask = 0xFFFFFFFF;

    b1 = (ip & mask) >> 24;
    mask >>= 8;
    b2 = (ip & mask) >> 16;
    mask >>= 8;
    b3 = (ip & mask) >> 8;
    mask >>= 8;
    b4 = (ip & mask);
    printf("%d.%d.%d.%d", b1, b2, b3, b4);
}
