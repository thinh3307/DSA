#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<long long> majorityNK(const vector<long long> &arr, int k) {
    unordered_map<long long,int> freq;
    for(long long x:arr) freq[x]++;
    int chia=arr.size()/k;
    vector<long long>result;
    for(auto& p:freq){
        if(p.second>chia) result.push_back(p.first);
    }
    sort(result.begin(),result.end());
    return result;

}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<long long> ans = majorityNK(arr, k);

    if (ans.empty()) {

        cout << -1 << "\n";

    } else {

        for (size_t i = 0; i < ans.size(); i++) {

            if (i) cout << " ";

            cout << ans[i];

        }

        cout << "\n";

    }

    return 0;

}

