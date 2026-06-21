/*
Problem: 1833. Maximum Ice Cream Bars
Difficulty: Medium

Approach:
Sort the costs array in non-decreasing order.
Traverse the sorted array from left to right.
For each ice cream:
If its cost is greater than the remaining coins, we cannot buy it or any subsequent ice cream.
Otherwise, buy it, subtract its cost from coins, and increment the answer.
Return the total number of ice creams purchased.

Time Complexity: O((n log n)
Space Complexity: O(1)

Date Solved: 21-06-2026
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        for(int x:costs){
            if(x>coins)break;
            ans++;
            coins-=x;
        }
        return ans;
    }
};
