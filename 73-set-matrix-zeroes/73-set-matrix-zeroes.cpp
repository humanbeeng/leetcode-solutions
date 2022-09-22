class Solution {
    
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool is_first_row_zero = false;
        bool is_first_col_zero = false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
//                 If we encounter element in matrix which is zero
                if(matrix[i][j] == 0) {
//                     That happens to be first row or col. Then set the flag
                    if(i == 0)
                        is_first_row_zero = true;
                    if(j == 0)
                        is_first_col_zero = true;   
                    
//                     Mark the corresponding row and col
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
//                 For each element, check if it is marked for zero
                if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
//         At last mark the first row and col to zero if set
        if(is_first_row_zero) {
            for(int j = 0; j < n; j++) 
                matrix[0][j] = 0;
        }
        
        if(is_first_col_zero) 
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        
        
    }
};