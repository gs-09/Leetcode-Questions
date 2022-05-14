class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, res;
        int nums_size = nums.size();
        while( start <= end ){
            int mid = start + ( end - start )/2;
            int next = ( mid + 1 ) % nums_size;
            int prev = ( mid + nums_size - 1 ) % nums_size;
            if( nums[mid] <= nums[next] && nums[mid] <= nums[prev] )
            {
                res = nums[mid];
                break;   
            }
            if( nums[mid] <= nums[end] )
                end = mid - 1;
            else
                start = mid + 1;
        }
        return res;
    }
};
