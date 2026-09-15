#ifndef BITS_H
#define BITS_H

const unsigned char BITS_POR_FICHA = 3;
const unsigned char MASCARA_FICHA  = 7;   // 0000 0111 -> aisla 3 bits
const unsigned char VACIO          = 0;   // 000
const unsigned char FICHA_MINIMA   = 1;   // 001 -> A
const unsigned char FICHA_MAXIMA   = 6;   // 110 -> F
const unsigned char RESERVADO      = 7;   // 111

unsigned int bytesNecesarios(unsigned int cantidadBits);

unsigned char leerFicha(const unsigned char *trama,
                        unsigned int indice,
                        unsigned int bytesTrama);

void escribirFicha(unsigned char *trama,
                   unsigned int indice,
                   unsigned char valor,
                   unsigned int bytesTrama);


#endif // BITS_H
