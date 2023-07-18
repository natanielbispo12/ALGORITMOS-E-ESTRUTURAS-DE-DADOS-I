#include <stdio.h>
#include <stdlib.h>

//Struct do tipo aluno que contém: matricula, nome, endereco e telefone.
typedef struct aluno {
    int mat;
    char nome[81];
    char end[121];
    char tel[21];
}Aluno;
//Essa função percorre o array e incializa todos elementos como NULL
void incializa (int n, Aluno** tab){
    int i;
    for (i = 0; i < 0; i++){
        tab[i] = NULL;
    }
}
//Essa função pede para o usuario digitar os dados de matricula, nome, endereco e telefone, caso o indice estiver dentro dos limites do vetor
void preenche (int n, Aluno** tab, int i){
    if(i < 0 || i >= n){
        printf("Indice fora do limite do vetor.\n");
        exit(1);
    }
    if(tab[i] == NULL){
        tab[i] = (Aluno*) malloc(sizeof(Aluno));
        printf("Entre com a matricula: ");
        scanf("%d", &tab[i]->mat);
        printf("Entre com o nome: ");
        scanf(" %80[^\n]", tab[i]->nome);
        printf("Entre com o endereco: ");
        scanf(" %120[^\n]", tab[i]->end);
        printf("Entre com o telefone: ");
        scanf(" %20[^\n]", tab[i]->tel);
    }
}
//Essa função libera a memoria alocada em uma posição caso o indice seja diferente de nulo.
void retira (int n, Aluno** tab, int i){
    if(i < 0 || i >= n){
        printf("Indice fora do limite do vetor.\n");
        exit(1);
    }
    if(tab[i] != NULL){
        free(tab[i]);
        tab[i] = NULL;
    }
}
//Essa função imprimre na tela os dados do aluno.
void imprime (int n, Aluno** tab, int i){
    if(i < 0 || i >= n){
        printf("indice fora do limite do vetor.\n");
        exit(1);
    }
    if(tab[i] != NULL){
        printf("Matricula: %d\n", tab[i]->mat);
        printf("Nome: %s\n", tab[i]->nome);
        printf("Endereco: %s\n", tab[i]->end);
        printf("Telefone: %s\n", tab[i]->tel);
    }
}
//Essa função chama a outra função imprime e percorre todo o array imprimindo na tela os dados preenxidos.
void imprime_tudo (int n, Aluno** tab){
    int i;
    for(i = 0; i < n; i++){
        imprime(n, tab, i);
    }
}
//Na main é chamado todas as funções e passado os parâmetros necessários para o funcionamento do programa.
int main (){
    Aluno* tab[10];
    incializa(10, tab);
    preenche(10, tab, 0);
    preenche(10, tab, 1);
    preenche(10, tab, 2);
    imprime_tudo(10, tab);
    retira(10, tab, 0);
    retira(10, tab, 1);
    retira(10, tab, 2);
    return 0;
}
