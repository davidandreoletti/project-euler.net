//
// Palindrome related functions
//

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
