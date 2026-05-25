#include<iostream>
#include<vector>
using namespace std;
class Solution{
private:
    bool rows[9][10]={false};
    bool cols[9][10]={false};
    bool boxes[9][10]={false};
    bool solve(vector<vector<char>>& board){
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.'){
                    int box_index=(r/3)*3+(c/3);
                    for(int val=1;val<=9;val++){
                        if(!rows[r][val]&&!cols[c][val]&&!boxes[box_index][val]){
                            board[r][c]=val+'0';
                            rows[r][val]=cols[c][val]=boxes[box_index][val]=true;
                            if(solve(board)) return true;
                            board[r][c]='.';
                            rows[r][val]=cols[c][val]=boxes[box_index][val]=false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board){
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]!='.'){
                    int val=board[r][c]-'0';
                    int box_index=(r/3)*3+(c/3);
                    rows[r][val]=cols[c][val]=boxes[box_index][val]=true;
                }
            }
        }
        solve(board);
    }
};