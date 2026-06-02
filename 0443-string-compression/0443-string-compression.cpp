class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        int i = 0;
        while (i < chars.size())
        {
            int group_size = 1;
            while (i + group_size < chars.size() && chars[i + group_size] == chars[i])
            {
                ++group_size;
            }

            chars[res++] = chars[i];

            if (group_size > 1)
            {
                string str = to_string(group_size);
                for (char c : str)
                {
                    chars[res++] = c;
                }
            }

            i += group_size;
        }

        return res;
    }
};