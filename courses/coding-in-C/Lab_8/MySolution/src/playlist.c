#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/workspaces/study-code/courses/coding-in-C/Lab_8/MySolution/include/playlist.h"

/**
 * 
 * @brief Es wird eine neue Playlist geschaffen, die die Grundlage der nachfolgenden Befehle ist
 * 
 * @param playlist_1 ist dabei ein Pointer auf den Struct "Playlist"
 */

void init_playlist(playlist* playlist_1) {
    if(playlist_1==NULL) {
        return;
    }
    playlist_1->p_head=NULL;
    playlist_1->size=0;
}

/**
 * 
 * @brief Neue Songs mit Name und Künstler sollen hinzugefügt werden können
 * 
 * @param NewSong beschreibt neu hinzugefügten Song
 * @param p_current aktueller Song(zum durchlaufen)
 */
void add_song(playlist* playlist_1, const char* title, const char* artist) {
    if(playlist_1->size>=MAX_SONGS) {
        printf("Maximale Anzahl an Songs erreicht\n");
        return;
    } else{
    Song* NewSong= malloc(sizeof(*NewSong));
    if(NewSong==NULL) {
        printf("Speicherallokation fehleschlagen\n");
        free(NewSong);
        return;
    }
    NewSong->title= malloc((strlen(title))+1);
    NewSong->artist= malloc(strlen(artist)+1);

    if(NewSong->title==NULL || NewSong->artist==NULL) {
        printf("Speicherallokation fehleschlagen\n");
        free(NewSong->title);
        free(NewSong->artist);
        free(NewSong);
        return;
    }
    strcpy(NewSong->title,title);
    strcpy(NewSong->artist, artist);
    NewSong->p_next=NULL;
    

    if(playlist_1->p_head==NULL){
        playlist_1->p_head=NewSong;
    } 
    
    //Bis ans Ende der Playlist laufen, um hinzuzufügen
    Song* p_current= playlist_1->p_head;
    while(p_current->p_next!=NULL) {
        p_current=p_current->p_next;
    }
    p_current->p_next=NewSong;
}
playlist_1->size++;

}


/**
 * 
 * @brief Ersten Song aus der Playlist löschen
 * 
 * @param p_tmp Speicher den Kopf der List zwischendurch, damit dieser nicht verloren geht
 */
void delete_firstSong(playlist* playlist_1) {
    if(playlist_1->p_head==NULL) {
        printf("Keine Songs zum löschen\n");
        return ;
    }

    Song* p_tmp= playlist_1->p_head;
    playlist_1->p_head= p_tmp->p_next;
    free(p_tmp->title);
    free(p_tmp->artist);
    free(p_tmp);
    playlist_1->size--;

}

/**
 * 
 * @brief Gesamte Playlist soll gelöscht werden
 * 
 */
void delete_playlist(playlist* playlist_1) {
    if(playlist_1==NULL) {
        return;
    }

    while(playlist_1->p_head!=NULL) {
        delete_firstSong(playlist_1);
    }
}


/**
 * @brief Playlist soll nun ausgegeben werden
 * 
 * @param p_current aktueller Song
 */
void print_playlist(playlist* playlist_1) {
        if(playlist_1->p_head==NULL) {
        printf("Playlist leer\n");
        return;
        
    }

    Song* p_current= playlist_1->p_head;
    
    while(p_current!=NULL) {
        printf("Title: %s , Artist: %s \n", p_current->title, p_current->artist);
        p_current= p_current->p_next;
    }
}