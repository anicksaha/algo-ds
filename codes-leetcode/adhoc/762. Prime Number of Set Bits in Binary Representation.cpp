class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int _primes[]= {2,3,5,7,11,13,17,19,23,29,31,37};
        set<int> primes (_primes,_primes+12);
        
        int ans = 0;
        
        for(int i=L;i<=R;i++) {
            if(primes.find(__builtin_popcount(i))!=primes.end())
                ans++;
        }
        
        return ans;
    }
};