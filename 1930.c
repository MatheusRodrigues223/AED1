// Matheus da Rosa Rodrigues
// RA: 176614

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char reguas[8];
    int tomadas = 0;


    fgets(reguas, sizeof(reguas), stdin);
    reguas[strcspn(reguas, "\n")] = 0;

    char* regua = strtok(reguas, " \n");
        while (regua != NULL) {

            int numero = atoi(regua);
            tomadas += numero;

            regua = strtok(NULL, " \n");

        }

    tomadas -= 3;
    
    printf("%d\n", tomadas);


    return 0;
}
