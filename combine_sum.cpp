#include <vector>
#include <numeric> // Not strictly needed but good practice

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentCombination;
        // Start the backtracking process from the first candidate (index 0)
        findCombinations(candidates, target, 0, currentCombination, result);
        return result;
    }

private:
    void findCombinations(
        const std::vector<int>& candidates,
        int target,
        int startIndex,
        std::vector<int>& currentCombination,
        std::vector<std::vector<int>>& result) {

        // --- Base Cases ---
        // 1. A valid combination is found
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }
        // 2. The path is invalid (sum exceeds target)
        if (target < 0) {
            return;
        }

        // --- Recursive Step (Explore) ---
        for (int i = startIndex; i < candidates.size(); ++i) {
            // Choose: Add the current candidate to our combination
            currentCombination.push_back(candidates[i]);

            // Explore: Recurse with the updated target.
            // We pass 'i' as the next startIndex because we can reuse the same element.
            findCombinations(candidates, target - candidates[i], i, currentCombination, result);

            // Un-choose (Backtrack): Remove the candidate to explore other paths.
            currentCombination.pop_back();
        }
    }
};
