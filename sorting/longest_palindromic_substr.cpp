class Solution {
public:
    bool is_palindrome(string s){
        int i = 0;
        int j = s.size() - 1;
        
        while (j > i){
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        string ans = "";
        int i = 0;
        int curr_len = std::min(1, (int)s.size());
        int max_len = curr_len;
        while (max_len + 2 >= curr_len && curr_len <= s.size()){
            if (i + curr_len > s.size()){
                i = 0;
                curr_len++;
                continue;
            }
            if (is_palindrome(s.substr(i, curr_len))){
                max_len = curr_len;
                ans = s.substr(i, curr_len);
                i = 0;
                curr_len++;
                continue;
            }
            i++;
        }
        return ans;
    }
};
