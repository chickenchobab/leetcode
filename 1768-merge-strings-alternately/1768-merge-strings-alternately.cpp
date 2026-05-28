class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int a = word1.size();
        int b = word2.size();
        int mn = min(a, b);
        int mx = max(a, b);

        string output;
        output.resize(a + b);

        for (int i = 0; i < mn; ++i)
        {
            output[i * 2] = word1[i];
            output[i * 2 + 1] = word2[i];
        }

        const string& longer = (a < b ? word2 : word1);

        for (int i = 2 * mn, j = mn; j < mx; ++i, ++j)
        {
            output[i] = longer[j];
        }

        return output;
    }
};