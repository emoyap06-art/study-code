#include <iostream>
#include <vector>

class AdjMatrix {
    private:
    std::vector<std::vector<int>>matrix;

    public:
    AdjMatrix(int number_of_Dim){
        matrix.resize(number_of_Dim, std::vector<int>(number_of_Dim, 0));
    }

    void setKane(int i, int j, int weight) {
        matrix[i][j] = weight;
    }

    int get_weight(int i, int j) const  {
        return matrix[i][j];
    }

    void print_matrix () {
        for(size_t i=0; i<matrix.size(); i++) {
            for(size_t j=0; j<matrix.size(); j++) {
                std::cout << matrix [i][j] <<" ";
            }
            std::cout <<std::endl;
        }
    }
};

int main () {
    AdjMatrix graph(3);

    graph.setKane(0, 2, 10);
    graph.setKane(1, 3, 20);

    std::cout<< "Weight from 0 to 2: " << graph.get_weight(0, 2) <<"\n" <<std::endl;
    std::cout<< "Weight from 1 to 3: " << graph.get_weight(1, 3) <<"\n" <<std::endl;

    graph.print_matrix();


    return 0;
}