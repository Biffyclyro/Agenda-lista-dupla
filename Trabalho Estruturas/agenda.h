struct contato{
	char nome[50], sobreNome[50], email[50];
	int tel;
	struct contato *prox, *ant;
};

struct alfa{
	char letra;
	struct alfa *prox, *ant;
	struct contato *raiz;
};

struct favoritos{
	struct favoritos *prox, *ant;
	struct contato *favorito;
};

typedef struct contato Contato;
typedef struct alfa Alfa;
typedef struct favoritos Favoritos;



void completaContato(Contato *c){
	printf("Entre com o sobrenome\n");
	gets(c->sobreNome);
	printf("Entre com email\n");
	gets(c->email);
	printf("Entre com o telefone\n");
	scanf("%d", &c->tel);
	
}


Alfa *ordemAlfa(Alfa *a){
	Contato *novo, *p;
	Alfa *nova, *k;
	char nContato[50];
	k=a;
	printf("Entre com o nome do contato: \n");
//	fflush(stdin);
	gets(nContato);		
	//fflush(stdin);	
	strupr(nContato);
	// Verifica se a letra existe, se n ele cria já com o contato novo
	
	if(k==NULL){
		nova=(Alfa*) malloc(sizeof(Alfa));
		nova->letra=nContato[0];
		nova->ant=NULL;
		nova->prox=NULL;
		//k aqui é null
		novo=(Contato*) malloc(sizeof(Contato));
		strcpy(novo->nome, nContato);		
		novo->prox=NULL;
		novo->ant=NULL;
		nova->raiz=novo;
		completaContato(novo);
		return nova;
	}else{
		if(nContato[0]< k->letra){
			nova=(Alfa*) malloc(sizeof(Alfa));
			nova->letra=nContato[0];
			nova->ant=NULL;
			nova->prox=k;
			k->ant=nova;			
			novo=(Contato*) malloc(sizeof(Contato));
			strcpy(novo->nome, nContato);			
			novo->prox=NULL;
			novo->ant=NULL;
			nova->raiz=novo;
			completaContato(novo);
			return nova;
		}
		for(;k->prox!=NULL && nContato[0] > k->letra ; k=k->prox);
	
		if(k->letra==nContato[0]){
							
			p=k->raiz;
			if(strcmp(p->nome, nContato)>0){
				
				novo=(Contato*) malloc(sizeof(Contato));
				strcpy(novo->nome, nContato);				
				novo->prox=p;
				p->ant=novo;
				novo->ant=NULL;
				k->raiz=novo;
				completaContato(novo);
				return a;	
			}else{
				for(;p->prox!=NULL && strcmp(p->nome, nContato)<0; p=p->prox);
			
				if(strcmp(p->nome, nContato)>0){				
					novo=(Contato*) malloc(sizeof(Contato));
					strcpy(novo->nome, nContato);					
					novo->prox=p;					
					novo->ant=p->ant;				
					p->ant->prox=novo;					
					p->ant=novo;
					completaContato(novo);				
					return a;
						
					
				}else{
				
				
			
					novo=(Contato*) malloc(sizeof(Contato));
					strcpy(novo->nome, nContato);
					
					novo->prox=p->prox;
					novo->ant=p;
					p->prox=novo;
					completaContato(novo);				
					return a;
				}
			}
			
			
		}else{			
			if(k->letra>nContato[0]){
				nova=(Alfa*) malloc(sizeof(Alfa));
				nova->letra=nContato[0];
				nova->ant=k->ant;
				nova->prox=k;
				k->ant=nova;
				nova->ant->prox=nova;
				
				novo=(Contato*) malloc(sizeof(Contato));
				strcpy(novo->nome, nContato);
				
				novo->prox=NULL;
				novo->ant=NULL;
				nova->raiz=novo;
				completaContato(novo);
				return a;
			}
			if(k->prox==NULL){
				nova=(Alfa*) malloc(sizeof(Alfa));
				nova->letra=nContato[0];
				nova->ant=k;
				nova->prox=NULL;
				k->prox=nova;				
				
				novo=(Contato*) malloc(sizeof(Contato));
				strcpy(novo->nome, nContato);
				
				novo->prox=NULL;
				novo->ant=NULL;
				nova->raiz=novo;
				completaContato(novo);
				return a;
			}else{
				
				nova=(Alfa*) malloc(sizeof(Alfa));
				nova->letra=nContato[0];
				nova->ant=k;
				nova->prox=k->prox;
				k->prox->ant=nova;
				
				novo=(Contato*) malloc(sizeof(Contato));
				strcpy(novo->nome, nContato);
				
				novo->prox=NULL;
				novo->ant=NULL;
				nova->raiz=novo;
				completaContato(novo);
				return a;
			}
			
		}
	}
	
		
	
	
	return a;
}



Favoritos *addFavoritos(Favoritos *f, Alfa *a){
	Alfa *k;
	Contato *p;
	Favoritos *novo, *s;
	char nFavorito[50];
	printf("Entre com o nome do contato a ser adicionado: \n");
	//fflush(stdin);
	gets(nFavorito);
	strupr(nFavorito);
	for(k=a; k->letra < nFavorito[0]; k=k->prox);
	
	for(p=k->raiz; strcmp(nFavorito, p->nome)!=0; p=p->prox)puts(p->nome);
	
	if(f==NULL){
		novo=(Favoritos*) malloc(sizeof(Favoritos));
		novo->ant=NULL;
		novo->prox=NULL;
		novo->favorito=p;
		return novo;
	}else{
		for(s=f; s->prox!=NULL; s=s->prox);	
		puts(p->nome);
		novo=(Favoritos*) malloc(sizeof(Favoritos));
		novo->favorito=p;
		novo->ant=s;
		novo->prox=NULL;
		s->prox=novo;
		return f;
	}
	
	
	
}



void imprimeContato(Alfa *a){
	Contato *p;
	for(p=a->raiz; p!=NULL; p=p->prox){
		puts(p->nome);
		puts(p->sobreNome);
		puts(p->email);
		printf("%d\n", p->tel);
		
	}
	
}


void exibeTudo(Alfa *a){
	Alfa *k;
	Contato *p;
	
	for(k=a; k!=NULL; k=k->prox){
		printf(" %c\n", k->letra);		
			imprimeContato(k);	
		
	}
}

Favoritos *excluiFavorito(Favoritos *f){
	Favoritos *ff;
	char nome[50];
	printf("Entre com o nome do favorito:\n");
	fflush(stdin);
	gets(nome);
	strupr(nome);
	ff=f;
	
	if(ff->ant==NULL && ff->prox==NULL){
		free(ff);
		return NULL;
		
	}
	if(ff->ant==NULL){		
		
		free(ff);
		ff=ff->prox;
		ff->ant=NULL;
		return ff;
	}

	for(; strcmp(ff->favorito->nome, nome)!=0; ff=ff->prox);
	puts(ff->favorito->nome);
	
	if(ff->prox==NULL){
		ff->ant->prox=NULL;		
		free(ff);
		return f;
	}else{
		ff->ant->prox=ff->prox;
		ff->prox->ant=ff->ant;
		free(ff);
		return f;
	}	
	
}


Alfa *excluiContato(Alfa *a, Favoritos *f){
	Contato *p;
	Alfa *k, *n;
	Favoritos *ff;
	char nome[50];
	printf("Entre com o nome do contato\n");
	fflush(stdin);
	gets(nome);
	strupr(nome);
	k=a;
	for(; k->letra != nome[0]; k=k->prox);
	
	p=k->raiz;
	for(;strcmp(p->nome, nome)!=0; p=p->prox);
	if(f!=NULL){
		for(ff=f; strcmp(ff->favorito->nome, p->nome)!=0 && ff->prox!= NULL; ff=ff->prox);
	//	printf("%c", ff->favorito->nome[0]);
		if(strcmp(ff->favorito->nome, p->nome)){
			f=excluiFavorito(ff);
		}
	}
	
	if(p->prox == NULL && p->ant==NULL){
		free(p);
		
		if(k->prox ==NULL && k->ant==NULL){
			
			
			free(k);
			return NULL;
		}
		if(k->ant==NULL){
			printf("aqui\n");
			k->prox->ant=NULL;		
			printf("%c\n", k->prox->letra);
			n=k->prox;
			free(k);
			
			printf("%c\n", k->prox->letra);
			return n;
		}
		if(k->prox==NULL){
			k->ant->prox=NULL;
			free(k);
			return a;
		}else{
			k->prox->ant=k->ant;
			k->ant->prox=k->prox;
			free(k);
			return a;
		}
		
	}else{
		if(p->prox==NULL){
			p->ant->prox=NULL;
			free(p);
			return a;
		}
		if(p->ant==NULL){
			p->prox->ant=NULL;
			k->raiz=p->prox;
			free(p);
			return a;
		}else{
			p->prox->ant=p->ant;
			p->ant->prox=p->prox;
			free(p);
			return a;
		}
	}
	
	
	
}

void imprimeFavoritos(Favoritos *f){
	Favoritos *ff;
	ff=f;
	if(ff==NULL){
		printf("Lista de favoritos vazia!!\n");
		return;
	}
	
	for(; ff!= NULL; ff=ff->prox)puts(ff->favorito->nome);
	return;
	
	
	
}




