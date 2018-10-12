#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"agenda.h"



main(){
	int x;
	int resp=0;
	Contato *c;
	Alfa *a;
	Favoritos *f;
	c=NULL;
	a=NULL;
	f=NULL;
	
	while(resp==0){
		
		printf("Escolha a opcao:\n");
		printf("1. Inserir.\n");		
		printf("2. Add Favorito. \n");
		printf("3. Exibe letra.\n");
		printf("4. Exibe tudo.\n");
		printf("5. Exibir favoritos.\n");
		printf("6. Excluir favorito.\n");
		printf("7. Excluir contato.\n");
		printf("8. Sair.\n");
	
		scanf("%d",&x);
		switch(x){
			case 1:{
		
				fflush(stdin);
				a=ordemAlfa(a);
				fflush(stdin);
				break;
			}			
		
			
			case 2:{
				fflush(stdin);
				f=addFavoritos(f,a);
				break;
			}
			
			case 3:{
				char x[10];
				Alfa *k;
				printf("Entre com a letra:\n");
				fflush(stdin);
				gets(x);
				fflush(stdin);
				strupr(x);				
	
				for(k=a; k->letra!=x[0]; k=k->prox)printf(" %c\n", k->letra );
				imprimeContato(k);
				break;
			}
			
			case 4:{
				exibeTudo(a);
				break;
			}
			
			case 5:{
				imprimeFavoritos(f);
				break;
			}
			
			case 6:{
			
				f=excluiFavorito(f);
				
				break;
			}
			case 7:{
				a=excluiContato(a,f);
				if(sizeof(f)!= sizeof(Favoritos))f=NULL;		
				break;
			}
			
			case 8:{
				printf("\nSaindo...\n");
				resp++;
				break;
			}
			
			default:{
				printf("Valor invalido!!\n");
				break;
			}
		}
	}
}











