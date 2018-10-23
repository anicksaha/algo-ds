// https://leetcode.com/problems/most-common-word/description/

class Solution {
public:
    bool isChar(char ch) {
        bool isUpper = (ch>=65 && ch<=90);
        bool isLower = (ch>=97 && ch<=122);
        return (isUpper || isLower);
    }
    
    string toLower(string s) {
        string _s= "";
        for(int i=0;i<s.length();i++) {
            _s+=tolower(s[i]);
        }
        return _s;
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int idx = 0,freq = 0;
        string ans,word = "";
        set<string> S(banned.begin(), banned.end());
        map<string,int> M;
        paragraph = toLower(paragraph);
        
        while(idx<paragraph.length()) {
            while(isChar(paragraph[idx]) && idx<paragraph.length()) {
                word+=paragraph[idx++];
            }
            
            // if not a banned word, then consider
            if(S.find(word)==S.end()) {
                M[word]++;
                if(M[word]>freq) {
                    freq = M[word];
                    ans = word;
                }
            }
            word = "";
            while(!isChar(paragraph[idx]) && idx<paragraph.length()) {idx++;}
        }
        
        return ans;
    }
};