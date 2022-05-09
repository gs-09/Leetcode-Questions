class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = INT_MIN;
        int i = 0, j = 0;
        int sz = nums.size();
        double sm = 0;
        while( j < sz ){
            sm += nums[j];
            if( j-i+1 < k )
                j++;
            else if( j-i+1 == k ){
                double res = sm/k;
                if( res > avg )
                    avg = res;
                sm -=nums[i];
                j++;
                i++;
            }
        }
        return avg;
    }
};
