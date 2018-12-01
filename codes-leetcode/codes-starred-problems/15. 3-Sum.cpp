class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // get only uniques
        set<vector<int>> ans_set;
        sort(nums.begin(),nums.end());  
        
        for(int i=0;i<nums.size();i++) { 
            int l, r; 
            l = i + 1; 
            r = nums.size() - 1;

            while(l<r) { 
                if (nums[i]+nums[l]+nums[r] == 0) { 
                    ans_set.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                } 
                else if (nums[i]+nums[l]+nums[r] < 0) 
                    l++; 
                else  
                    r--; 
            } 
        }
        
        for (auto v : ans_set)
            ans.push_back(v);
        
        return ans;
    }
};