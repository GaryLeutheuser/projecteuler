#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

std::vector<int> LongDivision(int, int, int);
int DecimalPeriodLength(std::string);

int main() {

  const int num_digits_denominator  = 1000;
  const int num_digits_answer       = 2000;
  
  int max_index = 0;
  int max_length = 0;

  for (int number = 2; number < num_digits_denominator; ++number) {
    using std::cout;
    using std::endl;

    int current_length;

    std::vector<int> answer;
    answer = LongDivision(1, number, num_digits_answer);

    // Convert the mantissa of the answer to a string
    std::stringstream answer_stringstream;
    std::copy(answer.begin() + 1, answer.end(),
              std::ostream_iterator<int>(answer_stringstream));
    std::string answer_string = answer_stringstream.str();
    
    //cout << number << ": " << DecimalPeriodLength(answer_string) << endl;
    //cout << number << ": " << DecimalPeriodLength(answer_string) << "\t"
    //     << answer_string << endl;

    current_length = DecimalPeriodLength(answer_string);
    if (current_length > max_length) {
      max_length = current_length;
      max_index = number;
    }
  }

  std::cout << max_index << ": " << max_length << std::endl;
  
  return 0;
}

// Long division function.
// Performs long division on the provided dividend and divisor.
// Returns 100 digits after the decimal point
std::vector<int> LongDivision(int dividend, int divisor, int num_digits) {
  using std::cout;
  using std::endl;
  
  std::vector<int> quotient_decimal_digits;

  int tmp_quotient;
  int tmp_dividend;
  int tmp_subtrahend;

  tmp_dividend = dividend;
  
  for (int i = 0; i < num_digits; ++i) {
    tmp_quotient = tmp_dividend/divisor;
    quotient_decimal_digits.push_back(tmp_quotient);
    tmp_subtrahend = tmp_quotient * divisor;
    tmp_dividend = (tmp_dividend - tmp_subtrahend) * 10;
  }
  
  return quotient_decimal_digits;
}

// Finds the length of the decimal period in the given mantissa.
int DecimalPeriodLength(std::string mantissa) {
  int test_length = 5;

  while (1) {
    std::string test_period = mantissa.substr(5, test_length);
    std::string next_period = mantissa.substr(test_length+5, test_length);
    //std::cout << test_period << std::endl;
    //std::cout << next_period << std::endl << std::endl;

    if (test_length > 1000) {
      return -1;
    }
    
    if (test_period.compare(next_period)) {
      ++test_length;
    } else {
      return test_length;
    }
  }
}
