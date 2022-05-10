class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>anagram_ind;
        map<char, int> mp;
        int i = 0, j = 0, cnt = 0;
        int s_size = s.length();
        int p_size = p.length();
        for( int x = 0; x < p_size; x++ ){
            if( mp[p[x]] )
                mp[p[x]]++;
            else
                mp[p[x]] = 1;
        }
        
        cnt = mp.size();
        while( j < s_size ){
            if( mp.find(s[j]) != mp.end() ){
                    mp[s[j]]--;
                if( mp.find(s[j])->second == 0 )
                    cnt--;
            }
            if( j-i+1 < p_size )
                j++;
            else if( j-i+1 == p_size ){
                if( cnt == 0 )
                {
                    anagram_ind.emplace_back(i);
                }
                
                if( mp.find(s[i]) != mp.end() ){
                    if( mp.find(s[i])->second == 0)
                        cnt++;
                    mp[s[i]]++;
                }
                i++;
                j++;
                
            }
        }
        return anagram_ind;
    }
};
