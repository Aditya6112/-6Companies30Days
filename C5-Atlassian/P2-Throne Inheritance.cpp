// Link: https://leetcode.com/problems/throne-inheritance/description/
class ThroneInheritance {
public:
    unordered_map<string,vector<string>> child;
    unordered_map<string,bool> visited;
    string king;
    ThroneInheritance(string kingName) {
        king=kingName;
    }
    
    void birth(string parentName, string childName) {
        child[parentName].push_back(childName);
    }
    
    void death(string name) {
        visited[name]=true;
    }
    
    void dfs(vector<string>& ans,string parent){
        if(!visited[parent])ans.push_back(parent);
        for(auto c : child[parent]){
            dfs(ans,c);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string>ans;
        dfs(ans,king);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */