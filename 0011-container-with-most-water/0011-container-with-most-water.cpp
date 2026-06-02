class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int answer = 0;

        while (s < e)
        {
            answer = max(answer, (e - s) * min(height[s], height[e]));
            height[s] < height[e] ? ++s : --e;
        }

        return answer;
    }
};