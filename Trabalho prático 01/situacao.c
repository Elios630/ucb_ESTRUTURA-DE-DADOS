#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[50];
    char telefone[15];
    char curso[50];
    float nota1;
    float nota2;
    float media;
    char situacao[15];
};

int main() {
    FILE *dadoEntrada, *dadoSaida;
    struct Aluno aluno;
    char linha[100];

    dadoEntrada = fopen("DadosEntrada.csv", "r");
    if (dadoEntrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    dadoSaida = fopen("SituacaoFinal.csv", "w");
    if (dadoSaida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    while (fgets(linha, sizeof(linha), dadoEntrada) != NULL) {
        char *dado = strtok(linha, ",");
        strcpy(aluno.nome, dado);
        dado = strtok(NULL, ",");
        strcpy(aluno.telefone, dado);
        dado = strtok(NULL, ",");
        strcpy(aluno.curso, dado);
        dado = strtok(NULL, ",");
        aluno.nota1 = atof(dado);
        dado = strtok(NULL, ",");
        aluno.nota2 = atof(dado);

        aluno.media = (aluno.nota1 + aluno.nota2) / 2.0;
        if (aluno.media >= 7.0) {
            strcpy(aluno.situacao, "APROVADO");
        } else {
            strcpy(aluno.situacao, "REPROVADO");
        }

        fprintf(dadoSaida, "%s, %.2f, %s\n", aluno.nome, aluno.media, aluno.situacao);
    }

    fclose(dadoEntrada);
    fclose(dadoSaida);

    printf("Processamento concluído. Verifique o arquivo SituacaoFinal.csv\n");

    return 0;
}