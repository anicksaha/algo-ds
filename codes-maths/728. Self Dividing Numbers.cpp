class Solution {
public:
    
    bool isSelfDividing(int n) {
        int N = n;
        while(n) {
            int dig = n%10;
            if(dig == 0 || N%dig!=0)
                return false;
            n/=10;
        }
        return true;
    }   
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) 
                ans.push_back(i);
        }
        return ans;
    }
};