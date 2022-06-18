#include"funcoes.h"

// Atalho para abrir  todas as funções no Vscode: Ctrl + K + J
// Atalho para fechar todas as funções no Vscode: Ctrl + K + 0


int main(){
    // Declaração de váriaveis
    int opcao, qnt_alunos = 0;
    tAlunosEmp alunos[MAX];


    // Interface do programa
    system("CLS || clear");
    printf("\033[0;32m\e[1mSISTEMA DE GERENCIAMENTO DE ALUNOS DE EMPREENDEDORISMO\e[0m\n");
    Timer();
    Timer();
    Timer();
    system("CLS || clear");

    do{
        printf("\e[1mSelecione uma opcao: \e[0m\n\n");
        printf("[1] - Cadastrar um novo aluno\n");
        printf("[2] - Buscar aluno\n");
        printf("[3] - Ler arquivo com listagem de alunos\n");
        printf("[4] - Gerar arquivo com dados dos alunos aprovados\n");
        printf("[5] - Gerar arquivo com dados dos alunos reprovados\n");
        printf("[6] - Fechar programa\n\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        // Opção 1 - Cadastro de novos alunos
        if(opcao == 1){
            Timer();
            system("CLS || clear");
            CadastrarAluno(alunos, qnt_alunos);
        }
        // Opção 2 - Busca por alunos cadastrados
        else if(opcao == 2){
            Timer();
            system("CLS || clear");
            BuscarAluno(alunos, qnt_alunos);
        }
        // Opção 3 - Ler arquivo com dados de alunos
        else if(opcao == 3){
            Timer();
            system("CLS || clear");
            LerArquivo(alunos, qnt_alunos);
        }
        // Opção 4 - Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabética
        else if(opcao == 4){
            Timer();
            system("CLS || clear");
            GerarAprovados(alunos, qnt_alunos);
        }
        // Opção 5 - Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabética
        else if(opcao == 5){
            Timer();
            system("CLS || clear");
            GerarReprovados(alunos, qnt_alunos);
        }
        else{
            system("CLS || clear");
            if(opcao != 6){
                printf("Opcao Invalida!\n\n");
            }
        }

    }while(opcao != 6);

    // Opção 6 - Fechar o programa e criar um arquivo com todos os alunos cadastrados
    if(opcao == 6){
        printf("Ate logo!");
        Timer();
        FecharPrograma(alunos, qnt_alunos);
    }
}
