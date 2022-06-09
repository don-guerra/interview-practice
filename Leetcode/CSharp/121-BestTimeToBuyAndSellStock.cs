public class Solution {
    public int MaxProfit(int[] prices) {
        return OptimizedSolution(prices);
    }

    private int NaiveSolution(int[] prices) {
        int maxProfit = 0;
        
        for (int i = 0; i < prices.Length; i++) {
            for (int j = i + 1; j < prices.Length; j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }

    private int OptimizedSolution(int[] prices) {
        int minPrice = 0;
        int maxProfit = 0;
        for (int i = 1; i < prices.Length; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            
            int diff = prices[i] - minPrice;
            if (diff > maxProfit) {
                maxProfit = diff;
            }
        }

        return maxProfit;
    }
}