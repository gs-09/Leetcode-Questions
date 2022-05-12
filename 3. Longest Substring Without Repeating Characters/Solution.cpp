class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i= 0, j = 0, mx = INT_MIN;
        map<char, int> mp;
        int s_size = s.length();
        while( j < s_size ){
            
            if( mp.find(s[j]) != mp.end() )
                mp[s[j]]++;
            else
                mp[s[j]] = 1;
            
            if( mp.size() == j-i+1 ){
                if( j-i+1 > mx )
                    mx = j-i+1;
                j++;
            }
            
            else if( mp.size() < j-i+1 ){
                while( mp.size() < j-i+1 ){
                    mp[s[i]]--;
                    if( mp[s[i]] == 0 )
                        mp.erase(s[i]);
                    i++;
                }
                if( j-i+1 > mx )
                    mx = j-i+1;
                j++;
            }
        }
        if( mx == INT_MIN )
            return 0;
        return mx;
    }
};
