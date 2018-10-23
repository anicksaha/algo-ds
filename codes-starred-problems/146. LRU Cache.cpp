#include<bits/stdc++.h> 
using namespace std;

class LRUCache {
public:
    
    list<pair<int,int> > cache; // linked-list for cache 
    map<int, list<pair<int,int> >::iterator> _map;
    int _N;
    
    LRUCache(int capacity) {
        _N = capacity;
    }
    
    int get(int key) {
        if (_map.find(key) != _map.end()){
            list<pair<int,int> >::iterator p = _map[key];
            put(key, p->second);
            return p->second;
        } else {
            return -1;
        }  
    }
    
    void put(int key, int value) {
        if (_map.find(key) == _map.end()) { 
            if (cache.size() == _N) { 
                pair<int,int> last = cache.back(); 
                cache.pop_back(); 
                _map.erase(last.first); 
            }    
        }  
        else {
            cache.erase(_map[key]); 
        }
        
        // update reference 
        cache.push_front(make_pair(key,value)); 
        _map[key] = cache.begin();        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */