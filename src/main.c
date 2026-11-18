#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 50
#define TAM_NOME 50

void cadastrarAluno(int matriculas[], char nomes[][TAM_NOME], float nota1[], float nota2[], float medias[], int *total);
void exibirTodos(int matriculas[], char nomes[][TAM_NOME], float nota1[], float nota2[], float medias[], int total);
void consultarPorMatricula(int matriculas[], char nomes[][TAM_NOME], float nota1[], float nota2[], float medias[], int total);
void listarSituacao(int matriculas[], char nomes[][TAM_NOME], float medias[], int total);
void exibirEstatisticas(float medias[], int total);
void ordenarPorMediaCrescente(int matriculas[], char nomes[][TAM_NOME], float nota1[], float nota2[], float medias[], int total);
void exibirMelhorAluno(int matriculas[], char nomes[][TAM_NOME], float medias[], int total);
void pesquisarPorInicioNome(int matriculas[], char nomes[][TAM_NOME], float nota1[], float nota2[], float medias[], int total);

int main() {
    int matriculas[MAX_ALUNOS];
    char nomes[MAX_ALUNOS][TAM_NOME];
    float nota1[MAX_ALUNOS];
    float nota2[MAX_ALUNOS];
    float medias[MAX_ALUNOS];
    int total = 0;
    int opcao;

    do {
        printf("\n========== GERENCIADOR ACADEMICO (MAX: 50) ==========\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Exibir todos os alunos\n");
        printf("3 - Consultar aluno por matricula\n");
        printf("4 - Listar aprovados e reprovados\n");
        printf("5 - Estatisticas da turma\n");
        printf("6 - [Extra] Ordenar alunos (ordem crescente de media)\n");
        printf("7 - [Extra] Exibir melhor aluno\n");
        printf("8 - [Extra] Pesquisar aluno pelo inicio do nome\n");
        printf("0 - Sair\n");
        printf("====================================================\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\n[Erro] Digite apenas numeros validos!\n");
            while (getchar() != '\n');
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarAluno(matriculas, nomes, nota1, nota2, medias, &total);
                break;
            case 2:
                exibirTodos(matriculas, nomes, nota1, nota2, medias, total);
                break;
            case 3:
                consultarPorMatricula(matriculas, nomes, nota1, nota2, medias, total);
                break;
            case 4:
                listarSituacao(matriculas, nomes, medias, total);
                break;
            case 5:
                exibirEstatisticas(medias, total);
                break;
            case 6:
                ordenarPorMediaCrescente(matriculas, nomes, nota1, nota2, medias, total);
                break;
            case 7:
                exibirMelhorAluno(matriculas, nomes, medias, total);
                break;
            case 8:
                pesquisarPorInicioNome(matriculas, nomes, nota1, nota2, medias, total);
                break;
            case 0:
                printf("\nEncerrando a aplicacao...\n");
                break;
            default:
                printf("\nOpcao invalida! Escolha uma opcao entre 0 e 8.\n");
        }
    } while (opcao != 0);

    return 0;
}

void cadastrarAluno(int matriculas[], char nomes[][TAM_NOME], float nota1[], float nota2[], float medias[], int *total) {
    int i, mat;

    if (*total >= MAX_ALUNOS) {
        printf("\n[Erro] Limite maximo de %d alunos atingido!\n", MAX_ALUNOS);
        return;
    }

    printf("\nDigite a matricula: ");
    scanf("%d", &mat);

    for (i = 0; i < *total; i++) {
        if (matriculas[i] == mat) {
            printf("\n[Erro] Ja existe um aluno cadastrado com a matricula %d!\n", mat);
            return;
        }
    }

    matriculas[*total] = mat;

    while (getchar() != '\n');
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", nomes[*total]);

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1[*total]);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2[*total]);

    medias[*total] = (nota1[*total] + nota2[*total]) / 2.0f;
    (*total)++;

    printf("\n[Sucesso] Aluno cadastrado! Total atual: %d/%d\n", *total, MAX_ALUNOS);
}

void exibirTodos(int matriculas[], char nomes[][TAM_NOME], float nota1[], float nota2[], float medias[], int total) {
    int i;

    if (total == 0) {
        printf("\nNenhum aluno cadastrado no sistema.\n");
        return;
    }

    printf("\n--- LISTA DE TODOS OS ALUNOS (%d/%d) ---\n", total, MAX_ALUNOS);
    for (i = 0; i < total; i++) {
        printf("Matricula: %d | Nome: %s | N1: %.2f | N2: %.2f | Media: %.2f\n",
               matriculas[i], nomes[i], nota1[i], nota2[i], medias[i]);
    }
}

void consultarPorMatricula(int matriculas[], char nomes[][TAM_NOME], float nota1[], float nota2[], float medias[], int total) {
    int i, busca;

    if (total == 0) {
        printf("\nNenhum aluno cadastrado no sistema.\n");
        return;
    }

    printf("\nDigite a matricula que deseja buscar: ");
    scanf("%d", &busca);

    for (i = 0; i < total; i++) {
        if (matriculas[i] == busca) {
            printf("\n--- ALUNO ENCONTRADO ---\n");
            printf("Matricula: %d\n", matriculas[i]);
            printf("Nome: %s\n", nomes[i]);
            printf("Notas: %.2f e %.2f\n", nota1[i], nota2[i]);
            printf("Media: %.2f\n", medias[i]);
            printf("Situacao: %s\n", (medias[i] >= 7.0f) ? "Aprovado" : "Reprovado");
            return;
        }
    }

    printf("\nAluno com a matricula %d nao foi encontrado.\n", busca);
}

void listarSituacao(int matriculas[], char nomes[][TAM_NOME], float medias[], int total) {
    int i;

    if (total == 0) {
        printf("\nNenhum aluno cadastrado no sistema.\n");
        return;
    }

    printf("\n--- SITUACAO ACADEMICA DA TURMA ---\n");
    for (i = 0; i < total; i++) {
        printf("%s (Matricula: %d) - Media: %.2f [%s]\n",
               nomes[i], matriculas[i], medias[i],
               (medias[i] >= 7.0f) ? "APROVADO" : "REPROVADO");
    }
}

void exibirEstatisticas(float medias[], int total) {
    int i;
    float soma_medias = 0.0f;
    float maior_media = medias[0];
    float menor_media = medias[0];
    int aprovados = 0;
    int reprovados = 0;

    if (total == 0) {
        printf("\nNenhum aluno cadastrado no sistema.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        soma_medias += medias[i];
        if (medias[i] > maior_media) {
            maior_media = medias[i];
        }
        if (medias[i] < menor_media) {
            menor_media = medias[i];
        }
        if (medias[i] >= 7.0f) {
            aprovados++;
        } else {
            reprovados++;
        }
    }

    printf("\n--- ESTATISTICAS DA TURMA ---\n");
    printf("Maior media: %.2f\n", maior_media);
    printf("Menor media: %.2f\n", menor_media);
    printf("Media geral da turma: %.2f\n", soma_medias / total);
    printf("Quantidade de aprovados: %d\n", aprovados);
    printf("Quantidade de reprovados: %d\n", reprovados);
}

void ordenarPorMediaCrescente(int matriculas[], char nomes[][TAM_NOME], float nota1[], float nota2[], float medias[], int total) {
    int i, j, tempMat;
    float tempMedia, tempN1, tempN2;
    char tempNome[TAM_NOME];

    if (total == 0) {
        printf("\nNenhum aluno cadastrado no sistema.\n");
        return;
    }

    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - i - 1; j++) {
            if (medias[j] > medias[j + 1]) {
                tempMedia = medias[j];
                medias[j] = medias[j + 1];
                medias[j + 1] = tempMedia;

                tempN1 = nota1[j];
                nota1[j] = nota1[j + 1];
                nota1[j + 1] = tempN1;

                tempN2 = nota2[j];
                nota2[j] = nota2[j + 1];
                nota2[j + 1] = tempN2;

                tempMat = matriculas[j];
                matriculas[j] = matriculas[j + 1];
                matriculas[j + 1] = tempMat;

                strcpy(tempNome, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], tempNome);
            }
        }
    }

    printf("\n[Sucesso] Alunos ordenados em ordem crescente de media!\n");
    exibirTodos(matriculas, nomes, nota1, nota2, medias, total);
}

void exibirMelhorAluno(int matriculas[], char nomes[][TAM_NOME], float medias[], int total) {
    int i, indiceMelhor = 0;

    if (total == 0) {
        printf("\nNenhum aluno cadastrado no sistema.\n");
        return;
    }

    for (i = 1; i < total; i++) {
        if (medias[i] > medias[indiceMelhor]) {
            indiceMelhor = i;
        }
    }

    printf("\n--- MELHOR ALUNO DA TURMA ---\n");
    printf("Nome: %s\n", nomes[indiceMelhor]);
    printf("Matricula: %d\n", matriculas[indiceMelhor]);
    printf("Media: %.2f\n", medias[indiceMelhor]);
}

void pesquisarPorInicioNome(int matriculas[], char nomes[][TAM_NOME], float nota1[], float nota2[], float medias[], int total) {
    int i, tamanhoPrefixo, encontrados = 0;
    char prefixo[TAM_NOME];

    if (total == 0) {
        printf("\nNenhum aluno cadastrado no sistema.\n");
        return;
    }

    while (getchar() != '\n');
    printf("\nDigite o inicio do nome para pesquisar: ");
    scanf(" %[^\n]", prefixo);

    tamanhoPrefixo = strlen(prefixo);

    printf("\n--- RESULTADOS DA PESQUISA POR \"%s\" ---\n", prefixo);
    for (i = 0; i < total; i++) {
        if (strncmp(nomes[i], prefixo, tamanhoPrefixo) == 0) {
            printf("Matricula: %d | Nome: %s | N1: %.2f | N2: %.2f | Media: %.2f\n",
                   matriculas[i], nomes[i], nota1[i], nota2[i], medias[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum aluno encontrado com o inicio \"%s\".\n", prefixo);
    }
}
