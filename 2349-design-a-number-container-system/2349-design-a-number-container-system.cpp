class NumberContainers {
public:
    unordered_map<int,int> mp;
    unordered_map<int,set<int>> mp1;
    NumberContainers() {
        mp.clear();
    }
    
    void change(int index, int number) {
        
        if(mp.find(index)!=mp.end())
        {
            int n =mp[index];
            mp1[n].erase(index);
        }
        mp[index]=number;
        mp1[number].insert(index);
    }
    
    int find(int number) {
       if(mp.size()==0)
           return -1;
        if(mp1[number].size()==0)
            return -1;
       return *mp1[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */