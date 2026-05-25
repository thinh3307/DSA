#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


long long firstNonRepeating(const vector<long long> &arr) {
    unordered_map<long long, int>freq;
    for(long long x:arr){
        freq[x]++;
    }
    for(long long x:arr){
        if(freq[x]==1) return x;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << firstNonRepeating(arr) << endl;
    return 0;
}
