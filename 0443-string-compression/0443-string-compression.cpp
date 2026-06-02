class Solution {
public:
    int compress(vector<char>& chars) {
        int s = chars.size();

        vector<char> output;
        int num = 1;
        for (int i = 1; i < s; ++i)
        {
            if (chars[i] == chars[i - 1])
            {
                ++num;
            }
            else
            {
                output.push_back(chars[i - 1]);
                if (num != 1)
                {
                    string numstr = to_string(num);
                    for (char c : numstr)
                    {
                        output.push_back(c);
                    }
                }
                num = 1;
            }
        }

        output.push_back(chars.back());
        if (num != 1)
        {
            string numstr = to_string(num);
            for (char c : numstr)
            {
                output.push_back(c);
            }
        }

        chars = output;

        return chars.size();
    }
};