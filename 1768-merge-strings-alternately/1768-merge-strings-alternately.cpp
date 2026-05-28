class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int mn = min(word1.size(), word2.size());
        string output;
        output.resize(word1.size() + word2.size());

        for (int i = 0; i < mn; ++i)
        {
            output[i * 2] = word1[i];
            output[i * 2 + 1] = word2[i];
        }

        const string& longer = (mn == word1.size() ? word2 : word1);

        for (int i = 2 * mn, j = mn; j < longer.size(); ++i, ++j)
        {
            output[i] = longer[j];
        }

        return output;
    }
};