//
//  main.cpp
//  RKTHIRDORDER
//
//  Created by Diego Berdeja on 29/09/2015.
//  Copyright (c) 2015 Diego Berdeja. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define LIM 10000
#define dy(x,y) (cos(x))
#define y(x) (sin(x))

int main(int argc, const char * argv[]) {
    
    float paso, begin, end, numero;
    float vector[LIM];
    float real[LIM], RK[LIM], H[LIM],E[LIM], PM[LIM];
    float k1, k2, k3;
    string filename="/Users/DiegoBerdeja/Desktop/";
    string token;
    
    H[0]=0;
    E[0]=0;
    RK[0]=0;
    PM[0]=0;
    
    //Pedimos los parametros del problema.
    cout << "Introduzca el inicio del rango: ";
    cin >> begin;
    cout << "Introduzca el final del rango: ";
    cin >> end;
    cout << "Introduzca el tamano de paso: ";
    cin >> paso;
    numero=ceil((end-begin)/paso+1);
    
    //Generamos el vector x, los valores reales, y los calculados.
    for (int ii=0; ii<numero; ii++) {
        vector[ii]=ii*paso;
    }
    
    for (int ii=0; ii<numero; ii++) {
        real[ii]=y(vector[ii]);
        if (ii>0) {
            //Calculos de RK tercer orden.
            k1=(dy(vector[ii-1],RK[ii-1]));
            k2=(dy(vector[ii-1]+paso/2, RK[ii-1]+k1*paso/2));
            k3=(dy(vector[ii-1]+paso, RK[ii-1]-(k1*paso)+(2*k2*paso)));
            RK[ii]=RK[ii-1]+(paso/6)*(k1+4*k2+k3);
            
            //Calculos de Heun.
            H[ii]=H[ii-1]+(paso/2)*(dy(vector[ii-1], H[ii-1])+dy(vector[ii-1]+paso, H[ii-1]+paso*dy(vector[ii-1], H[ii-1])));
            
            //Calculos de Euler.
            E[ii]=E[ii-1]+paso*dy(vector[ii-1],E[ii-1]);
            
            //Calculamos el punto medio.
            PM[ii]=PM[ii-1]+paso*dy(vector[ii-1]+paso/2, PM[ii-1]+(paso/2)*dy(vector[ii-1],PM[ii-1]));
            
            
        }
    }
    
    //Imprimimos los resultados.
    cout << "Elija el nombre del archivo: ";
    cin >> token;
    
    filename=filename+token+".txt";
    
    FILE* fp=fopen(filename.c_str(), "w");
    
    fprintf(fp, "paso=%f\nIteracion, X, Y_real(X), Y_RK(X), Y_PM(X),Error\n",paso);
    
    for (int ii=0; ii<numero; ii++) {
        fprintf(fp, "%d, %f, %f, %f, %f, %f\n",ii+1,vector[ii],real[ii],RK[ii],PM[ii],fabs((real[ii]-PM[ii])/real[ii])*100);
    }
    
    
    
    fclose(fp);
    
    cout << endl;
    
    return 0;
}
