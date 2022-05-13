class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, res = -1;
        int nums_size = nums.size();
        while( start <= end ){
            int mid = start + ( end - start )/2;
            int next = ( mid + 1 ) % nums_size;
            int prev = ( mid + nums_size - 1 ) % nums_size;
            if( ( nums[mid] <= nums[next] ) && ( nums[mid] <= nums[prev] ) ){
                res = mid;
                break;
            }
            else if( nums[mid] <= nums[end] )
                end = mid - 1;
            else if( nums[start] <= nums[mid] )
                start = mid + 1;
        }
        int split_1 = bin_srch( nums, 0, res - 1, target);
        int split_2 = bin_srch( nums, res, nums_size - 1, target);
        
        return split_1 < 0 ? (split_2 < 0 ? -1: split_2) : split_1 ;
    }
    
    int bin_srch( vector<int>& arr, int start, int end, int target ){
        int res = -1;
        while( start <= end ){
            int mid = start + ( end - start)/2;
            if( arr[mid] == target )
            {
                res = mid;
                break;
            }
            
            if( arr[mid] <= target )
                start = mid + 1;
            else
                end = mid - 1;
        }
        return res;
    }
};
