#LRU (Least Recently Used Cache)
![Cache diagram]
(http://2.bp.blogspot.com/-d4lLgfO1Hes/UXPj9nY5CLI/AAAAAAAAJTU/_5iO5TbMd7k/s1600/bonappetit_lrucache01.png)

*Diagram courtesy of http://2.bp.blogspot.com/-d4lLgfO1Hes/UXPj9nY5CLI/AAAAAAAAJTU/_5iO5TbMd7k/s1600/bonappetit_lrucache01.png*

Keys are used to specify the data elements to be accessed. Each of which have a string value (val).
This C++ class is created using a hash table (''std::unordered_map'') and doubly linked list (''std::list'')
Using both of these data structures ensures all accesses are performed in ϴ(1) time.

Saw a page about this on the [mcicpc website](http://mcicpc.cs.atu.edu/archives/2012/mcpc2012/lru/lru.html) as well as in the book, Cracking the Code Interview and thought it was a cool idea.

