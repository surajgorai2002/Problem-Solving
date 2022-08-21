class Solution {
public:
    vector<int> output;
    void matching(string& s, string& stamp, int& start) {
        int m = s.size();
        int n = stamp.size();
        int diff = m - n;
        for (int i = start; i <= diff; i++) {
            bool match = true;            
            for (int j = 0; j < n; j++) {
                if (s[i + j] != '?' && s[i+j] != stamp[j]) {                    
                    match = false;
                    break;
                }
            }
            
            if (match) {
                for (int j = 0; j < n; j++) {
                     s[i+j] = '?';
                }
                output.push_back(i);
                if (start == i) {
                    for (int j = i; j <= diff; j++) {
                        if (s[j+n-1] != '?') {
                            start = j;
                            break;
                        }                            
                    }
                }
                break;
            }
        }
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int m = target.size();
        int count = m * 10;
        
        string testPattern = string(m, '?');
        int startIndex = 0;
        for (int i = 0; i < count; i++ ) {
            matching(target, stamp, startIndex);
            if (target == testPattern) {
                std::reverse(output.begin(), output.end());
                return output;
            }
        }
        return vector<int>();
    }
};