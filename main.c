#include <stdio.h>
#include <stdlib.h>

struct Livro{
    char nome[40];
    char isbn[40];
    float preco;
    int score;
    char editora[40];
};
typedef struct Livro* pLivro;

pLivro livro_aloc(int qtde){
    return (pLivro)malloc(qtde * sizeof(struct Livro));
}

void livro_ler(pLivro livros, int qtde){
    for (int i = 0; i < qtde; i++){
        scanf(" %[^\n] %[^\n] %f %d %[^\n]", livros[i].nome, livros[i].isbn,
              &livros[i].preco, &livros[i].score, livros[i].editora);
    }
}

void livro_exibe(pLivro livros, int qtde){
    for (int i = 0; i < qtde; i++){
        printf("Livro %d:\n", i + 1);
        printf("Nome: %s\n", livros[i].nome);
        printf("ISBN: %s\n", livros[i].isbn);
        printf("Preço: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n", livros[i].editora);
        if (i < qtde - 1){
            printf("\n");
        }
    }
}

void livro_desaloca(pLivro livros){
    free(livros);
}

int main(){
    int qtde;
    pLivro livros;
    scanf("%d", &qtde);
    livros = livro_aloc(qtde);
    livro_ler(livros, qtde);
    livro_exibe(livros, qtde);
    livro_desaloca(livros);

    return 0;
}