#include <stdio.h>  //biblioteca de comunicação do usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocaçõens de texto por região
#include <string.h> //biblioteca responsavel pro cuidar das string

int registro() //função responsavel por cadastrar os usuarios do sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("digite o CPF a ser cadastrado:"); //coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel pro copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"a");
	fclose(file);
	
	file =fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file= fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //difinindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200,file) !=NULL)
	{
		printf("\nEssas são as informaçõens do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario não se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
    {
    int opcao=0; //difinindo variaveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartorio da EBAC ###\n\n");
	printf("login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao =strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)	
	{
	 system("cls");
	 for(laco=1;laco=1;)
	 {
	 	
	 	setlocale(LC_ALL,"portuguese"); //definindo a linguagem
	 	
	 	printf("### cartorio da EBAC ###\n\n"); //inicio do menu
	 	printf("Escolha a opção desejada do menu\n\n");
	 	printf("\t1 - registrar nomes\n");
	 	printf("\t2 - consultar nomes\n" );
	 	printf("\t3 - Deletar nomes\n\n");
	 	printf("\t4 - Sair do sistema\n\n");
	 	printf("opção: "); //fim do menu
	 	
	 	scanf("%s", &opcao); //armazenamento a escolha do usuario
	 	
	 	system("cls"); //responsavel pro limpar a tela
	 	
	 	switch(opcao) //inicio da seleção do menu
	 	{
	 		case 1:
	 	    registro(); //chamada de funçõens
	 	    break;
	 	    
	 	    case 2:
	 	    consulta();
	 	    break;
	 	    
	 	    case 3:
	 	    deletar();
	 	    break;
	 	    
	 	    case 4:
	 	    printf("Obrigado pro utilizar o sistema!\n");
	 	    return 0;
	 	    break;
	 	    
	 	    default:
	 	    printf("Essa opção não está disponivel!\n");
	 	    system("pause");
	 	    break;
	 	    } //fim da seleção
		 }	
	}
	
	else
	     printf("senha incorreta!");
}
