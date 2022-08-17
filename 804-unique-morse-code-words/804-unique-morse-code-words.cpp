class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
          vector<string> v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        
        unordered_map<string,int> res;
        for(int i=0;i<words.size();i++)
        {
            string s="";
            for(int j=0;j<words[i].size();j++)
            {
                s+=v[words[i][j]-'a'];
            }
            res[s]++;
        }
        return res.size();
    }
};