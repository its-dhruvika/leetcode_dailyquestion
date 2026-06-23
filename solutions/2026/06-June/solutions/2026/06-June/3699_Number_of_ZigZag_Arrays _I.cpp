/*
Problem:3699. Number of ZigZag Arrays I
Difficulty: Hard

Approach:
Let:

m = r - l + 1
dp[j] = number of valid sequences ending at rank j
Initially, for length 1, every value can be chosen once:

dp[j] = 1
Now I build the sequence length by length.

For an alternating pattern that starts with an increasing move:

Length 2 needs previous < current
Length 3 needs previous > current
Length 4 needs previous < current
and so on
Therefore:

For even lengths, I need all smaller ranks.
For odd lengths, I need all larger ranks.
Instead of recomputing sums every time:

Even length → use running prefix sums.
Odd length → use running suffix sums.
The provided trick of reversing the array each iteration achieves exactly the same effect and keeps the implementation very compact.

At the end, the DP counts only one starting pattern.

Since a ZigZag sequence can start either:

up, down, up...
down, up, down...
both patterns are symmetric.

So I multiply the final answer by 2


Date Solved: 23-06-2026
*/

SOLUTION:-

  class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> dp(m, 1);

        for (int len = 2; len <= n; len++) {
            reverse(dp.begin(), dp.end());

            long long pref = 0;

            for (int i = 0; i < m; i++) {
                int old = dp[i];

                dp[i] = pref;

                pref = (pref + old) % MOD;
            }
        }

        long long ans = 0;

        for (int x : dp) {
            ans = (ans + x) % MOD;
        }

        return (ans * 2) % MOD;
    }
};
