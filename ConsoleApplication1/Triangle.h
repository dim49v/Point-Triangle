#pragma once
#include "Point.h"
class Triangle
{
public:
	Triangle();
	Triangle(const Triangle &ob1);
	Triangle(const Point &a, const Point &b, const Point &c); //
	~Triangle();
private:
	Point t1_, t2_, t3_;
	bool pr = true;
	double l1, l2, l3;
	void length();
	void test();
public:
	void set(Point a, Point b, Point c); //
	Point getPoint(int n);
	void setPoint(int n, const Point& p1);
	double perimeter();
	double area();
	double maxLength();
	Triangle operator+(const Point &p1);
	Triangle operator+(double temp);
	Triangle operator=(const Triangle &p1);
	bool operator==(const Triangle &p1);
	friend ostream &operator<<(ostream& out, const Triangle& ob1);
	friend istream &operator>>(istream& in, Triangle& ob1);
};

