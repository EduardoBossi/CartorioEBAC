#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço em memória.
#include <locale.h> //biblioteca de alocações de texto por região.
#include <string.h> //biblioteca responsável por cuidar das strings.

int registro()
{
setlocale(LC_ALL, "Portuguese");

char arquivo[40];
char cpf[20];
char nome[40];
char sobrenome[40];
char cargo[40];

printf("Digite o CPF a ser cadastrado:");
scanf("%s", cpf);

strcpy(arquivo, cpf); //Responsável por copiar os valores das strings

FILE *file; //Cria o arquivo
file = fopen(arquivo, "w"); //Reconhece o arquivo e abre o arquivo
fprintf(file,cpf); //Salvo o valor da variável
fclose(file); //Fecha o arquivo

file = fopen(arquivo, "a"); //Letra "A", atualiza as informações dentro da pasta.
fprintf(file, ",");
fclose(file);

printf("Digite o nome a ser cadastrado:");
scanf("%s", nome);

file = fopen(arquivo, "a");
fprintf(file, nome);
fclose(file);

file = fopen(arquivo, "a");
fprintf(file, ",");
fclose(file);

printf("Digite o sobrenome a ser cadastrado:");
scanf("%s", sobrenome);

file = fopen(arquivo, "a");
fprintf(file, sobrenome);
fclose(file);

file = fopen(arquivo, "a");
fprintf(file, ",");
fclose(file);

printf("Digite o cargo a ser cadastrado:");
scanf("%s", cargo);

file = fopen(arquivo, "a");
fprintf(file, cargo);
fclose(file);

}
int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}

	while(fgets(conteudo,200, file)!= NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	}


}
int deletar()
{
	setlocale(LC_ALL, "Portuguese");

	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra mais no sistema!\n");
		system("pause");
	}
	
}
int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //Indicando para voltar ao menu
	{
		system("cls"); //Limpar tela a seguir
	
		setlocale(LC_ALL, "Portuguese");
		printf("Cartório EBAC\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes:\n");
		printf("\t2 - Consultar nomes:\n");
		printf("\t3 - Deletar nomes:\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção:");
	
		scanf("%d", &opcao); //Armazena os dados inseridos pelo usuário na variável opção.
		system ("cls");
	
			switch(opcao) //Início da seleção.
		{
			case 1:
			registro();//chamada de funções.
			system("pause");
			break;
		
			case 2:
			consulta();
			system("pause");
			break;
		
			case 3:
			deletar();
			system("pause");
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0; //Encerra o programa.
			break; 
		
			default:	
			printf("Essa opção não está disponível!\n");
			break;
		}//Fim da seleção.
	}

printf("Esse software é de livre uso da comunidade EBAC.");
}


