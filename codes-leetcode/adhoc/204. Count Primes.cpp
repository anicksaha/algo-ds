class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) {
            return 0;
        }
        
        bool isPrime[n+1];
        memset(isPrime, true, sizeof(isPrime));
        isPrime[1] = false;
        
        for(int i=2;i*i<=n; i++) {
            if(isPrime[i]) {
                for(int j=2*i; j<=n; j+=i)
                    isPrime[j] = false;
            }
        }
        
        int ans = 0;
        for(int i=1; i<n; i++)
            if(isPrime[i])
                ans++;
        
        return ans;
    }
};