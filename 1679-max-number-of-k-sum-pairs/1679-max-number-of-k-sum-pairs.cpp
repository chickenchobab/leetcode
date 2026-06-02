class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int ans = 0;

        int s = 0, e = nums.size() - 1;
        while (s < e)
        {
            int sum = nums[s] + nums[e];
            if (sum > k)
            {
                --e;
            }
            else if (sum < k)
            {
                ++s;
            }
            else
            {
                ++ans;
                ++s;
                --e;
            }
        }

        return ans;
    }
};