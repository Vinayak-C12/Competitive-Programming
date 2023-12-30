//Leetcode - Valid Sudoko - Medium
//https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int cnt = 9;
        //3 boolean matrices initialised with false for checking repetetions in each row,column and each 3x3 box
        bool row[cnt][cnt] = {false};
        bool col[cnt][cnt] = {false};
        bool box[cnt][cnt] = {false};
        //Iterating through each entry in the board matrix
        for(int r = 0;r<cnt;r++)
        {
            for(int c = 0;c<cnt;c++)
            {
                if(board[r][c]=='.')
                {
                    continue;
                }
                //idx is the number in the sudoko box. We convert the character to int by doing board[r][c]-'0' and then sub 1 again as the mapping is from (1-9)
                  to (0-8) in the matrices
                int idx = board[r][c]-'0'-1;
                //area is used to get the 3x3 sudoko box of which the number is a part of
                int area = (r/3)*3 + c/3;
                //Checking for entries wrt to that particular row, col and box with the number
                if(row[r][idx]||col[c][idx]||box[area][idx])
                {
                    return false;
                }
                //Updating the values
                row[r][idx]="true";
                col[c][idx]="true";
                box[area][idx]="true";
            }
            
        }
        return true;
        
    }
};
