#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector<pair<char,int>> countFrequency(const string &s) {
    unordered_map<char,int> freq;
    for(char c: s){
        freq[c]++;
    }
    vector<pair<char,int>>result(freq.begin(),freq.end());
    sort(result.begin(),result.end(),[](const pair<char,int>&a, const pair<char,int>&b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        return a.first<b.first;
    });
    return result;
}

int main() {
    string s;
    getline(cin, s);

    vector<pair<char,int>> result = countFrequency(s);
    for (auto &p : result) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
