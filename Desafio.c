#include <stdio.h>

typedef struct {
    char estado;
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Cidade;

void gerarCodigoCidade(char estado, char* codigo) {
    static int contador[26] = {0}; // Para 26 estados possíveis

    int indice = estado - 'A'; // Assume que estados são letras de A a Z

    if (contador[indice] < 4) {
        contador[indice]++;
        sprintf(codigo, "%c%02d", estado, contador[indice]);
    } else {
        printf("Erro: Estado %c já tem 4 cidades cadastradas.\n", estado);
    }
}

void gerarCodigoCidade(char estado, char* codigo) {
    static int contador[26] = {0}; // Para 26 estados possíveis

    int indice = estado - 'A'; // Assume que estados são letras de A a Z

    if (contador[indice] < 4) {
        contador[indice]++;
        sprintf(codigo, "%c%02d", estado, contador[indice]);
    } else {
        printf("Erro: Estado %c já tem 4 cidades cadastradas.\n", estado);
    }
}

void cadastrarCidade(Cidade *cidade) {
    printf("Digite o estado (1 caractere): ");
    scanf(" %c", &cidade->estado);
    getchar(); // Consumir o caractere de nova linha

    printf("Digite o nome da cidade: ");
    fgets(cidade->nomeCidade, sizeof(cidade->nomeCidade), stdin);

    printf("Digite a população: ");
    scanf("%d", &cidade->populacao);

    printf("Digite a área em km²: ");
    scanf("%f", &cidade->area);

    printf("Digite o PIB: ");
    scanf("%f", &cidade->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontosTuristicos);
}

void exibirCidade(Cidade cidade) {
    char codigo[10];
    gerarCodigoCidade(cidade.estado, codigo);

    printf("\n--- Dados da Cidade ---\n");
    printf("Estado: %c\n", cidade.estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s", cidade.nomeCidade);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões de reais\n", cidade.pib);
    printf("Número de Pontos Turísticos: %d\n", cidade.pontosTuristicos);
}

int main() {
    Cidade cidade;
    cadastrarCidade(&cidade);
    exibirCidade(cidade);

    return 0;
}
