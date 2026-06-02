class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            sums[i] = sums[i - 1] + nums[i];
        }

        int ans = sums[k - 1];
        for (int e = k; e < nums.size(); ++e)
        {
            ans = max(ans, sums[e] - sums[e - k]);
        }  

        return (double)ans / k;
    }
};