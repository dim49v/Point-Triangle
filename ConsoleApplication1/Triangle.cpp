#include "Triangle.h"
#include <math.h>
#include <iostream>
using namespace std;

Triangle::Triangle() :t1_(Point()), t2_(Point()), t3_(Point())
{
	Triangle::length();
	Triangle::test();
}
Triangle::Triangle(const Triangle &ob1){
	t1_ = ob1.t1_;
	t2_ = ob1.t2_;
	t3_ = ob1.t3_;
	pr = ob1.pr;
	l1 = ob1.l1; 
	l2 = ob1.l2;
	l3 = ob1.l3;
}

Triangle::Triangle(const Point &a, const Point &b, const Point &c) :t1_(a), t2_(b), t3_(c)
{
	Triangle::length();
	Triangle::test();
}
Triangle::~Triangle()
{
}

void Triangle::length(){
	l1 = t1_.length(t2_);
	l2 = t2_.length(t3_);
	l3 = t3_.length(t1_);
}
void Triangle::test(){
	pr = true;
	if (l1 >= l2 + l3 || l2 >= l1 + l3 || l3 >= l1 + l2){
		cout << "Triangle have invalid point" << endl;
		pr = false;
	}
	if (l1 == 0 || l2 == 0 || l3 == 0){
		cout << "Triangle have side = 0" << endl;
		pr = false;
	}
}
void Triangle::set(Point a, Point b, Point c)
{
	t1_ = a;
	t2_ = b;
	t3_ = c;
	Triangle::length();
	Triangle::test();
}
Point Triangle::getPoint(int n){
	Point temp;
	if (n<1 || n>3){
		cout << "Point doesn't exist. Return empty point" << endl;
	}
	switch (n)
	{
	case 1:
		temp = t1_;
		break;
	case 2:
		temp = t2_;
		break;
	case 3:
		temp = t3_;
		break;
	}
	return temp;
}
void Triangle::setPoint(int n, const Point& p1){
	if (n<1 || n>3){
		cout << "Point doesn't exist" << endl;
	}
	switch (n)
	{
	case 1:
		t1_ = p1;
		break;
	case 2:
		t2_ = p1;
		break;
	case 3:
		t3_ = p1;
		break;
	}
}
double Triangle::perimeter(){
	if (pr){
		return l1 + l2 + l3;
	}
	else{
		return 0;
	}
}
double Triangle::area(){
	if (pr){
		double p = (l1 + l2 + l3) / 2;
		return sqrt(p*(p - l1)*(p - l2)*(p - l3));
	}
	else{
		return 0;
	}
}
double Triangle::maxLength(){
	return fmax(fmax(l1, l2), l3);
}
Triangle Triangle::operator + (const Point &p1){
	return Triangle(t1_ + p1, t1_ + p1, t1_ + p1);
}
Triangle Triangle::operator + (double temp){
	return Triangle(t1_ + temp, t1_ + temp, t1_ + temp);
}
Triangle Triangle::operator = (const Triangle &p1){
	t1_ = p1.t1_;
	t2_ = p1.t2_;
	t3_ = p1.t3_; //
	pr = p1.pr;
	l1 = p1.l1;
	l2 = p1.l2;
	l3 = p1.l3;
	return*this;
}
bool Triangle::operator == (const Triangle &p1){
	return(t1_ == p1.t1_ && t2_ == p1.t2_ && t3_ == p1.t3_);
}
ostream &operator<<(ostream& out, const Triangle& ob1){
	out << ob1.t1_ << ob1.t2_ << ob1.t2_;
	return out;
}
istream &operator>>(istream& in, Triangle& ob1){
	in >> ob1.t1_ >> ob1.t2_ >> ob1.t3_;
	return in;
}