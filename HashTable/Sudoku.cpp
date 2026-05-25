#include<iostream>
#include<vector>
using namespace std;
class Soulution{
public:
    bool isValidSudoku(vector<vector<char>>& board){
        int rows[9][9]={0};
        int cols[9][9]={0};
        int boxes[9][9]={0};
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.'){
                    continue;
                }
                int val=board[r][c]-'0';
                int box_index=(r/3)*3+(c/3);
                if(rows[r][val]==1||cols[c][val]==1||boxes[box_index][val]==1) return false;

                rows[r][val]=1;
                cols[c][val]=1;
                boxes[box_index][val]=1;
            }
        }
        return true;
    }
};