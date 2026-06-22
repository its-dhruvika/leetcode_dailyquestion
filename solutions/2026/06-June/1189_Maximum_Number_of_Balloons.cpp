/*
Problem: 
Difficulty: Easy

Approach:
Forming the word “balloon” requires:

Screenshot 2026-06-22 065638.png

Therefore, we only need to count the occurrences of the characters:

“a”, “b”, “l”, “o”, and “n” in the text string.
Since each “balloon” requires two “l 
′
 s” and two “o 
′
 s”:

To find the possible word “balloon” instances we can form, we divide the counts of “l” and “o” by 2.
Screenshot 2026-06-22 072216.png

Returning the minimum value among the counts of “a”, “b”, “l”, “o”, and “n” will give the maximum number of words that can be formed.

Screenshot 2026-06-22 072254.png


Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 22-06-2026
*/


class Solution {
public:
    int maxNumberOfBalloons(string t) {
        int f[5] = {0};
        string s = "balon";

        for (uint32_t ch : t)
            for (int i = 0; i < 5; i++)
                f[i] += !(ch ^ s[i]);

        return min({f[0], f[1], f[2] >> 1, f[3] >> 1, f[4]});
    }
};
