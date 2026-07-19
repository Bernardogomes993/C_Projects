#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct paciente *ponteiroPaciente;
typedef struct arvore *ponteiroArvore;

void removeEnter(char str[]){
    for(int i=0 ; str[i] != '\0' ; i++){
        if(str[i] == '\n'){
            str[i] = '\0';
            return;
        }
    }
}

struct paciente{
    char nomePaciente[100];
    char corPaciente[50];
    int prioridadePaciente;
    ponteiroPaciente prox;
};

typedef struct paciente Paciente;

struct arvore{
    char perguntaUrgencia[100];
    char corUrgencia[50];
    ponteiroArvore esquerda;
    ponteiroArvore direita;

};

typedef struct arvore Arvore;


ponteiroArvore criarNo(char pergunta[] , char cor[]){
    ponteiroArvore novoNo = (ponteiroArvore)malloc(sizeof(Arvore));
    if(novoNo != NULL){
        strcpy(novoNo -> perguntaUrgencia , pergunta);
        strcpy(novoNo ->corUrgencia , cor);
        novoNo ->esquerda = NULL;
        novoNo -> direita = NULL;
    }

    return novoNo;
}

ponteiroArvore inicializarTriagem(){
    ponteiroArvore raiz = criarNo("Tem dor forte no peito?" , "");
    raiz ->esquerda = criarNo("" , "Vermelho");
    raiz -> direita = criarNo("Tem febre alta ?" , "");
    raiz -> direita -> esquerda = criarNo("" , "Laranja");
    raiz -> direita -> direita = criarNo("" , "Verde");

    return raiz;
}


ponteiroArvore fazerTriagem(ponteiroArvore raiz){
    ponteiroArvore atual = raiz;
    char respostaPaciente[50];

    while(strlen(atual ->corUrgencia) == 0){
        printf("%s " ,atual ->perguntaUrgencia);
        scanf("%s" , respostaPaciente);
        getchar();

        if(strcasecmp(respostaPaciente , "Sim") == 0){
            atual = atual -> esquerda;
        }

        else{

            if(strcasecmp(respostaPaciente , "Nao") == 0){
                atual = atual -> direita;
            }
        }
    }

    return atual;

}

void aprenderNovaPergunta(ponteiroArvore pAtual){
    char novaCor[50];
    char novaPergunta[100];
    char novaResposta[100];

    printf("Introduza a nova cor: \n");
    fgets(novaCor , 50 , stdin);
    removeEnter(novaCor);

    printf("Digite a nova pergunta: \n");
    fgets(novaPergunta , 100 , stdin);
    removeEnter(novaPergunta);

    printf("A resposta para a nova cor e 'Sim' ou 'Nao' ? \n");
    fgets(novaResposta , 100 , stdin);
    removeEnter(novaResposta);

    ponteiroArvore pCorAntiga = criarNo("" , pAtual ->corUrgencia);
    ponteiroArvore pCorNova = criarNo("", novaCor);

    strcpy(pAtual ->corUrgencia , "");
    strcpy(pAtual ->perguntaUrgencia , novaPergunta);

    if(strcasecmp(novaResposta , "Sim") == 0){
        pAtual -> esquerda = pCorNova;
        pAtual -> direita = pCorAntiga;
    }

    else{

        if(strcasecmp(novaResposta , "Nao") == 0){
            pAtual -> esquerda = pCorAntiga;
            pAtual ->direita = pCorNova;
        }
    }

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
                return 4;
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
    ponteiroPaciente atual = cabeca;

    if(novoNo != NULL){
        strcpy(novoNo ->nomePaciente , nome);
        strcpy(novoNo ->corPaciente , cor);
        novoNo ->prioridadePaciente = prioridade;
        novoNo ->prox = NULL;
    }

    else{
        return cabeca;
    }

    if(cabeca == NULL){
        return novoNo;
    }

    if(prioridade < cabeca ->prioridadePaciente){
        novoNo -> prox = cabeca;
        cabeca = novoNo;
        return novoNo;
    }

    while(atual -> prox != NULL && atual -> prox ->prioridadePaciente <= prioridade){
        atual = atual -> prox;
    }

    novoNo -> prox = atual -> prox;
    atual -> prox = novoNo;
    return cabeca;

}

void mostrarFila(ponteiroPaciente cabeca){
    ponteiroPaciente atual = cabeca;

    while(atual != NULL){
        printf("Nome: %s \n" , atual ->nomePaciente);
        printf("Cor de urgencia: %s \n" , atual -> corPaciente);
        printf("Numero de prioridade: %d \n" , atual -> prioridadePaciente);
        printf("\n");
        atual = atual -> prox;
    }
}


int main(){
    ponteiroArvore raiz = inicializarTriagem();
    ponteiroPaciente filaPacientes = criarListaVazia();
    int opcao;
    char corPacienteDisplay[50];
    char respostaUtilizador[50];
    int prioridadeAux;
    char nomePacienteAux[100];

    do{
        printf("Selecione a opcao: 1 - Inicializar triagem , 2 - Mostrar fila de pacientes, 0 - Sair do programa \n");
        scanf("%d" , &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            ponteiroArvore noFinal = fazerTriagem(raiz);
            strcpy(corPacienteDisplay , noFinal ->corUrgencia);
            printf("A cor do paciente e : %s \n" , corPacienteDisplay);

            printf("Concorda com o diagnostico ? ('Sim' / 'Nao')\n");
            scanf("%s" , respostaUtilizador);
            getchar();

            if(strcasecmp(respostaUtilizador , "Nao") == 0){
                aprenderNovaPergunta(noFinal);
                printf("Confirme a nova cor associada: \n");
                fgets(corPacienteDisplay , 50 , stdin);
                removeEnter(corPacienteDisplay);
            }


            prioridadeAux = conversorPrioridade(corPacienteDisplay);

            printf("Qual o nome do paciente: \n");
            fgets(nomePacienteAux , 100 , stdin);
            removeEnter(nomePacienteAux);

            filaPacientes = inserirFila(filaPacientes , nomePacienteAux , corPacienteDisplay , prioridadeAux);

            break;
        case 2:
            mostrarFila(filaPacientes);
            break;
        
        default:
            break;
        }

    }while(opcao != 0);

}