#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> queries(n);
    for (int i = 0; i < n; i++) 
        cin >> queries[i].first >> queries[i].second;

    int len = s.size();
    vector<int> prefix(len + 1, 0);

    // Build prefix sum of treasures
    for (int i = 0; i < len; i++) 
        prefix[i + 1] = prefix[i] + (s[i] == 'T');

    // Process all queries after taking input
    for (auto [l, r] : queries) 
        cout << prefix[r] - prefix[l - 1] << endl;

    return 0;
}

