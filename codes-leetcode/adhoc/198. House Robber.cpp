class Solution {
public:
    int rob(vector<int>& nums) {
        
        int N = nums.size();
        
        if(N==0) {
            return 0;
        } else if(N==1) {
            return nums[0];
        } else if(N==2) {
            return max(nums[0], nums[1]);
        }
            
        int dp[N];
        
        memset(dp,0,sizeof(dp));
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<N;i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);        
        }
        
        return dp[N-1];
    }
};