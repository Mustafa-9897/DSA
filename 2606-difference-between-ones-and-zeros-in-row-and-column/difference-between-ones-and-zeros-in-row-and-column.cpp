class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // since (m*n <= 10^5) given so we can use O(m*n)
        int n = grid.size(), m = grid[0].size();

        vector<int> rowOne(n, 0), rowZero(n, 0);
        vector<int> colOne(m, 0), colZero(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    rowOne[i]++;
                    colOne[j]++;
                }
                else {
                    rowZero[i]++;
                    colZero[j]++;
                }
            }
        }

        vector<vector<int>> diff(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                diff[i][j] = rowOne[i] + colOne[j] - rowZero[i] - colZero[j];
            }
        }

        return diff;
    }
};