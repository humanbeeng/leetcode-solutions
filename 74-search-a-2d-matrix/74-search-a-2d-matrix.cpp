class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n_rows = matrix.size();
        int n_cols = matrix[0].size();
        int n_elements = n_rows * n_cols;
        
        int left = 0, right = n_elements - 1;
        
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            int mid_i = mid / n_cols;
            int mid_j = mid % n_cols;
            int mid_element = matrix[mid_i][mid_j];
            
            if(mid_element == target) {
                return true;
            }
            if(target > mid_element) {
                left = mid + 1;
            }
            else right = mid - 1;
        }
        
        return false;
    }
};