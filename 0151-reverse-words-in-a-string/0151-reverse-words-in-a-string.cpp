class Solution {
public:
    string reverseWords(string s) {
        vector<pair<int, int>> words;
        words.reserve(s.size());

        int offset = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                if (offset)
                {
                    words.push_back({i - offset, offset});
                    offset = 0;
                }
            }
            else
            {
                ++offset;
            }
        }

        if (offset)
        {
            words.push_back({s.size() - offset, offset});
        }

        string output = "";
        output.reserve(s.size());
        for (auto it = rbegin(words); it != rend(words); ++it)
        {
            auto [idx, len] = *it;
            output.append(s.substr(idx, len) + " ");
        }
        output.pop_back();

        return output;
    }
};