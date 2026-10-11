#include <stack>
#include <vector>

/**
 * Learning Journal:
 * - Pattern: Monotonic Stack (Next Smaller Element).
 * - Aha! Moment: Storing indices in the stack allows direct in-place modification of prices.
 *   Using a while loop lets a single smaller price cascade backwards and discount multiple
 *   waiting items on the stack, achieving O(N) linear time since each index is pushed and
 *   popped at most once.
 * - Trap: Using an `if` statement only resolves the single top item, failing to discount
 *   earlier items on the stack that are also greater than or equal to the current price:
 *     // INCORRECT (Trap): only discounts at most one item
 *     if (!price_stack.empty() && _prices[price_stack.top()] >= _prices[i]) {
 *         _prices[price_stack.top()] -= _prices[i];
 *         price_stack.pop();
 *     }
 *
 *     // CORRECT: cascades backwards through all eligible items
 *     while (!price_stack.empty() && _prices[price_stack.top()] >= _prices[i]) {
 *         _prices[price_stack.top()] -= _prices[i];
 *         price_stack.pop();
 *     }
 */

struct Solution
{
    static std::vector<int> finalPrices(std::vector<int>& _prices)
    {
        std::stack<int> price_stack{};

        for (int i = 0; i < _prices.size(); i++) {
            while (!price_stack.empty() && _prices[price_stack.top()] >= _prices[i]) {
                _prices[price_stack.top()] -= _prices[i];
                price_stack.pop();
            }
            price_stack.push(i);
        }

        return _prices;
    }

    /*
     * Brute force solution that would probably hit TLE. It works but it's slower then solution
     * above.
     */
    // static std::vector<int> finalPricesBruteForced(std::vector<int>& _prices)
    // {
    //     int upper_boundary = _prices.size();
    //     std::vector<int> final_prices{};
    //
    //     for (int i = 0; i < upper_boundary; i++) {
    //         int item_price = _prices[i];
    //         int discount = 0;
    //
    //         for (int j = i + 1; j < upper_boundary; ++j) {
    //             if (item_price >= _prices[j]) {
    //                 discount = _prices[j];
    //                 break;
    //             }
    //         }
    //
    //         final_prices.push_back(item_price - discount);
    //     }
    //
    //     return final_prices;
    // }
};
