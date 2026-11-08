#include <iostream>

using namespace std;





void ingangtillifsatser(){
    cout << "ingan till ifsatser" << endl;
}

bool harpass(){
    cout << "Har du pass (ja/nej)?";
    string svar;
    cin >> svar;
    return (svar == "ja");
}

bool harkorkort(){
    cout << "Har du korkort (ja/nej)?";
    string svar;
    cin >> svar;
    return (svar == "ja");
}

int alder(){
    cout << "Din alder:";
    int alder;
    cin >> alder;
    return alder;
}

void state(){
    if(alder()>=20 && harkorkort()){
        cout << "Du ar over 20 och har korkort." << endl;}
        else {
        cout << "Du uppfyller inte kraven." << endl;}



}
