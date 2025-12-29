#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40

struct ALUNO{
    char nome[30];
    int ra;
    char curso[20];
};


void limparAluno(struct ALUNO *a){
    a->nome[0] = '\0';
    a->curso[0] = '\0';
    a->ra = 0;
}

void inicializarVetores(struct ALUNO *v){
    for(int i = 0; i < MAX; i++){
        limparAluno(&v[i]);
    }
}

void cadastrarAluno(struct ALUNO *curso, int baseRA, char nomeCurso[]){
    for(int i = 0; i < MAX; i++){
        if(curso[i].nome[0] == '\0'){
            printf("Nome: ");
            scanf("%s", curso[i].nome);
            curso[i].ra = baseRA + i;
            strcpy(curso[i].curso, nomeCurso);
            printf("Aluno cadastrado com sucesso! RA: %d\n", curso[i].ra);
            return;
        }
    }
    printf("Limite de alunos atingido!\n");
}

void pesquisarAluno(struct ALUNO *curso, int indice){
    if(curso[indice].nome[0] == '\0'){
        printf("Aluno nao encontrado!\n");
        return;
    }
    printf("%s | %d | %s\n", curso[indice].nome, curso[indice].ra, curso[indice].curso);
}

void alterarNome(struct ALUNO *curso, int indice){
    if(curso[indice].nome[0] == '\0'){
        printf("Aluno nao encontrado!\n");
        return;
    }
    printf("Novo nome: ");
    scanf("%s", curso[indice].nome);
    printf("Nome alterado com sucesso!\n");
}

void excluirAluno(struct ALUNO *curso, int indice){
    if(curso[indice].nome[0] == '\0'){
        printf("Aluno nao encontrado!\n");
        return;
    }
    limparAluno(&curso[indice]);
    printf("Aluno excluido com sucesso!\n");
}


int main() {
    int caso, continua = 1, qualcurso, rapesquisa;

    struct ALUNO alunosads[MAX];
    struct ALUNO alunosodonto[MAX];
    struct ALUNO alunosdireito[MAX];

    inicializarVetores(alunosads);
    inicializarVetores(alunosodonto);
    inicializarVetores(alunosdireito);

    do {
        printf("\nMENU:\n");
        printf("1: Cadastrar Aluno\n");
        printf("2: Pesquisar Aluno\n");
        printf("3: Alterar Nome\n");
        printf("4: Excluir Aluno\n");
        printf("5: Sair\n");
        scanf("%d", &caso);

        switch (caso) {

        case 1:
            printf("\nQual curso?\n1: ADS\n2: Odonto\n3: Direito\n");
            scanf("%d", &qualcurso);

            if(qualcurso == 1)
                cadastrarAluno(alunosads, 100, "ADS");
            else if(qualcurso == 2)
                cadastrarAluno(alunosodonto, 200, "Odontologia");
            else if(qualcurso == 3)
                cadastrarAluno(alunosdireito, 300, "Direito");
            else
                printf("Curso invalido!\n");
            break;

        case 2:
            printf("RA do aluno: ");
            scanf("%d", &rapesquisa);

            if(rapesquisa / 100 == 1)
                pesquisarAluno(alunosads, rapesquisa - 100);
            else if(rapesquisa / 100 == 2)
                pesquisarAluno(alunosodonto, rapesquisa - 200);
            else if(rapesquisa / 100 == 3)
                pesquisarAluno(alunosdireito, rapesquisa - 300);
            else
                printf("RA invalido!\n");
            break;

        case 3:
            printf("RA do aluno: ");
            scanf("%d", &rapesquisa);

            if(rapesquisa / 100 == 1)
                alterarNome(alunosads, rapesquisa - 100);
            else if(rapesquisa / 100 == 2)
                alterarNome(alunosodonto, rapesquisa - 200);
            else if(rapesquisa / 100 == 3)
                alterarNome(alunosdireito, rapesquisa - 300);
            else
                printf("RA invalido!\n");
            break;

        case 4:
            printf("RA do aluno: ");
            scanf("%d", &rapesquisa);

            if(rapesquisa / 100 == 1)
                excluirAluno(alunosads, rapesquisa - 100);
            else if(rapesquisa / 100 == 2)
                excluirAluno(alunosodonto, rapesquisa - 200);
            else if(rapesquisa / 100 == 3)
                excluirAluno(alunosdireito, rapesquisa - 300);
            else
                printf("RA invalido!\n");
            break;

        case 5:
            continua = 0;
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (continua);

    return 0;
}
