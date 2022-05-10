class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> mx_subarray;
        int i = 0, j = 0;
        int sz = nums.size();
        deque<int> q;
        while( j < sz ){
            if( q.empty() )
                q.push_back(nums[j]);
            else if( nums[j] > q.front() ){
                while( !q.empty() ){
                    q.pop_back();
                }
                q.push_back(nums[j]);
            }
            else if( nums[j] <= q.front() ){
                while( q.back() < nums[j] )
                    q.pop_back();
                q.push_back(nums[j]);
            } 
            
            if( j-i+1 < k )
                j++;
            
            else if( j-i+1 == k ){
                mx_subarray.push_back(q.front());
                if( nums[i] == q.front() )
                    q.pop_front();
                i++;
                j++;
            }
        }
        return mx_subarray;
    }
};
