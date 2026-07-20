#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Left - Yes
//Right - No

void removeEnter(char str[]){
    for(int i= 0; str[i] != '\0' ; i++){
        if(str[i] == '\n'){
            str[i] = '\0';
            return;
        }
    }
}

typedef struct treeNode *pointerTree;

struct treeNode{
    char userQuestion[100];
    pointerTree left;
    pointerTree right;

};

typedef struct treeNode Tree;

pointerTree addNew(char question[]){
    pointerTree newNode = (pointerTree)malloc(sizeof(Tree));
    if(newNode != NULL){
        strcpy(newNode ->userQuestion , question);
        newNode -> left = NULL;
        newNode -> right = NULL;
    }

    return newNode;
}


void displayTree(pointerTree root){
    if(root == NULL){
        return;
    }

    printf("Question: %s -> " , root ->userQuestion);

    if(root -> left != NULL){
        printf("Left: %s | " , root -> left ->userQuestion);
    }

    else{

        printf("Left: Empty | ");
    }

    if(root -> right != NULL){
        printf("Right: %s \n" , root -> right ->userQuestion);
    }

    else{

        printf("Right: NULL \n");
    }

    displayTree(root -> left);
    displayTree(root -> right);
}

void playGame(pointerTree root){
    pointerTree current = root;
    char userAnswer[20];
    char userAnimal[100];
    char userQuestionAux[100];

    while(current -> left != NULL && current -> right != NULL){
        printf("Question: %s \n" , current -> userQuestion);
        scanf("%s" , userAnswer);
        getchar();

        if(strcasecmp(userAnswer , "Yes") == 0){
            current = current -> left;
        }

        else{

            if(strcasecmp(userAnswer , "No") == 0){
                current = current -> right;
            }
        }
    }

    printf("You were thinking of: %s ? \n" , current ->userQuestion);
    scanf("%s" , userAnswer);
    getchar();

    if(strcasecmp(userAnswer , "Yes") == 0){
        printf("Computer guessed \n");
        return;
    }

    else{

        if(strcasecmp(userAnswer , "No") == 0){

            printf("What was the animal that you were thinking ? \n");
            fgets(userAnimal , 100 ,stdin);
            removeEnter(userAnimal);

            printf("What is the question to distinct: \n");
            fgets(userQuestionAux , 100 , stdin);
            removeEnter(userQuestionAux);

            printf("Is the answer for %s is 'Yes' or 'No' ? \n" , userAnimal);
            scanf("%s" , userAnswer);
            getchar();

            pointerTree newAnimal = addNew(userAnimal);
            pointerTree oldAnimal = addNew(current ->userQuestion);

            strcpy(current ->userQuestion , userQuestionAux);



            if(strcasecmp(userAnswer , "Yes") == 0){
                current -> left = newAnimal;
                current -> right = oldAnimal;
            }

            else{
                if(strcasecmp(userAnswer , "No") == 0){
                    current -> left = oldAnimal;
                    current -> right = newAnimal;
                }
            }


        }
    }
}


int main(){
    pointerTree root = addNew("Is a mammal ? ");
    root -> left = addNew("Whale");
    root -> right = addNew("Penguin");
    int option;
   
    do{

        printf("Select an option: 1 - Play , 0 - Leave \n");
        scanf("%d" , &option);
        getchar();

        if(option == 1){
             playGame(root);
             //displayTree(root);
        }
       


    }while(option != 0);
    

}