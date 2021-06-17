#include <array>
#include <unordered_map>
#include <string>
#include <iostream>
#include <utility>
#include <string>

#include "SimpleLookUpTable.h"
namespace DecimalToRomanConversor {
    static constexpr std::array<std::pair<int, char>, 7> ConvertionData{{
        {1,'I'},
        {5,'V'},
        {10,'X'},
        {50,'L'},
        {100,'C'},
        {500,'D'},
        {1000,'M'}}
    };
    
    static Map<int, char, ConvertionData.size()> ConvertionLookUpTable {(ConvertionData)};

    constexpr const char * Convert ( const int value )
    {
        const int max_length = 100;
        int leftOver = value / 10; 
        int remainder = value % 10;
        int multiplier = 1;

        std::array<int,max_length> romanBlocks({}) ;



       return "";
    }
    
}

