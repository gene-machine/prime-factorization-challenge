#include <iostream>
#include <vector>
#include <valarray>

using namespace std;

vector<unsigned int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
bool isPrime(unsigned long int test);

int main() {
    unsigned long int composite;
    cout << "Enter a composite number to be factored:";
    cin >> composite;

    vector<unsigned long int> factors;

    if(isPrime(composite)){factors.push_back(1);factors.push_back(composite);}
    else{
        for(unsigned int testFactor:primes){
            while(composite % testFactor == 0){
                composite = composite/testFactor;
                factors.push_back(testFactor);
            }
        }
        factors.push_back(composite);
    }

    cout << "The Factors are: ";
    for(unsigned long int factor:factors){cout << factor << " ";}

    return 0;}

bool isPrime(unsigned long int test){
    unsigned int max = ceil(sqrt(test));
    unsigned int index = 0;
    while(index < primes.size()){
        unsigned int testFactor = primes[index];
        if(testFactor > max) return true;
        else if(test % testFactor == 0) return false;

        if(testFactor == primes.back()) {
            unsigned int check = primes.back() + 2;
            while(!isPrime(check)){check++; check++;}
            primes.push_back(check);}
        index++;}}
