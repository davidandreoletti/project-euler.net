//
// Run: clang++ -stdlib=libc++ -std=c++98 -pedantic -I`pwd`/../../include  main.cpp; time ./a.out;
//

#include <cstdint> // uint64_t
#include <cstdio> //printf
#include <list>
#include "math/sieves.h"

int main(void) {
    // Solution brute force with some analysis :(
    // Prime-counting function π(x) shows that x=10^5 yields about 9952 primes and x=10^6 yields about 78,498 primes (http://en.wikipedia.org/wiki/Prime-counting_function).
    // So let's generate all primes for x up to about [1..3]*10^5
    std::list<uint64_t> ps;
    std::list<uint64_t>::iterator it1;
    sieveEuler(1, 200000, &ps, 0);
    it1 = ps.begin();
    for (int i = 1; it1!=ps.end() && i!=10001 ;i++) {it1++;}
    printf("Answer: %llu \n", *it1);
    return 0;
}


