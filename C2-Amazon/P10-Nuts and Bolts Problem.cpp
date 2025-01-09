// Link: https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        unordered_map<int,char>order;
        order[0]='!';
        order[1]='#';
        order[2]='$';
        order[3]='%';
        order[4]='&';
        order[5]='*';
        order[6]='?';
        order[7]='@';
        order[8]='^';
        
        vector<int>sorted_nuts;
        vector<int>sorted_bolts;
        
        //convert the nuts and bolts array in a number array so we can sort easily
        for(int i=0;i<n;i++){
            char nut=nuts[i];
            char bolt=bolts[i];
            for(auto o:order){
                if(o.second==nut){
                    sorted_nuts.push_back(o.first);
                }
                if(o.second==bolt){
                    sorted_bolts.push_back(o.first);
                }
            }
        }

        sort(sorted_nuts.begin(),sorted_nuts.end());
        sort(sorted_bolts.begin(),sorted_bolts.end());
        
        for(int i=0;i<n;i++){
            char n=order[sorted_nuts[i]];
            char b=order[sorted_bolts[i]];
            nuts[i]=n;
            bolts[i]=b;
        }
    }
};