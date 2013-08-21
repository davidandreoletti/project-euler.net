//
// Run: clang++ -stdlib=libc++ -std=c++98 -pedantic -I`pwd`/../../include  main.cpp; time ./a.out;
//

#include <cstdint> // uint64_t
#include <cstdio> //printf
#include <list>
#include "math/sieves.h"

int main(void) {
    // Solution
    uint64_t n0 = 2;
    uint64_t n1 = 2000000-1;
    std::list<uint64_t> ps;
    std::list<uint64_t>::iterator it;
    uint64_t s = 0;
    sieveTrialDivision(n0, n1, &ps, 0);
    for (it=ps.begin(); it!=ps.end() ;++it){
        s += *it;
    }
    printf("Answer: %llu \n", s);
    return 0;
}


