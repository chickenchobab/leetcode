class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1, pp = 1;
        int z = 0;
        for (int i : nums)
        {
            p *= i;
            i == 0 ? ++z : pp *= i;
        }

        if (z == 0)
        {
            for (int& i : nums)
            {
                i = p / i;
            }
            return nums;
        }
        else if (z == 1)
        {
            for (int& i : nums)
            {
                if (i == 0) i = pp;
                else i = 0;
            }
            return nums;
        }
        
        return vector<int>(nums.size(), 0);
    }
};