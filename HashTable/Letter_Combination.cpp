#include<iostream>
#include<vector>
using namespace std;
class Solution{
private:
    const vector<string> Phone_map={
        "", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    void backtrack(string &digits, int index, string &curr, vector<string>& result){
        if(index==digits.length()){
            result.push_back(curr);
            return;
        }
        int digits_num=digits[index]-'0';
        string letters=Phone_map[digits_num];
        for(char c: letters){
            curr.push_back(c);
            backtrack(digits,index+1,curr,result);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits){
        vector<string> result;
        if(digits.empty()){
            return result;
        }
        string current="";
        backtrack(digits,0,current,result);
        return result;
    }
};