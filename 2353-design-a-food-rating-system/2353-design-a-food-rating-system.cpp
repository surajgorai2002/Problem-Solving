class FoodRatings {
public:
    // unordered_map<string ,int> mp;
    unordered_map<string , int >mp;
    unordered_map<string , string > mp1;
    unordered_map<string , set<pair<int , string >>> h;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for(int i=0;i<foods.size();i++)
        {
           mp[foods[i]]=ratings[i];
            mp1[foods[i]]=cuisines[i];
            h[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
         int x=mp[food];
        h[mp1[food]].erase({-x,food});
        h[mp1[food]].insert({-newRating,food});
        
        mp[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        // return mp1[*mp[cuisines].begin()];
     pair<int ,string> p=   *h[cuisine].begin();
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */