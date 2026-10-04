#include <vector>

struct Solution
{
    static std::vector<std::vector<int>> generate(int _rows)
    {
        std::vector<std::vector<int>> triangle(_rows);

        for (int i = 0; i < _rows; i++) {
            triangle[i].resize(i + 1, 1);

            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        return triangle;
    }
};
