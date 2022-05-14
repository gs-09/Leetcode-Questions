class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int nums_size = nums.size();
        while( start < end ){
            int mid = start + ( end - start )/2;
            if( nums[mid] == nums[end] )
                end--;
            else if( nums[mid] > nums[end] )
                start = mid + 1;
            else
                end = mid;
        }
        return nums[end];
    }
};
