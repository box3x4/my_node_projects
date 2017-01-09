#include <iostream>

using std::cin;
using std::cout;

int main()
{

	/*Mesmo inicio da lista encadeada simples, porém agora ao declarar a estrutura NODE tem que lembrar de declarar também a ponteiro para o nó anterior*/

	struct node
	{
		int num;
		node *prox;
		node *ant;
	};

	struct node *inicio = NULL;
	struct node *fim = NULL;
	struct node *aux;

	int op, num, find;
	do
	{
		cout<<"Menu \n";
		cout<<"1 - Insere no inicio\n";
		cout<<"3 - Consultar lista toda de frente para tras\n";
		cout<<"4 - Consultar lista toda de tras para frente\n";
		cout<<"5 - Remover da lista\n";
		cout<<"6 - Esvaziar a Lista \n";
		cout<<"7 - Sair\n";
		cout<<"Digite Opcao: ";
		cin>>op;

		if (op < 1 || op > 7)
			cout<<"opcao invalida\n";

		if(op==1) /*inserir numero no comeco*/
		{
			cout<<"Numero a ser inserido: ";
			node *novo=new node();
			cin>>novo->num;
			novo->ant=NULL;
			novo->prox=NULL;
			aux=inicio;
			
			if(inicio==NULL)
			{
				inicio=novo;
				fim=novo;
				inicio->prox=NULL;
			}
			
			else
			{
				while(aux!=NULL && novo->num>aux->num)
					aux=aux->prox;
					
				if(aux==inicio)
				{
					novo->prox=inicio;
					novo->ant=NULL;
					inicio=novo;
					aux->ant=novo;
				}
				else
				{
					if(aux==NULL)
					{
						fim->prox=novo;
						novo->ant=fim;
						novo->prox=NULL;
						fim=novo;
					}
					else
					{
						aux->ant->prox=novo;
						novo->ant=aux->ant;
						novo->prox=aux;
						aux->ant=novo;
					}
				}
			}
		}
		
		if(op==3) /*listagem normal*/
		{
			if(inicio==NULL)
				cout<<"Lista Vazia!\n";
			
			/*Mesmo esquema da listagem normal em uma lista simplesmente encadeada*/
			
			else
			{
				aux=inicio;
				while(aux!=NULL)
				{
					cout<<aux->num<<" ";
					aux=aux->prox;
				}
				cout<<"\n";
			}
		}
		
		if(op==4) /*listagem invertida */
		{
			if(inicio==NULL)
				cout<<"Lista Vazia!\n";
			
			/*Mesmo esquema da listagem normal, porem o ponteiro "aux" começa no fim, e vem caminhando pelo ponteiro aux->ant*/
			
			else
			{
				aux=fim;
				while(aux!=NULL)
				{
					cout<<aux->num<<" ";
					aux=aux->ant;
				}
				cout<<"\n";
			}
		}
		
		if(op==5)/*retirar numero*/
		{
			if(inicio==NULL)
				cout<<"Lista Vazia!\n";
			else
			{
				cout<<"Numero a ser retirado: ";
				cin>>num;
				aux=inicio;
				find=0;
				
				/*Mesmo esquema da remoção de lista simplesmente encadeada, só mudando a parte especificada ali embaixo*/
				
				while(aux!=NULL)
				{
					if(aux->num==num)
					{
						find=find+1;
						if(aux==inicio)
						{
							inicio=aux->prox;
							delete(aux);
							inicio->ant=NULL;
							aux=inicio;
						}
						else
						{
							if(aux==fim)
							{
								fim=fim->ant;
								delete(aux);
								fim->prox=NULL;
								aux=NULL;
							}
							else
							{
								aux->ant->prox=aux->prox;
								aux->prox->ant=aux->ant;
								node *aux2;
								
								/*Nessa parte, cria um ponteiro auxiliar temporario, para ter um ponteiro para o auxiliar fixo apontar.
								  Usando isso é possivel fazer a remoção da lista sem declarar um ponteiro adicional "ant"*/
								
								aux2=aux->prox;
								delete(aux);
								aux=aux2;
							}
						}
					}
					else
						aux=aux->prox;
				}
				
				if(find==0)
					cout<<"Numero nao encontrado!\n";
				else
					cout<<"Numero encontrado"<<find<<"vez(es)\n";
			}
		}
		
		if(op==6) /*esvaziar lista*/
		{
			if(inicio==NULL)
				cout<<"Lista Vazia!\n";
			else
			{
				aux=inicio;
				
				/*A mesma operação da lista simplesmente encadeada*/
				
				while(aux!=NULL)
				{
					inicio=inicio->prox;
					delete(aux);
					aux=inicio;
				}
			}
		}
	}while(op!=7);
	
	return 0;
}
