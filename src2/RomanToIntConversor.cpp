#include <unordered_map>
#include <string>
#include <iostream>
class RomanToIntConversor
{
public:
    //RomanToIntConversor (const RomanToIntConversor &) = delete ;

    [[nodiscard]]static int Convert(const std::string &);
private:
    [[nodiscard]]static RomanToIntConversor& Get();
    std::unordered_map<char, int> m_ConversionTable;
    RomanToIntConversor ();
};

// Constructor loads the table in to the conversion lookup table
RomanToIntConversor::RomanToIntConversor(){
  m_ConversionTable['I'] = 1;
  m_ConversionTable['V'] = 5;
  m_ConversionTable['X'] = 10;
  m_ConversionTable['L'] = 50;
  m_ConversionTable['C'] = 100;
  m_ConversionTable['D'] = 500;
  m_ConversionTable['M'] = 1000;
}

[[nodiscard]]RomanToIntConversor& RomanToIntConversor::Get ()
{
    static RomanToIntConversor m_conversor ;
    return m_conversor;
}

[[nodiscard]]int RomanToIntConversor::Convert(const std::string & romanNumber)
{
    
    int last = 0;
    int suma = 0;

    for (int i=0; i<romanNumber.size(); i++){
      const int actual = Get().m_ConversionTable[romanNumber[i]];
      if (actual > last)
        suma -= 2 * last;

      suma += actual; // simpre se suma el actual
      last = actual;  // el ultimo visitado se define como el actual
    }
    return suma;

}

