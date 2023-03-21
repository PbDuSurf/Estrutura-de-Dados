#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

typedef struct CadastroPiloto {
	
char nomeCompleto[20];
char nacinalidade[20];
char corPele[20];
char corOlhos[20];
char corCabelo[20];
char altura[20];
char peso[20]; 
char idade[20];
char qntCampeonatoGanho[20];
char polePosition[20];
char voltasMaisRapidas[20];

} Piloto;

typedef struct cadastroCarro {

char nomeCompleto[20];
char comprimento[20];
char largura[20];
char altura[20];
char peso[20];
char motor[20];
char aceleracao[20]; 
char capacidTanque[20];
char caixaCambio[20];
char roda[40];
char qntEtanolCombustivel[20];

} Carro;

typedef struct cadastroEquipe {
	
char nomeCompleto[30];	
char nacionalidade[20];
char qntMembros[20];
char qntTitulosConstrutores[20];
char qntTitulosCondutores[20];
char polePositions[20];
char voltasMaisRapidas[20];
char vlrMercado[20];
char txInscricao[20];
char corEquipe[20];
char chefeEquipe[20];
char diretComercial[20];
char diretTecnico[20];
char aerodinamicistaChefe[20];
char projetistaChefe[20];
char chefePesquisaDesenvol[20];
char chefeMecanicos[20];
char tecPneus[20];
char tecComponentes[20];
char tecTransmissao[20];
char tecCombustivel[40];
char  mecpitstop[20];

} Equipe ;

//Declaração das variáveis
int input = 0;
int qtdPiloto;
int tamPiloto;
Piloto *piloto;
int qtdCarro;
int tamCarro;
Carro *carro;
int qtdEquipe;
int tamEquipe;
Equipe *equipe;
FILE *arquivo;
char cliente_dir[] = "Clientes.bin";

//Declaração dos Procedimentos e Funções a serem utilizados
void menuPrincipal();
void menuPiloto();
void menuCarro();
void menuEquipe();
void menuAlterarCliente();
void removerQuebraLinha();
Piloto receberPiloto();
Carro receberCarro();
Equipe receberEquipe();
void inserirPiloto();
void inserirCarro();
void inserirEquipe();

//Início do main
int main(int argc, char** argv) {
    menuPrincipal();
    return 0;
}

void erro(char *nome_arquivo) {
    printf("Nao foi possivel abrir o arquivo %s\n", nome_arquivo);
}

void sucesso() {
    system("cls");
    printf ("Operacao realizada com sucesso!");
}

void menuPrincipal() {
    do {
        printf("\n");
        printf ("\t\t\t\t  MENU PRINCIPAL!\n");
        printf ("\t\t\t===============================\n");
        printf ("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Menu Piloto          |\n");
        printf("\t\t\t|    2 - Menu Equipe          |\n");
        printf("\t\t\t|    3 - Menu Carro           |\n");
        printf("\t\t\t|\t  0 - Sair            |\n");
        printf ("\t\t\t|\t                      |\n");
        printf ("\t\t\t===============================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input) {
        case 1:
            menuPiloto();
            break;
        case 2:
        	menuEquipe();
            break;
        case 3:
        	menuCarro();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(input != 0);
    system("cls");
}

void menuPiloto() {
    do {
        printf("\n");
        printf ("\t\t\t\t       MENU PILOTO!\n");
        printf ("\t\t\t=========================================\n");
        printf ("\t\t\t|\t                                |\n");
        printf("\t\t\t|    1 - Listar Piloto                  |\n");
        printf("\t\t\t|    2 - Buscar Piloto                  |\n");
        printf("\t\t\t|    3 - Cadastrar Piloto               |\n");
        printf("\t\t\t|    4 - Alterar Cadastro de Piloto     |\n");
        printf("\t\t\t|    5 - Excluir Cadastro               |\n");
        printf("\t\t\t|    6 - Menu Principal                 |\n");
        printf("\t\t\t|    0 - Sair                           |\n");
        printf ("\t\t\t|                                       |\n");
        printf ("\t\t\t=========================================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input) {
        case 3:
            fflush(stdin);
            inserirPiloto(receberPiloto());
            break;
        case 6:
            menuPrincipal();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(input != 0);
    system("cls");
}

void menuEquipe() {
    do {
        printf("\n");
        printf ("\t\t\t\t       MENU EQUIPE!\n");
        printf ("\t\t\t=========================================\n");
        printf ("\t\t\t|\t                                |\n");
        printf("\t\t\t|    1 - Listar Equipe                  |\n");
        printf("\t\t\t|    2 - Buscar Equipe                  |\n");
        printf("\t\t\t|    3 - Cadastrar Equipe               |\n");
        printf("\t\t\t|    4 - Alterar Cadastro de Equipe     |\n");
        printf("\t\t\t|    5 - Excluir Cadastro               |\n");
        printf("\t\t\t|    6 - Menu Principal                 |\n");
        printf("\t\t\t|    0 - Sair                           |\n");
        printf ("\t\t\t|                                       |\n");
        printf ("\t\t\t=========================================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input) {
        case 3:
            fflush(stdin);
            inserirEquipe(receberEquipe());
            break;
        case 6:
            menuPrincipal();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(input != 0);
    system("cls");
}
void menuCarro() {
    do {
        printf("\n");
        printf ("\t\t\t\t       MENU CARRO!\n");
        printf ("\t\t\t=========================================\n");
        printf ("\t\t\t|\t                                |\n");
        printf("\t\t\t|    1 - Listar Carro                   |\n");
        printf("\t\t\t|    2 - Buscar Carro                   |\n");
        printf("\t\t\t|    3 - Cadastrar Carro                |\n");
        printf("\t\t\t|    4 - Alterar Cadastro de Carro      |\n");
        printf("\t\t\t|    5 - Excluir Cadastro               |\n");
        printf("\t\t\t|    6 - Menu Principal                 |\n");
        printf("\t\t\t|    0 - Sair                           |\n");
        printf ("\t\t\t|                                       |\n");
        printf ("\t\t\t=========================================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input) {
        case 3:
            fflush(stdin);
            inserirCarro(receberCarro());
            break;
        case 6:
            menuPrincipal();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(input != 0);
    system("cls");
}

void removerQuebraLinha(char *string) {
    if(string != NULL && strlen(string) > 0) {
        short tamanho = strlen(string);
        if(string[tamanho-1] == '\n') {
            string[tamanho-1] = '\0';
        }
    }
}

void receberString(char *string_destino, int quantidade_caracteres) {
    fgets(string_destino, quantidade_caracteres, stdin);
    removerQuebraLinha(string_destino);
}

Piloto receberPiloto() {
    Piloto p;

    printf("Nome do Piloto: ");
    receberString(p.nomeCompleto, 20);
    printf ("Nacionalidade: ");
    receberString(p.nacinalidade, 20);
    fflush(stdin);
    printf ("Cor da Pele: ");
    receberString(p.corPele, 20);
    fflush(stdin);
    printf ("Cor dos Olhos: ");
    receberString(p.corOlhos, 20);
    fflush(stdin);
    printf ("Cor do Cabelo: ");
    receberString(p.corCabelo, 20);
    fflush(stdin);
    printf ("Altura: ");
    receberString(p.altura, 20);
    fflush(stdin);
    printf ("Peso: ");
    receberString(p.peso, 20);
    fflush(stdin);
    printf ("Idade: ");
    receberString(p.idade, 20);
    fflush(stdin);
    printf ("Quantos campeonatos ganhos: ");
    receberString(p.qntCampeonatoGanho, 20);
    fflush(stdin);
     printf ("Quantas PoliPositions: ");
    receberString(p.polePosition, 20);
    fflush(stdin);
     printf ("Quantas voltas mais rapidas: ");
    receberString(p.voltasMaisRapidas, 20);
    fflush(stdin);

    sucesso();
    return p;
    
}

Carro receberCarro() {
    Carro c;

    printf("Nome do Carro: ");
    receberString(c.nomeCompleto, 20);
    printf ("Comprimento do Carro: ");
    receberString(c.comprimento, 20);
    fflush(stdin);
    printf ("Largura do Carro: ");
    receberString(c.largura, 20);
    fflush(stdin);
    printf ("Altura do Carro: ");
    receberString(c.altura, 20);
    fflush(stdin);
    printf ("Peso do Carro: ");
    receberString(c.peso, 20);
    fflush(stdin);
    printf ("Tipo do Motor: ");
    receberString(c.motor, 20);
    fflush(stdin);
    printf ("Aceleracao do Carro: ");
    receberString(c.aceleracao, 20);
    fflush(stdin);
    printf ("Capacidade do Tanque: ");
    receberString(c.capacidTanque, 20);
    fflush(stdin);
    printf ("Aro da Roda: ");
    receberString(c.roda, 20);
    fflush(stdin);
     printf ("Quantidade de Etanol (Combustivel: ");
    receberString(c.qntEtanolCombustivel, 20);
    fflush(stdin);

    sucesso();
    return c;
}

Equipe receberEquipe() {
    Equipe e;

    printf("Nome da Equipe: ");
    receberString(e.nomeCompleto, 20);
    printf ("Nacionalidade: ");
    receberString(e.nacionalidade, 20);
    fflush(stdin);
    printf ("Quantidade de Membros: ");
    receberString(e.qntMembros, 20);
    fflush(stdin);
    printf ("Quantidade de Titulos Construtores: ");
    receberString(e.qntTitulosConstrutores, 20);
    fflush(stdin);
    printf ("Quantidade de Titulos Condutores: ");
    receberString(e.qntTitulosCondutores, 20);
    fflush(stdin);
    printf ("Quantidade de PoliPositions: ");
    receberString(e.polePositions, 20);
    fflush(stdin);
    printf ("Quantidade de Voltas Mais Rapidas: ");
    receberString(e.voltasMaisRapidas, 20);
    fflush(stdin);
    printf ("Valor de Mercado: ");
    receberString(e.vlrMercado, 20);
    fflush(stdin);
    printf ("Taxa de Inscricao: ");
    receberString(e.txInscricao, 20);
    fflush(stdin);
    printf ("Cor da Equipe: ");
    receberString(e.corEquipe, 20);
    fflush(stdin);
    printf ("Nome do Chefe de Equipe: ");
    receberString(e.chefeEquipe, 20);
    fflush(stdin);
    printf ("Nome do Diretor Comercial: ");
    receberString(e.diretComercial, 20);
    fflush(stdin);
    printf ("Nome do Diretor Tecnico: ");
    receberString(e.diretTecnico, 20);
    fflush(stdin);
    printf ("Nome do Aerodinamicista Chefe: ");
    receberString(e.aerodinamicistaChefe, 20);
    fflush(stdin);
    printf ("Nome do Projetista Chefe: ");
    receberString(e.projetistaChefe, 20);
    fflush(stdin);
    printf ("Nome do Chefe de Pesquisa de Desenvolvimento: ");
    receberString(e.chefePesquisaDesenvol, 20);
    fflush(stdin);
    printf ("Nome do Mecanico Chefe: ");
    receberString(e.chefeMecanicos, 20);
    fflush(stdin);
    printf ("Nome do Tecnico de Pneus: ");
    receberString(e.tecPneus, 20);
    fflush(stdin);
    printf ("Nome do Tecnico de Componentes: ");
    receberString(e.tecComponentes, 20);
    fflush(stdin);
    printf ("Nome do Tecnico de Transmissao: ");
    receberString(e.tecTransmissao, 20);
    fflush(stdin);
    printf ("Nome do Tecnico de Combustivel: ");
    receberString(e.tecCombustivel, 20);
    fflush(stdin);
	printf ("Nome dos Mecanicos de Pitstop: ");
  	receberString(e.mecpitstop, 20);
	fflush(stdin);
    
    sucesso();
    return e;
}

void inserirPiloto(Piloto p) {
    if(qtdPiloto == tamPiloto) {
        tamPiloto *= 1.5;
        piloto = realloc(piloto, tamPiloto*sizeof(Piloto));
    }
    piloto[qtdPiloto] = p;
    qtdPiloto++;
}    

void inserirCarro(Carro c) {
    if(qtdCarro == tamCarro) {
        tamCarro *= 1.5;
        carro = realloc(carro, tamCarro*sizeof(Carro));
    }
    carro[qtdCarro] = c;
    qtdCarro++;
}    

void inserirEquipe(Equipe e) {
    if(qtdEquipe == tamEquipe) {
        tamEquipe *= 1.5;
        equipe = realloc(equipe, tamEquipe*sizeof(Equipe));
    }
    equipe[qtdEquipe] = e;
    qtdEquipe++;
}    



