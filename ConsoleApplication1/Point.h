#pragma once
#include <iostream>
using namespace std;
class Point
{
public:
	Point();
	Point(const Point &p1);
	Point(double x, double y);
	~Point();
private:
	double x_;
	double y_;
public:
	void set(double x, double y);
	void setX(double x);
	void setY(double y);
	double getX(); //
	double getY();
	double length(const Point &p1); //
	Point operator+(const Point &p1);
	Point operator+(double temp);
	Point operator=(const Point &p1);
	bool operator==(const Point &p1);
	friend ostream &operator<<(ostream& out,const Point& ob1);
	friend istream &operator>>(istream& out, Point& ob1);

};

