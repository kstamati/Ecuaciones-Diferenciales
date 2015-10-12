//Resolver una ecuación diferencial ordinaria

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
using namespace std;
// La funcion a evaluar es:
#define y(x) ((4/1.3)*(exp(.8*x)-exp(-.5*x))+2*exp(-0.5*x))
// Su derivada es:
#define dy(x,y)(4*(exp(0.8*x)) - 0.5*(y))
//definidas las funciones a evaluar

//Funcion para pedir los valores de la Ecuacion
void pidevalores (float &xi,float &xf,float &tamañop,float &yi,string &token){
    cout<< "\nIndica el tamaño de paso:";
    cin>> tamañop;
    cout<< "\nIndica el valor inicial de Y(X): ";
    cin>> yi;
    cout<< "\nIndica el valor inicial de X: ";
    cin>> xi;
    cout<< "\nIndica el valor final de X: ";
    cin>> xf;
    cout << "Elija el nombre del archivo: ";
    cin >> token;
}
//Metodo de aproximacion de Euler
void iteracion(float &xi,float &xf, float &tamañop,float &yi,string &filename){
    int iteracion=0;
    float y,pendiente1, pendiente2,prom,yparcial;
    //FILE*= file pointer
    //"w"= write (sobre el archivo)
    FILE* fp=fopen(filename.c_str(), "w");
    fprintf(fp, "paso=%f\nIteracion, X, Y_R(X), Y_E(X), Error\n",tamañop);
    
    cout<<iteracion<<"\t"<<yi<<"\t"<<xi<<endl;
    do
    {
        yparcial=yi;
        iteracion++;
        pendiente1= dy(xi,yi);
        //paso tipo Euler yi:
        yparcial=yi+ (pendiente1*tamañop);
        xi=xi+tamañop;
        y=y(xi);
        pendiente2=dy(xi,yparcial);
        prom=(pendiente1+pendiente2)/2;
        yi=yi+ (prom*tamañop);
        //Aqui imprimimos en el archivo,%d indica el primer dato un int, %f indica dato tipo float
        fprintf(fp, "%d, %f, %f, %f, %f\n",iteracion,xi,y,yi,fabs((y-yi)/y)*100);
        
        
    }
    while(xi<xf);
    //Cerramos el archivo
    fclose(fp);
    
}
int main (){
    float xi,xf,tamañop,yi;
    string token;
    pidevalores(xi,xf,tamañop,yi,token);
    //Direccion donde guardamos el archivo
    string filename="/Users/Kleomenes/Desktop/";
    filename=filename+token+".txt";
    iteracion(xi,xf,tamañop,yi,filename);
}