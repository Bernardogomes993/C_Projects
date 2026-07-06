#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MASTER_PASS 123
#define SIZE 100

void removeEnter(char str[]){
    for(int i = 0 ; str[i] != '\0' ; i++){
        if(str[i] == '\n'){
            str[i] = '\0';
            return;
        }
    }
}

struct credential{
    char website[50];
    char username[50];
    char password[50];
};

typedef struct credential Credential;

//Shift +3
void cesarCypher(char passStr[]){
    for(int i = 0 ; passStr[i] != '\0' ; i++){
        passStr[i] =  passStr[i] + 3;
    }
}

void uncipher(char passStr[]){
    for(int i = 0 ; passStr[i] != '\0' ; i++){
        passStr[i] = passStr[i] - 3;
    }
}

Credential addCredential(){
    Credential newCred;
    char websiteAux[50];
    char usernameAux[50];
    char passwordAux[50];

    printf("Enter your website: \n");
    fgets(websiteAux , 50 , stdin);
    removeEnter(websiteAux);

    printf("Enter your username: \n");
    fgets(usernameAux , 50 , stdin);
    removeEnter(usernameAux);

    printf("Enter your password: \n");
    fgets(passwordAux , 50 , stdin);
    removeEnter(passwordAux);


        
    strcpy(newCred.website , websiteAux);
    strcpy(newCred.username , usernameAux);
    strcpy(newCred.password , passwordAux);

    return newCred;


}



void saveCredential(int size , Credential myCred[]){
    FILE *f = fopen("passwords.txt" , "w");
    if(f == NULL){
        printf("Could not open the file!\n");
    }
    else{
        for(int i = 0 ; i < size ; i++){
            cesarCypher(myCred[i].password);
            fprintf(f , "%s %s %s\n" , myCred[i].website , myCred[i].username , myCred[i].password);
            uncipher(myCred[i].password);
           

        }
          fclose(f);
    }
  
}



int loadData(Credential myCred[]){
    int countCredential = 0;
    FILE *f = fopen("passwords.txt" , "r");

    if(f == NULL){
        printf("Could not open the file!\n");
    }
    else{
        while(fscanf(f, "%s %s %s\n" , myCred[countCredential].website , myCred[countCredential].username ,  myCred[countCredential].password) != EOF){
            uncipher(myCred[countCredential].password);
            countCredential++;
        }
        fclose(f);
        
    }
    return countCredential;
}

void displayData(int size , Credential myCred[]){
    int userOption;
    for(int i = 0 ; i < size ; i++){
        printf("Website: %s\n" , myCred[i].website);
        printf("Username: %s\n" , myCred[i].username);
        printf("Password: %s\n" , myCred[i].password);
        printf("\n");
    }
}
void displayDataCypher(int size , Credential myCred[]){
    int userOption;
    for(int i = 0 ; i < size ; i++){
        printf("Website: %s\n" , myCred[i].website);
        printf("Username: %s\n" , myCred[i].username);
        cesarCypher(myCred[i].password);
        printf("Password: %s\n" , myCred[i].password);
        uncipher(myCred[i].password);
        printf("\n");
    }
}




int main(){
   
    // Fazer a função do cesar cypher.
    int getPass;
    int userOption;
    Credential credentialList[SIZE];
    int size = loadData(credentialList);
    printf("Type de master password: \n");
    scanf("%d" , &getPass);
    getchar();

    if(getPass == MASTER_PASS){
       
       

        do{
            printf("Select the options: 1 - Add new credential , 2 - Display all the credentials Cyphered , 3 - Display all credentials uncipher, 4 - Quit \n");
            scanf("%d" , &userOption);
            getchar();

            switch (userOption)
            {
            case 1:
                if(size < SIZE){
                    credentialList[size] = addCredential();
                    size++;
                }
                else{
                    printf("The table is full!\n");
                  
                }
                break;
            case 2:
                displayDataCypher(size , credentialList);
                break;
            case 3:
                displayData(size , credentialList);
                break;
            default:
                printf("Leaving...\n");
                userOption = 4;
                break;
            }
        }while(userOption != 4);
        saveCredential(size , credentialList);
    } 
    else{
        printf("Wrong master password !\n");
        return 0;
    }
   
 
}