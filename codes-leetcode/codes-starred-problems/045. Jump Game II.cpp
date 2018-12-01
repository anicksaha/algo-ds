class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps[n];
        
        if (n == 0) 
            return 0; 
  
        jumps[0] = 0; 
        
        for (int i=1;i<n; i++) {    
            jumps[i] = INT_MAX; 
            for (int j=0;j<i;j++) { 
                if (i<=j+nums[j] && jumps[j]!=INT_MAX) { 
                    jumps[i] = min(jumps[i], jumps[j] + 1); 
                    break; 
                } 
            } 
        } 
        return jumps[n-1]; 
    }
};