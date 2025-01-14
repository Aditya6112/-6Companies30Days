// Link: https://leetcode.com/problems/friends-of-appropriate-ages/

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> ageCount(121, 0);
        for (int age : ages) {
            ageCount[age]++;
        }
        
        int requests = 0;
        for (int ageA = 1; ageA <= 120; ++ageA) {
            if (ageCount[ageA] == 0) continue;
            
            for (int ageB = 1; ageB <= 120; ++ageB) {
                if (ageCount[ageB] == 0) continue;
                
                // Check the conditions for a valid friend request
                if (ageB <= 0.5 * ageA + 7 || ageB > ageA) continue;
                
                // Add the valid requests
                requests += ageCount[ageA] * ageCount[ageB];
                
                // Exclude self-friend requests
                if (ageA == ageB) {
                    requests -= ageCount[ageA];
                }
            }
        }
        
        return requests;
    }
};
