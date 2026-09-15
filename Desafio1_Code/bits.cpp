#include "bits.h"

unsigned int bytesNecesarios(unsigned int cantidadBits)
{
    return (cantidadBits + 7) / 8;
}


unsigned char leerFicha(const unsigned char *trama,
                        unsigned int indice,
                        unsigned int bytesTrama) {
    unsigned int bitInicial = indice * BITS_POR_FICHA;
    unsigned int byte = bitInicial >> 3;    // equivale a bitInicial / 8
    unsigned int desp = bitInicial & 7;     // equivale a bitInicial % 8

    unsigned short ventana = trama[byte];

    if (byte + 1 < bytesTrama) {
        ventana |= (unsigned short)trama[byte + 1] << 8;
    }

    return (unsigned char)((ventana >> desp) & MASCARA_FICHA);
}


void escribirFicha(unsigned char *trama,
                   unsigned int indice,
                   unsigned char valor,
                   unsigned int bytesTrama)
{
    unsigned int bitInicial = indice * BITS_POR_FICHA;
    unsigned int byte = bitInicial / 8;
    unsigned int desp = bitInicial % 8;

    bool hayByteSiguiente = (byte + 1) < bytesTrama;

    unsigned short ventana = trama[byte];

    if (hayByteSiguiente) {
        ventana |= (unsigned short)trama[byte + 1] << 8;
    }

    ventana = ventana & ~((unsigned short)MASCARA_FICHA << desp);

}




