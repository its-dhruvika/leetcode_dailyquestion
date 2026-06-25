/*
Problem: 3737. Count Subarrays With Majority Element I

Difficulty: Medium

Approach:
Approach 1 - Brute Force
Idea
Generate every possible subarray.

Count how many times the target appears.

If

targetCount > length / 2
increment the answer.

Complexity
Time:

O(n²)
with incremental counting.

Space:

O(1)
Why It Isn't Ideal
We're repeatedly evaluating the same condition.

There's clearly some hidden structure we're not using.

Approach 2 - Balance Transformation
Instead of storing frequencies,

convert

target

↓

+1

others

↓

-1
Now every subarray has a score.

Positive score

↓

Target is majority.

This dramatically simplifies the condition.

However,

we still haven't figured out the fastest way to count all positive-sum subarrays.

That becomes the next challenge.

Approach 3 - Prefix Balance (Optimal)
After the transformation,

the problem becomes:

Count subarrays whose transformed sum is positive.

This immediately suggests:

Prefix sums
Prefix balance
Counting previous prefixes efficiently
The remaining challenge is no longer about majority elements.

It's purely a prefix comparison problem.

And that's exactly where the optimal solution comes from.

We'll derive that carefully in Part 2.

Date Solved: 25-06-2026
*/


SOLUTION :-

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;

        for (int l = 0; l < n; l++) {
            int targetCount = 0;

            for (int r = l; r < n; r++) {
                if (nums[r] == target) {
                    targetCount++;
                }

                int len = r - l + 1;

                if (targetCount > len / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
