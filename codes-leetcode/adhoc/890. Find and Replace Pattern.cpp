// https://leetcode.com/problems/find-and-replace-pattern/description/

class Solution {
public:
    
    bool match(string word, string pattern) {
        map<char,char> m1; // A to B
        map<char,char> m2; // B to A
        
        if(word.length()!=pattern.length()) {
            return false;
        }
        
        int len = word.length();
        
        for(int i=0;i<len;i++) {
            char w = word[i];
            char p = pattern[i];
            
            if(m1.find(w) == m1.end()) { m1[w]=p; }
            if(m2.find(p) == m2.end()) { m2[p]=w; }
            
            if(m1[w]!=p || m2[p]!=w) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(int i=0;i<words.size();i++) {
            if(match(words[i],pattern)) {
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};