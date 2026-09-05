class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       // each row is m long
       // there are n rows
       // the very middle is arr[m/2][n/2]
       // if the min >= max and target is not found, return false
       // if there is no matrix, return false
       if(matrix.empty()) {
        return false;
       }
       int min_row = 0;
       int min_col = 0;
       int max_row = matrix.size()-1;
       int max_col = matrix[0].size()-1;
       int curr_col = (max_row + max_row)/2;
       int curr_row = (min_row + max_row)/2;;
       while (min_row <= max_row) {
        curr_row = (min_row + max_row)/2;
        cout << max_row << endl;
        /*
        0
        */
        if(target < matrix[curr_row][0]) {
            cout <<  matrix[curr_row][0] << target;
            max_row = curr_row-1;
            cout << max_row << min_row;
        }
        else if(target > matrix[curr_row][max_col]) {
            cout << matrix[curr_row][max_col];
            min_row = curr_row+1;
        }
        else {
            cout << "Found Row\n";
            for(int i = 0; i< matrix[0].size(); i++) {
                if(matrix[curr_row][i] == target) {
                    return true;
                } 
            }
            return false;
        } 

       }
       return false;
    }
};
