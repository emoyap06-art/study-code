#ifndef PLAYLIST_H
#define PLAYLIST_H
#define MAX_SONGS 5


typedef struct Song{
    char* title;
    char* artist;

    struct Song* p_next;
} Song;

typedef struct playlist{
    Song* p_head;
    int size;
} playlist;

void init_playlist(playlist* playlist_1);
void add_song(playlist* playlist_1, const char* title, const char* artist);
void print_playlist(playlist* playlist_1);
void delete_firstSong(playlist* playlist_1);
void delete_playlist(playlist* playlist_1);

#endif