/**
 * mySet.hpp
 * A set class implemented with my very own hash function!
 */

#ifndef MYSET_HPP_INCLUDED
#define MYSET_HPP_INCLUDED

#include <string>

class MySet {
    private:
        class Iterator;
    public:
        MySet();
        ~MySet();
        void insert(std::string key);
        bool exists(std::string key) const;
        int size() const;

        // const keyword after function declaration
        // denotes that calling the function 
        bool operator==(const MySet rhs) const;
        bool operator!=(const MySet rhs) const;

        // i think this line enables us to use the 
        // standard c++ iterator syntax with MySet
        using iterator = Iterator;        
        iterator begin() const; // returns iterator at first non-empty spot in corresponding array
        iterator end() const; // returns invalid/past the end of the tree iterator

        std::ostream& print(std::ostream& stream) const;
        std::ostream& showStatistics(std::ostream& stream) const;

    private: 
        size_t size;
        

};

#endif  // MYSET_HPP_INCLUDED
