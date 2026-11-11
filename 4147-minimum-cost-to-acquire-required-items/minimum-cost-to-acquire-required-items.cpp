class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long sum = 0;

        int mini = min(need1, need2);
        int maxi = max(need1, need2);

        // Case 1: Buy individual items
        long long costA = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        // Case 2: Buy both-type items for the maximum requirement
        long long costB = 1LL * maxi * costBoth;

        // Case 3: Buy both-type items for common requirements
        // and individual items for remaining requirements
        long long costC = 1LL * mini * costBoth
                        + 1LL * (need1 - mini) * cost1
                        + 1LL * (need2 - mini) * cost2;

        return min({costA, costB, costC});
    }
};