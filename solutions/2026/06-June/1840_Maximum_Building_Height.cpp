/*
Problem: 1840. Maximum Building Height

Difficulty: Hard

Approach:
Add building 1 as a restriction.

Since the first building must always have height 0, we insert:

(1, 0)
Sort all restrictions by building index.

Processing the buildings in increasing order allows us to determine how much a restriction can be influenced by the previous one.

Left-to-Right Pass

Suppose we have two consecutive restricted buildings:
(x1, h1) and (x2, h2)
The distance between them is:

d = x2 - x1
Starting from height h1, the height can increase by at most 1 per building. Therefore, the maximum reachable height at x2 is:

h1 + d
Hence, we update:

h2 = min(h2, h1 + d)
This ensures that every restriction is valid with respect to the buildings on its left.

Right-to-Left Pass

Similarly, a restriction can also be limited by a building on its right.

If the next restricted building has height h2, then the current building cannot exceed:

h2 + d
Therefore, we update:

h1 = min(h1, h2 + d)
After these two passes, every restriction stores the maximum feasible height for that building.

Compute the maximum peak between consecutive restrictions.

Consider two adjacent restricted buildings:

(x1, h1) and (x2, h2)
Let:

d = x2 - x1
The tallest possible building between them is obtained by increasing from the smaller side and decreasing toward the other side. The maximum achievable height is:

(h1 + h2 + d) / 2
We compute this value for every adjacent pair and keep the maximum.

Handle buildings after the last restriction.

After the final restricted building, there are no upper bounds. Therefore, the height can continue increasing by 1 for every remaining building:

lastHeight + (n - lastPosition)
The final answer is the maximum among all segment peaks and this last increasing portion.
Time Complexity: O(m log m)
Space Complexity: O(m)

Date Solved: 20-06-2026
*/


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<vector<int>> arr;

        arr.push_back({1, 0});

        for (auto &r : restrictions) {
            arr.push_back(r);
        }

        sort(arr.begin(), arr.end());

        // Left to right pass
        for (int i = 1; i < arr.size(); i++) {
            int d = arr[i][0] - arr[i - 1][0];
            arr[i][1] = min(arr[i][1], arr[i - 1][1] + d);
        }

        // Right to left pass
        for (int i = arr.size() - 2; i >= 0; i--) {
            int d = arr[i + 1][0] - arr[i][0];
            arr[i][1] = min(arr[i][1], arr[i + 1][1] + d);
        }

        int ans = 0;

        for (int i = 1; i < arr.size(); i++) {
            int x1 = arr[i - 1][0];
            int h1 = arr[i - 1][1];

            int x2 = arr[i][0];
            int h2 = arr[i][1];

            int d = x2 - x1;

            ans = max(ans, (h1 + h2 + d) / 2);
        }

        int lastPos = arr.back()[0];
        int lastH = arr.back()[1];

        ans = max(ans, lastH + (n - lastPos));

        return ans;
    }
};
