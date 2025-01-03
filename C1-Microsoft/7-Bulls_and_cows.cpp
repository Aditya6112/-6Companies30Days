// Link: https://leetcode.com/problems/bulls-and-cows/
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        int cows=0;
        vector<int>secretCnt(10,0);
        vector<int>guessCnt(10,0);
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }else{
                secretCnt[secret[i]-'0']++;
                guessCnt[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            cows+=min(secretCnt[i],guessCnt[i]);
        }
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};