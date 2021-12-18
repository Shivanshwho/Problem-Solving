class ThroneInheritance {
private:
    unordered_map<string,vector<string>>fam;
    unordered_map<string,bool>ded;
    string king;
    void dfs(vector<string>&ans,string par)
    {
        if(ded[par]==false)
        {
            ans.push_back(par);
        }
        for(auto it : fam[par])
        {
            dfs(ans,it);
        }
    }
public:
    ThroneInheritance(string kingName) {
        this->king=kingName;
        ded[kingName]=false;
    }
    
    void birth(string parentName, string childName) {
        fam[parentName].push_back(childName);
        ded[childName]=false;
    }
    
    void death(string name) {
        ded[name]=true;
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