#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        
        if(deck.size()<2)
            return false;
        
        int freq[10000];
        memset(freq, 0, sizeof(freq));
        
        for(int i=0;i<deck.size();i++)
            freq[deck[i]]++;
        
        int c = freq[deck.size()-1];
        bool ans = true;
        
        for(int i=0;i<deck.size();i++)
            c = __gcd(c, freq[deck[i]]);
        
        return c>1;
    }
};