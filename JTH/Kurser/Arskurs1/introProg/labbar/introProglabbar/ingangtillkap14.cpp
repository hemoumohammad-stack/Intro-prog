#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <array>
#include <ctime>

using namespace std;

//******* 14.2 *******

void skrivUtvek (const vector<int>& vek){
    cout << "( ";
    for (size_t i = 0; i < vek.size(); ++i)
        cout << vek[i] << " ";
    cout << ")" << endl;
}

void fyllmedvarde (vector<int>& vek, int varde){

    for (size_t i = 0; i < vek.size(); ++i)
        vek[i] = varde;
}



void fyllmedslumtal(vector<int>& vek, int minsta, int storsta){
    for (size_t i = 0; i < vek.size(); ++i)
        vek[i] = minsta + rand() % (storsta - minsta + 1);

}

bool innehaller(const vector<int>& vek, int x){

    for (size_t i = 0; i < vek.size(); ++i){
        if (vek[i] == x)
            return true;
    }
    return false;
}
void provaskrivUtvek() {
    cout << "...provaskrivUtvek" << endl;

    cout << "verfiera manuellt att utskriften blir (7 8 9 10)" << endl;
    vector<int> vek{7, 8, 9, 10};
    skrivUtvek(vek);
    cout << "provaskrivUtvek lyckades ????" << endl;

}

void testfyllmedvarde() {
    cout << "... testfyllmedvarde" << endl;
    const int size = 100;
    vector<int> vek(size, 0);
    fyllmedvarde(vek, 42);

    for (size_t i = 0; i < size; ++i)
        assert(vek[i] == 42);

    cout<< "...testfyllmedvarde lyckades" << endl;
}

void testfyllmedslumptal() {
    cout <<"...testfyllmedslumptal" << endl;
    const int size = 10000;
    int minsta = -8;
    int storsta = 5;

    vector<int> vek(size, 0);

    fyllmedslumtal(vek, minsta, storsta);
    bool observeratMinsta = false;
    bool observeratStorsta = false;
    bool observeratMellan = false;
    bool observeratUtanfor = false;

    for (size_t i = 0; i < size; ++i){
        const int x = vek[i];
        if (x == minsta) observeratMinsta = true;
        if (x == storsta) observeratStorsta = true;
        if (minsta < x && x < storsta) observeratMellan = true;
        if (x < minsta || storsta < x) observeratUtanfor = true;
    }
    assert (observeratMinsta && observeratStorsta && observeratMellan && !observeratUtanfor);

    cout << "... testFyllmedSlumptal lyckades" << endl;

}


void testinnehaller(){
    cout <<"...testinnehaller" << endl;
    const int size = 100;
    vector<int> vek(size, 42);

    vek[0]= 44;
    vek[size/ 2] = 45;
    vek [size - 1] =46;


    assert (!innehaller (vek, 43));
    assert (innehaller(vek, 44));
    assert (innehaller (vek, 45));
    assert (innehaller(vek, 46));

    vector<int> tom;
    assert (!innehaller(tom, 0));
    cout <<"...testinnehaller lyckades" << endl;
}
void testavektorfunktioner(){
    cout << "testavektorfunktion ..." << endl;
    cout << "(om programet kraschar har du en bug)" << endl;

    provaskrivUtvek();

    testfyllmedvarde();
    testfyllmedslumptal();
    testinnehaller();

    cout << "testaVektorfunktioner lyckades..." << endl;
}

// ******** 14.3 ************


int minst(const vector<int>& vek) {
    int m = vek[0];
    for (size_t i = 1; i < vek.size(); ++i) {
        if (vek[i] < m)
            m = vek[i];
    }
    return m;
}


int storst(const vector<int>& vek) {
    int m = vek[0];
    for (size_t i = 1; i < vek.size(); ++i) {
        if (vek[i] > m)
            m = vek[i];
    }
    return m;
}


int indexTillMinsta(const vector<int>& vek) {
    int index = 0;
    for (size_t i = 1; i < vek.size(); ++i) {
        if (vek[i] < vek[index])
            index = i;
    }
    return index;
}


int indexTillStorsta(const vector<int>& vek) {
    int index = 0;
    for (size_t i = 1; i < vek.size(); ++i) {
        if (vek[i] > vek[index])
            index = i;
    }
    return index;
}

// Returnerar true om vektorn är sorterad, dvs. om v[i] <= v[i+1].
bool arSorterad(const vector<int>& vek) {
    for (size_t i = 0; i + 1 < vek.size(); ++i) {
        if (vek[i] > vek[i + 1])
            return false;
    }
    return true;
}

void testaMinst() {
    cout << "... testaMinst" << endl;
    const int size = 100;
    vector<int> vek(size, 42);
    vek[0] = 40;
    assert(minst(vek) == 40);
    vek[size - 1] = 30;
    assert(minst(vek) == 30);
    vek[size / 2] = -10;
    assert(minst(vek) == -10);
    cout << "... testaMinst lyckades" << endl;
}

void testaStorst() {
    cout << "... testaStorst" << endl;
    const int size = 100;
    vector<int> vek(size, -42);

    vek[0] = -10;
    assert(storst(vek) == -10);
    vek[size - 1] = -5;
    assert(storst(vek) == -5);
    vek[size / 2] = -1;
    assert(storst(vek) == -1);
    cout << "... testaStorst lyckades" << endl;
}

void testaIndexTillMinsta() {
    cout << "... testaIndexTillMinsta" << endl;
    const int size = 100;
    vector<int> vek(size, 42);
    vek[0] = 40;
    assert(indexTillMinsta(vek) == 0);
    vek[size - 1] = 30;
    assert(indexTillMinsta(vek) == size - 1);
    vek[size / 2] = -10;
    assert(indexTillMinsta(vek) == size / 2);
    cout << "... testaIndexTillMinsta lyckades" << endl;
}

void testaIndexTillStorsta() {
    cout << "... testaIndexTillStorsta" << endl;
    const int size = 100;
    vector<int> vek(size, -42);
    vek[0] = -10;
    assert(indexTillStorsta(vek) == 0);
    vek[size - 1] = -5;
    assert(indexTillStorsta(vek) == size - 1);
    vek[size / 2] = 1;
    assert(indexTillStorsta(vek) == size / 2);
    cout << "... testaIndexTillStorsta lyckades" << endl;
}

void testaArSorterad() {
    cout << "... testaArSorterad" << endl;
    const int size = 100;


    vector<int> vek(size, 0);
    for (size_t i = 0; i < size; ++i)
        vek[i] = -10 + i / 3;

    assert(arSorterad(vek));


    vector<int> v1 = vek;
    vector<int> v2 = vek;
    vector<int> v3 = vek;
    v1[0] = v1[1] + 1;
    v2[size / 2] = v2[size / 2 + 1] + 1;
    v3[size - 1] = v2[size - 2] - 1;

    assert(!arSorterad(v1));
    assert(!arSorterad(v2));
    assert(!arSorterad(v3));

    vector<int> tom;
    assert(arSorterad(tom));

    cout << "... testaArSorterad lyckades" << endl;
}

void testaFlerVektorfunktioner() {
    cout << "testaFlerVektorfunktioner ..." << endl;
    cout << "(om programmet kraschar har du en bug)" << endl;

    testaMinst();
    testaStorst();
    testaIndexTillMinsta();
    testaIndexTillStorsta();
    testaArSorterad();
    cout << "testaFlerVektorfunktioner lyckades ..." << endl;
}

// ******** 14.4 ************

         void skrivUtVaxelV2(int antalKronor) {
    static vector<int> valorer{500, 200, 100, 20, 10, 5, 2, 1};

    cout << antalKronor << " kronor ar:" << endl;
    int kvar = antalKronor;
    for (size_t i = 0; i < valorer.size(); ++i) {
        int antal = kvar / valorer[i];
        kvar = kvar % valorer[i];
        if (antal > 0)
            cout << "   " << antal << " x " << valorer[i] << endl;
    }
}

void provaSkrivUtVaxel2() {
    cout << "provaSkrivUtVaxel2" << endl;
    skrivUtVaxelV2(947);

}


// ******** 14.5 ************

         void fyllMedUnikaSlumptal(vector<int>& vek, int minst, int storst) {

    assert(storst - minst + 1 >= static_cast<int>(vek.size()));

    for (size_t i = 0; i < vek.size(); ++i) {
        int tal;
        bool redanAnvant;
        do {
            tal = minst + rand() % (storst - minst + 1);
            redanAnvant = false;
            // leta bara i den tidigare delen av vektorn
            for (size_t j = 0; j < i; ++j) {
                if (vek[j] == tal)
                    redanAnvant = true;
            }
        } while (redanAnvant);
        vek[i] = tal;
    }
}

void provaFyllMedUnikaSlumptal() {
    cout << "provaFyllMedUnikaSlumptal" << endl;
    vector<int> vek(10);
    fyllMedUnikaSlumptal(vek, 1, 10);
    skrivUtvek(vek);

    for (int tal = 1; tal <= 10; ++tal)
        assert(innehaller(vek, tal));
    cout << "provaFyllMedUnikaSlumptal lyckades" << endl;
}

// ******** 14.6 ************


vector<int> lottoradFranAnvandare() {
    vector<int> rad;
    cout << "Knappa in 7 olika tal mellan 1 och 35." << endl;
    while (rad.size() < 7) {
        cout << "tal " << rad.size() + 1 << ": ";
        int tal;
        cin >> tal;
        if (tal < 1 || tal > 35)
            cout << "Talet maste vara mellan 1 och 35." << endl;
        else if (innehaller(rad, tal))
            cout << "Du har redan valt " << tal << "." << endl;
        else
            rad.push_back(tal);
    }
    return rad;
}


vector<int> slumplottorad() {
    vector<int> rad;
    while (rad.size() < 7) {
        int tal = 1 + rand() % 35;
        if (!innehaller(rad, tal))
            rad.push_back(tal);
    }
    return rad;
}


int antalMatch(const vector<int>& v1, const vector<int>& v2) {
    int antal = 0;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (innehaller(v2, v1[i]))
            antal += 1;
    }
    return antal;
}


void korTusenExperiment(const vector<int>& anvandarensRad) {
    const int antalExperiment = 1000;
    int summa = 0;
    int max = 0;
    for (int i = 0; i < antalExperiment; ++i) {
        int antalRatt = antalMatch(anvandarensRad, slumplottorad());
        summa += antalRatt;
        if (antalRatt > max)
            max = antalRatt;
    }
    cout << "genomsnitt: " << static_cast<double>(summa) / antalExperiment
         << " ratt, som mest: " << max << " ratt" << endl;
}


void lottoexperimentera() {
    srand(static_cast<unsigned>(time(nullptr)));
    vector<int> anvandarrad = lottoradFranAnvandare();
    for (int i = 0; i < 20; i += 1) {
        korTusenExperiment(anvandarrad);
    }
}

// ******** 14.8.2 ************

void skrivUtSudoku(const array<array<int, 9>, 9>& sudoku) {
    const string avskiljare = "+---------+---------+---------+";

    for (int r = 0; r < 9; ++r) {
        if (r % 3 == 0)
            cout << avskiljare << endl;
        for (int k = 0; k < 9; ++k) {
            if (k % 3 == 0)
                cout << "|";
            if (sudoku[r][k] == 0)
                cout << "   ";
            else
                cout << " " << sudoku[r][k] << " ";
        }
        cout << "|" << endl;
    }
    cout << avskiljare << endl;
}

void provaSkrivSudoku() {
    array<array<int, 9>, 9> sudoku{{
        {6, 0, 2, 5, 8, 1, 3, 9, 7},
        {7, 8, 1, 9, 0, 4, 5, 2, 0},
        {5, 0, 0, 6, 2, 7, 8, 0, 1},
        {0, 7, 4, 2, 9, 0, 6, 8, 3},
        {9, 3, 8, 4, 1, 0, 2, 0, 5},
        {2, 6, 5, 0, 7, 3, 0, 0, 4},
        {0, 5, 6, 0, 4, 2, 7, 3, 9},
        {0, 2, 0, 3, 6, 9, 1, 5, 8},
        {3, 1, 9, 0, 0, 8, 0, 6, 0}
    }};
    skrivUtSudoku(sudoku);
}


    void ingangtillkap14(){
    cout << endl << "ingangtillkap14 +++++"  << endl;

    testavektorfunktioner();
    testaFlerVektorfunktioner();
    provaSkrivUtVaxel2();
    provaSkrivSudoku();
    provaFyllMedUnikaSlumptal();
    provaSkrivUtVaxel2();
    }
