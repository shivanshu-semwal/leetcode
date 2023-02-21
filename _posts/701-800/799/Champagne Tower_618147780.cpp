class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {     
        double result[query_row+10][query_row+10];
        for(int i=0;i<query_row+10;i++)
            for(int j=0;j<query_row+10;j++)
                result[i][j] = 0.0;
        result[0][0] = poured;
        for (int i = 0; i < query_row+2; i++) {
            for (int j = 0; j <= i; j++) {
                if (result[i][j] >= 1) {
                    result[i + 1][j] += (result[i][j] - 1) / 2.0;
                    result[i + 1][j + 1] += (result[i][j] - 1) / 2.0;
                    result[i][j] = 1;
                }
            }
        }
        return result[query_row][query_glass];
    }
};
