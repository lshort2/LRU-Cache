//Luke Short
//FotP: At birth a human has 350 bones, but only 206
//  bones when fully grown.



//Simple LRU (Least Recently Used) cache in C++
#include"lru.h"

/**
 * @brief get Data fxn - acquire the data stored @ specified key.
 *
 * @param key:int Register / Location that we'd like to know the contents of.
 *
 * @return If key in cache, returns corresponding string, o/w returns "%INVALID%"
 */
string LRUCache::readData(const int& key)
{
    auto it = hashy.find(key);

    if(it != hashy.end())//Case for when it is in the cache
    {
        std::cout<< "Cache hit!" <<it->second->second <<" located @ " <<key <<"\n";
        //string str =it->second;//string which we want
        
        listy.splice(listy.begin(), listy, it->second);//Move accessed element to front of list

        /*auto oldF = listy.begin();//std::iterator pointing to first element of list
        std::swap(oldF, it);
        hashy[key] = oldF;*/

        //return str;
        return it->second->second;
    }
    else
    {  
        std::cout<< "Cache miss.\n";
        return "%INVALID%";
    }
}

/**
 * @brief Write data to location specified by key.
 *
 * @param key:int Register / location whose contents are being modified.
 * @param val:string Data being place at location specified by key.
 */
void LRUCache::writeData(const int& key, string val)
{
    auto it = hashy.find(key);

    if(it != hashy.end())//Case for when it is in the cache
    {
        std::cout<< "Cache hit for writing " <<val <<" to " <<key <<'\n';
        listy.splice(listy.begin(), listy, it->second);//Move accessed element to front of list
        it->second->second = val;//Set value in the DLL
    }
    else if(listy.size() < m_cacheSize)//Case for when DLL is not yet as big as m_cacheSize
    {
        listy.push_front(std::make_pair(key, val));
        hashy[key] = listy.begin();
    }
    else//Cache is full... must evict LRU block
    {
        listy.push_front(std::make_pair(key, val));
        hashy[key] = listy.begin();

        auto endIt = listy.end();
        endIt--;                  //now it actuall points at last element
        hashy.erase(endIt->first);//remove from hash table
        listy.pop_back();          //remove from DLL


    }
}

/**
 * @brief Print cache fxn - prints all of contents located in LRU cache.
 */
void LRUCache::printCacheData()
{
    for(std::pair<int,string> elem : listy)//Credit for for loop kung fu goes to: http://en.cppreference.com/w/cpp/container/list
    {
        std::cout<< '[' <<std::setw(10) <<elem.second <<"] ";
    }
    std::cout<< std::endl;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Good 'ol int main()  /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    LRUCache cashy;//Create LRU Cache object of default size
    cashy.printCacheData();
    cashy.writeData(1, "bob");
    cashy.writeData(2, "Luke");
    cashy.writeData(3, "Master Poe");
    cashy.printCacheData();
    cashy.readData(2);
    cashy.printCacheData();
    cashy.writeData(1, "red");
    cashy.writeData(2, "orange");
    cashy.writeData(3, "yelllow");
    cashy.writeData(4, "green");
    cashy.writeData(5, "blue");
    cashy.writeData(6, "indigo");
    cashy.writeData(7, "violet");
    cashy.printCacheData();
    cashy.writeData(4, "beige");
    cashy.readData(5);
    cashy.printCacheData();
    cashy.readData(42);
    

    return 0;
}


