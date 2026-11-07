#include <iostream>
#include <string>

using namespace std;

void adderaTvaTal(){
    cout << "Två tal skall adderas. " << endl;
    cout << "Ange x:";
    int x;
    cin >> x;

    cout << "Ange y:";
    int y;
    cin >> y ;

    cout << "Summan av"
 << x
 << " och"
 << y
 << "är"
 <<   x+y
 << endl;
}

void sagHej(){
    cout << "Ange ditt förnamn:";
    string fornamn;
    cin >> fornamn;
    cout << "tack"
         << fornamn
         << ", ange nu ditt efternamn:";
    string efternamn;
    cin >> efternamn;
    cout << "Hej " << fornamn << " " << efternamn<< "!" << endl;

}


void ingangtillvariabler(){
    cout << "inång till variabeler" << endl;
    sagHej();

    adderaTvaTal();
}