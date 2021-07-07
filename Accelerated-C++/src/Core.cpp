#include "Core.h"
#include "grade.h"

using namespace std;

//TODO
string Core::name() const{ return n; }

double Core::grade() const{
	return ::grade(midterm, final, homework);
}

istream &Core::read_common(istream &in){
	in >> n >> midterm >> final;
	return in;
}

istream &Core::read(istream &in){
	read_common(in);
	read_hw(in, homework);
	return in;
}

bool compare(const Core &c1, const Core &c2){
	return c1.name() < c2.name();
}

bool compare_grade(const Core &c1, const Core &c2){
	return c1.grade() < c2.grade();
}

bool compare_grade_ptr(const Core *c1, const Core *c2){
	return c1->grade() < c2->grade();
}

istream &read_hw(istream &in, Vec<double> &hw){
	if (in) {
		hw.clear();
		double x;
		while ( in >> x )
			hw.push_back(x);
		
		in.clear();
	}
	return in;
}