

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


bool isAnagram(const string &s, const string &t) {
    if(s.size()!=t.size()) return false;
    unordered_map<char, int> freq;
    for(char c:s) freq[c]++;
    for(char c:t) freq[c]--;
    for(auto&p:freq){
        if(p.second!=0) return false;
    }
    return true;
}

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);

    cout << (isAnagram(s, t) ? "YES" : "NO") << endl;
    return 0;
}
