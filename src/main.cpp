#include <boost/lexical_cast/bad_lexical_cast.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "RomanNumbers.h"
#include "DecimalNumber.h"
int getInt()
{
   std::string input;
   std::cin>>input;
   if (input.compare("done")==0)return -1;// si el usuario desea salir retorna -1
   try{//intentar convertir a entero
       int n=boost::lexical_cast<int>(input);
       return n;
   }catch (boost::bad_lexical_cast){
       std::cout<<"Ingrese un entero valido"<<std::endl;
       return getInt();
   }
}
void runRomanConversion()
{
    
    loadConversionMapToInt();
    std::string roman;
    std::cin>>roman;
    while (roman.compare("done")!=0)
    {
        boost::to_upper(roman);
        std::cout<<toDecimal2(roman)<<std::endl;
        std::cin>>roman;
    }
}
void runIntConversion()
{
    loadConversionMapToRoman();
    int input= getInt();
    while (input>0){
        std::cout<<toRoman(input)<<std::endl;
        input= getInt();

    }

}
void printHelp(char ** args){
        std::cout<<"Ejecutar"<<std::endl;
        std::cout<<"./"<<args[0]<<" "<<"Roman"<<"\t"<<"para traducir a romanos"<<std::endl;
        std::cout<<"./"<<args[0]<<" "<<"Decimal"<<"para traducir a base 10"<<std::endl;

}
int main(int argc, char ** argv){
    if (argv[1]==nullptr)printHelp(argv);
    else if (strcmp(argv[1],"Decimal")==0)runRomanConversion();
    else  if (strcmp(argv[1],"Roman")==0)runIntConversion();
    else std::cout<<"Ingrese una opcion valida"<<std::endl;
    return 0;
    
    
}
