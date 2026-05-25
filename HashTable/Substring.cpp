#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>result;
        if(s.empty()||words.empty()) return result;
        int word_len=words[0].length();
        int num_words=words.size();
        int s_len=s.length();
        int total_len=word_len * num_words;
        if(s_len<total_len) return result;
        unordered_map<string, int> word_count;
        for(const string& w:words){
            word_count[w]++;
        }
        for(int i=0;i<word_len;i++){
            int left=i;
            unordered_map<string,int> curr_count;
            int count=0;
            for(int right=i;right+word_len<=s_len;right+=word_len){
                string sub=s.substr(right,word_len);
                if(word_count.count(sub)){
                    curr_count[sub]++;
                    count++;
                    while(curr_count[sub]>word_count[sub]){
                        string left_word=s.substr(left,word_len);
                        curr_count[left_word]--;
                        count--;
                        left+=word_len;
                    }
                    if(count==num_words){
                        result.push_back(left);
                    }
                }
                else{
                    curr_count.clear();
                    count=0;
                    left=right+word_len;
                }

            }
        }
        return result;
    }
};