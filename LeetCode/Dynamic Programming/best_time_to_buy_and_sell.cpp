#include <iostream>
#include <vector>

// LeetCode #121

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // Initialize max profit and minimum buy prices
            int profit = 0;
            int buy = prices[0];
    
            for (int i = 0; i < prices.size(); ++i) {
                // max profit is either the current profit or prices[i] - buy price
                profit = max(profit, prices[i] - buy);
                // min buy is either the current buy or prices[i]
                buy = min(buy, prices[i]);
            }
    
            return profit;
        }
    };