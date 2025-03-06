class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int size = grid.size();
        std::vector<int> occurrences(size * size + 1, 0);
        int repeat = -1, missing = -1;

        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                int number = grid[row][col];
                occurrences[number]++;
            }
        }

        for (int i = 1; i <= size * size; i++) {
            if (occurrences[i] == 0) {
                missing = i;
            } else if (occurrences[i] == 2) {
                repeat = i;
            }
        }

        return {repeat, missing};
    }
};