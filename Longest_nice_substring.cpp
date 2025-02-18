class Solution {
public:
    // Helper function to check if a substring is nice
    bool isNice(const string& sub) {
        unordered_set<char> seen;
        for (char c : sub) {
            seen.insert(c);
        }
        for (char c : seen) {
            if (isalpha(c) && (seen.find(toupper(c)) == seen.end() || seen.find(tolower(c)) == seen.end())) {
                return false;
            }
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        int n = s.size();
        string result = "";
        
        // Try all possible substrings
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                string sub = s.substr(i, j - i);
                if (isNice(sub) && sub.size() > result.size()) {
                    result = sub;
                }
            }
        }
        
        return result;
    }
};
