/*
  skriv in nedanstånde kod inklusive dessa kommentarer.
  Du behöver ej förstå alla rader nu. Programmet börjar vid main.
*/

#include <iostream> // innehåller cout
#include <thread>   // innehåller sleep_for
#include <chrono>   // innehåller milliseconds


using namespace std;
using namespace this_thread;
using namespace chrono;

void raknatilltre(){
    sleep_for( milliseconds(500));
    cout << "Ett" << endl;
    sleep_for( milliseconds(500));
    cout << "Tva" << endl;
    sleep_for( milliseconds(1000));
    cout << "Tre" << endl;
    sleep_for( milliseconds(500));
}

void raknatillfyra(){

    sleep_for( milliseconds(500));
    cout << "Ett" << endl;
    sleep_for( milliseconds(500));
    cout << "Tva" << endl;
    sleep_for( milliseconds(1000));
    cout << "Tre" << endl;
    sleep_for( milliseconds(500));
    cout << "fyra" << endl;
}





//Här börjar programmet
void ingangtillkap02(){
    cout<< "nu raknar vi till tre" << endl;
    raknatilltre();
    cout << "och nu till fyra" << endl;
    raknatillfyra();
}
