#ifndef LRU_H
#define LRU_H

#define LRU_CACHE_SIZE 6

#include<map>
#include<list>
#include<iostream>
#include<iomanip>//needed for std::setw

using std::string;//Because writing out std::string every time gets tiring

class LRUCache {
    public:
        LRUCache() : m_cacheSize(LRU_CACHE_SIZE){};  //ctor w/ 0 args
        LRUCache(unsigned int size) : m_cacheSize(size){};    //ctor w/ 1 arg
        //~LRUCache();
        string readData(const int& key);                    //READ data stored in [key]
        void writeData(const int& key, string val);         //WRITE data (val) to [key]
        void printCacheData();
    private:
        unsigned int m_cacheSize;
        //std::list<string>     listy;                 //Doubly linked list to hold [m_cacheSize] elements
        std::list<std::pair<int, string>>     listy; //Doubly linked list to hold [m_cacheSize] elements
        std::map<int, decltype(listy.begin())> hashy;//Maps key vals to iters that point to DLL elements
};

#endif
