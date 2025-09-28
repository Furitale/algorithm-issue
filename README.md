# algorithm-issue

## Solution Approach

We use the sliding window technique with two pointers (`left` and `right`) to maintain a window in string `s`. The algorithm works as follows:

1. **Count Characters in t:**
	- Use a hash map to count the frequency of each character in `t`.

2. **Expand the Window:**
	- Move the `right` pointer to expand the window, adding characters from `s` to another hash map that tracks the window's character counts.
	- When a character's count in the window matches the required count in `t`, increment a `formed` counter.

3. **Contract the Window:**
	- When all required characters are present in the window (`formed == required`), move the `left` pointer to shrink the window as much as possible while still containing all characters from `t`.
	- Update the minimum window size and starting index whenever a smaller valid window is found.

4. **Result:**
	- After traversing `s`, return the substring with the minimum length that contains all characters from `t`. If no such substring exists, return an empty string.

This approach ensures an efficient O(m + n) time complexity, suitable for large input sizes.