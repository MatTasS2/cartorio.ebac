#include <stdio.h> // bicblioteca de comunicaçaoem com o usuario
#include <stdlib.h> //biblioteca de alocaçao de espaço de memoria 
#include <locale.h> //biblioteca de alocaçoes de texto por regiao
#include <string.h> // biblioteca reponsavel por cuidar da string


int registro() // funçao reponsavel por cadasto

{
//inicio da variaveis/string
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
// fim da variavel/string de cadastro
    
    printf ("digite seu cpf: ");// coletando infomaçao do usuario
    scanf("%s", cpf);//%s refere-se a string/salvando valor
    
    strcpy(arquivo, cpf); // responsavel copiar os valores das string
    
	FILE *file; //cria o arquivo
    file= fopen( arquivo, "w");   //cria o arquivo "w" significa escrever
    fprintf(file,cpf);//salvo o valor da variavel
    fclose(file);//fecho o arquivo
    
    file = fopen(arquivo, "a");//abrindo arquiv e atualizando com "a"
    fprintf(file, ",");//pulando linha 
    fclose(file);//fechando arqu aberto
    
    printf("digite seu nome: ");
    scanf("%s",  nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    
    printf("digite seu sobrenome: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("digite seu cargo: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    system ("pause");

}

int consultar()
{
  setlocale(LC_ALL, "portuguese" );//definindo a linguage	
	
 
  char conteudo[200];
  char cpf[40];
  
  
  
  printf("digite o cpf a ser consultado: ");
  scanf("%s" , cpf);
  
  FILE *file;//localizando arqui
  file = fopen(cpf,"r");//abrindo arquiv e rescrevendo
  
  strcpy(conteudo, cpf);
  
  if(file == NULL)//se arqui for nulo 
  {
  printf ("não cadastrado!\n");	
  }
  
	 
  while(fgets(conteudo,200,file)!= NULL); 
  {
  printf("t- informações do usuário:");
  printf("\n\n");
  printf("%s",conteudo);
  printf("\n\n");

  }
   system("pause");    
  }


int deletar()
{
    char cpf[40];
    
    printf("digite o cpf: ");
	scanf("%s", cpf );
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL) //buscando cpf digitado , se nn encontrado igual a "nao cadastrado"
    {
         printf("não cadastrado! \n");
         system("pause");
    }
    
    else
	
	{
    if(remove(cpf)==0) //removendo cpf encontrado
	printf("usuário removido com sucesso");
	system("pause");  
	}
	 	
	
}

int main()
{
    int opcao=0; // definindo as variaves
	int c=1;

		
	for(c=1; c=2; ) // inicio do ciclo de rep
{   
	
	system("cls");//reponsavel por limpa a tela
	
    setlocale(LC_ALL, "portuguese" );//definindo a linguagem
    
    
        printf  ("### cartório da ebac ###\n\n");//começo do menu
	    printf  ("escolha a opçao desejada do menu:\n\n");
	    printf  ("\t1 - registra nomes\n");
	    printf  ("\t2 - consultar nomes\n");
       	printf  ("\t3 - deletar nomes\n");// fim do menu
	    printf("\n opçao: ");
	
	    scanf("%d", &opcao); //armazenando as opçoes escolhidas
        system("cls");
	    
	  switch(opcao)  
      {
	  
      	case 1:
      	registro();//chama as funções
      	break;
      	
      	case 2:
      	consultar();
	    break;
	    
	    case 3:
	    deletar();
	    break;
	    
	    default:
	    printf("essa opçao nao esta disponivel\n"); //fim da seleções
	    system("pause");
       	break;
        
		}//fim da seleção
	   
	 	

 }// fim do ciclo de rep
	
	
}




