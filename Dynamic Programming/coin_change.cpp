class Solution {
public:
    int solve(int amount, vector<int>& coins, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }
        else if (amount < 0) {
            return INT_MAX - 1;
        }
        else if (dp[amount] != -1) {
            return dp[amount];
        }
        else {
            int answ = INT_MAX - 1;
            for (auto& coin : coins) {
                answ = min(answ, 1 + solve(amount-coin, coins, dp));
            }
            dp[amount] = answ;
        }
        return dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        
        int answ = solve(amount, coins, dp);
        return answ != INT_MAX - 1 ? answ : -1; 
    }
};