// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0;
        int balance = 0;
        for(int i=0;i<S.length();i++) {
            (S[i]=='(') ? balance++ : balance--;
            if(balance==-1) {
                balance = 0;
                ans++;
            }
        }  
        return ans + balance;
    }
};