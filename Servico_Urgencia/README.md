# Sistema de Triagem Hospitalar Inteligente com Aprendizagem Dinâmica

Este é um sistema de triagem médica desenvolvido em **C** que simula o fluxo de atendimento de um hospital.
Este projeto contém 3 versões sendo que a terceira o utilizador pode não concordar com o diagnóstico do 
sistema e poderá assim fazer novas perguntas e definir novas ramificações.

## Funcionalidades
* **Triagem automatizada através de árvores de decisão**: O sistema faz algumas perguntas ao utilizador
  sobre o estado do paciente. O utilizador responde sim ou não às perguntas e no fim é associada uma cor
  ao paciente que determina a prioridade deste e se o estado é grave ou não.
* **Fila de espera dinâmica**: Os pacientes são inseridos de forma automática numa lista ligada. Esta lista
  é ordenada consoante a gravidade do paciente sendo que **1** é o estado mais grave e corresponde à cor
  vermelha.
* **Aprendizagem Dinâmica**: Na terceira versão o sistema permite que o utilizador discorde do dignóstico
  e permite que este possa adicionar novas perguntas e cores para definir a situação.A àrvore binária é sempre
  atualizada consoante os **prompts** do utilizador.

## Estruturas de dados utilizadas:
* **Àrvore Binária**: É utilizada para gerar o estado de prioridade do paciente onde os nós internos são as
  perguntas e as folhas são os diagnósticos finais.
* **Lista Ligada**: Gere a fila de pacientes de maneira ordenada com base na prioridade de cada um.

## Evolução do projeto:
1. **Versão 1**: Triagem estática onde é utilizada uma única àrvore binária.
2. **Versão 2**: Permite triagens diferentes como triagem cardiáca e respiratória.
3. **Versão 3**: Permite a aprendizagem dinâmica da àrvore com base nos prompts do utilizador.
   
