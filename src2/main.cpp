#include <vector>
#include <iostream>


constexpr std::vector<int> v ()
{
    std::vector<int> values {1,2,3,4,5,6};
    return values;
}
int main ()
{

    constexpr std::vector<int> values = v();
    return values.size();
}
