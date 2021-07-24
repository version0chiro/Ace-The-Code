class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowLength = matrix.size();
        int colLength = matrix[0].size()-1;
        int temp;
        // for(int j=0;j<rowLength)
        for(int j=0;j<rowLength/2;j++){
            int start = j;
            int end = rowLength-j-1;
            for(int i=start;i<end;i++){
                temp = matrix[start][i];
                matrix[start][i]=matrix[colLength-i][start];
                matrix[colLength-i][start] = matrix[end][colLength-i];
                matrix[end][colLength-i] = matrix[i][end];
                matrix[i][end] = temp;

            }
        }
            
    }
};