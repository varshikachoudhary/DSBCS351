#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {

        // Update minimum buying price
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // Calculate today's profit
        int profit = prices[i] - minPrice;

        // Update maximum profit
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, pricesSize);

    printf("Maximum Profit: %d\n", result);

    return 0;
}
