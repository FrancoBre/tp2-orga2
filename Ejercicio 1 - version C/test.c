#include<stdlib.h> 
#include<stdio.h> 

void add(unsigned char** matrix, int n);
void aclarar(unsigned char** red, unsigned char** green, unsigned char** blue, int n);
unsigned char** generateMatrix();
void printMatrix(unsigned char** matrix);

// las matrices son siempre de 10x10 por motivos de prueba
void printMatrix(unsigned char** matrix) {
    for(int i=0;i<10;i++){ 
    	for(int j=0;j<10;j++){ 
    		printf("%d ",matrix[i][j]); 
    	}

    	printf("\n"); 
    }
}

void aclarar(unsigned char** red, unsigned char** green, unsigned char** blue, int n) {
    printf("\n######################## SUMANDO 10 A RED ########################\n\n");
    add(red, n);

    printf("\n####################### SUMANDO 10 A GREEN #######################\n\n");
    add(green, n);

    printf("\n####################### SUMANDO 10 A BLUE ########################\n\n");
    add(blue, n);
}

void add(unsigned char** matrix, int n) {
    for(int i=0; i<10; i++){ 
        for(int j=0; j<10; j++){ 
            // se satura en 255
            if((matrix[i][j] + n) > 255) {
                matrix[i][j] = 255; 
            } else {
                matrix[i][j] = matrix[i][j] + n;
            }

        } 
    }

    printMatrix(matrix);
}

unsigned char** generateMatrix() {
    // Creo una matriz de 512x512
    unsigned char **matrix = (unsigned char **) malloc(10*sizeof(unsigned char *));

    for(int i=0;i<10;i++) {
        matrix[i] = (unsigned char *) malloc(10*sizeof(unsigned char));
        //&matrix[i] = 20;
    }
    
    return matrix;
}

int main() {
    
    printf("\n###################### GENERANDO MATRIZ RED ######################\n\n"); 
    unsigned char **red = generateMatrix();
    printMatrix(red);

    printf("\n###################### GENERANDO MATRIZ GREEN ######################\n\n");
    unsigned char **green = generateMatrix();
    printMatrix(green);

    printf("\n###################### GENERANDO MATRIZ BLUE ######################\n\n");
    unsigned char **blue = generateMatrix();
    printMatrix(green);

    aclarar(red, green, blue, 10);

    return 0;
}
