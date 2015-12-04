#include <iostream>
#include <gmpxx.h>
#include <cstring>

using std::cout;
using std::endl;

int main() {
  mpz_class lastNum = 1;
  mpz_class currentNum = 2;

  mpz_class temp;

  int index= 3;

  while(1) {
    // Save the current number
    temp = currentNum;
    // Update the current number
    currentNum = currentNum + lastNum;
    // Update the last number
    lastNum = temp;

    // Update index
    index++;

    // Perform length check
    if (strlen(mpz_get_str(NULL, 10, currentNum.get_mpz_t())) == 1000) {
      cout << index << endl;
      break;
    }
  }
  
  return 0;
}
