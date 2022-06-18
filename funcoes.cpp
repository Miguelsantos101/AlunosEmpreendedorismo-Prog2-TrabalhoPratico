#include"funcoes.h"

void CadastrarAluno(tAlunosEmp *v, int &n){
    printf("Total de alunos cadastrados: [%d]", n);
    printf("\n\nInforme o Nome, RA, Nota da P1, Nota da P2, Nota do Trabalho e a Nota da PO nesta ordem: \n");
    fflush(stdin);

    scanf("%[^0-9\t] %d %lf %lf %lf %lf", v[n].Nome,
                                         &v[n].RA,
                                         &v[n].P1,
                                         &v[n].P2,
                                         &v[n].T,
                                         &v[n].PO);

    CalcMF(v, n);
    Situacao(v, n);
    OrdenaAlunos(v, n);

    printf("\nAluno cadastrado com sucesso!\n");

    Timer();
    system("CLS || clear");
    n++;
}

void BuscarAluno(tAlunosEmp *v, int n){
    int resultalunos = 0;
    char bscaluno[MAX];
    printf("Informe o nome do aluno: ");

    OrdenaAlunos(v, n);
    
    fflush(stdin);
    scanf("%s", bscaluno);

    printf("\nNome do aluno\t\t\tMedia Final\t\t  Situacao\n\n");

    for(int a1 = 0; a1 < n; a1++){
        char temp[MAX];
        strcpy(temp, v[a1].Nome);

        if(strstr(strupr(temp), strupr(bscaluno)) != NULL){
            printf("%-25s\t\e[1m%7.1lf\e[0m\t\t\t",  v[a1].Nome,
                                                     v[a1].MF);

            if(v[a1].MF >= 6){
                printf("\033[1;32m%10s\033[0m\n", v[a1].Situacao);
            }
            else{
                printf("\033[1;31m%10s\033[0m\n", v[a1].Situacao);
            }
            resultalunos++;
        }
    }

    printf("\nTotal de alunos encontrados: [%d]\n\n", resultalunos);
}

void LerArquivo(tAlunosEmp *v, int &n){
    FILE *p;
    char arq[MAX];
    int alunos_lidos = 0;

    printf("Digite o nome do arquivo que deseja ler: \n");
    fflush(stdin);
    scanf("%s", arq);

    p = fopen(arq, "r");
    if(p == NULL){
        printf("\nERRO! O arquivo nao pode ser aberto por algum motivo.\n\n");
    }
    else{
        while(feof(p) == 0){
            fscanf(p, "%[^0-9\t] %d %lf %lf %lf %lf\n", v[n].Nome,
                                                        &v[n].RA,
                                                        &v[n].P1,
                                                        &v[n].P2,
                                                        &v[n].T,
                                                        &v[n].PO);
            CalcMF(v, n);
            Situacao(v, n);
            n++;
            alunos_lidos++;
        }
        printf("\nForam cadastrados [%d] alunos!\n\n", alunos_lidos);

        OrdenaAlunos(v, n);
        
        fclose(p);
    }
}

void GerarAprovados(tAlunosEmp *v, int n){
    FILE *p;
    int total_aprovados = 0;


    if(n < 1){
        printf("Nao ha alunos cadastrados.\n\n");
    }
    else{
        p = fopen("aprovados.txt", "w+");
        for(int b1 = 0; b1 < n; b1++){
            if(v[b1].MF >= 6){
                fprintf(p, "%-30s\t\t%d\t\t%6.1lf\n", v[b1].Nome, 
                                                      v[b1].RA, 
                                                      v[b1].MF);
                total_aprovados++;
            }
        }
        fprintf(p, "Total: %d\n", total_aprovados);
        fclose(p);
        printf("O arquivo com alunos aprovados foi criado com sucesso!\n\n");
    }
}

void GerarReprovados(tAlunosEmp *v, int n){
    FILE *p;
    int total_reprovados = 0;


    if(n < 1){
        printf("Nao ha alunos cadastrados.\n\n");
    }
    else{
        p = fopen("reprovados.txt", "w+");
        for(int c1 = 0; c1 < n; c1++){
            if(v[c1].MF < 6){
                fprintf(p, "%-30s\t\t%d\t\t%6.1lf\n", v[c1].Nome, 
                                                         v[c1].RA, 
                                                         v[c1].MF);
                total_reprovados++;
            }
        }
        fprintf(p, "Total: %d\n", total_reprovados);
        fclose(p);
        printf("O arquivo com alunos reprovados foi criado com sucesso!\n\n");
    }
}

void FecharPrograma(tAlunosEmp *v, int n){
    FILE *p;

    if(n > 0){
        p = fopen("atual.txt", "w+");
        for(int d1 = 0; d1 < n; d1++){
            fprintf(p,"%-30s\t\t%d\t%4.1lf%6.1lf%6.1lf%6.1lf\n", v[d1].Nome,
                                                                v[d1].RA,
                                                                v[d1].P1,
                                                                v[d1].P2,
                                                                v[d1].T,
                                                                v[d1].PO);
        }
        fclose(p);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CalcMF(tAlunosEmp *v, int n){
    if(v[n].PO > v[n].P1){
        if(v[n].P2 >= v[n].P1){
            v[n].MF = (0.35 * v[n].PO) + (0.35 * v[n].P2) + (0.3 * v[n].T);
        }
        else if(v[n].P1 > v[n].P2){
            v[n].MF = (0.35 * v[n].P1) + (0.35 * v[n].PO) + (0.3 * v[n].T);
        }
        else{
            v[n].MF = (0.35 * v[n].P1) + (0.35 * v[n].P2) + (0.3 * v[n].T);
        }
    }
    else if(v[n].PO > v[n].P2){
        if(v[n].P1 >= v[n].P2){
            v[n].MF = (0.35 * v[n].P1) + (0.35 * v[n].PO) + (0.3 * v[n].T);
        }
        else if(v[n].P2 > v[n].P1){
            v[n].MF = (0.35 * v[n].PO) + (0.35 * v[n].P2) + (0.3 * v[n].T);
        }
        else{
            v[n].MF = (0.35 * v[n].P1) + (0.35 * v[n].P2) + (0.3 * v[n].T);
        }
    }
    else{
        v[n].MF = (0.35 * v[n].P1) + (0.35 * v[n].P2) + (0.3 * v[n].T);
    }
}

void Situacao(tAlunosEmp *v, int n){
    for(int alpha = 0; alpha <= n; alpha++){
        if(v[alpha].MF >= 6){
            strcpy(v[alpha].Situacao, "Aprovado");
        }
        else{
            strcpy(v[alpha].Situacao, "Reprovado");
        }
    }
}

void OrdenaAlunos(tAlunosEmp *v, int n){
    int min;
    
    for(int beta = 0; beta < n - 1; beta++){
        min = beta;
        for(int gamma = beta + 1; gamma < n; gamma++){
            if(strcmp(v[gamma].Nome, v[min].Nome) < 0){
                min = gamma;
            }
            else if(strcmp(v[gamma].Nome, v[min].Nome) == 0){
                if(v[min].RA > v[gamma].RA){
                    min = gamma;
                }
            }
        }
        TrocaAlunos(v[beta], v[min]);
    }
}

void TrocaAlunos(tAlunosEmp &vAtual, tAlunosEmp &vMin){
    tAlunosEmp aux;

    aux = vAtual;
    vAtual = vMin;
    vMin = aux;
}

void Timer(){
    struct timespec tim, tim2;
    tim.tv_sec  = 1;
    tim.tv_nsec = 0;

    nanosleep(&tim, &tim2);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
