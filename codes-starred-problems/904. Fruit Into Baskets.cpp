class Solution {
public:
    int totalFruit(vector<int>& tree) {
        
        if(tree.size()<=2) 
            return tree.size();
        
        int idx = 0;
        int idx2;
        int numTypes = 1;
        pair<int, int> nums; 
        nums.first = tree[0]; 
        nums.second = INT_MIN;
        
        if(tree[0]!=tree[1])nums.second = tree[1];
        int ctr = 2; // total fruits in current window
        int ans = 2;
        
        for(int i=2; i<tree.size(); i++) {
            if(tree[i]==nums.first || tree[i]==nums.second) {
                ctr++;
            } else if(nums.second==INT_MIN){
                nums.second = tree[i];
                ctr++;
            } else {
                idx2 = i-1;
                int latestColor = tree[idx2]; 
                while(tree[idx2]==latestColor) { 
                    idx2--;
                }
                
                ctr = ctr - ((idx2-idx)+1);
                idx = idx2+1;
                if(latestColor==nums.first) { 
                    nums.second = tree[i];
                } else { 
                    nums.first = tree[i];
                }
                ctr++; //for new element   
            }
            
            ans = max(ans, ctr);
        }
        
        return ans;
    }
};