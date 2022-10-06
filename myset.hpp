/**
 * mySet.hpp
 * A set class implemented with my very own hash function!
 */

#ifndef MYSET_HPP_INCLUDED
#define MYSET_HPP_INCLUDED

#include <string>

class myset {
    private:
        class Iterator;
    public:
        MySet();
        ~MySet();
        void insert(std::string key, int value);
        bool exists(std::string key) const;
        int size() const;

        // const keyword after function declaration
        // denotes that calling the function 
        bool operator==(const mySet rhs) const;
        bool operator!=() const;


        using iterator = Iterator;        
        iterator begin() const; // returns iterator at first non-empty spot in corresponding array
        iterator end() const; // returns invalid/past the end of the tree iterator
    
    private: 
}