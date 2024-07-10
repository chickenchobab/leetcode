class Solution {
public:
    int num = 'Z' - 'A' + 1;
    int cnt['Z' - 'A' + 1] = {0,};

    int findCommonLetter(){
      int ret = 0;
      for (int i = 0; i < num; ++ i){
        if (cnt[ret] < cnt[i]) ret = i;
      }
      return ret;
    }

    int characterReplacement(string s, int k) {
        
        int len = s.length(), start = 0, end = 0, common = 0, ans = 0;

        for (end = 0; end < len; ++ end) {
          cnt[s[end] - 'A'] ++;
          if (cnt[common] <= cnt[s[end] - 'A']){
            common = s[end] - 'A';
          }
          while ((end - start + 1) - cnt[common] > k){
            cnt[s[start] - 'A'] --;
            if (s[start] - 'A' == common) common = findCommonLetter();
            start ++;
          }
          ans = max(ans, end - start + 1);
        }

        return ans;
    }
};