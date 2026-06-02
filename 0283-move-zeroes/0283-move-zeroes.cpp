class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int s = 0;
        for (int e = 1; e < nums.size(); ++e)
        {
            if (nums[e] == 0) continue;

            while (s < e && nums[s] != 0) ++s;
            if (s < e)
            {
                swap(nums[s], nums[e]);
            }
        }
    }
};