/*
Problem: 3612. Process String with Special Operations I
Difficulty: Medium

Approach:
We use a StringBuilder (or string in C++) to maintain the current result while traversing the input string from left to right.

For each character:

If it is a lowercase letter, append it to the result.
If it is *, remove the last character if the result is not empty.
If it is #, append the current result to itself, effectively duplicating the string.
If it is %, reverse the current result.
Since we process each character exactly according to the rules given in the problem statement, the final state of our string after the traversal is the required answer.

Time Complexity: O(m)
Space Complexity: O(m)

Date Solved: 16-06-2026
*/


class Solution {
public:
    string processStr(string s) {
        string res;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == '*') {
                if (res.length() != 0) {
                    res.pop_back();
                }
            } 
            else if (ch == '#') {
                res += res;
            } 
            else if (ch == '%') {
                reverse(res.begin(), res.end());
            } 
            else if (ch >= 'a' && ch <= 'z') {
                res.push_back(ch);
            }
        }

        return res;
    }
};


