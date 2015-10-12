#include <iostream>
#include <math.h>
#include <string.h>
#include <sstream>
#include <iomanip>

using namespace std;


void PideValores(double *X4, double *X3, double *X2, double *X1, double *X0, double *Xini, double *Yini, double *Xfin, double *h)
{
    cout << "Introduce el valor de X4 de la derivada: ";
    cin >> *X4;
    cout << endl;
    
    cout << "Introduce el valor de X3 de la derivada: ";
    cin >> *X3;
    cout << endl;
    
    cout << "Introduce el valor de X2 de la derivada: ";
    cin >> *X2;
    cout << endl;
    
    cout << "Introduce el valor de X1 de la derivada: ";
    cin >> *X1;
    cout << endl;
    
    cout << "Introduce el valor de X0 de la derivada: ";
    cin >> *X0;
    cout << endl << endl;
    
    cout << "Introduce el valor inicial de X: ";
    cin >> *Xini;
    cout << endl;
    
    cout << "Introduce el valor inicial de Y: ";
    cin >> *Yini;
    cout << endl;
    
    cout << "Introduce el valor final de X: ";
    cin >> *Xfin;
    cout << endl;
    
    cout << "Introduce el tamaño de paso h: ";
    cin >> *h;
    cout << endl;
    
    cout << "La derivada es: dy/dx = " << *X4 << "X^4 + " << *X3 << "X^3 + " << *X2 << "X^2 + " << *X1 << "X + " << *X0 << endl << endl;
    cout << "El valor inicial de X es: " << *Xini << endl;
    cout << "El valor inicial de Y es: " << *Yini << endl;
    cout << "El valor final de X es: " << *Xfin << endl;
    cout << "El tamaño de paso es: " << *h << endl;
    cout << endl << endl;
}



void Euler (double *X4, double *X3, double *X2, double *X1, double *X0, double *Xini, double *Yini, double *Xfin, double *h)
{
    
    double Pasos = ceil((*Xfin-*Xini)/(*h));
    double Y = *Yini;
    double Yc = 197867;
    double errorglobal = 0;
    double errorrelativo=0;
    double i=0;
    
    cout << " " << "\t\t\t" << "Y calculada" << "\t\t\t" << "Y Euler" << "\t\t\t" << "Error global" << "\t\t\t" << "Error Relativo" << endl;
    
    for (double j = *Xini; j<= Pasos ; j++)
    {
        Yc = (-0.5)*(i*i*i*i)+(4)*(i*i*i)+(-10)*(i*i)+(8.5)*(i)+(1);
        
        if (j==*Xini)
        {
            Y=*Yini;
        }
        else
        {
            Y = (Y + ((*h)*((*X4)*((i-0.5)*(i-0.5)*(i-0.5)*(i-0.5))+(*X3)*((i-0.5)*(i-0.5)*(i-0.5))+(*X2)*((i-0.5)*(i-0.5))+(*X1)*((i-0.5))+(*X0))));
        }
        
        
        errorglobal = fabs(((Yc-Y)/Yc)*100);
        errorrelativo = Y-Yc;
        
        i+=0.5;
        
        cout << setprecision (3) << fixed  << j << "\t\t\t" << Yc << "\t\t\t" << Y << "\t\t\t" << errorglobal << "\t\t\t" << errorrelativo << endl;
    }
}



int main()
{
    double X4, X3, X2, X1, X0, Xini, Yini, Xfin, h;
    
    PideValores(&X4, &X3, &X2, &X1, &X0, &Xini, &Yini, &Xfin, &h);
    Euler(&X4, &X3, &X2, &X1, &X0, &Xini, &Yini, &Xfin, &h);
    cout << endl << endl;
    
    
    return 0;
}
