#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void skrivhypotenusaberakningnarna(double x, double y ){
    double rKvadrat = x*x + y*y;
    double r = sqrt( rKvadrat );
    cout << "x är " << x << " och y är " << y << "." << endl
         << "Summan av kvadraterna blir " << rKvadrat << endl
         << "vilket gör att hypotenusans längd blir " << r << endl;

}

void provhypotenusaberakningnarna() {
    skrivhypotenusaberakningnarna(5,6);
    skrivhypotenusaberakningnarna(9,4);


}
void ingangtillfunkinochut (){
    cout << endl << "ingangtillfunkinochut......" << endl;

    provhypotenusaberakningnarna ();


}