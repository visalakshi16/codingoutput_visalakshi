#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    int minMax = INT_MAX;

    for (int i = 0; i <= n - k; i++) {
        int maxVal = arr[i];
        for (int j = i; j < i + k; j++) 
            maxVal = max(maxVal, arr[j]);
        
        minMax = min(minMax, maxVal);
    }

    cout << minMax << endl;
    return 0;
}
