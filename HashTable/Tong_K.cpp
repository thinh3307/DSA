#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long countSubarraysWithSum(const vector<long long> &arr, long long k) {
    unordered_map<long long,int>freq;
    freq[0]=1;
    long long count=0, prefixSum=0;
    for(long long x:arr){
        prefixSum+=x;
        if(freq.count(prefixSum-x)) count+=freq[prefixSum-k];
        freq[prefixSum]++;
    }
    return count;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << countSubarraysWithSum(arr, k) << endl;
    return 0;

}

