class Solution {
public:
    
    bool isVowel(char ch) {
        char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};
        set<char> S(vowels, vowels + 10);
        return (S.find(ch)!=S.end());
    }
    
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i<j) {
            while(!isVowel(s[i]) && i<j) {i++; }
            while(!isVowel(s[j]) && i<j) {j--; }
            if(i<j) {
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};