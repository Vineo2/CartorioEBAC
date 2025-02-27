#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsavel por cadastras os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//Inicio da ciração de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da ciração de variáveis/strings
	
	printf("Digite o CPF a ser casdastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string, salvar a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	char *token;

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");
    if (file == NULL) 
	{
        printf("\nCPF inválido ou não encontrado no banco de dados!\n");
        printf("\n\n");
        system("pause");
        return 1;
    }

    printf("\nInformações do usuário:\n");
    fgets(conteudo, 200, file); // Lê a linha do arquivo
    token = strtok(conteudo, ","); // Divide a linha em tokens que ajuda a separar cada informação dada
    
    printf("\n\n");
    printf("CPF: %s\n", token); //  Mostra o CPF
    token = strtok(NULL, ","); // Avança para o próximo token
    printf("Nome: %s\n", token); // Mostra o nome
    token = strtok(NULL, ","); // Avança para o próximo token
    printf("Sobrenome: %s\n", token); // Mostra o sobrenome
    token = strtok(NULL, ","); // Avança para o próximo token
    printf("Cargo: %s\n", token); // Mostra o cargo
    printf("\n\n");
    
    fclose(file);
    system("pause");
    return 0;
}

int deletar()
{
	char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    if (remove(cpf) == 0)
    {
        printf("Usuário deletado com sucesso!\n");
    }
    else
    {
        printf("Erro: usuário não encontrado.\n");
    }
    
    system("pause");
    return 0;
}


int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	while(laco == 1)
{
	system("cls");
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("\t-> Cartório da EBAC <-\n\n"); //inicio do menu
	printf(" Escolha a opção desejada no menu abaixo:\n\n");
	printf("\t1 - Registrar Nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - Deletar Nomes\n\n"); 
	printf("Opçao: "); //fim do menu
	
	if (scanf("%d", &opcao) != 1) //Verificaçao para ver se a opção selecionada é um número, bugs ocorriam quando era uma letra
	{
	    system("cls");
		printf("Por favor, insira um número válido.\n");
		printf("\n\n");
		while (getchar() != '\n');
		system("pause");
		continue;
		
	}
	
	system("cls"); //Responsável por limpar a tela
	
	switch(opcao) //Inicio da seleção do menu
		  {
		  	case 1:
		  	registro(); //Chamada de funções
	         break;
	         
	        case 2:
	         consulta();
	         break;
	         
	        case 3:
			 deletar();
	         break;
	         
	        default:
	         printf("Essa opção não está disponivel!\n");
	         printf("\n\n");
             system("pause");	
	         break;   
			 //Fim da seleção 
		  }	 
	
    }
    return 0;
}
