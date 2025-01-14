// Link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string str;
        int slots=1;
        while(getline(ss,str,',')){
            if(slots<=0)return false;
            if(str=="#")slots-=1;
            else slots+=1;
        }
        return slots==0;
    }
};