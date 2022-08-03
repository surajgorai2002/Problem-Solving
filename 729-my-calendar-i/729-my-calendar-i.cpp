class MyCalendar {
public:
    vector<pair<int, int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int n =v.size();
        bool ans=1;
        if(n==0)
        {
            v.push_back({start,end});
            return true ;
        }
        for(int i=0;i<n ; i++)
        {
            int start1=v[i].first;
            int end1=v[i].second;
          
                
            if ((start<start1 && end<=start1)||(start>=end1&& end>end1))
            {
             ans =ans && 1;
               
            }
            else
                ans=ans && 0;
        }
        if(ans==1)
        {
            v.push_back({start,end});
        }
                return ans ;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */