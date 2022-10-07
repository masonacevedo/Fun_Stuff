#include <iostream>
#include <cmath>
#include <vector>


bool divisible(size_t &a, size_t &b){
    return floor(double(a)/double(b)) == (double(a)/double(b));
}

bool generatePrimesHelper (size_t &n, std::vector <size_t> primes){
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

std::vector <size_t> generatePrimes (size_t &n){
    std::vector <size_t> primes;

    for (size_t index = 2; index <= n; index++){
        if (generatePrimesHelper(index, primes)){
            primes.push_back(index);
        }
    }
    return primes;
}

bool isPrime(size_t &n){
    for (size_t index = 2; index <= sqrt(n); index++){
        if (divisible(n, index)){
            return false;
        }
    }
    return true;
}

size_t nextPrime(size_t &n){
    size_t m = n;
    while (true){
        if (isPrime(m)){
            return m;
        }
        m++;
    }
}


int main(){
    

    size_t n;
    std::cout << "Input a composite number and I will tell you the first prime after it: ";
    std::cin >> n;
    std::cout << "\n";
    size_t ans = nextPrime(n);
    std::cout << ans << std::endl;

    // std::vector primes = generatePrimes(n);
    // std::cout << "primes: [";
    // for (int i = 0; i < primes.size(); i++){
    //     if (i == (primes.size()-1)){
    //         std::cout << primes[i];
    //     }
    //     else{
    //         std::cout << primes[i] << ", ";
    //     }
        
    // }
    // std::cout << "]" << std::endl;

}