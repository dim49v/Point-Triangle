#include "Point.h"
#include <iostream>
#include <math.h>
using namespace std;
Point::Point() : x_(0), y_(0)
{
}
Point::Point(const Point &p1){
	x_ = p1.x_;
	y_ = p1.y_;
}

Point::Point(double x, double y) : x_(x), y_(y)
{
}

Point::~Point()
{
}
void Point::set(double x, double y){
	x_ = x;
	y_ = y;
}
void Point::setX(double x){
	x_ = x;
}
void Point::setY(double y){
	y_ = y;
}
double Point::getX(){
	return x_;
}
double Point::getY(){
	return x_;
}
double Point::length(const Point &p1){
	double a, b;
	a = x_ - p1.x_;
	b = y_ - p1.y_;
	return sqrt(a*a + b*b);
}
Point Point::operator+(const Point &p1){
	return Point(x_ + p1.x_, y_ + p1.y_);
}
Point Point::operator+(double temp){
	return Point(x_ + temp, y_ + temp);
}
Point Point::operator=(const Point &p1){
	x_ = p1.x_;
	y_ = p1.y_;
	return* this;
}
ostream &operator<<(ostream& out, const Point& ob1){
	out << "x= " << ob1.x_ << " y= " << ob1.y_ << endl;
	return out;
}
istream &operator>>(istream& in, Point& ob1){
	cout << "x= ";
	in >> ob1.x_;
	if (!in){
		cout << "Error in" << endl;
		system("pause");
		exit(1);
	}
	cout << "y= ";
	in >> ob1.y_;
	if (!in){
		cout << "Error in" << endl;
		system("pause");
		exit(1);
	}
	return in;
}
bool Point::operator==(const Point &p1){
	return (x_ == p1.x_) && (y_ = p1.y_);
}