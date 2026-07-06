#include <stdio.h>
#include <string.h>

//Shift +3
void cesarCypher(char passStr[]){
    for(int i = 0 ; passStr[i] != '\0' ; i++){
        passStr[i] =  passStr[i] + 3;
    }
}

int main(){
    char pass[50] = "123";
    cesarCypher(pass);
    
}