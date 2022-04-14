#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct dados
{
    struct dados *esq;
    int info;
    struct dados *dir;
}

typedef struct dados NO;


void cria_LDE(NO **Inicio, NO **Fim)
{
    *Inicio = NULL;
    *Fim = NULL;
}

void Ins_Inicio(NO **Inicio, NO **Fim, int v)
{
    NO *p;
    p = (NO *) calloc(1, sizeof(NO));
    p->info = v;
    p->esq = NULL;
    p->dir = *Inicio;

    if (*Inicio == NULL)
    {
        *Fim = p;
    }
    else
    {
        (*Inicio)->esq = p;
    }

    *Inicio = p;
}

void Imprime(NO *Inicio)
{
    NO *p;
    p = Inicio;

    printf("\nNULL");
    while (p != NULL)
    {
        printf("<-%d->", p->info);
        p = p->dir;
    }
    printf("NULL\n");
}

main()
{
    NO *Inicio, *Fim;
    int op, val;

    //criando a lista vazia
    cria_LDE(&Inicio, &Fim);

    do 
    {
        system("cls");
        puts("1 - Inserir no Inicio");
        puts("2 - Insernir no Fim");
        puts("3 - Imprimir a Lista");

        puts("0 - Sair do Programa");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &val);
                Ins_Inicio(&Inicio, &Fim, val);
                break;

            case 2:
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &val);
                Ins_Fim(&Inicio, &Fim, val);
                break;

            case 3:
                if (Inicio == NULL)
                {
                    puts("\nLista Vazia!");
                }
                else
                {
                    printf("\nLista: \n");
                    Imprime(Inicio);
                }
                getch();
                break;
            }//fim do switch
    }while(op != 0);
}//main