#include <stdio.h>
#include <stdlib.h>

//Cadastro de aluno
typedef struct
{
    char nome[100];
    float nota;
    int mat;

} Aluno;

aloc_vetor()
{
    int i;
    Aluno *p;
    p=(Aluno*)malloc(sizeof(Aluno)*3);
    if(p==NULL)
    {
        printf("nao foi possivel alocar");
        exit(1);
    }

    return p;
}


void arquivar()
{
    int i;
    FILE* fd;
    Aluno *p;
    fd = fopen("Alunos.txt","r");
    if(fd==NULL)
    {
        printf("Não foi possível criar o arquivo\n");
        exit(1);
    }

    for(i=0; i<3; i++)
    {
        fscanf(fd, "Aluno: %s\nNota: %f\nMatricula: %d\n",(p+i)->nome,&(p+i)->nota,&(p+i)->mat);
    }



    fclose(fd);//fecha e salva o arquivo

}

void imprimir()
{
int i;
Aluno*p;

 for(i=0; i<3; i++)

    {
        printf("Aluno: %s\nNota: %.1f\nMatricula: %d\n",(p+i)->nome,(p+i)->nota,(p+i)->mat);
        printf("\n");
    }

}

int main()
{

    int i;
    FILE* fd;
    Aluno *p;
    p=aloc_vetor();
    arquivar();
    imprimir();
    free (p);
    return 0;
}
