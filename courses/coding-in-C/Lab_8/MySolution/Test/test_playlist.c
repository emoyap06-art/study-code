#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Unit-tests === */

// example unit test
void test_init_playlist(void)
{
    playlist p;
    init_playlist(&p);

    assert(p.p_head == NULL);
    assert(p.size == 0);
}

void test_add_song(void) {
    playlist p;
    init_playlist(&p);

    add_song(&p, "Für Elise", "Beethoven");

    assert(p.size==1);
    assert(strcmp(p.p_head->title, "Für Elise")==0);
    assert(strcmp(p.p_head->artist, "Beethoven")==0);

}

void test_delete_firstSong() {
    playlist p;
    init_playlist(&p);

    add_song(&p, "Für Elise", "Beethoven");
    add_song(&p, "Hasso", "KC");

    delete_firstSong(&p);

    assert(p.size==1);
    assert(p.p_head!=NULL);
    assert(strcmp(p.p_head->title, "Hasso")==0);
    assert(strcmp(p.p_head->artist, "KC")==0);
    
}

void test_delete_firstSong_empty() { // what happens if we delete first song from empty playlist 
    playlist p;
    init_playlist(&p);  

    delete_firstSong(&p);

    assert(p.p_head == NULL);
    assert(p.size==0);
}

 void test_delete_playlist() {
    playlist p;
    init_playlist(&p); 
    
    add_song(&p, "Für Elise", "Beethoven");
    add_song(&p, "Hasso", "KC");

    delete_playlist(&p);

    assert(p.p_head==NULL);
    assert(p.size==0);

}

void test_max_songs_limit(){
    playlist p;
    init_playlist(&p);

    for(int i=0; i<=MAX_SONGS; i++) {
        add_song(&p, "...", "...");
    }

    assert(p.size==MAX_SONGS); //Anzahl Songs muss Anzahl der Grenze entsprechen
    add_song(&p, "Zu viel", "zu viel");

    assert(p.size==MAX_SONGS); //Darf sich nicht verändern auc nach hinzufügen des "Zu viel" songs

    delete_playlist(&p);
}
/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    test_delete_playlist();
    test_max_songs_limit(); // verify if the limit will be not be surpassed

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}