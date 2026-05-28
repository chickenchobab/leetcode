class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> output(candies.size(), 0);

        int greatest = *max_element(begin(candies), end(candies));
        for (int i = 0; i < candies.size(); ++i)
        {
            output[i] = greatest - candies[i] <= extraCandies;
        }

        return output;
    }
};