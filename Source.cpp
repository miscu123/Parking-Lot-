#include "Header.h"
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    int nr_marci, nr_locuri, nr_modele, nr_modele_marca, min, a, b;
    ofstream g("C:\\Parking Lot.txt");

    cout << "Introduceti numarul de locuri disponibile in parcare: ";
    cin >> nr_locuri;
    Parcare locuri(nr_locuri);
    cout << locuri; // supraincarcare

    cout << "Introduceti numarul de marci diferite de masini ce se afla in parcare: ";
    cin >> nr_marci;
    while (nr_marci > nr_locuri) {
        cout << "Prea multe marci. Introduceti alt numar. ";
        cin >> nr_marci;
    }
    Marca marci(nr_marci);

    for (int i = 0; i < nr_marci; ++i) {
        cout << marci.getNume(i) << endl;
    }

    cout << "Cate modele de masini sunt in total in parcare? ";
    cin >> nr_modele;
    while ((nr_modele > nr_locuri) || (nr_modele < nr_marci)) {
        cout << "Numar incorect de modele. Introduceti alt numar. ";
        cin >> nr_modele;
    }

    min = nr_locuri - nr_marci;

    if (nr_locuri == nr_marci) {
        nr_modele_marca = 1;
        for (int i = 0; i < nr_marci; i++) {
            cout << "Numarul de modele pentru marca " << marci.getNume(i) << " este: "
                << nr_modele_marca << endl;
        }
    }
    else {
        int modele_ramase = nr_locuri;
        for (int i = 0; i < nr_marci; ++i) {
            int nr_modele_marca;
            if (i == nr_marci - 1) {
                cout << "Marca " << marci.getNume(i) << " va avea " << modele_ramase
                    << " modele " << endl;
                nr_modele_marca = modele_ramase;
            }
            else {
                cout << "Cate modele de " << marci.getNume(i)
                    << " sunt? (Introduceti un numar intre 1 si " << modele_ramase << "): ";
                cin >> nr_modele_marca;
                while (nr_modele_marca < 1 || nr_modele_marca >= modele_ramase) {
                    cout << "Numarul de modele este invalid. Introduceti un numar intre 1 si "
                        << modele_ramase << ": ";
                    cin >> nr_modele_marca;
                }
            }
            modele_ramase -= nr_modele_marca;
        }
        cout << "Modelele de masini au fost introduse cu succes in parcare." << endl;
    }

    Model model(nr_modele);
    model.afisare();

    g.clear();
    a = 0;
    b = 1;
    schimba(a, b);

    g << "Marcile de masini ce se afla in parcare sunt: " << endl;
    g << marci.getNume(a) << ' ';
    g << marci.getNume(b) << ' ';
    for (int i = 2; i < nr_marci; i++) {
        g << marci.getNume(i) << ' ';
    }
    g.close();

    cout << "Marcile de masini din parcare au fost introduse cu succes in fisier! ";
    system("pause");
    return 0;
}
