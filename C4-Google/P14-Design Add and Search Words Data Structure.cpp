// Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/
class WordDictionary {
public:
    vector<string>all_words;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        all_words.push_back(word);
    }
    
    bool search(string word) {
        for(auto& all:all_words){
            if(all.size()==word.size()){
                bool match=true;
                for(int i=0;i<all.size();i++){
                    if(word[i]!=all[i] && word[i]!='.'){
                        match=false;
                        break;
                    }
                }
                if(match){
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */