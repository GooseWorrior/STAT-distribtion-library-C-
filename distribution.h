#include<iostream>
#include<string>
#include<math.h>

using namespace std;


// constant 

extern const double MATH_e;


//  helper function

double permute(int m, int n);

double fact(int n);

double choose(int m, int n);

// class definition
class RV {
    public: 
      RV();
      RV(string a);
      void set_DU(int n);
      void set_HG(int N, int r, int n);
      void set_Bin(int n, double p);
      void set_NB(int m, double p);
      void set_Geo(double p);
      void set_Poisson(int n, double p);
      void destroy();
	virtual double pf(int);
	virtual double cdf(int);
	friend double permute(int, int);
	friend double fact(int);
	friend double choose(int, int);
	friend double pow(double x, double y);
	friend double sum(int from, int to, double (* imp)(int));
	friend RV * info(RV);
    private:
    	RV * distrib;
};

class DU : public RV {
	public:
		DU();
		DU(int n);
		double pf(int);
		double cdf(int);
	private:
		double num;
}; 

class HG : public RV {
	public:
		HG();
		HG(int N, int r, int n);
		double pf(int);
		double cdf(int);
	private:
		int Total;
		int Spec;
		int Chs;
};

class Bin : public RV {
	public:
		Bin();
		Bin(int n, double p);
		double pf(int);
		double cdf(int);
	private:
		int num;
		double prob;
};


class NB : public RV {
	public:
		NB();
		NB(int m, double p);
		double pf(int);
		double cdf(int);
	private:
		int num;
		double prob;
};

class Geo : public RV {
	public:
		Geo();
		Geo(double p);
		double pf(int);
		double cdf(int);
	private:
		double prob;
};


class Poisson : public RV {
	public:
		Poisson();
		Poisson(int n, double p);
		double pf(int);
		double cdf(int);
	private:
		double prob;
		int num;
};
