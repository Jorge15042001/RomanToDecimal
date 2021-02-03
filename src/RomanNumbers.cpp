#include "RomanNumbers.h"
#include <map>
#include <string>
//std::map<char, int> conversorToInt;
void loadConversionMapToInt(){
    conversorToInt['I']=1;
    conversorToInt['V']=5;
    conversorToInt['X']=10;
    conversorToInt['L']=50;
    conversorToInt['C']=100;
    conversorToInt['D']=500;
    conversorToInt['M']=1000;
    

}
/*
 * funcionamiento: (se asume que el numero que se recibe es un romano valido)
 * se asume que todo numero se debe sumar al total, sin importar su posicion ni los numeros adyacentes
 * si se detecta que el numero que se va a sumar es mayor que el anterior, entonces se resta 2 veces el anterior,
 *      la primera resta es para cancelar la suma que se realizo en la iteracion anterior
 *      la segunda resta, es porque si el numero anterior al actual es menor entonces este se debe restar al acutal
 * 
 */

int toDecimal(std::string& romanNumber){
    if (romanNumber.size()==0) return 0;// si no se recibe nada se retorna 0
    if (romanNumber.size()==1) return conversorToInt[romanNumber[0]];// si solo se recibe una letra se convierte y se retorna
    int last= conversorToInt[romanNumber[0]];//se define como ultimo visitado el primer elemento
    int suma=last;// suma que acumula el resultado
    for (int i=1;i<romanNumber.size();i++){
        int actual=conversorToInt[romanNumber[i]];
        if (actual>last)suma-=2*last;//si el actual es meyor que el anterior, significa que habia que restarlo y no que sumarlos, porl  lo que se lo resta 2 veces, para cancelar el efecto de la suma anterior y por la resta que debiahacerce
        suma+=actual;//simpre se suma el actual
        last=actual;//el ultimo visitado se define como el actual
    }
    return suma;

}
/*
 *funcionamiento: (se asume que se recibe un numero Romano valido)
 *se recorre la cadena 2 caracteres a la vez, si el primero es mayor que el que le sigue su valor se suma al acumulado
 *caso contrario se resta
 */
int toDecimal2(std::string& romanNumber){
    if (romanNumber.size()==0) return 0;// si no se recibe nada se retorna 0
    if (romanNumber.size()==1) return conversorToInt[romanNumber[0]];// si solo se recibe una letra se convierte y se retorna
    int actual;
    int next;
    int suma=0;// conversorToInt[romanNumber[0]];//se define como ultimo visitado el primer elemento
    for (int i=0;i<romanNumber.size()-1;i++){
        actual=conversorToInt[romanNumber[i]];
        next=conversorToInt[romanNumber[i+1]];
        if (actual<next)suma-=actual;
        else suma+=actual;
    }
    suma+=next;// el ultimo valor siempre se suma

    return suma;

}
