#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Parcare {
private:
    int* locuri;
    int n;
public:
    Parcare(int n);
    ~Parcare();
    friend ostream& operator<<(ostream& x, const Parcare& locuri);
};

Parcare::Parcare(int n) : n(n) {
    locuri = new int[n];
}

Parcare::~Parcare() {
    delete[] locuri;
}

ostream& operator<<(ostream& x, const Parcare& locuri) {
    x << "Numarul de locuri este: " << locuri.n << endl;
    return x;
}

class Model;

class Marca {
private:
    string* nume;
    int n;

public:
    friend class Model;
    virtual void afisare() {
        cout << "Numele marcilor de masini sunt:" << endl;
    }
    Marca(int);
    Marca();
    ~Marca();
    string getNume(int) const;
    void setNume(int, const string&);
};

Marca::Marca(int dim) : n(dim) {
    nume = new string[n];
    for (int i = 0; i < n; ++i) {
        bool marcaExista = false;
        do {
            marcaExista = false;
            cout << "Introduceti numele marcii " << i + 1 << ": ";
            cin >> nume[i];
            for (int j = 0; j < i; ++j) {
                if (nume[i] == nume[j]) {
                    marcaExista = true;
                    cout << "Marca deja existenta. Introduceti alta marca." << endl;
                    break;
                }
            }
        } while (marcaExista);
    }
}

Marca::Marca() : n(0), nume(nullptr) {}

Marca::~Marca() {
    delete[] nume;
}

string Marca::getNume(int i) const {
    return nume[i];
}

void Marca::setNume(int i, const string& num) {
    nume[i] = num;
}

class Model : public Marca {
private:
    string* numeModel;
    int n;
public:
    friend class Marca;

    Model(int numarModele);
    ~Model();
    void afisare() override {
        cout << "Numele modelelor de masini din aceasta parcare sunt:" << endl;
        for (int i = 0; i < n; i++) {
            cout << numeModel[i] << endl;
        }
    }
};

Model::Model(int numarModele) : n(numarModele) {
    numeModel = new string[n];
    for (int i = 0; i < n; ++i) {
        cout << "Introduceti numele modelului pentru marca " << i + 1 << ": ";
        cin >> numeModel[i];
    }
}

Model::~Model() {
    delete[] numeModel;
}

template <class T>
void schimba(T& a, T& b) {
    swap(a, b);
}
