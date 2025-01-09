// Link: https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while(columnNumber>0){
            columnNumber--;
            res+=(char)((columnNumber)%26 + 'A');
            columnNumber/=26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};