/*
Problem: 3614. Process String with Special Operations II
Difficulty: HARD

Approach:
Step 1: Forward Pass — Compute Final Length
We simulate how the string length changes:

Normal character (a-z)

adds one character → len++
'*'

deletes last character (if exists)
→ len = max(0, len - 1)
'#'

duplicates string
→ len *= 2
'%'

no change in length
Why this works?
We don’t need actual string content yet — only how big it becomes.

Think of it like tracking “capacity growth” instead of building the container.

Step 2: Boundary Check
After forward pass:

if k >= len → return '.'
Because index k does not exist in final string.

Step 3: Backward Pass — Reverse Simulation
Now we move from right to left and undo operations.

We maintain:

len = current simulated length
k = target index we are tracking backward
Case 1: Normal Character
If current character is not special:

It contributes one position at the end of current string.
So:
if k == len - 1 → return character
else len--
👉 We are basically saying:
“If this was the last character in this version, we found our answer.”

Case 2: '*' (Deletion)
Forward: removes last character
Backward: restores length

len++
👉 We are undoing the deletion.

Case 3: '#' (Doubling)
Forward:

S → S + S
Backward:
We map index back to original half:

half = len / 2
If k >= half → it came from second half:

k -= half
Then:

len /= 2
Case 4: '%' (Reverse)
Forward:

reverse string
Backward:
We reverse index mapping:

k = len - 1 - k
👉 This flips position inside current length.


Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 17-06-2026
*/



class Solution {
    typedef long long ll;
public:
    char processStr(string s, ll k) {
        int n = s.size();
        ll len = 0;

        for (auto& ch : s) {
            if (ch == '*')
                len = max(len - 1, 0LL);
            else if (ch == '#')
                len *= 2;
            else if (ch != '%')
                len++;
        }

        if (k >= len) return '.';

        for (int i = n - 1;; i--) {
            switch (s[i]) {
            case '*':
                len++;
                break;
            case '#':
                if (k >= len / 2)
                    k -= len / 2;
                len /= 2;
                break;
            case '%':
                k = len - 1 - k;
                break;
            default:
                if (len == k + 1)
                    return s[i];
                len--;
            }
        }
    }
};
