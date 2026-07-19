#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void removeEnter(char str[]){
    for(int i=0 ; str[i] != '\0' ; i++){
        if(str[i] == '\n'){
            str[i] = '\0';
            return;
        }
    }
}

typedef struct paciente *ponteiroPaciente;
typedef struct arvore *ponteiroArvore;

struct paciente{
    char nomePaciente[100];
    char corPaciente[100];
    int valorUrgencia;
    char tipoTriagem[100];
    ponteiroPaciente prox;
};

typedef struct paciente Paciente;

struct arvore{
    char perguntaEstado[100];
    char corUrgencia[100];
    ponteiroArvore esquerda;
    ponteiroArvore direita;
};

typedef struct arvore Arvore;

ponteiroArvore criarNo(char pergunta[] , char cor[]){
    ponteiroArvore novoNo = (ponteiroArvore)malloc(sizeof(Arvore));
    if(novoNo != NULL){
        strcpy(novoNo ->perguntaEstado , pergunta);
        strcpy(novoNo ->corUrgencia , cor);
        novoNo ->esquerda = NULL;
        novoNo -> direita = NULL;
    }

    return novoNo;
}

ponteiroArvore inicializarTriagemCardiaca(){
    ponteiroArvore raiz = criarNo("A dor irradia para o braco esquerdo ou mandibula ?" , "");
    raiz -> esquerda = criarNo("" , "Vermelho");
    raiz -> direita = criarNo("A dor comecou a mais de duas horas ? " , "");
    raiz -> direita -> esquerda = criarNo("" , "Amarelo");
    raiz -> direita -> direita = criarNo("" , "Verde");

    return raiz;
}

ponteiroArvore inicializarTriagemRespiratoria(){
    ponteiroArvore raiz = criarNo("O paciente consegue falar frases completas sem parar para respirar ?" , "");

    raiz -> esquerda = criarNo("Tem pieira ou chiado no peito ?" , "");
    raiz-> esquerda -> esquerda = criarNo("" , "Laranja");
    raiz -> esquerda -> direita = criarNo("" , "Amarelo");

    raiz -> direita = criarNo("" , "Vermelho");

    return raiz;
}

int conversorPrioridade(char cor[]){
    if(strcasecmp(cor , "Vermelho") == 0){
        return 1;
    }

    else{
        if(strcasecmp(cor , "Laranja") == 0){
            return 2;
        }

        else{

            if(strcasecmp(cor , "Amarelo") == 0){
                return 3;
            }

            else{

                if(strcasecmp(cor , "Verde") == 0){
                    return 4;
                }
            }
        }
    }
}

ponteiroPaciente criaListaVazia(){
    ponteiroPaciente p = NULL;
    return p;
}

ponteiroPaciente inserirFila(ponteiroPaciente cabeca , char nome[] , char cor[] , int prioridade , char triagem[]){
    ponteiroPaciente novoNo = (ponteiroPaciente)malloc(sizeof(Paciente));
    ponteiroPaciente pAux = cabeca;

    if(novoNo != NULL){
        strcpy(novoNo ->nomePaciente , nome);
        strcpy(novoNo ->corPaciente , cor);
        strcpy(novoNo ->tipoTriagem , triagem);
        novoNo ->valorUrgencia = prioridade;
    }

    else{
        return cabeca;
    }

    if(cabeca == NULL){
        return novoNo;
    }

    if(prioridade < cabeca ->valorUrgencia){
        novoNo -> prox = cabeca;
        cabeca = novoNo;
        return novoNo;
    }

    while(pAux -> prox != NULL && pAux -> prox ->valorUrgencia <= prioridade){
        pAux = pAux -> prox;
    }

    novoNo -> prox = pAux -> prox;
    pAux -> prox = novoNo;
    return cabeca;
  
}

char * fazerTriagem(ponteiroArvore raiz){
    ponteiroArvore atual = raiz;
    char resposta[100];

    while(strlen(atual ->corUrgencia) == 0){
        printf("%s " , atual -> perguntaEstado);
        scanf("%s" , resposta);
        getchar();

        if(strcasecmp(resposta , "Sim") == 0){
            atual = atual -> esquerda;
        }

        else{

            if(strcasecmp(resposta , "Nao") == 0){
                atual = atual -> direita;
            }
        }
    }

    return atual -> corUrgencia;
}

void mostrarLista(ponteiroPaciente cabeca){
    ponteiroPaciente atual = cabeca;

    while(atual != NULL){
        printf("Nome: %s \n" , atual ->nomePaciente);
        printf("Cor: %s \n" , atual ->corPaciente);
        printf("Prioridade: %d \n" , atual ->valorUrgencia);
        printf("Tipo de triagem: %s \n" , atual ->tipoTriagem);
        printf("\n");
        atual = atual -> prox;
    }
}


int main(){
    ponteiroArvore triagemCardiaca = inicializarTriagemCardiaca();
    ponteiroArvore triagemRespiratoria = inicializarTriagemRespiratoria();
    ponteiroPaciente filaPacientes = criaListaVazia();

    int opcao;
    char tipoTriagem[50];
    char corPacienteDisplay[50];
    int prioridadePaciente;
    char nomePacienteAux[100];

    do{
         printf("Selecione 1 para inicializar a triagem , 2 - Para mostrar a lista dos pacientes, 0 para sair do programa \n");
        scanf("%d" , &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Digite o tipo de triagem - 'Cardiaca' ou 'Respiratoria' ? \n");
            fgets(tipoTriagem , 50 , stdin);
            removeEnter(tipoTriagem);

            if(strcasecmp(tipoTriagem , "Cardiaca") == 0){
              
               strcpy(corPacienteDisplay , fazerTriagem(triagemCardiaca));
               printf("A cor do paciente e: %s \n" , corPacienteDisplay);
               prioridadePaciente = conversorPrioridade(corPacienteDisplay);

               printf("Introduza o nome do paciente: \n");
                fgets(nomePacienteAux , 100 , stdin);
                removeEnter(nomePacienteAux);

               filaPacientes = inserirFila(filaPacientes , nomePacienteAux , corPacienteDisplay , prioridadePaciente , tipoTriagem);

            }

            else{
                if(strcasecmp(tipoTriagem , "Respiratoria") == 0){
                  
                    strcpy(corPacienteDisplay , fazerTriagem(triagemRespiratoria));
                    printf("A cor do paciente e: %s \n" , corPacienteDisplay);
                    prioridadePaciente = conversorPrioridade(corPacienteDisplay);

                printf("Introduza o nome do paciente: \n");
                fgets(nomePacienteAux , 100 , stdin);
                removeEnter(nomePacienteAux);

                filaPacientes = inserirFila(filaPacientes , nomePacienteAux , corPacienteDisplay , prioridadePaciente , tipoTriagem);

                }
            }
            break;
        case 2:
            mostrarLista(filaPacientes);
            break;
        
        default:
            break;
        }



    }while(opcao != 0);


}