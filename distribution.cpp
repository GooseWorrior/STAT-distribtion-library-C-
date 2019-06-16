#include "distribution.h"

using namespace std;

// constant definition 

const double MATH_e = 2.71828182846;


// helper function
double permute(int m, int n) {
    double result = 1.0;
	for (int i = 0; i < n; i++) result *= (m - i);
	return result;
} 

double fact(int n) {
	double result = 1.0;
	for (int i = 0; i < n; i++) result *= (n - i);
	return result;
}


double choose(int m, int n) {
	double result = 1.0;
	return permute(m, n) / fact(n);
}

double sum(int from, int to, double (* imp)(int)) {
	double result;
	for (int i = from; i <= to; i++) {
		result += imp(i);
	}
	return result;
}

RV * info(RV a) {
	return a.distrib;
} 
// class function::RV

RV::RV() {
	distrib = NULL;
} 

RV::RV(string ref) {
	if (ref == "DU") {
		distrib = new DU();
	} else if (ref == "HG") {
		distrib = new HG();
	} else if (ref == "Bin") {
		distrib = new Bin();
	} else if (ref == "NB") {
		distrib = new NB();
	} else if (ref == "Geo") {
		distrib = new Geo();
	} else if (ref == "Poisson") {
		distrib = new Poisson();
	} else {
		distrib = NULL;
	}
}

void RV::set_DU(int n) {
	distrib = new DU(n);
}

void RV::set_Bin(int n, double p) {
	distrib = new Bin(n, p);
}

void RV::set_Geo(double p) {
	distrib = new Geo(p);
}

void RV::set_HG(int N, int r, int n) {
	distrib = new HG(N, r, n);
}

void RV::set_NB(int m, double p) {
	distrib = new NB(m, p);
}

void RV::set_Poisson(int n, double p) {
    distrib = new Poisson(n, p);	
}

void RV::destroy() {
	delete distrib;
}

// vtable placeholder
double RV::cdf(int n) {return 0.0;}

double RV::pf(int n) {return 0.0;}

// class function: HG

HG::HG() : Spec(0), Total(0), Chs(0) {}

HG::HG(int N, int r, int n) : Total(N), Spec(r), Chs(n) {}

double HG::pf(int n) {
   return (choose(Spec, n) * choose(Total - Spec, Chs - n)) / choose(Total, Chs);
}

double HG::cdf(int n) {
	double result;
	for (int i = 0; i <= n; i++) {
		result += HG::pf(i);
	}
	return result;
}

// class function: Bin

Bin::Bin() : num(0), prob(0) {}

Bin::Bin(int n, double p) : num(n), prob(p){}

double Bin::pf(int n) {
   return choose(num, n) * pow(prob, n) * pow(1 - prob, num - n);
}

double Bin::cdf(int n) {
	double result;
	for (int i = 0; i <= n; i++) {
		result += Bin::pf(i);
	}
	return result;
}

// class function: Poisson

Poisson::Poisson() : num(0), prob(0) {}

Poisson::Poisson(int n, double p) : num(n), prob(p) {}

double Poisson::pf(int n) {
   double u = num * prob;
   return ((1 / pow(MATH_e, u)) * pow(u, (double)n)) / fact(n); 
}

double Poisson::cdf(int n) {
	double result;
	for (int i = 0; i <= n; i++) {
		result += Poisson::pf(i);
	}
	return result;
}

// class function: DU

DU::DU() : num(0) {}

DU::DU(int n) : num(n) {}

double DU::pf(int n) {
   return (1.0 / num);
}

double DU::cdf(int n) {
	return ((double)n / (double) num);
}

// class function: NB

NB::NB() : num(0), prob(0.0) {}

NB::NB(int n, double p) : num(n), prob(p) {}

double NB::pf(int n) {
   return choose(n + num - 1, n) * pow(1 - prob, n) * pow(prob, num);
}

double NB::cdf(int n) {
   double result = 0;
   for(int i = 0; i <= n; i++) {
   	result += NB::pf(i);
   }
   return result;
}

// class function: Geo

Geo::Geo() : prob(0.0) {}

Geo::Geo(double p) : prob(p) {}

double Geo::pf(int n) {
   return pow(1 - prob, n) * prob; 
}

double Geo::cdf(int n) {
   double result = 0;
   for(int i = 0; i <= n; i++) {
   	result += Geo::pf(i);
   }
   return result;
}


