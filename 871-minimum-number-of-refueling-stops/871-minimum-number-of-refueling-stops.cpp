class Solution {
public:
    int minRefuelStops(int target, int startfuel, vector<vector<int>>& stations) {
      priority_queue<int> pq;
        int ans=0;
        int j=0;
        int n =stations.size();
        while(startfuel<target)
        {
        while(j<n&& stations[j][0]<=startfuel)
        {

            pq.push(stations[j][1]);
            j++;
        }
        if(pq.size()==0)
            return -1;
        startfuel+=pq.top();
        pq.pop();
        ans++;
    }
        return ans;
        
        
        
    }
};