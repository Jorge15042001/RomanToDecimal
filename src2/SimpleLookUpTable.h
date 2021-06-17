#include <array>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <utility>
template<typename Key, typename Value,std::size_t size>
struct Map
{
    std::array<std::pair<Key, Value>, size> data;
    [[nodiscard]] constexpr Value at (const Key &key) const {
        const auto itr =
            std::find_if(begin(data),end(data),
                    [&key](const auto &v){return v.first == key;});

        if ( itr  != end (data) ) return itr->second;
        throw std::range_error("Not Found");
    }
};


