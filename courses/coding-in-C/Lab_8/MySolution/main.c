#include "/workspaces/study-code/courses/coding-in-C/Lab_8/MySolution/include/playlist.h"
#include <stdio.h>

int main() {

playlist p1;

init_playlist(&p1);

add_song(&p1, "Hasso", "KC");
add_song(&p1, "Stan", "Eminem");
add_song(&p1, "Für Elise", "Ludwig van Beethoven");
add_song(&p1, "Bohemian Rhapsody", "Queen");    

print_playlist(&p1);

delete_firstSong(&p1);
print_playlist(&p1);

delete_playlist(&p1);
print_playlist(&p1);

return 0;
}