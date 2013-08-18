//
// Run: lang++ -stdlib=libc++ -std=c++98 -pedantic -I`pwd`/../../include  main.cpp; time ./a.out;
//

#include <cstdint> // uint64_t
#include <cstdio> //printf
#include <list>
#include "math/sieves.h"

int main(void) {
    uint64_t t = 600851475143;
    // Sieve increment
    uint64_t rInc = 100;
    uint64_t r0 = 1;
    uint64_t r1 = r0;
    std::list<uint64_t> ps;
    std::list<uint64_t>::iterator it1;
    int f = 0;
    do {
        r0 = r1+1;
        r1 = r0+rInc;
        sieveEuler(r0, r1, &ps, 1);
        printf("Find prime factors for %llu ...\n", t);
        // Find primes p0,p1,p2,...,pn such that p0*p1*p2*...*pn divides t perfectly
        it1 = ps.begin(); // Start p0
        while (t!=(*it1) && it1!=ps.end()) {
            if ((t%(*it1)) == 0) {
                // next prime p dividing t perfectly is in range ]p ... t/p]
                t = t/(*it1);
                printf("t = %llu p=%llu \n", t, *it1);
            } else {
                it1++;
            }
        }
        f = (t==(*it1));
    } while (!f);
    printf("Answer: %llu \n", *it1);
    return 0;
}


