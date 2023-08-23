#include <iostream>
#include "proxy.h"

int main() {
    auto real_db = VeryHeavyDatabase();
    auto cached_db = CacheProxyDB(std::addressof(real_db));
    auto test_db = TestDB(std::addressof(real_db));
    std::cout << cached_db.GetData("key") << std::endl;
    std::cout << cached_db.GetData("key") << std::endl;
    std::cout << test_db.GetData("key") << std::endl;

    // hw

    auto limit_db = OneShotDB(std::addressof(real_db), 2);
    
    for (int i = 0; i < 10; ++i)
    {
        std::cout << limit_db.GetData("key") << std::endl;
    }

    // exit
    std::cout << std::endl;
    std::cout << "PRESS ENTER...";
    std::cin.get();
    return EXIT_SUCCESS;
}