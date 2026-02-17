#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define STEPS 20

static void print_field(const int *p_field, int n, int t) {
    printf("Time %d: ", t);
    for (int i = 0; i < n; i++) {
        printf("%d", *(p_field + i));
        if (i < n - 1) printf(" ");
    }
    printf("\n");
}

static void clear_array(int *p_arr, int n) {
    for (int i = 0; i < n; i++) {
        *(p_arr + i) = 0;
    }
}

int main(void) {
    int field[N];
    int next[N];

    int *p_field = field;   // Pointer auf erstes Element
    int *p_next  = next;    // Pointer auf temp Array

    // Zufall initialisieren
    srand((unsigned)time(NULL));

    // 1) Array mit 0 initialisieren
    clear_array(p_field, N);

    // 2) Drei Partikel setzen: Index 2,4,6
    *(p_field + 2) = 1;
    *(p_field + 4) = 1;
    *(p_field + 6) = 1;

    for (int t = 0; t <= STEPS; t++) {
        // Aktuellen Zustand ausgeben
        print_field(p_field, N, t);

        if (t == STEPS) break;

        // 4) next-State Array leeren
        clear_array(p_next, N);

        // Für Kollisions-Check zählen wir, wie viele Partikel in eine Zelle ziehen.
        // (Ohne structs, daher einfach ein int count pro Zelle im selben next-Array "kodieren")
        // -> wir nutzen ein zusätzliches Zähl-Array, ebenfalls int.
        int counts[N];
        int *p_counts = counts;
        clear_array(p_counts, N);

        // 5) Alle Partikel bewegen (basierend auf p_field), Ergebnis in counts sammeln
        for (int i = 0; i < N; i++) {
            if (*(p_field + i) == 1) {
                int dir = rand() % 2;      // 0 = links, 1 = rechts
                int j = i + (dir ? 1 : -1);

                // Randbedingung: nicht aus Feld raus
                if (j < 0) j = 0;
                if (j >= N) j = N - 1;

                // Zielzelle hochzählen (Pointerarithmetik)
                *(p_counts + j) += 1;
            }
        }

        // 5) Kollisionen anwenden:
        // - genau 1 Partikel => next[j]=1
        // - 0 oder >=2 => next[j]=0 (bei >=2 ist es eine Kollision)
        int collision_printed = 0;
        for (int j = 0; j < N; j++) {
            if (*(p_counts + j) == 1) {
                *(p_next + j) = 1;
            } else {
                *(p_next + j) = 0;
                if (*(p_counts + j) >= 2) {
                    // Optional: Kollisionsmeldung
                    printf("Collision on index %d\n", j);
                    collision_printed = 1;
                }
            }
        }

        // next -> field kopieren (oder Pointer tauschen; hier kopieren wir sauber)
        for (int i = 0; i < N; i++) {
            *(p_field + i) = *(p_next + i);
        }
    }

    return 0;
}
