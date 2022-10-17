# Fun_Stuff

This is a set of small projects I've worked on, and may still be working on!

They are all too small to get their own repository, so here they are. 

So far, we have the following:

1. My very own implementation of a hash set data structure! 
    * add an element: O(1)
    * check if an element is in the set: O(1)
    * remove an element from the set: O(1)
    This hash set uses open addressing, and maintains a vector of elements that it resizes to 
    an appropriate prime number when necessary. 
    Furthermore, I implemented the hash function for this data structure! 
    The hash function isn't quite perfect, but it works pretty well. 
    The elements stored in the hashset are strings. 


2. A file primes.cpp with functions for:
    * Determining whether an integer is prime.
    * Generating a list of all the primes up until some number *n*. 
    * Given a prime, determining the first prime after it.

    Note that this project is *also* useful for the above hash set 
    project, because it's good to keep the array size in a hash map a prime number! 