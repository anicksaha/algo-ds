class Solution {
public:
    
    // Run Length Encoding
    vector<pair<char,int> > _encode(string s) {
        vector<pair<char,int> > ANS;
        int idx = 0, c = 0;
        char curr;
        while(idx<s.length()) {     
            if(curr!=s[idx]) {
                curr = s[idx];
                c = 1;
            }
            while(curr==s[idx]  && idx<s.length()) {
                c++;
                idx++;
            }
            ANS.push_back(make_pair(curr, c));
        }
        return ANS;
    }
    
    bool isLongPressedName(string name, string typed) {
        
        vector<pair<char,int> > _name = _encode(name);
        vector<pair<char,int> > _typed = _encode(typed);
        
        if(_name.size()!=_typed.size()) {
            return false;
        }
        
        for(int i=0;i<_name.size();i++) {
            if(_name[i].first!=_typed[i].first) {
                return false;
            }
            if(_name[i].second>_typed[i].second) {
                return false;
            }
        }
        
        return true;
    }
};