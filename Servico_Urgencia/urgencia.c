#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeEnter(char str[]){
    for(int i = 0 ; str[i] != '\0' ; i++){
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
    char corUrgencia[100];
    int valorUrgencia;
    ponteiroPaciente prox;

};

typedef struct paciente Paciente;


struct arvore{
    char perguntaEstado[100];
    char corEstado[100];
    ponteiroArvore esquerda;
    ponteiroArvore direita;


};

typedef struct arvore Arvore;


ponteiroArvore criarNo(char pergunta[] , char cor[]){
    ponteiroArvore novoNo = (ponteiroArvore)malloc(sizeof(Arvore));

    if(novoNo != NULL){
        strcpy(novoNo ->perguntaEstado , pergunta);
        strcpy(novoNo -> corEstado , cor);
        novoNo -> esquerda = NULL;
        novoNo -> direita = NULL;
    }

    return novoNo;
}

ponteiroArvore inicializarTriagem(){
    ponteiroArvore raiz = criarNo("Tem dor forte no peito ?" , "");
    raiz -> esquerda = criarNo("" , "Vermelho");
    raiz -> direita = criarNo("Tem febre alta ? " , "");

    raiz -> direita -> esquerda = criarNo("" , "Laranja");
    raiz -> direita -> direita = criarNo("" , "Verde");

    return raiz;
}


char* fazerTriagem(ponteiroArvore raiz){
    ponteiroArvore atual = raiz;
    char respostaPaciente[100];

    while(strlen(atual ->corEstado) == 0){
        printf("%s" , atual ->perguntaEstado);
        scanf("%s" , respostaPaciente);
        getchar();

        if(strcasecmp(respostaPaciente , "Sim") == 0 ){
            atual = atual -> esquerda;
        }

        else{
            if(strcasecmp(respostaPaciente , "Nao") == 0){
                atual = atual -> direita;
            }
        }

    }
    return atual ->corEstado;
}

int conversorPrioridade(char corPacienteParam[]){
    if(strcasecmp(corPacienteParam , "Vermelho") == 0){
        return 1;
    }
    else{

        if(strcasecmp(corPacienteParam , "Laranja") == 0){
            return 2;
        }

        else{
            if(strcasecmp(corPacienteParam , "Verde") == 0){
                return 3;
            }

            else{
                return 0;
            }
        }
    }
}

ponteiroPaciente criarListaVazia(){
    ponteiroPaciente p = NULL;
    return p;
}

ponteiroPaciente inserirFila(ponteiroPaciente cabeca , char nome[] , char cor[] , int prioridade){
    ponteiroPaciente novoNo = (ponteiroPaciente)malloc(sizeof(Paciente));
    ponteiroPaciente pAux = cabeca;
    if(novoNo != NULL){
        strcpy(novoNo ->nomePaciente , nome);
        strcpy(novoNo -> corUrgencia , cor);
        novoNo ->valorUrgencia = prioridade;
        novoNo -> prox = NULL;
          
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
   pAux ->prox = novoNo;

   return cabeca;

}

void mostrarPacientes(ponteiroPaciente cabeca){
    ponteiroPaciente pAux = cabeca;

    while(pAux != NULL){
        printf("Nome: %s \n" , pAux ->nomePaciente);
        printf("Cor de urgencia: %s \n" , pAux ->corUrgencia);
        printf("Valor de urgencia: %d \n" , pAux ->valorUrgencia);
        printf("\n");

        pAux = pAux ->prox;
    }
}



int main(){
    int opcao;
    char corPacienteDisplay[100];
    int prioridadePaciente;
    char nomePaciente[100];
    ponteiroArvore raiz = inicializarTriagem();
    ponteiroPaciente filaPacientes = criarListaVazia();

    do{
        printf("Selecione 1 para inicializar a triagem , 2 - Para mostrar a lista dos pacientes, 0 para sair do programa \n");
        scanf("%d" , &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            strcpy(corPacienteDisplay , fazerTriagem(raiz));

            printf("A cor do paciente e: %s \n" , corPacienteDisplay);

            prioridadePaciente = conversorPrioridade(corPacienteDisplay);

            printf("Introduza o nome do paciente: \n");
            fgets(nomePaciente , 100 , stdin);
            removeEnter(nomePaciente);

          
            filaPacientes = inserirFila(filaPacientes, nomePaciente , corPacienteDisplay , prioridadePaciente);

            break;
        case 2:
            mostrarPacientes(filaPacientes);
            break;
        
        default:
            break;
        }


    }while(opcao != 0);

    return 0;
}