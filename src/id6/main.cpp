//
// Run: clang++ -stdlib=libc++ -std=c++98 -pedantic main.cpp; time ./a.out;
//

#include <cstdio> //printf

int main(void) {
    // Solution using analysis only
    // d = (1^2 + 2^2 + 3^2 + ... + 100^2) - (1+2+3+...+100)^2
    // d = (n(n+1)(2n+1))/6 - (n(n+1)/2)^2, n = 100
    unsigned int n = 100;
    printf("Answer: %u \n", ((n*(n+1))/2)*((n*(n+1))/2) - ((n*(n+1)*(2*n+1))/6));
    return 0;
}


