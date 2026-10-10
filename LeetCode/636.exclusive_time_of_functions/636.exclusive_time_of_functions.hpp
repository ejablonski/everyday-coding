#include <stack>
#include <string>
#include <vector>

/**
 * Learning Journal:
 * - Pattern: Stack (Last-In, First-Out) for nested execution.
 * - Aha! Moment: The math for elapsed time changes depending on the log type. A `START` event
 * happens at the very beginning of a timestamp. An `END` event happens at the very end of a
 * timestamp.
 * - Trap 1: When an `END` event occurs, the elapsed duration needs a `+1` (to cover the full day),
 * AND the `previous_timestamp` clock must be moved forward by `+1` so the next event starts
 * tracking from the correct point in time.
 */

enum OP
{
    START,
    END
};

struct LogData
{
    int id;
    OP operation;
    int timestamp;
};

struct Solution
{
    [[nodiscard]]
    static LogData parseLog(const std::string& _s)
    {
        LogData ld{};
        const auto first_it = _s.find(':');
        const auto second_it = _s.find(':', first_it + 1);
        ld.id = std::stoi(_s.substr(0, first_it));
        ld.operation = _s[first_it + 1] == 's' ? OP::START : OP::END;
        ld.timestamp = std::stoi(_s.substr(second_it + 1, _s.length()));

        return ld;
    }

    [[nodiscard]]
    static std::vector<int> exclusiveTime(int _n, std::vector<std::string>& _logs)
    {
        std::vector<int> timestamps(_n, 0);
        std::stack<int> call_stack{};
        int previous_timestamp = 0;

        for (const auto& log : _logs) {
            LogData ld = parseLog(log);

            if (!call_stack.empty()) {
                timestamps[call_stack.top()] +=
                    (ld.timestamp - previous_timestamp) + (ld.operation == OP::END ? 1 : 0);
            }

            if (ld.operation == OP::START) {
                call_stack.push(ld.id);
            } else {
                call_stack.pop();
            }

            previous_timestamp = ld.timestamp + (ld.operation == OP::END ? 1 : 0);
        }

        return timestamps;
    }
};
