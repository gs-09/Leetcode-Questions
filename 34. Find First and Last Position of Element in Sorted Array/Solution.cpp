class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos;
        int start = 0, end = nums.size()-1, res = -1;
        while( start < nums.size() && end >= 0 && start <= end ){
            int mid = start + ( end - start )/2;
            if( nums[mid] == target ){
                res = mid;
                end = mid - 1;
            }
            else if( nums[mid] > target )
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        if( res == -1 ){
            pos.emplace_back(-1);
            pos.emplace_back(-1);
        }
        else {
            pos.emplace_back(res);
            res = -1, start = 0, end = nums.size();
            while( start < nums.size() && end >= 0 && start <= end ){
            int mid = start + ( end - start )/2;
            if( nums[mid] == target ){
                res = mid;
                start = mid + 1;
            }
            else if( nums[mid] > target )
                end = mid - 1;
            else
                start = mid + 1;
            }
            pos.emplace_back(res);
        }
        return pos;
    }
};
