class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();

        //对角线翻转 —— std::swap
        for(int i = 0; i < N; i++)
            for(int j = i + 1; j < N; j++)
                swap(matrix[i][j], matrix[j][i]);

        //水平翻转 —— std::reverse
        for(auto& vec: matrix)
            reverse(vec.begin(), vec.end());
    }
};
