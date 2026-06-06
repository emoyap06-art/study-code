#include <iostream>


class Matrix {
private:
    static const int SIZE = 3;
    bool matrix[SIZE][SIZE];

public:
Matrix() {
    for(int i=0; i< SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            matrix[i][j] = 0;
        }
    }
}
void set_Kante(int i, int j, bool value)
{
    matrix[i][j]= value;
}

void print_matrix() const {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            std::cout<<matrix[i][j]<< " ";
        }
        std::cout << std::endl;
        }   
    }
};

int main () {
    Matrix graph;

    graph.set_Kante(0, 1, true); //von A nach B
    graph.set_Kante(1, 0, true); //von B nach A

    graph.set_Kante(0, 2, true); //von A nach C
    graph.set_Kante(2, 0, true); //C nach A

    graph.set_Kante(2, 3, true); //B nach C
    graph.set_Kante(3, 2, true); //C nach B

    graph.print_matrix();

    return 0;

}
