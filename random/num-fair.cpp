#include <iostream>
#include <string>
using namespace std;

bool isDivisibleByDigits(long long  int num) {
    std::string numStr = std::to_string(num);
    for (char digitChar : numStr) {
        int digit = digitChar - '0';  // Convert char to int
        if (digit == 0) continue; // Skip if the digit is 0 to avoid division by zero
        if (num % digit != 0) {
            return false; // If not divisible by this digit, return false
        }
    }
    return true; // All digits are divisors
}

long long int findNextDivisibleNumber(long long int num){
    while (!isDivisibleByDigits(num)) {
        num++; // Increment and check next number
    }
    return num; // Return the first number that satisfies the condition
}

int main() {
    int caseNum;
    cin >> caseNum;
    long long int  caseArr[caseNum];
    for(int i=0; i< caseNum; i++){
        cin >> caseArr[i]; 
    }
    for(int j=0; j< caseNum; j++){
        long long int result = findNextDivisibleNumber(caseArr[j]);
        cout << result << endl;
    }
    return 0;
}
