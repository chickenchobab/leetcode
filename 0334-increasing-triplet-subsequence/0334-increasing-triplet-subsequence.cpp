class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        vector<int> backs;
        backs.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i)
        {
            if (backs.back() < nums[i])
            {
                backs.push_back(nums[i]);
                if (backs.size() == 3) return true;
            }
            else
            {
                int pos = lower_bound(begin(backs), end(backs), nums[i]) - begin(backs);
                backs[pos] = nums[i];
            }
        }
        
        return false;
    }
};