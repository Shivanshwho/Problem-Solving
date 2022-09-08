  struct Trie_node{
        Trie_node* child[26];
        bool is_end;
        Trie_node()
        {
            for(int i=0;i<26;i++)
            {
                child[i]=NULL;
                is_end=false;
            }
        }
    };

class Trie {
public:
  
      Trie_node* head;  
            Trie()
            {
                head= new Trie_node();
            }
      
    
    
    void insert(string word) {
        Trie_node* temp= head;
        for(int i=0;i<word.size();i++)
        {
            if(temp->child[word[i]-'a']==NULL)
            {
                temp->child[word[i]-'a']=new Trie_node();
                
            }
            temp =temp->child[word[i]-'a'];
        }
        temp->is_end=true;
    }
    
    bool search(string word) {
        Trie_node* temp=head;
        for(int i=0;i<word.length();i++)
        {
            if(temp->child[word[i]-'a']==NULL)
            {
                return false;
            }
            temp=temp->child[word[i]-'a'];
        }
        if(temp->is_end)
        {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
         Trie_node* temp=head;
        for(int i=0;i<prefix.length();i++)
        {
            if(temp->child[prefix[i]-'a']==NULL)
            {
                return false;
            }
            temp=temp->child[prefix[i]-'a'];
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