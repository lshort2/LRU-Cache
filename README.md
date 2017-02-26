#LRU (Least Recently Used Cache)
Saw a page about this on the [mcicpc website](http://mcicpc.cs.atu.edu/archives/2012/mcpc2012/lru/lru.html) as well as in the book, Cracking the Code Interview and thought it was a cool idea.

This implementation uses keys to specify the data elements to be accessed each of which have a string value (val).
Class is created using a hash table std::unordered_map and doubly linked list (std::list)

