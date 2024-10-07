#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()
{
	//início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser caddastrado: ");
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings		

	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo. \n");
	}
	
	while(fgets(conteudo, 200, file)  != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema \n");
		system("pause");
	}
	
}

int main()	
	{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco==1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
	
		printf("###Cartório da EBAC###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //Inicio da seleção
		{
			case 1:
			registro(); //chamada de funções
			break;
				
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;
				
			default:
			printf("Essa opção não está disponível!");
			break;	
				
		} //fim da seleção
	
	
		if(opcao==1) //Inicio da seleção
		{
			printf("Você escolheu o registro de nomes!\n");
			system("pause");
		}
		if(opcao==2)
		{
			printf("Você escolheu consultar os nomes!\n");
			system("pause");
		}
		if(opcao==3)
		{
			printf("Você escolheu deletar nomes!\n");
			system("pause");
		}
		if(opcao>=4 || opcao<=0) //Final da seleção
		{
			printf("Essa opção não está disponível!");
			system("pause");
		}//fim da seleção
	
	}
}
