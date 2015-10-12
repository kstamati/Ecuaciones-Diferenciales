#include <iostream>
#include <math.h> 
#include <stdio.h>

using namespace std;
#define dy(x,y) (4*(exp(0.8*x))) - (0.5*y)
#define yreal(x) ((4/1.3)*(exp(0.8*x) - exp(-0.5*x))) + (2*(exp(-0.5*x)))

void PideValores(float &xi, float &xf, float &yi, float &h);
void Runge_Kutta (float &xi, float &xf, float &yi, float &h, float error);

int main()
{
float xi, xf, yi, h, error=0;
PideValores(xi, xf, yi, h);
Runge_Kutta(xi, xf, yi, h, error);
return 0;
}

void PideValores(float &xi, float &xf, float &yi, float &h)
{
cout<<"Indica el valor inicial de x: "<<endl;
cin>>xi;
cout<<"Indica el valor final de x: "<<endl;
cin>>xf;
cout<<"Indica el valor inicial de y: "<<endl;
cin>>yi;
cout<<"Indica el tamano de paso h: "<<endl;
cin>>h;
cout<<endl;
}

void Runge_Kutta (float &xi, float &xf, float &yi, float &h, float error)
{
	int i = ceil((xf-xi)/h);
	float *x = new float [i];
	float *y = new float [i];
	y[0] = yi;
	x[0] = xi;
	float p=h;
	float k1; 
	float k2; 
	float k3;
	float k4;
	for (int n=1;n<=i;n++)
	{
		x[n] = p;
		p = p + h;
	}
	cout<<"X\tY\tYreal\tError"<<endl;
	for (int nn=0;nn<=i;nn++)
	{
		k1 = dy(x[nn],y[nn]);
		k2 = dy((x[nn] + (h/2)), (y[nn] + ((k1*h)/2)));
		k3 = dy((x[nn] + (h/2)), (y[nn] + ((k2*h)/2)));
		k4 = dy((x[nn] + h), (y[nn] + (k3*h)));
		y[nn+1] = y[nn] + (((k1 + (2*k2) + (2*k3) + k4)*h)/6);
		error = fabs(((yreal(x[nn]) - y[nn])/(yreal(x[nn]))*100));
		cout<<x[nn]<<"\t"<<y[nn]<<"\t"<<yreal(x[nn])<<"\t"<<error<<"%"<<endl;
	}
}
