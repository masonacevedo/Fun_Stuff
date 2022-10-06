#include <iostream>
#include <cmath>
#include <vector>

bool divisible(int a, int b){
    return floor(double(a)/double(b)) == (double(a)/double(b));
}

bool generatePrimesHelper (int n, std::vector <int> primes){
    if (n == 2){
        return true;
    }
    int index = 0;
    
    while (primes[index] <= sqrt(n)) {
        if (divisible(n, primes[index])){
            return false;
        }
        index++;
    }
    return true;
}

std::vector <int> generatePrimes (int n){
    std::vector <int> primes;

    for (int index = 2; index <= n; index++){
        if (generatePrimesHelper(index, primes)){
            primes.push_back(index);
        }
    }
    return primes;
}

bool isPrime(int n){
    for (int index = 2; index <= sqrt(n); index++){
        if (divisible(n, index)){
            return false;
        }
    }
    return true;
}


int main(){

    int n;
    std::cout << "Input a number and I give you the primes less than or equal to that number: ";
    std::cin >> n;
    std::cout << "\n";

    std::vector primes = generatePrimes(n);
    std::cout << "primes: [";
    for (int i = 0; i < primes.size(); i++){
        if (i == (primes.size()-1)){
            std::cout << primes[i];
        }
        else{
            std::cout << primes[i] << ", ";
        }
        
    }
    std::cout << "]" << std::endl;

}