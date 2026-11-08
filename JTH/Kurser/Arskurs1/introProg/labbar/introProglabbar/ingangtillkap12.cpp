#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <chrono>
#include <thread>

using namespace std;

// ******** 12.2 Kylskåp ************

void kylskapMedWhileTrue() {
    cout << "kylskap med while true" << endl;
    while (true) {
        cout << "temperatur: ";
        double temperatur;
        cin >> temperatur;

        if (temperatur < -273) {
            break;
        }
        if (temperatur <= 2) {
            cout << "For kallt!" << endl;
        } else if (temperatur >= 8) {
            cout << "For varmt!" << endl;
        } else {
            cout << "Lagom." << endl;
        }
    }
    cout << "lamnar kylskapsloop." << endl;
}

void kylskapMedWhileVillkor() {
    cout << "kylskap med while villkor" << endl;

    double temperatur = 0;
    while (temperatur > -273) {
        cout << "temperatur: ";
        cin >> temperatur;

        if (temperatur > -273) {
            if (temperatur <= 2) {
                cout << "For kallt!" << endl;
            } else if (temperatur >= 8) {
                cout << "For varmt!" << endl;
            } else {
                cout << "Lagom." << endl;
            }
        }
    }
    cout << "lamnar kylskapsloop" << endl;
}

// ******** 12.4 Summa ************

int aritmetiskSummaFranAnalys(int n) {
    return n * (n + 1) / 2;
}

int aritmetiskSummaFranLoop(int n) {
    int summa = 0;
    for (int i = 1; i <= n; ++i) {
        summa += i;
    }
    return summa;
}

void jamforSummaberakningar(int n) {
    int resultat = aritmetiskSummaFranLoop(n);
    int diff = resultat - aritmetiskSummaFranAnalys(n);
    cout << "aritmetiskSummaFranLoop(" << n << ") = " << resultat
         << ", diff = " << diff << endl;
    assert(diff == 0);
}

void jamforFleraSummaberakningar() {
    cout << "jamfor flera summaberakningar" << endl;
    for (int n = 0; n < 100; n += 20)
        jamforSummaberakningar(n);
}

// ******** 12.5 Slumptal ************

unsigned int PSEUDOSLUMPTAL = 42;

void froaSlumptalsgeneratorn(unsigned int fro) {
    PSEUDOSLUMPTAL = fro;
}

// 12.5.5: byt till rand() genom att kommentera in/ut raderna nedan
unsigned int ettSlumptal() {
    PSEUDOSLUMPTAL = 1664525 * PSEUDOSLUMPTAL + 1013904223;
    return PSEUDOSLUMPTAL;
    // return rand();
}

void genereraNagraSlumptal() {
    cout << "skriver 5 stora slumptal: " << endl;

    for (int i = 0; i < 5; ++i)
        cout << ettSlumptal() << " ";
    cout << endl;

    // 12.5.2: tärningskast, tal mellan 1 och 6
    cout << "skriver 30 tarningskast: " << endl;

    for (int i = 0; i < 30; ++i)
        cout << ettSlumptal() % 6 + 1 << " ";
    cout << endl;
}

// 12.5.3: tar upp till någon minut att köra
void undersokSlumptalsgeneratorn() {
    cout << "undersokSlumptalsgeneratorn" << endl;

    unsigned long long int antalAnrop = 0;
    unsigned long long int foregaendeAntal = 0;

    int antal42or = 0;

    while (antal42or < 4) {
        unsigned int i = ettSlumptal();
        antalAnrop += 1;
        if (i == 42) {
            cout << "sag 42 efter " << antalAnrop << " anrop. ";
            if (antal42or == 0)
                cout << "(den forsta 42:an)" << endl;
            else
                cout << "dvs. " << antalAnrop - foregaendeAntal
                     << " steg efter foregaende 42:a" << endl;

            foregaendeAntal = antalAnrop;
            antal42or += 1;
        }
    }
}

void provaMinaSlumptal() {
    cout << "provaMinaSlumptal" << endl;

    genereraNagraSlumptal();
    // undersokSlumptalsgeneratorn(); // tar lång tid, kommentera in vid behov
}

// ******** 12.6 Gissa datorns tal ************

// Returnerar tal mellan 0 och n (exklusive n)
int nyttTal(int n) {
    return rand() % n;
}

int anvandarensGissning() {
    cout << "din gissning: ";
    int gissning;
    cin >> gissning;
    return gissning;
}

void utforEnSpelomgang() {
    cout << "Utfor en spelomgang." << endl;
    const int n = 100;
    const int datornsTal = nyttTal(n);
    int antalUtfordaGissningar = 0;
    cout << "Datorn tanker pa ett tal mellan noll och " << n
         << ". Gissa vilket!" << endl;

    while (true) {
        int gissning = anvandarensGissning();
        antalUtfordaGissningar += 1;

        this_thread::sleep_for(chrono::milliseconds(500));

        if (gissning < datornsTal) {
            cout << "For litet." << endl;
        } else if (gissning > datornsTal) {
            cout << "For stort." << endl;
        } else {
            cout << "Vilken tur!" << endl;
            cout << "Du fick ratt pa " << antalUtfordaGissningar
                 << ":e forsoket!" << endl;
            break;
        }
    }

    cout << endl;
}

// ******** 12.8 Kvadratroten ************

double kvadratroten(double x) {
    double a = 1;
    double foregaende = 0;
    // Iterera tills två konsekutiva approximationer skiljer < 1e-6
    while (abs(a - foregaende) >= 1e-6) {
        foregaende = a;
        double k = x / a;
        a = (a + k) / 2;
    }
    return a;
}

void jamforKvadratrotsberakningar(double x) {
    double resultat = kvadratroten(x);
    double diff = resultat - sqrt(x);
    cout << "kvadratroten(" << x << ") beraknad till " << resultat
         << " diff " << diff << endl;
}

void jamforFleraKvadratrotsberakningar() {
    jamforKvadratrotsberakningar(0.1);
    jamforKvadratrotsberakningar(2);
    jamforKvadratrotsberakningar(10);
    jamforKvadratrotsberakningar(100);

    jamforKvadratrotsberakningar(1234 * 1234);
    cout << endl;
}

// ******** 12.9 Fibonacci ************

// Skriver ut de n första fibonacci-talen numrerade från 1.
void skrivUtFibonacci(int n) {
    if (n >= 1)
        cout << "1:1";
    if (n >= 2)
        cout << ", 2:1";
    int x2 = 1;
    int x1 = 1;
    for (int i = 3; i <= n; ++i) {
        int x = x1 + x2;
        cout << ", " << i << ":" << x;
        x2 = x1;
        x1 = x;
    }
    cout << endl;
}

// ******** 12.10 Rita med text ************

void skrivMultiplikationsmatris() {
    cout << "Multiplikationsmatris" << endl;
    const int n = 10;
    for (int r = 1; r <= n; ++r) {
        for (int k = 1; k <= n; ++k) {
            cout.width(4);
            cout << r * k;
        }
        cout << endl;
    }
    cout << endl;
}

void fyllRektangel(int hojd, int bredd) {
    cout << "Fylld rektangel" << endl;
    for (int r = 0; r < hojd; ++r) {
        for (int k = 0; k < bredd; ++k)
            cout << "#";
        cout << endl;
    }
    cout << endl;
}

void ritaRektangel(int hojd, int bredd) {
    cout << "Ritad rektangel." << endl;
    for (int r = 0; r < hojd; ++r) {
        for (int k = 0; k < bredd; ++k) {
            bool kant = (r == 0 || r == hojd - 1 || k == 0 || k == bredd - 1);
            cout << (kant ? "#" : " ");
        }
        cout << endl;
    }
    cout << endl;
}

void fyllTriangel(int hojd) {
    cout << "Fylld triangel." << endl;
    for (int r = 1; r <= hojd; ++r) {
        for (int k = 0; k < r; ++k)
            cout << "#";
        cout << endl;
    }
    cout << endl;
}

void fyllCirkel(int radie) {
    cout << "Fylld cirkel" << endl;
    for (int r = -radie; r <= radie; ++r) {
        for (int k = -radie; k <= radie; ++k) {
            if (r * r + k * k <= radie * radie)
                cout << "#";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void ritaMedText() {
    cout << "ritaMedText." << endl;
    cout << endl;
    skrivMultiplikationsmatris();
    fyllRektangel(4, 20);
    cout << endl;
    ritaRektangel(4, 20);
    cout << endl;
    fyllTriangel(5);
    cout << endl;
    fyllCirkel(5);
    cout << endl;
}

// ******** 12.11 Estimera PI ************

double estimatAvCirkelareaFranRadie(int radie) {
    int antal = 0;
    for (int y = -radie; y <= radie; ++y)
        for (int x = -radie; x <= radie; ++x) {
            if (x * x + y * y <= radie * radie)
                antal += 1;
        }
    return antal;
}

// Returnerar ett estimat av talet pi. Större radie ger ett bättre estimat.
double estimatAvPiFranRadie(int radie) {
    // pi * r2 = area
    // pi = area / r2
    double area = estimatAvCirkelareaFranRadie(radie);
    return area / (radie * radie);
}

void gorFleraEstimatAvPi() {
    for (int radie = 1; radie < 10000; radie = radie * 2) {
        double pi = estimatAvPiFranRadie(radie);
        cout << "radie = " << radie << ", pi estimeras till " << pi
             << endl;
    }
}

// ******** 12.12 Rationell approximation ************

// 12.12.1: generaliserad version (x och antalSiffror som inparametrar)
void skrivUtRationellApproximation(double x, int antalSiffror) {
    int grans = static_cast<int>(pow(10, antalSiffror)); // täljare/nämnare < grans

    double basta = 0;
    int bastaTaljare = 0;
    int bastaNamnare = 1;
    double minstaFel = 1e300;

    for (int taljare = 1; taljare < grans; ++taljare) {
        for (int namnare = 1; namnare < grans; ++namnare) {
            double kvot = static_cast<double>(taljare) / namnare;
            double fel = abs(kvot - x);
            if (fel < minstaFel) {
                minstaFel = fel;
                basta = kvot;
                bastaTaljare = taljare;
                bastaNamnare = namnare;
            }
        }
    }
    cout << antalSiffror << " siffror: " << bastaTaljare << "/" << bastaNamnare
         << " = " << basta << endl;
}

// 12.12: tvåsiffrig version för pi
void skrivRationellApproximationAvPi() {
    skrivUtRationellApproximation(M_PI, 2);
}

void provaRationellApproximation() {
    for (int i = 1; i <= 4; ++i)
        skrivUtRationellApproximation(M_PI, i);
}

// ******** 12.13 Primtal ************

// Returnerar true omm n är ett primtal
bool arPrimtal(int n) {
    if (n < 2)
        return false;
    for (int k = 2; k * k <= n; ++k) {
        if (n % k == 0)
            return false;
    }
    return true;
}

void provaPrimtal() {
    cout << endl
         << "provaPrimtal" << endl
         << "Knappa in tal, avsluta med 0." << endl;
    while (true) {
        cout << "ge tal: ";
        int tal = 1;
        cin >> tal;
        if (tal <= 0)
            break;
        if (arPrimtal(tal))
            cout << tal << " ar primtal" << endl;
        else
            cout << tal << " kan faktoriseras" << endl;
    }
    cout << "(avslutar provaPrimtal)" << endl;
}

void testaPrimtal() {
    cout << "testaPrimtal" << endl;
    assert(arPrimtal(2));
    assert(arPrimtal(3));
    assert(arPrimtal(5));
    assert(arPrimtal(7));
    assert(arPrimtal(7919));
    assert(!arPrimtal(4));
    assert(!arPrimtal(6));
    assert(!arPrimtal(35));
    assert(!arPrimtal(7913));
    assert(!arPrimtal(10201));
    cout << "testaPrimtal lyckades" << endl;
}

// ******** 12.15 Collatz ************

long int nastaCollatz(long int n) {
    if (n % 2 == 0)
        return n / 2;
    return 3 * n + 1;
}

void skrivCollatzSekvens(long int startvarde) {
    long int n = startvarde;
    cout << n;
    while (n != 1) {
        n = nastaCollatz(n);
        cout << " " << n;
    }
    cout << endl;
}

long int collatzMax(long int startvarde) {
    long int n = startvarde;
    long int storst = n;
    while (n != 1) {
        n = nastaCollatz(n);
        if (n > storst)
            storst = n;
    }
    return storst;
}

long int collatzLangd(long int startvarde) {
    long int n = startvarde;
    long int langd = 1; // startvärdet räknas som första talet
    while (n != 1) {
        n = nastaCollatz(n);
        langd += 1;
    }
    return langd;
}

void skrivCollatzStatistik(long int maxN) {
    long int maxVarde = 0;
    long int maxVardeStart = 0;
    long int maxLangd = 0;
    long int maxLangdStart = 0;

    for (long int start = 1; start <= maxN; ++start) {
        long int m = collatzMax(start);
        if (m > maxVarde) {
            maxVarde = m;
            maxVardeStart = start;
        }
        long int l = collatzLangd(start);
        if (l > maxLangd) {
            maxLangd = l;
            maxLangdStart = start;
        }
    }
    cout << "maximalt varde = " << maxVarde
         << " (for startVarde =" << maxVardeStart << ")" << endl;
    cout << "maximal langd = " << maxLangd
         << " (for startVarde =" << maxLangdStart << ")" << endl;
}

void provaCollatzfunktionerna() {
    cout << endl << "provaCollatzfunktionerna" << endl;
    cout << "Anropar skrivCollatzSekvens(7)" << endl;
    skrivCollatzSekvens(7);
    cout << "collatzMax(7) = " << collatzMax(7) << endl;
    cout << "collatzLangd(7) = " << collatzLangd(7) << endl;

    skrivCollatzStatistik(10000);
    cout << endl;
}


void ingangtillkap12 () {
    cout << endl << "ingangTillLoopar +++++" << endl;

    // provaCollatzfunktionerna();
    //testaPrimtal();
    // provaPrimtal();
   // provaRationellApproximation();
    //gorFleraEstimatAvPi();
    //ritaMedText();
    //skrivUtFibonacci(20);
    //jamforFleraKvadratrotsberakningar();
   // utforEnSpelomgang();
    // provaMinaSlumptal();
   // jamforFleraSummaberakningar();
    // kylskapMedWhileVillkor();
    // kylskapMedWhileTrue();
}