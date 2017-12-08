#include "Point.h"
#include "Triangle.h"
#include <iostream>
using namespace std;
int main(){
	Point p1(1,1), p2(6.,7.), p3(3., 6.5);
	Triangle tr(p1, p2, p3);
	cout << tr.maxLength() << " " << tr.area() << " " << tr.perimeter() << endl;
	cout << tr;
	system("pause");
}