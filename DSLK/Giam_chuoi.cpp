#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (cin >> s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '['))) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        cout << st.size() << "\n";
    }
}
int main(){
    solve();
}