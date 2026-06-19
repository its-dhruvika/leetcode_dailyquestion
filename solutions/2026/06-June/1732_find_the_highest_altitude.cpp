/*
Problem: 1732. Find the Highest Altitude

Difficulty: EASY

Approach:
Start with:

sum = 0 (current altitude)
ans = 0 (highest altitude so far)
For each value in gain:

Update current altitude: sum += gain[i]
Update maximum altitude using a branchless max technique
Global Max
Let diff = sum - ans

We want to add:

diff if diff > 0
0 otherwise
The sign of diff is extracted using:

(diff >> 31) → 0 if diff >= 0, -1 if diff < 0
Inverting this gives a mask:

~(diff >> 31) → -1 if diff >= 0, 0 if diff < 0
This mask selectively allows diff to be applied only when it is positive

The update keeps ans equal to the maximum of ans and sum

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 19-06-2026
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current = 0;
        int maxAltitude =0;
        for(int x : gain){
            current +=x;
            maxAltitude = max(maxAltitude , current);
        }
        return maxAltitude;
    }
};

