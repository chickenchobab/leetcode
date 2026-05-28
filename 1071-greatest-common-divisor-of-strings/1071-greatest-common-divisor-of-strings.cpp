class Solution {
public:

    bool CheckDivision(const string& a, const string& b)
    {
        int x = a.length();
        if (x == 0) return true;
        int y = b.length();
        if (y % x) return false;

        for (int i = 0; i < y; i += x)
        {
            for (int j = 0; j < x; ++j)
            {
                if (b[i + j] != a[j]) return false;
            }
        }

        return true;
    }

    int GcdOfInts(int a, int b)
    {
        int div = a;
        while (div && (b % div || a % div))
        {
            --div;
        }

        return div;
    }

    string gcdOfStrings(string str1, string str2) {
        string a{str1[0]};
        string b{str2[0]};

        while (!CheckDivision(a, str1))
        {
            a += str1[a.length()];
        }
        while (!CheckDivision(b, str2))
        {
            b += str2[b.length()];
        }

        if (a.length() > b.length())
        {
            std::swap(a, b);
        }

        if (CheckDivision(a, b))
        {
            int gcd = GcdOfInts(str1.length() / b.length(), str2.length() / b.length());
            string output = "";
            while (gcd--)
            {
                output += b;
            }
            return output;
        }

        return string("");
    }
};