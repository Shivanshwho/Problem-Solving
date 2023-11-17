struct TrieNode{
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isEnd=false;
    }
};


class Trie {
public:
    TrieNode* head;
    Trie() {
        head = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* temp=head;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]-'a']==NULL)
            {
                 temp->children[word[i]-'a']= new TrieNode();
            }
            temp= temp->children[word[i]-'a'];
        }
        temp->isEnd= true;
    }
    
    bool search(string word) {
        TrieNode* temp=head;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]-'a']==NULL)
            {
                return false;
            }
           temp=temp->children[word[i]-'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string word) {
         TrieNode* temp=head;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]-'a']==NULL)
            {
                return false;
            }
           temp=temp->children[word[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */