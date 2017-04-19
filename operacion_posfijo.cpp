#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo
{
    int num;
    nodo *siguiente;
};

struct nodo2
{
    char oper;
    nodo2 *siguiente;
};

void ingresar_posfija(nodo *&, nodo2 *&, char *);
void mostrar_pila(nodo *, nodo2 *);
void opercaion_posfija(nodo *&, nodo2 *&, char *);

int main()
{
    nodo *pila=NULL;
    nodo2 *pila2=NULL;
    char a[50], *pa=a;
    int n;

    ingresar_posfija(pila,pila2,pa);
    mostrar_pila(pila,pila2);
    opercaion_posfija(pila,pila2,pa);
    printf("El resultado es: ");
    while(pila!=NULL)
    {
        nodo *aux=pila;
        n=aux->num;
        pila=aux->siguiente;
        printf("%d",n);
    }

}

void ingresar_posfija(nodo *&pila, nodo2 *&pila2, char *pa)
{
    char a[10];
    int n, c=0;
    printf("Ingrese operacion posfija dejando espacio despues de cada numero: ");
    fgets(pa,50,stdin);

    for(int i=0;i<strlen(pa);i++)
    {
        if(pa[i]!=' ')
        {
            a[c]=pa[i];
            c++;
        }
        else
        {
            n=atoi(a);
            nodo *nuevo_nodo=(nodo*)malloc(sizeof(nodo));
            nuevo_nodo->num=n;
            nuevo_nodo->siguiente=pila;
            pila=nuevo_nodo;
            for(int r=0;r<c;r++)
            {
                a[r]=' ';
            }
            c=0;
        }

        if(pa[i]=='+' || pa[i]=='-' || pa[i]=='*' || pa[i]=='/' || pa[i]=='^')
        {
            nodo2 *nuevo2=(nodo2*)malloc(sizeof(nodo2));
            nuevo2->oper=pa[i];
            nuevo2->siguiente=pila2;
            pila2=nuevo2;
        }
    }

}

void mostrar_pila(nodo *pila, nodo2 *pila2)
{
    int n;
    char c;
    printf("PILA NUMEROS:\n");
    while(pila!=NULL)
    {
        nodo *aux=pila;
        n=aux->num;
        pila=aux->siguiente;
        printf("%d\n",n);
    }

    printf("\nPILA OPERADORES:\n");
    while(pila2!=NULL)
    {
        nodo2 *aux2=pila2;
        c=aux2->oper;
        pila2=aux2->siguiente;
        printf("%c\n",c);
    }

}

void opercaion_posfija(nodo *&pila, nodo2 *&pila2, char *pa)
{
    int n;
    for(int i=0;i<strlen(pa);i++)
    {
        switch(pa[i])
        {
        case '+':
            {
                nodo *aux=pila;
                n=aux->num;
                pila=aux->siguiente;
                pila->num=n+pila->num;
                free(aux);
                //printf("%d ",pila->num);
            }break;
        case '-':
            {
                nodo *aux=pila;
                n=aux->num;
                pila=aux->siguiente;
                pila->num=n-pila->num;
                free(aux);
                //printf("%d ",pila->num);
            }break;
        case '*':
            {
                nodo *aux=pila;
                n=aux->num;
                pila=aux->siguiente;
                pila->num=n*pila->num;
                free(aux);
                //printf("%d ",pila->num);
            }break;
        case '/':
            {
                nodo *aux=pila;
                n=aux->num;
                pila=aux->siguiente;
                pila->num=n/pila->num;
                free(aux);
                //printf("%d ",pila->num);
            }break;
        }
    }
}

