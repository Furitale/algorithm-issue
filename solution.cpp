// Minimum Window Substring Solution
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    unordered_map<char, int> t_count, window_count;
    for (char c : t) t_count[c]++;
    int required = t_count.size();
    int formed = 0;
    int l = 0, r = 0;
    int min_len = INT_MAX, min_l = 0;
    while (r < s.size()) {
        char c = s[r];
        window_count[c]++;
        if (t_count.count(c) && window_count[c] == t_count[c]) formed++;
        while (l <= r && formed == required) {
            if (r - l + 1 < min_len) {
                min_len = r - l + 1;
                min_l = l;
            }
            char left_char = s[l];
            window_count[left_char]--;
            if (t_count.count(left_char) && window_count[left_char] < t_count[left_char]) formed--;
            l++;
        }
        r++;
    }
    return min_len == INT_MAX ? "" : s.substr(min_l, min_len);
}

// Example usage
int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    string result = minWindow(s, t);
    printf("%s\n", result.c_str()); // Output: BANC
}

