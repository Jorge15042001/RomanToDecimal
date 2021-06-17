#include <iostream>
#include "DecimalNumber.h"
void loadConversionMapToRoman(){
    conversorToRoman[1]='I';
    conversorToRoman[5]='V';
    conversorToRoman[10]='X';
    conversorToRoman[50]='L';
    conversorToRoman[100]='C';
    conversorToRoman[500]='D';
    conversorToRoman[1000]='M';
    

}

/**
 *this fucition takes a number and returns a list of integer in 
 */
std::vector<int>transfrom(int n,int multiplier){
    std::vector<int> response;
    response.reserve(4);
    if(n==9)response.emplace_back(10*multiplier);
    else if(n>3 && n<9)response.emplace_back(5*multiplier);
    int repetitions= n%5;
    if (repetitions==4)response.insert(response.begin(),multiplier);
    else for (;repetitions>0;repetitions--)response.emplace_back(multiplier);

    return response;
}
std::string vectorToString(std::vector<int>&nums){
    std::string response;
    response.resize(nums.size());
    for (int i=0;i<response.size();i++){
        response[i]= conversorToRoman[nums[i]];
    }
    return response;
}
std::string toRoman(int decimal){
    int leftOver=decimal/10;
    int remainder=decimal%10;
    int multiplier=1;
    std::vector<int>romano;
    while (remainder>0 || leftOver>0){
        std::vector<int> converted= transfrom(remainder,multiplier);
        romano.insert(romano.begin(),converted.begin(),converted.end());
        remainder=leftOver%10;
        leftOver=leftOver/10;
        multiplier*=10;
    }
    return vectorToString(romano);
}
