#include <iostream>
#include <cmath>

bool divisible(int a, int b){
    return floor(float(a)/float(b)) == (float(a)/float(b));
}

bool isPrime(int n){
    for (int index = 2; index < sqrt(n); index++){
        if (divisible(n, index)){
            return false;
        }
    }
    return true;
}


int main(){
    int n;
    std::cout << "Input a number, and I will tell you if it's prime:";
    std::cin >> n;
    std::cout << "\n";
    if (isPrime(n)){
        std::cout << n << " is prime!";
    }
    else{
        std::cout << n << " is composite!";
    }
    std::cout << std::endl;
}