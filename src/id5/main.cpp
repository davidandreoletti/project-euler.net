//
// Run: clang++ -stdlib=libc++ -std=c++98 -pedantic main.cpp; time ./a.out;
//

#include <cstdio> //printf

int main(void) {
    // Solution using some analysis / brute force :(
    // Number n is a multiple of 1,2,3,4, ..., 19,20. However:
    // 20 ≡ 0 (mod 10), 20 ≡ 0 (mod 5), 20 ≡ 0 (mod 2), 20 ≡ 0 (mod 1), so 10,5,2,1 don't need to be checked.
    // 18 ≡ 0 (mod 9), 18 ≡ 0 (mod 3), 18 ≡ 0 (mod 2), 18 ≡ 0 (mod 1),  so 9,3,2,1 don't need to be checked.
    // 16 ≡ 0 (mod 8), 16 ≡ 0 (mod 4), 16 ≡ 0 (mod 2), 16 ≡ 0 (mod 1),  so 8,4,2,1 don't need to be checked.
    // 15 ≡ 0 (mod 5), 15 ≡ 0 (mod 3), 15 ≡ 0 (mod 2), 15 ≡ 0 (mod 1),  so 5,3,2,1 don't need to be checked.
    // 14 ≡ 0 (mod 7), 14 ≡ 0 (mod 2), 14 ≡ 0 (mod 1),                  so 7,2,1 don't need to be checked.
    // 12 ≡ 0 (mod 6), 12 ≡ 0 (mod 4), 15 ≡ 0 (mod 2), 15 ≡ 0 (mod 1),  so 6,4,2,1 don't need to be checked.
    // So n must be multiple of 20,19,18,17,16,15,14,13,12,11 only
    unsigned int i = 1;
    for (;!(i%20 == 0 && i%19 == 0 && i%18 == 0 && i%17 == 0 && i%16 == 0 && i%15 == 0 && i%14 == 0 && i%13 == 0 && i%12 == 0 && i%11 == 0);i++);
    printf("Answer: %u \n", i);
    // Solution using analysis only :)
    // Number n is a multiple of 1,2,3,4, ..., 19,20. However:
    // 20 ≡ 0 (mod 10), 20 ≡ 0 (mod 5), 20 ≡ 0 (mod 2), 20 ≡ 0 (mod 1), so 10,5,2,1 don't need to be checked.
    // 18 ≡ 0 (mod 9), 18 ≡ 0 (mod 3), 18 ≡ 0 (mod 2), 18 ≡ 0 (mod 1),  so 9,3,2,1 don't need to be checked.
    // 16 ≡ 0 (mod 8), 16 ≡ 0 (mod 4), 16 ≡ 0 (mod 2), 16 ≡ 0 (mod 1),  so 8,4,2,1 don't need to be checked.
    // 15 ≡ 0 (mod 5), 15 ≡ 0 (mod 3), 15 ≡ 0 (mod 2), 15 ≡ 0 (mod 1),  so 5,3,2,1 don't need to be checked.
    // 14 ≡ 0 (mod 7), 14 ≡ 0 (mod 2), 14 ≡ 0 (mod 1),                  so 7,2,1 don't need to be checked.
    // 12 ≡ 0 (mod 6), 12 ≡ 0 (mod 4), 15 ≡ 0 (mod 2), 15 ≡ 0 (mod 1),  so 6,4,2,1 don't need to be checked.
    // So n must be multiple of 20,19,18,17,16,15,14,13,12,11 only
    // n = 2*5*2 * 19 * 2*3*3 * 17 * 2*2*2*2 * 3*5 * 2*7 * 13 * 2*2*3 * 11
    // n = 5 * 19 * 2*3*3 * 17 * 2*2*2*2 * 3*5 * 2*7 * 13 * 3 * 11   // Removed 2*2 since 2*2*2*2 contains 2*2 already
    // n = 5 * 19 * 2*3*3 * 17 * 2*2*2*2 * 5 * 2*7 * 13 * 11         // Removed *3 since 3*3*2 contains *3 already
    // n = 5 * 19 * 2*3*3 * 17 * 2*2*2*2 * 2*7 * 13 * 11             // Removed *5 since first *5 contains *5 already
    // n = 5 * 19 * 3*3 * 17 * 2*2*2*2 * 7 * 13 * 11                 // Removed *2 since first 2*2*2*2 contains *2 already
    printf("Answer: %u \n", 5 * 19 * 3*3 * 17 * 2*2*2*2 * 7 * 13 * 11);
    return 0;
}


