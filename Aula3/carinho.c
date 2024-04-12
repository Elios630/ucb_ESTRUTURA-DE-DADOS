#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item{
    char Nome[128];
    int Qnt;
    float Pre;
};

int main() {
    FILE *arquivo;
    struct Item x;

    arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    
    float total = 0.0;
    while (fscanf(arquivo, "%s %d %f", x.Nome, &x.Qnt, &x.Pre) != EOF){
        float subTotal=x.Qnt*x.Pre;
        printf("Nome: %s\nQnt: %d\nPreço: %.2f\n", x.Nome, x.Qnt, x.Pre);
        printf("subTotal: %.2f\n", subTotal);
        total+=subTotal;
    }
    printf("Total: %.2f\n", total);
    
    
    fclose(arquivo);
    return 0;
}


