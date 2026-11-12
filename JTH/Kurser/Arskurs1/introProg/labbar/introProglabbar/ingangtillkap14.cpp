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


void ingangtillkap14(){
    cout << endl << "ingangtillkap14 +++++"  << endl;

    testavektorfunktioner();

}
