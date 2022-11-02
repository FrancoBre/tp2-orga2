/* 
Realice una funci on, con la siguiente aridad, void aclarar(unsigned char** red, unsigned
char** green, unsigned char** blue, int n) en assembler sin utilizar instrucciones mul-
timedia que le sume n a cada una de las matrices. Deber a saturar correctamente.
*/

#include <stdio.h>
#include <stdlib.h>

void add(unsigned char** matrix, int n);
void aclarar(unsigned char** red, unsigned char** green, unsigned char** blue, int n);
unsigned char** generateMatrix();

void aclarar(unsigned char** red, unsigned char** green, unsigned char** blue, int n) {
    add(red, n);
    add(green, n);
    add(blue, n);
}

void add(unsigned char** matrix, int n) {
    for(int i=0; i<512; i++){ 
        for(int j=0; j<512; j++){ 
            // se satura en 255
            if((matrix[i][j] + n) > 255) {
                matrix[i][j] = 255; 
            } else {
                matrix[i][j] = matrix[i][j] + n;
            }
        } 
    }
}

unsigned char** generateMatrix() {
    // Creo una matriz de 512x512
    unsigned char **matrix = (unsigned char **) malloc(512*sizeof(unsigned char *));

    for(int i=0;i<512;i++) {
        matrix[i] = (unsigned char *) malloc(512*sizeof(unsigned char)); 
    }
    
    return matrix;
}

int main() {
    unsigned char **red = generateMatrix();
    unsigned char **green = generateMatrix();
    unsigned char **blue = generateMatrix();

    aclarar(red, green, blue, 100);

    return 0;
}