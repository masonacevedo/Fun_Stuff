#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include <random>
#include "myset.hpp"
#include "primes.cpp"

MySet::MySet() {
    // i think the "this" keyword could be used here,
    // but it's not strictly necessary! 
    size_ = 0;
    elements = {};
    bucket_size_ = 13;
    elements.resize(bucket_size_);
    max_load = 0.6;
}

void MySet::insert(std::string key){
    // if element already exists, do nothing
    if (exists(key)){
        return;
    }

    // if element is not in hash table, insert it!
    int hash = myHash(key, bucket_size_);
    if (elements[hash] == ""){
        elements[hash] = key;
    }
    else{
        int currentIndex = hash;
        while (elements[currentIndex] != ""){
            currentIndex++;
        }
        elements[currentIndex] = key;
    }
    
    // increment size
    size_++;

    // if load factor has exceeded max load, resize!
    if (float(size_)/float(bucket_size_) > max_load){
        // rather than just doubling the size of the vector,
        // we double it, then look for the next prime shortly after that. 
        bucket_size_ *= 2;
        bucket_size_ = nextPrime(bucket_size_);
        elements.resize(bucket_size_);
    }
}

bool MySet::exists(std::string key) const{
    int hash = myHash(key, bucket_size_);
    if (elements[hash] == "") {
        return false;
    }
    else if (elements[hash] == key){
        return true;
    }
    else {
        int currentIndex = hash;
        while (elements[currentIndex] != ""){
            if (elements[currentIndex] == key){
                return true;
            }
            currentIndex++;
        }
        return false;
    }
}

size_t MySet::size() const{
    return size_;
}


std::string genRandomString(){
    // randomly generates a string w/
    // between 1 and 10 characters.

    // rand() % 11 returns a number in the range [0,9]
    // so we add 1 to get a number in the range [1,10]
    

    std::string alphabet[26] = {"a","b","c","d","e","f","g","h",
    "i","j","k","l","m","n","o","p","q","r","s","t","u","v","w",
    "x","y","z",};

    std::random_device rd;
    int n = (rd() % 9)+1;

    // build the string one character at a time
    std::string s;
    for (int index = 0; index < n; index++){
        s += alphabet[(rd()%26)];
    }

    return s;
}


int myHash(std::string key, int bucketSize){
    // Given a key, and a bucket size, we compute a basic hash function.
    // Specifically, we look at the underlying bytes associated with
    // each character in the string. Then, we reinterpret those bytes as integers,
    // and do some arithmetic on them. 
    // Note that this function is O(n), where n is the length of the string.
    // But we're just going to assume the strings we're using are short, in which
    // case this is close enough to a constant time hash function. 

    // for mathematical reasons, it's good to use this R variable.
    // it just needs to be a small, prime, integer.
    int R = 13;


    std::byte bytes[key.length()];

    // std::memcpy just copies the bytes associated w/ each character in the string into the "bytes" array
    std::memcpy(bytes, key.data(), key.length());

    int hash = 0;
    for (int index = 0; index < key.length(); index++){
        // std::cout << "hash:" << hash << "\n";
        hash = ((R * hash) + int(pow(int(bytes[index]),2))) % bucketSize;
    }
    return hash;
}


int main(){

    // std::random_device rd;
    // std::cout << rd() << std::endl;
 
 
    std::string test = genRandomString();
    std::cout << test << std::endl;
 
 
 
    // std::string s;
    // std::cout << "Please input a string to be hashed:";
    // std::cin >> s;
    // int ans = myHash(s, 8191);

    // std::cout << "Your string hashed to:" << ans << std::endl;

    
    return 0;
}