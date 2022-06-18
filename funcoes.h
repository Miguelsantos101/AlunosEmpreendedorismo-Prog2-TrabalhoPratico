#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX 100

struct tAlunosEmp{
    char Nome[MAX], Situacao[21];
    int RA;
    double P1, P2, T, PO, MF;
};


void CadastrarAluno(tAlunosEmp *v, int &n);
void BuscarAluno(tAlunosEmp *v, int n);
void LerArquivo(tAlunosEmp *v, int &n);
void GerarAprovados(tAlunosEmp *v, int n);
void GerarReprovados(tAlunosEmp *v, int n);
void FecharPrograma(tAlunosEmp *v, int n);

void CalcMF(tAlunosEmp *v, int n);
void Situacao(tAlunosEmp *v, int n);
void OrdenaAlunos(tAlunosEmp *v, int n);
void TrocaAlunos(tAlunosEmp &v, tAlunosEmp &vMin);
void Timer();
