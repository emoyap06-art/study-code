#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char *name;
    char *artist;

    struct Song* p_next;
} Song;

typedef struct playlist {
    Song* p_head;
} playlist;

/**
 * @brief Leere Playlist Initialisieren
 * 
 * @param playlist_1 ertse Playlist
 **/
void init_playlist (playlist* playlist_1) {
    playlist_1->p_head =NULL;
}

/** 
 * @brief Song hinzufügen
 * 
 * @param name Name des neuen Songs
 * @param artist Künstler des Songs
 * @param playlist_1 pointer auf erste Playlist
 **/ 
void addSong(char *name, char *artist, playlist* playlist_1) {
    Song* NewSong= malloc(sizeof(*NewSong));
    if(NewSong == NULL){
        printf("Speicherallokation fehllgeschlagen");
        return;
    }

    NewSong->name= malloc(strlen(name)+1);
    NewSong->artist= malloc(strlen(artist)+1);
    if (NewSong->name == NULL || NewSong->artist == NULL){
        printf("Speicherallokation fehlgeschlagen");
        free(NewSong->name);
        free(NewSong->artist);
        free(NewSong);
        return;
    }
    strcpy(NewSong->name, name);
    strcpy(NewSong->artist, artist);

    NewSong->p_next = NULL;
    
    //An Anfang der Liste einfügen
    if(playlist_1->p_head == NULL) {
    playlist_1->p_head= NewSong; 
    return;
    }    
    
    //An Ende der Liste einfügen
    Song* p_count;
    p_count=playlist_1->p_head;
    while(p_count->p_next!=NULL) {
        p_count= p_count->p_next;
    }   
    p_count->p_next=NewSong;
}

void Print_Playlist(playlist* playlist_1) {

    Song* current_song;

    if (playlist_1->p_head == NULL) {
        printf("Noch kein Song hinzugefügt");
        return ;
    }
    current_song= playlist_1->p_head;

    while(current_song!=NULL) {  
        printf("Title: %s\n", current_song->name);
        printf("Artist: %s\n\n", current_song->artist);
        current_song= current_song->p_next;
        }
}

void delete_first_song(playlist* playlist_1) {
    if(playlist_1->p_head==NULL){
        printf("Nichts vorhanden");
        return;
    }
    Song* p_tmp= playlist_1->p_head;
    playlist_1->p_head= p_tmp->p_next;

    free(p_tmp->name);
    free(p_tmp->artist);
    free(p_tmp);
}
/**
 * @brief delete playlist and free up memory
 *
 * @param playlist pointer to playlist
 */
void delete_playlist(playlist *playlist_1)
{

    while (playlist_1->p_head!=NULL)
    {
        delete_first_song(playlist_1);
    }
    printf("Liste leer");
    return;
}

int main() {
    playlist playlist_1;

    init_playlist(&playlist_1);

    addSong("One kiss is all it takes", "Dua Lipa", &playlist_1);
    addSong("Many Man", "Fifty Cent", &playlist_1);
    Print_Playlist(&playlist_1);

    printf("----------------------\n");
    
    delete_first_song(&playlist_1);
    Print_Playlist(&playlist_1);

    printf("-----------------\n");

    delete_playlist(&playlist_1);
    Print_Playlist(&playlist_1);

    return 0;
}