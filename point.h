#pragma once
#include <cmath>

//osztály
class Point
{
    // ha private nem érhető el kívülről csak a classon belül. (Point a(1,2); cout << a._x; nem fut le) getter setter metódus alul van
    public:
        double _x, _y;
		
    // publikus -> kívülről elérhető
    public:
		Point(){} // üres konstruktor
		//konstruktor 1.módszer
        Point(double a = 0, double b = 0) : _x(a),_y(b) {}

		//konstruktor 2. modszer  JAVA-n ilyesmi lesz
        /*Point(double a = 0, double b = 0){
            _x=a;
            _y=b;
        }*/
		
		// ahol lehet ott konstans referenciát használjunk paraméter átadásnál
		// konstans = nemváltozik az értéke
		// referenciáról volt szó az első órán, de annyi hogy alias név ként átadódik az objektum (ha nincs ott akkor pedig lemásolódik)
		// a const a "{" elött azt jelenti hogy a függvény nem változtatja meg a belselyében semminek az értékét.
        double distance(const Point &p) const {
            return sqrt(pow(_x-p._x,2) + pow(_y-p._y,2));
        }
    // operátor beolvasáshoz
	// friend = látja a privát adat tagokat
	
    friend std::istream& operator>>(std::istream& s, Point& e)
    {
        s>>e._x;
        s>>e._y;
        return s;
    }
	
	// getter,setter metódusok implementálhatók ha az adattagok privátak az egyszerűség kedvéért most publikusak
	/* 
	double getX(){
		return _x;
		
	}
	double getY(){
		return _y;
		
	}
	double setX(const double& a){
		_x=a;
		
	}
	double setY(const double& a){
		_y=a;
		
	}
	
	*/
};



