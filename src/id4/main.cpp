//
// Run: clang++ -stdlib=libc++ -std=c++98 -pedantic main.cpp; time ./a.out;
//

#include <cstdio> //printf

/**
 *  Indicates if n is a palindrome (http://en.wikipedia.org/wiki/Palindromic_number)
 *  n Number
 *  return True if n is a Palindrome
 */
int isPalindromic(unsigned int n) {
    unsigned int cn = n;
    unsigned int s = 0;
    while (n > 0) {
        s = s*10 + n%10;
        n /= 10;
    }
    return cn == s;
}

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


