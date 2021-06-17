#if RomanInclude == 0
#define RomanInclude =1
#include <map>
#include <string>
inline std::map<char, int> conversorRomanToInt;
void loadConversionMapToInt();
int toDecimal(std::string& romanNumber);
int toDecimal2(std::string& romanNumber);
#endif
