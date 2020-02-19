#include <iostream>
#include <fstream>
#include <vector>
#include "point.h"
#include "circle.h"
// input filet magadnak gyártsd le, de segítségnek ide teszem az órait, feladat eredménye a 0.0 -2.0 pont.
/*
0.0  0.0  2.0
  3.0    4.0
-12.0    3.0
  0.0  -10.0
  0.0   -2.0
  0.0    0.0

*/
using namespace std;
// lineáris keresés dekralálása (szükséges előre mert amainben már hazsnáljuk de az implementálást ellehet később is végezni)
bool search(const Circle& cir, const vector<Point> &t, unsigned int &ind);

int main()
{
  //1.óra anyaga
    ifstream f("input.txt");
  // leellenörzi hogy jó e a fájl neve / létezik e ilyen fájl a könyvtárban
    if(f.fail()) cout << "Hibas fajl nev!\n";
    
    double a, b, c;
    f >> a >> b >> c;
    //kör konstruktorának hívása
    Circle cir(Point(a,b),c);
    // pontok beolvasása módszer 1
    /*vector<Point> t;
    while(f >> a >> b){
        t.push_back(Point(a,b));
    }*/
    
    // beolvasás a pont megírt operátorával
    Point be;
    while(f >> be){
        cout << be._x << " " << be._y << endl;
        t.push_back(be);

    }

    unsigned int ind;
        if(search(cir, t, ind))
        cout << "A (" << t[ind]._x << "," << t[ind]._y << ") koordinataju pont a korbe esik\n";
    else cout << "Egyik pont sincs a korben\n";

    return 0;
}

// lineáris keresés implementálása tétel szerint
// adattagok konstans referenciák mert nem változnak, és nem akarjuk hogy lemásolódjanak
// az ind adattag nem konstans mert változtatjuk az értékét DE referencia hogy a fügvény akívülről meg kapott változó értéket változtassa ne a másoltat.
bool search(const Circle& cir, const vector<Point> &t, unsigned int &ind)
{
    bool l = false;
    for(unsigned int i=0; !l && i<t.size(); ++i)
    {
        l = cir.in(t[i]);
        ind = i;
    }
    return l;

/*
    for(ind=0; ind<t.size(); ++ind)
    {
        if( cir.in(t[i]) ) return true;
    }
    return false;
*/
}
