#include "Grad.h"
#include "grade.h"

using namespace std;

//TODO
double Grad::grade() const{
	return min(Core::grade(), thesis);
}

istream &Grad::read(std::istream &in){
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}