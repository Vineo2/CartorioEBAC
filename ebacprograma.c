#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o responsavel por cadastras os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//Inicio da cira��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cira��o de vari�veis/strings
	
	printf("Digite o CPF a ser casdastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string, salvar a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da vari�vel
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
        printf("\nCPF inv�lido ou n�o encontrado no banco de dados!\n");
        printf("\n\n");
        system("pause");
        return 1;
    }

    printf("\nInforma��es do usu�rio:\n");
    fgets(conteudo, 200, file); // L� a linha do arquivo
    token = strtok(conteudo, ","); // Divide a linha em tokens que ajuda a separar cada informa��o dada
    
    printf("\n\n");
    printf("CPF: %s\n", token); //  Mostra o CPF
    token = strtok(NULL, ","); // Avan�a para o pr�ximo token
    printf("Nome: %s\n", token); // Mostra o nome
    token = strtok(NULL, ","); // Avan�a para o pr�ximo token
    printf("Sobrenome: %s\n", token); // Mostra o sobrenome
    token = strtok(NULL, ","); // Avan�a para o pr�ximo token
    printf("Cargo: %s\n", token); // Mostra o cargo
    printf("\n\n");
    
    fclose(file);
    system("pause");
    return 0;
}

int deletar()
{
	char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    if (remove(cpf) == 0)
    {
        printf("Usu�rio deletado com sucesso!\n");
    }
    else
    {
        printf("Erro: usu�rio n�o encontrado.\n");
    }
    
    system("pause");
    return 0;
}


int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	while(laco == 1)
{
	system("cls");
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("\t-> Cart�rio da EBAC <-\n\n"); //inicio do menu
	printf(" Escolha a op��o desejada no menu abaixo:\n\n");
	printf("\t1 - Registrar Nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - Deletar Nomes\n\n"); 
	printf("Op�ao: "); //fim do menu
	
	if (scanf("%d", &opcao) != 1) //Verifica�ao para ver se a op��o selecionada � um n�mero, bugs ocorriam quando era uma letra
	{
	    system("cls");
		printf("Por favor, insira um n�mero v�lido.\n");
		printf("\n\n");
		while (getchar() != '\n');
		system("pause");
		continue;
		
	}
	
	system("cls"); //Respons�vel por limpar a tela
	
	switch(opcao) //Inicio da sele��o do menu
		  {
		  	case 1:
		  	registro(); //Chamada de fun��es
	         break;
	         
	        case 2:
	         consulta();
	         break;
	         
	        case 3:
			 deletar();
	         break;
	         
	        default:
	         printf("Essa op��o n�o est� disponivel!\n");
	         printf("\n\n");
             system("pause");	
	         break;   
			 //Fim da sele��o 
		  }	 
	
    }
    return 0;
}
