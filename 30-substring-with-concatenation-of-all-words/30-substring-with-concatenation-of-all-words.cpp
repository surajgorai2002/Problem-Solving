class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         map<string, int> m ;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
       
        vector<int>ans;
        int w=words[0].size();
        int n=words.size(); 
        if(s.size()<n*w)
            return ans;
        for(int i=0;i<=s.size()-n*w;i++)
        {
            string w1 = s.substr(i,w);
            
            if(m.find(w1)!=m.end() && m[w1]>0)
            {  
                map<string,int> m1=m;
                int count=m1.size();
               
                m1[w1]--;
                if(m1[w1]==0)
                  count--;     
                for(int j=i+w;j<=s.size()-w;j+=w)
                {
                    string k=s.substr(j,w);
                    if(m1.find(k)!=m1.end()&& m1[k]>0)
                    {
                        m1[k]--;
                        if(m1[k]==0)
                        count--;   
                    }
                    else
                        break;
                }
                if(count==0)
                    ans.push_back(i);
               
            }
           
        }
        return ans ;
    }
};