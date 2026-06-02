class Solution {
public:
    bool isSubsequence(string s, string t) {

        int s_s = s.size();
        int t_s = t.size();
        if (s_s > t_s)
        {
            return false;
        }

        int num = 0;
        for (int i = 0, j = 0; i < s_s && j < t_s && num < s_s; ++i)
        {
            while (j < t_s && s[i] != t[j]) ++j;
            
            if (j < t_s)
            {
                ++num;
                ++j;
            }
        }

        return num == s_s;
    }
};