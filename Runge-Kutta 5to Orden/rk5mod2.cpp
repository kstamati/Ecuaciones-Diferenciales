// Runge Kutta de Quinto Orden

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

double DERIVS (double X, double Y){
	
	return (-2.0*pow(X,3) + 12*pow(X,2) -20*X + 8.5);
	
	
	
	
}

double RK5 (int i, int n, double x, double y, double h, double y0, double ynew){
	
		for (i = 0; i < n ; i++){
	
	double k1 = DERIVS (x, y);
	double k2 = DERIVS(x + (1/4)*h, y + (1/4)*k1*h);
	double k3 = DERIVS(x + (1/4)*h, y + (1/8)*k1*h + (1/8)*k2*h);
	double k4 = DERIVS(x + (1/2)*h, y - (1/2)*k2*h + k3*h);
	double k5 = DERIVS(x + (3/4)*h, y + (3/16)*k1*h + (9/16)*k4*h);
	double k6 = DERIVS(x + h, y - (3/7)*k1*h + (2/7)*k2*h + (12/7)*k3*h - (12/7)*k4*h + (8/7)*k5*h);
	
	x = x + h;
		
	ynew = y0 + (1.0/90.0)*(7.0*k1 + 32.0*k3 + 12.0*k4 + 32.0*k5 + 7.0*k6)*h;
	
	y0 = ynew;
	
	cout << x << " 		" << ynew <<  endl;  
	
	
	}	
	
	return ynew;
	
}

int main (){
	int i, n;
	double h = 0.25;
	double a = 0.0;
	double b = 1.0;
	double x, y, x0, xf, ynew, y0, w;
	
	x0 = a;
	x = x0;
	xf = 4.0;
	y0 = b;
	n = (xf-x0)/h;
	

	
	cout << 	RK5(i, n, x, y, h, y0, ynew)  << endl;
		
	

	
	
	
	
	
	
	
	return 0;
}

