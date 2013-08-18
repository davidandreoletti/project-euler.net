//
// Run: clang++ -stdlib=libc++ -std=c++98 -pedantic -I`pwd`/../../include  main.cpp; time ./a.out;
//

#include <cstdio> //printf
#include "math/palindrome.h"

int main(void) {
    // Solution O(n^2)  :(
    unsigned int n = 999;
    unsigned int p = 0;
    unsigned int r = 0;
    while (n > 99) {
        unsigned int m = 999;
        while (n<=m && m > 99) {
           if ((r = n*m) > p && isPalindromic(r)) {
               p = r;
           }
           m--;
        }
        n--;
    } 
    printf("Answer: %u \n", p);
    return 0;
}


