//
// Sieves related functions
//

#include <cstdint> // uint64_t
#include <cstdio> //printf
#include <list>

/**
 *  Sieves prime numbers using Euler's sieve (http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Euler.27s_Sieve)
 *  in a specific range
 *  n0 Start range
 *  n1 End range
 *  ps Prime list
 *  v  Verbose output. 0 for no output.
 */
void sieveEuler(uint64_t n0,uint64_t n1, std::list<uint64_t>* ps, int v) {
    std::list<uint64_t>::iterator sit = ps->begin();
    std::list<uint64_t>::iterator eit = ps->end();
    if (sit != eit) {
        eit--;
    }
    if (v) {printf("Generating all potential primes in range [%llu to %llu] ...\n", n0, n1);}
    n0 = n0 < 2 ? 2 : n0;
    for (uint64_t i=n0; i<=n1; i++) {
        // All primes are odd except 2
        if (i%2 || i == 2) {ps->push_back(i);}
    }
    if (v) {printf("Find prime numbers in range [%llu to %llu] ...\n", n0, n1);}
    
    std::list<uint64_t>::iterator sit1 = ps->begin();
    while (sit1 != ps->end()) {
        if (v) {printf("Found prime number = %llu ...\n", *sit1);}
        std::list<uint64_t>::iterator sit2 = sit1;
        while (sit2 != ps->end()) {
            if (((*sit2)%(*sit1)) == 0 && (*sit2)!=(*sit1)) {
                sit2 = ps->erase(sit2);
            }  else {
                sit2++;
            }
        }
        sit1++;
    }
}
