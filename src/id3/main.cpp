//
// Run: clang++ -stdlib=libc++ -std=c++98 -pedantic main.cpp; time ./a.out;
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
 *  v  Verbose output  
 */
void sieveEuler(uint64_t n0,uint64_t n1, std::list<uint64_t>* ps, int v) {
    std::list<uint64_t>::iterator sit = ps->begin();
    std::list<uint64_t>::iterator eit = ps->end();
    if (sit != eit) {
        eit--;
    }
    if (v) {printf("Generating all integers in range [%llu to %llu] ...\n", n0, n1);}
    n0 = n0 < 2 ? 2 : n0;
    for (uint64_t i=n0; i<=n1; i++) {
        ps->push_back(i);
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


