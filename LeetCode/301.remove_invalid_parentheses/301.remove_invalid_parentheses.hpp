#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution
{
    // Helper function to check if a string has valid parentheses
    [[nodiscard]]
    static bool isValid(const std::string& s)
    {
        int count = 0;
        for (char c : s) {
            if (c == '(')
                count++;
            else if (c == ')')
                count--;

            // If closing brackets ever exceed opening ones, it's invalid
            if (count < 0)
                return false;
        }
        return count == 0;
    }

  public:
    [[nodiscard]]
    static std::vector<std::string> removeInvalidParentheses(std::string s)
    {
        std::vector<std::string> result;
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;

        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            std::string current = q.front();
            q.pop();

            if (isValid(current)) {
                result.push_back(current);
                found = true;
            }

            // If we found a valid string at this level, don't generate strings
            // for the next level (but finish processing the current level's queue)
            if (found)
                continue;

            // Generate all possible states by removing exactly one bracket
            for (size_t i = 0; i < current.length(); ++i) {
                // We only care about removing parentheses, not letters
                if (current[i] != '(' && current[i] != ')')
                    continue;

                // Create a new string with the character at index i removed
                std::string next = current.substr(0, i) + current.substr(i + 1);

                // Only enqueue if we haven't seen this exact string before
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return result;
    }
};
