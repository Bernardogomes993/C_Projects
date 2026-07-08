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

typedef struct music *pointerMusic;
typedef struct playlist *pointerPlaylist;


struct music{
    char musicName[50];
    char artistName[50];
    pointerMusic next;
   
};

typedef struct music Music;


struct playlist{
    char playlistName[50];
    pointerMusic firstSong;
    pointerPlaylist nextPlayList;
};

typedef struct playlist Playlist;

pointerPlaylist emptyPlaylist(){
    pointerPlaylist p = NULL;
    return p;
}

int playlistExists(pointerPlaylist plst , char myPlayName[]){
    pointerPlaylist pAux = plst;
    while(pAux != NULL){
        if(strcasecmp(pAux ->playlistName , myPlayName) == 0){
            return 1;
        }
        pAux = pAux -> nextPlayList;
    }
    return 0;
} 

void addPlaylist(pointerPlaylist *plst){

    char playlistNameAux[50];
    pointerPlaylist pAux = *plst;
    printf("Enter the playlist name: \n");
    fgets(playlistNameAux , 50 , stdin);
    removeEnter(playlistNameAux);


    if(playlistExists(pAux , playlistNameAux)){
        printf("This playlist already exists !\n");
        return;
    }


    pointerPlaylist newNode = (pointerPlaylist)malloc(sizeof(Playlist));
    if(newNode != NULL){
        newNode ->nextPlayList = NULL;
        newNode ->firstSong = NULL;
        strcpy(newNode ->playlistName , playlistNameAux);

        if(*plst == NULL){
            *plst = newNode;
        }

        else{
            while(pAux ->nextPlayList != NULL){
                pAux = pAux ->nextPlayList;
            }

            pAux -> nextPlayList = newNode;
        }
    }

}

int musicExists(pointerMusic plst , char myArtist[] , char mySong[]){
    pointerMusic pAux = plst;
    while(pAux != NULL){
        if(strcasecmp(pAux ->artistName , myArtist) == 0 && strcasecmp(pAux ->musicName , mySong) == 0){
            return 1;
        }
        pAux = pAux -> next;
    }
    return 0;
}

  

void addSong(pointerPlaylist plst){
    char namePlayListAux[50];
    char musicNameAux[50];
    char artistNameAux[50];
    pointerPlaylist pAux = plst;
    pointerPlaylist pAux2 = NULL;
    int found = 0;
    printf("Enter the name of the playlist: \n");
    fgets(namePlayListAux , 50 , stdin);
    removeEnter(namePlayListAux);

    while((pAux) != NULL){
        if(strcasecmp(pAux ->playlistName , namePlayListAux) == 0){
            found = 1;
            pAux2 = pAux;
        }
      
        pAux = pAux ->nextPlayList;
    }

    if(found){
        printf("Add the music name: \n");
        fgets(musicNameAux , 50 , stdin);
        removeEnter(musicNameAux);

        printf("Add the artist name: \n");
        fgets(artistNameAux , 50 , stdin);
        removeEnter(artistNameAux);

         if(musicExists(pAux2 ->firstSong , artistNameAux , musicNameAux)){
                printf("The music or the artist already exists!\n");
                return;
            }

       

        pointerMusic pMusicAux = pAux2 ->firstSong;
        pointerMusic newMusicNode = (pointerMusic)malloc(sizeof(Music));
        
        if(newMusicNode != NULL){

            newMusicNode ->next = NULL;
            strcpy(newMusicNode ->musicName , musicNameAux);
            strcpy(newMusicNode ->artistName , artistNameAux);

           
            if(pAux2 ->firstSong == NULL){
                pAux2->firstSong = newMusicNode;
            }

            else{
                while(pMusicAux -> next != NULL){
                    pMusicAux = pMusicAux ->next;
                }

                pMusicAux ->next = newMusicNode;
            }
        }

       



    }

    else{
        printf("The playlist was not found !\n");
        return;
    }

}

void showPlaylist(pointerPlaylist plst){
    pointerPlaylist pAux = plst;

    while(pAux != NULL){

        printf("Playlist Name: %s\n" , pAux -> playlistName);

        pointerMusic pAuxMusic = pAux ->firstSong;

        while(pAuxMusic != NULL){
            printf("Music name: %s " , pAuxMusic ->musicName);
            printf("Artist name: %s\n" , pAuxMusic ->artistName);
            pAuxMusic = pAuxMusic ->next;
        }

        pAux = pAux ->nextPlayList;
    }
}

void removeSong(pointerPlaylist plst){
    char playlistNameAux[50];
    char songAux[50];
    int found = 0;
    pointerPlaylist pAuxPlayList = plst;
    pointerPlaylist pAux2PlayList = NULL;

    printf("Enter the playlist name: \n");
    fgets(playlistNameAux , 50 , stdin);
    removeEnter(playlistNameAux);

    while(pAuxPlayList != NULL){
        if(strcasecmp(pAuxPlayList ->playlistName , playlistNameAux) == 0){
            found = 1;
            pAux2PlayList = pAuxPlayList;
        }
        pAuxPlayList = pAuxPlayList ->nextPlayList;
    }

    if(found){
        printf("What song do you want to remove: \n");
        fgets(songAux , 50 , stdin);
        removeEnter(songAux);

        pointerMusic pMusicAux = pAux2PlayList ->firstSong;
        pointerMusic pMusicAux2 = NULL;

        while(pMusicAux != NULL){
            if(strcasecmp(pMusicAux ->musicName , songAux) == 0){
                if(pMusicAux == pAux2PlayList -> firstSong){
                    pAux2PlayList -> firstSong = pMusicAux -> next;
                    free(pMusicAux);
                  
                    return;
                }

                else{
                    pMusicAux2 -> next = pMusicAux -> next;
                    free(pMusicAux);
                    return;
                }

            }
            pMusicAux2 = pMusicAux;
            pMusicAux = pMusicAux ->next;
        }

    }


}

int countPlaylist(pointerPlaylist plst){
    pointerPlaylist pAux = plst;
    int counter = 0;

    while(pAux != NULL){
        counter++;
        pAux = pAux ->nextPlayList;
       
    }

    return counter;
}

int countSongs(pointerMusic plst){
    pointerMusic pAux = plst;
    int counter = 0;
    while(pAux != NULL){
        counter++;
        pAux = pAux -> next;

    }
    return counter;
}

void storeData(pointerPlaylist plst){
    FILE *f = fopen("playlist.bin" , "wb");
    int numberPlaylist = countPlaylist(plst);
    pointerPlaylist playlistAux = plst;
    if(f == NULL){
        printf("Could not open the file \n");
    }
    else{
        fwrite(&numberPlaylist , sizeof(int) , 1 , f);
        while(playlistAux != NULL){

            fwrite(playlistAux ->playlistName , sizeof(char) , 50 , f);
            int numSongs = countSongs(playlistAux ->firstSong);
            fwrite(&numSongs , sizeof(int) , 1 , f);

            pointerMusic pMusicAux = playlistAux ->firstSong;

            while(pMusicAux != NULL){
                fwrite(pMusicAux ->musicName , sizeof(char) , 50 , f);
                fwrite(pMusicAux ->artistName , sizeof(char) , 50 , f);
                pMusicAux = pMusicAux ->next;
            }

            playlistAux = playlistAux ->nextPlayList;
        }
        fclose(f);
    }
}

void loadData(pointerPlaylist *plst){
    FILE *f = fopen("playlist.bin" , "rb");
    if(f == NULL){
        printf("Could not open the file \n");
        return;
    }

    else{
        int totalPlaylist;
        fread(&totalPlaylist , sizeof(int) , 1 , f);

        for(int i = 0 ; i < totalPlaylist ; i++){
            char playlistNameAux[50];
            fread(playlistNameAux , sizeof(char) , 50 , f);

            pointerPlaylist newPlaylist = (pointerPlaylist)malloc(sizeof(Playlist));
            strcpy(newPlaylist ->playlistName , playlistNameAux);
            newPlaylist ->firstSong = NULL;
            newPlaylist ->nextPlayList = NULL;

            if(*plst == NULL){
                *plst = newPlaylist;
            }

            else{
                pointerPlaylist playlistAux = *plst;
                while(playlistAux -> nextPlayList != NULL){
                    playlistAux = playlistAux ->nextPlayList;
                }
                playlistAux ->nextPlayList = newPlaylist;
            }

            int numSongs;
            fread(&numSongs , sizeof(int) , 1 , f);

            for(int i = 0 ; i < numSongs ; i++){
                char songNameAux[50];
                char artistNameAux[50];
                fread(songNameAux , sizeof(char) , 50 , f);
                fread(artistNameAux , sizeof(char) , 50 , f);

                pointerMusic newMusic = (pointerMusic)malloc(sizeof(Music));
                strcpy(newMusic ->musicName , songNameAux);
                strcpy(newMusic -> artistName , artistNameAux);
                newMusic ->next = NULL;

                if(newPlaylist ->firstSong == NULL){
                    newPlaylist ->firstSong = newMusic;
                }

                else{
                    pointerMusic pMusicAux = newPlaylist ->firstSong;
                    while(pMusicAux ->next != NULL){
                        pMusicAux = pMusicAux -> next;
                    }

                    pMusicAux ->next = newMusic;
                }

                

            }
        }
        fclose(f);
    }
}



int main(){
    int userOption;
    pointerPlaylist myPlayList = emptyPlaylist();
    loadData(&myPlayList);
    do{
        printf("Select this options: 1 - Create Playlist , 2 - Add song to a playlist , 3 - Remove a song from a playlist , 4 - Show Playlists , 5 - Quit\n");
        scanf("%d" , &userOption);
        getchar();

        switch (userOption)
        {
        case 1:
            
            addPlaylist(&myPlayList);
            break;
        case 2:
            addSong(myPlayList);
            showPlaylist(myPlayList);
            break;
        case 3:
            removeSong(myPlayList);
            showPlaylist(myPlayList);
            break;
        case 4:
            showPlaylist(myPlayList);
            break;
        default:
            break;
        }

    }while(userOption != 5);
   
    storeData(myPlayList);


}