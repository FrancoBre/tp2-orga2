/* 
Realice una funci on, con la siguiente aridad, void aclarar(unsigned char** red, unsigned
char** green, unsigned char** blue, int n) en assembler sin utilizar instrucciones mul-
timedia que le sume n a cada una de las matrices. Deber a saturar correctamente.
*/

#include <stdio.h>
#include <stdlib.h>

void aclarar(unsigned char** red, unsigned char** green, unsigned char** blue, int n);
void printMatrix(unsigned char** red, unsigned char** green, unsigned char** blue);
unsigned char** generateMatrix();

unsigned char** generateMatrix() {
    // Creo una matriz de 512x512
    unsigned char **matrix = (unsigned char **) malloc(512*sizeof(unsigned char *));

    for(int i=0;i<512;i++) {
        matrix[i] = (unsigned char *) malloc(512*sizeof(unsigned char)); 
    }
    
    for(int i=0; i<512; i++){ 
        for(int j=0; j<512; j++){ 
            matrix[i][j] = i+j; 
        } 
    }
    
    return matrix;
}

void printMatrix(unsigned char** red, unsigned char** green, unsigned char** blue) {
    printf("\n###################### PRINT MATRIZ RED ######################\n\n");
    for(int i=0;i<10;i++){ 
    	for(int j=0;j<10;j++){ 
    		printf("%d ",red[i][j]); 
    	}

    	printf("\n"); 
    }

    printf("\n###################### PRINT MATRIZ GREEN ######################\n\n");
    for(int i=0;i<10;i++){ 
    	for(int j=0;j<10;j++){ 
    		printf("%d ",green[i][j]); 
    	}

    	printf("\n"); 
    }

    printf("\n###################### PRINT MATRIZ BLUE ######################\n\n");
    for(int i=0;i<10;i++){ 
    	for(int j=0;j<10;j++){ 
    		printf("%d ",blue[i][j]); 
    	}

    	printf("\n"); 
    }
}

int main() {
    unsigned char **red = generateMatrix();
    unsigned char **green = generateMatrix();
    unsigned char **blue = generateMatrix();

    printMatrix(red, green, blue);

    aclarar(red, green, blue, 100);

    printMatrix(red, green, blue);

    return 0;
}