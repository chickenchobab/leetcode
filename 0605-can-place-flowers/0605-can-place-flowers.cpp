class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if (n == 0)
        {
            return true;
        }

        int s = flowerbed.size();
        if (s == 1)
        {
            return flowerbed[0] + n <= 1;
        }
        
        if (!flowerbed[0] && !flowerbed[1])
        {
            --n;
            flowerbed[0] = 1;
        }

        for (int i = 1; i < s - 1 && n; ++i)
        {
            if (flowerbed[i]) continue;

            if(!flowerbed[i - 1] && !flowerbed[i + 1])
            {
                --n;
                flowerbed[i] = 1;
                ++i;
            }
        }

        if (n && !flowerbed[s - 2] && !flowerbed[s - 1])
        {
            --n;
        }

        return n == 0;
    }
};