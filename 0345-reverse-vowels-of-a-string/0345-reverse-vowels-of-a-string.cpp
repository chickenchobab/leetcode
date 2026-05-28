class Solution {
public:
    bool IsVowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int a = 0, b = s.length() - 1;
        while (a < b)
        {
            while (a < b && !IsVowel(s[a]))
                ++a;
            
            while (a < b && !IsVowel(s[b]))
                --b;

            if (a < b)
            {
                std::swap(s[a], s[b]);
                ++a;
                --b;    
            }
        }

        return s;
    }
};