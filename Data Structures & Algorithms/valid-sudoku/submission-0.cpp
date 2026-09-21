class Solution {

    bool isValid(vector<char> &vec) {
        set<char> seen;
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == '.') {
                continue;
            }
            if(seen.contains(vec[i])) {
                cout << "Has seen " << vec[i];
                return false;
            }
            seen.insert(vec[i]);
        
        }
        return true;
    }
public:
/*
have a freq
*/

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> transpose(9, vector<char>(9));
        vector<vector<char>> boxes(9);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                transpose[j][i] = board[i][j];
            }
        }
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                int row = (i/3)*3
 + (j/3);
            boxes[row].push_back(board[i][j]);                
            }
        }
        for(auto row: board) {
            if(!isValid(row)) {
                return false;
            }
        }
        for(auto row: transpose) {
            if(!isValid(row)) {
                return false;
            }
        }
        for(auto row: boxes) {
            if(!isValid(row)) {
                return false;
            }
        }


        return true;;
    }
};
