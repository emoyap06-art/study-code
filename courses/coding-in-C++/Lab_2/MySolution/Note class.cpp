#include <iostream>
#include <string>

class Note {
    private:
    std::string* text;

    public:
    Note(std::string inputText) {
        text = new std::string(inputText);
    }

    Note(const Note& other) {
        text= new std::string(*other.text);
    }

    Note();
    void display() {
        std::cout<< *text << std::endl;
    }
    ~Note() {
        delete text;
        text= nullptr;
        std::cout<<"Memory released" <<std::endl;
    }
};

    int main() {
        Note n_1("Hallo Welt");
        Note n_2 = n_1;
        n_1.display();
        n_2.display();

        n_1.~Note();
        n_2.~Note();


        return 0;
    }





    //Beim n_1=n_2 setzen erlaubt der compiler es automatisch, weil ein automatischer copy constructot erstellt wird, 
    //der auf die selber adresse, wie n_1 zeigt
    //
    //Das ist schlecht, da im folgendem dieser entsprechend doppelt gelöscht wird --> Programmabsturz

    //Lösung: eigenen copy-constructor erstellen