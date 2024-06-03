#include <stdio.h> // biblioteca de comunicaçao com o usuario
#include<stdlib.h> // biblioteca de alocaçao espaço de memoria
#include<locale.h> // biblioteca de alocaçao de texto por regiao
#include<string.h> // biblioteca responsavel por cuidas das string

int registro() //funçao responsavel pro cadastrar os usuarios no sistema
{
	//inicio criaçao de variaveis/string
    char arquivo [40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criaçao de variaveis/string   
	
	printf("digite o cpf a ser cadastrado:"); //coletando informaçao do usuario
	scanf("%s",cpf); //%s refere-se a string

   strcpy(arquivo,cpf); //responsavel por copiar os valores das string
   
   FILE *file; // cria o arquivo
   
   file=fopen(arquivo,"w");// cria o arquivo e o 'w' significa escrever
   fprintf(file,cpf);// salvo o valor da variavel
   fclose(file);// fecho o arquivo
   
   file=fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   printf("digite o nome a ser cadastrado:");
   scanf("%s",nome);
   
   file=fopen(arquivo,"a");
   fprintf(file,nome);
   fclose(file);
   
    file=fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   printf("digite o sobrenome a ser cadastrado");
   scanf("%s",sobrenome);
   
   file=fopen(arquivo,"a");
   fprintf(file,sobrenome);
   fclose(file);
   
   printf("digite o cargo a ser cadastrado: ");
   scanf("%s",cargo);
   
   file = fopen(arquivo,"a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
   
   
}
int consultar()
{
     setlocale(LC_ALL, "portuguese");
   
     char cpf[40];
     char conteudo[200];
     
     printf("digite o cpf a ser consultado:");
     scanf("%s",cpf);
     
     FILE *file;
     file= fopen(cpf,"r");
     
     if(file == NULL)
     {
     	printf("nao foi possivel abrir o arquivo,nao localizado!.\n");
	 }
	 
	 while(fgets(conteudo,200,file)!=NULL)
	 {
	 	printf("\n essas sao as informaçõens do usuario:");
	 	printf("%s",conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");
 

}
int deletar()
{
    char cpf[40];
    
    printf("digite o cpf a ser deletado:");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE*file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf(" o usuario nao se encontra no sistema/n");
    	system("pause");
	}
}

int main()
{
	
    int opcao=0; //definindo variaveis	
    int laco=1;
 
    for(laco=1;laco=1;)
{

	setlocale(LC_ALL, "portuguese"); //definindo linguagem

	printf("###cartorio da ebac###\n\n"); //inicio do menu
	printf("escolha opçao desejada no menu:\n");
	printf("\t1 - registrar nomes\n");
	printf("\t2 - consultar nomes\n");
	printf("\t3 - deletar  nomes\n");
	printf("esse softre e livre uso  dos alunos\n\n"); // fim do menu
	
	scanf("%d", &opcao); // armazenando a escolha do usuario
	
	system("cls"); //responsavel por limpar a tela
	
	switch(opcao) // inicio da seleçao do menu
	{
		case 1:
			registro(); //chamada de funcoens
			system("pause");
			break;
		
		case 2:
			consultar();
			system("pause");
			break;
			
		case 3:
			deletar();
			system("pause");
			break;
			
		default:
		 printf("essa opcao nao esta disponivel");
		 system("pause");
		 break;
	}
	
}
}
