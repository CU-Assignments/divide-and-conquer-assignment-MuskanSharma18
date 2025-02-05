class Solution {
public:
string longestNiceSubstring(string s) {
    int n = s.length();
    string longest = "";
    for (int i = 0; i < n; i++) {
        unordered_set<char> seen;
        for (int j = i; j < n; j++) {
            seen.insert(s[j]);
            bool isNice = true;
            for (char c : seen) {
                if (seen.find(tolower(c)) == seen.end() || seen.find(toupper(c)) == seen.end()) {
                    isNice = false;
                    break;
                }
            }
            if (isNice && j - i + 1 > longest.length()) {
                longest = s.substr(i, j - i + 1);
            }
        }
    }
    return longest;
}
};
