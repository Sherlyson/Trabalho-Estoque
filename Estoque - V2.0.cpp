#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

typedef struct{
	char nome[50];
	int qnt;
	float preco;
	float venda;
} produto;

int prg=0, i, x=0, cod, opcao, qtp, cod_q;
float saldo=0, vv=0, vlp;

void cadastrar(produto *prod, int *prg)
{ //Função Cadastrar

	int cond, opcao;

	do{
		do{
		    prod = (produto*)realloc(prod,((*prg)+1)*sizeof(produto));
			if (prod==NULL)
	        {
	            printf ("Memoria insuficiente");
	            return;
			}
			printf("Informe o nome do produto: ");
			scanf("%s",prod[*prg].nome);
			printf ("Informe o preco do produto: ");
			scanf ("%f", &prod[*prg].preco);
				if (prod[*prg].preco<=0)
				{
				printf ("Preco invalido\n");
				}
			printf ("Informe a quantidade de produtos: ");
			scanf ("%d", &prod[*prg].qnt);
				if (prod[*prg].qnt<0)
				{
				printf ("Quantidade invalida\n");
				}
			prod[*prg].venda=0;
			x++;
			(*prg)++;
			system ("cls");
		}
		while (cond==1);
		system ("cls");
	}while(opcao==2);

}

void vender(produto *prod)
{ //Função de Vender
	int perg;

    printf("Informe o codigo do produto: ");
	scanf("%d", &cod);
	for(i=0; i<=cod; i++){
    if(cod==i){
		printf("Digite a quantidade que voce quer vender: ");
		scanf("%d", &cod_q);
        qtp=prod[i].qnt;
        }
    }

			if (cod_q<=0 || cod_q>qtp){
				printf("Quantidade de produtos indisponivel\n");
				system("PAUSE");
				system("cls");
			}else{
				vlp=prod[cod].preco;
				vv=cod_q*vlp;
				printf("Total: R$%.2f\n", vv);
				printf("Voce quer concluir a venda?\n\n1- Sim\n2- Nao\n\n>> ");
				scanf("%d", &perg);
					if(perg==1){
					    prod[cod].qnt=prod[cod].qnt-cod_q;
						saldo=saldo+vv;
						printf("Voce vendeu com sucesso!\n");
						prod[cod].venda = prod[cod].venda+cod_q;
	                    system("PAUSE");
						system("cls");
					    }
			        }
			    }

void estoque(produto *prod)
{ //Função de Estoque

    printf ("Seu estoque:\n\n");
	if (x==0){
		printf ("Nenhum produto no estoque\n");
		system("PAUSE");
		system("cls");
		}else{
		    for(i=0; i<prg; i++)
			{
			printf ("||Codigo: %d\t||Nome: %s\t||Preco: R$ %.2f\t||Quantidade: %d\n", i, prod[i].nome, prod[i].preco, prod[i].qnt);
			}
		}
		system("PAUSE");
		system("cls");
}

void vendas(produto *prod)
{ // Função para ver os valores das vendas
	for(i=0;i<prg;i++){
		printf("||Codigo: %d\t||Nome: %s\t||Quantidade em estoque: %d\n", i, prod[i].nome, prod[i].qnt);
		}
		printf("Saldo total: R$%.2f\n", saldo);
		system("PAUSE");
		system("cls");
}

int main(void)
{ // Função do Menu Principal
    system("color F0");

produto *prod;

   prod = (produto*)malloc(sizeof(produto));
    if (prod==NULL)
        {
            printf ("Memoria insuficiente");
            exit(1);
		}

    do{
	    printf("\n~~~~GERENCIADOR DE SUPERMERCADO~~~~BEM VINDO!~~~~\n");
	    printf("\nO que voce quer fazer?\n");
	    printf("\n 1- Adicionar produtos\n 2- Vender produtos\n 3- Ver o estoque\n 4- Ver vendas\n 5- Sair\n");
	    printf("\n~~~~GERENCIADOR DE SUPERMERCADO~~~~BEM VINDO!~~~~\n");
	    printf("\nEscolha o numero da opcao: ");
	    scanf("%d", &opcao);
	    switch(opcao){
	        case (1):
	        	cadastrar(prod, &prg);
			break;
            case(2):
        	    vender(prod);
            break;
            case(3):
        	    estoque(prod);
		    break;
            case(4):
			    vendas(prod);
		    break;
            case(5):
        	    printf("\n\nObrigado por usar o programa!\n\n");
                exit(0);
            break;
            default:
		        printf("Comando invalido\n");
		        system("PAUSE");
		        system("cls");
           }
	    }while(1);
    return 0;
}
