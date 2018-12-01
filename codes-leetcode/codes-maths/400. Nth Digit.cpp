// https://leetcode.com/problems/nth-digit/description/

typedef long long int ll;

class Solution {
public:
    int findNthDigit(int n) {
        int digits = 1;
        ll interval = digits * 9 * (ll)pow(10,digits-1);
        int number = 1; // track of the range starting number
        
        while(n>interval){
            n-=interval;
            number+=(interval/digits);
            digits++;
            interval = digits * 9 * (ll)pow(10,digits-1);
        }
        
        number+=(n-1)/digits; 
        int idx = n%digits; // nth digit from left 
        if(idx==0) idx+=digits; 
        
        idx = (digits - idx);
        for(int i=0;i<idx;i++) {
            number/= 10;
        }
        return number%10;
    }
};