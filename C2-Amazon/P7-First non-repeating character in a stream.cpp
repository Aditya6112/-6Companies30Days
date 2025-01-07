// Link: https://leetcode.com/problems/first-unique-character-in-a-string/
class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size()==1)return 0;
        unordered_set<char>st;
        for(int i=0;i<s.size()-1;i++){
            char ch=s[i];
            for(int j=i+1;j<s.size();j++){
                if(ch==s[j]){
                    st.insert(ch);
                    break;
                }else if(st.count(ch)==0){
                    if(j==s.size()-1){
                        return i;
                    }
                }
            }
        }
        if(st.count(s[s.size()-1])==0)return s.size()-1;
        return -1;
    }
};