#include <iostream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;

// ******** 13.1.1 Skriv del av ASCII-tabellen ************

void skrivNagraAsciiTecken() {
    cout << "skrivNagraAsciiTecken" << endl;

    for (int asciital = 'a' - 5; asciital <= 'z' + 5; ++asciital) {
        char tecken = asciital;
        cout << asciital << '\t' << tecken << endl;
    }
}

// ******** 13.2.11 versalstrang ************

string versalstrang(const string& str) {
    string resultat = str; // ändringsbar kopia
    for (size_t i = 0; i < resultat.size(); ++i)
        resultat[i] = toupper(resultat[i]);
    return resultat;
}

void automattestaVersalstrang() {
    cout << "testar versalStrang" << endl;
    assert(versalstrang("abc ABC 123 .,- xyz") == "ABC ABC 123 .,- XYZ");
    assert(versalstrang("") == "");
    cout << "test av versalStrang lyckades!" << endl;
}

// ******** 13.2.12 rubrikstrang ************

string rubrikstrang(const string& str) {
    string resultat = str;
    bool forstaIOrdet = true;
    for (size_t i = 0; i < resultat.size(); ++i) {
        if (isspace(resultat[i])) {
            forstaIOrdet = true;
        } else if (forstaIOrdet) {
            resultat[i] = toupper(resultat[i]);
            forstaIOrdet = false;
        } else {
            resultat[i] = tolower(resultat[i]);
        }
    }
    return resultat;
}

void automattestaRubrikstrang() {
    cout << "testar rubrikstrang" << endl;

    assert(rubrikstrang("ha en BRA DAG !") == "Ha En Bra Dag !");
    assert(rubrikstrang("HA EN BRA DAG !") == "Ha En Bra Dag !");
    assert(rubrikstrang("") == "");
    cout << "test av rubrikstrang lyckades!" << endl;
}

// ******** 13.2.14 reducerad ************

// Ersätter varje sekvens av mellanslag med ett enda mellanslag
string reducerad(const string& str) {
    string resultat = "";
    bool foregaendeVarMellanslag = false;

    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] != ' ') {
            resultat += str[i];
            foregaendeVarMellanslag = false;
        } else if (!foregaendeVarMellanslag) {
            resultat += ' ';
            foregaendeVarMellanslag = true;
        }
    }
    return resultat;
}

void automattestaReducerad() {
    cout << "testar reducerad" << endl;

    assert(reducerad("Ha en bra dag !") == "Ha en bra dag !");
    assert(reducerad(" A B C ") == " A B C ");
    assert(reducerad("ABC") == "ABC");
    assert(reducerad("") == "");

    cout << "testen av reducerad lyckades!" << endl;
}

// ******** 13.2.15 trimmad ************

// Tar bort blanka tecken i början och slutet av str
string trimmad(const string& str) {
    // hitta index till första icke-blanka tecknet
    size_t forsta = 0;
    while (forsta < str.size() && isspace(str[forsta]))
        ++forsta;

    // alla tecken blanka (eller tom sträng)
    if (forsta == str.size())
        return "";

    // hitta index till sista icke-blanka tecknet
    size_t sista = str.size() - 1;
    while (isspace(str[sista]))
        --sista;

    string resultat = "";
    for (size_t i = forsta; i <= sista; ++i)
        resultat += str[i];
    return resultat;
}

void automattestaTrimmad() {
    cout << "testar trimmad" << endl;
    assert(trimmad("Ha en bra dag!") == "Ha en bra dag!");
    assert(trimmad("   Ha en bra dag!  ") == "Ha en bra dag!");
    assert(trimmad("   A   B C   ") == "A   B C");
    assert(trimmad("          ") == "");
    assert(trimmad("") == "");
    assert(trimmad("abc") == "abc");
    cout << "testen av trimmad lyckades!" << endl;
}

// ******** 13.2.16 arVokal och arKonsonant ************

bool arVokal(char ch) {
    string vokaler = "aeiouyAEIOUY";
    for (size_t i = 0; i < vokaler.size(); ++i) {
        if (vokaler[i] == ch)
            return true;
    }
    return false;
}

bool arKonsonant(char ch) {
    string konsonanter = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    for (size_t i = 0; i < konsonanter.size(); ++i) {
        if (konsonanter[i] == ch)
            return true;
    }
    return false;
}

void automattestaArVokalOchArKonsonant() {
    cout << "automattestar arVokal och arKonsonant" << endl;

    string vokaler = "aeiouyAEIOUY";
    string konsonanter = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    string andraTecken = " .,?!;";

    for (size_t i = 0; i < vokaler.size(); ++i)
        assert(arVokal(vokaler[i]));
    for (size_t i = 0; i < konsonanter.size(); ++i)
        assert(arKonsonant(konsonanter[i]));
    for (size_t i = 0; i < andraTecken.size(); ++i)
        assert(!arVokal(andraTecken[i]) && !arKonsonant(andraTecken[i]));

    cout << "testerna av arVokal / arKonsonant lyckades!" << endl;
}


void ingangtillkap13() {
    cout << endl << "ingangtillkap13 +++++" << endl;

    // automattestaArVokalOchArKonsonant();
    // automattestaTrimmad();
   // automattestaReducerad();
   // automattestaRubrikstrang();
   // automattestaVersalstrang();
    //skrivNagraAsciiTecken();
}
