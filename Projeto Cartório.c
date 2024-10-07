#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()
{
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
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
		printf("N�o foi poss�vel abrir o arquivo. \n");
	}
	
	while(fgets(conteudo, 200, file)  != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema \n");
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
	
		printf("###Cart�rio da EBAC###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //Inicio da sele��o
		{
			case 1:
			registro(); //chamada de fun��es
			break;
				
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;
				
			default:
			printf("Essa op��o n�o est� dispon�vel!");
			break;	
				
		} //fim da sele��o
	
	
		if(opcao==1) //Inicio da sele��o
		{
			printf("Voc� escolheu o registro de nomes!\n");
			system("pause");
		}
		if(opcao==2)
		{
			printf("Voc� escolheu consultar os nomes!\n");
			system("pause");
		}
		if(opcao==3)
		{
			printf("Voc� escolheu deletar nomes!\n");
			system("pause");
		}
		if(opcao>=4 || opcao<=0) //Final da sele��o
		{
			printf("Essa op��o n�o est� dispon�vel!");
			system("pause");
		}//fim da sele��o
	
	}
}
