class Solution {
public:
    bool IsVowel(char c)
    {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
    string reverseVowels(string s) {
        vector<char> vowels;
        int l = s.length();
        vowels.reserve(l);

        for (char c : s)
        {
            if (IsVowel(c))
            {
                vowels.push_back(c);
            }
        }

        string output;
        output.resize(l);

        int v = vowels.size() - 1;
        for (int i = 0; i < l; ++i)
        {
            if (IsVowel(s[i]))
            {
                output[i] = vowels[v--];
            }
            else
            {
                output[i] = s[i];
            }
        }

        return output;
    }
};