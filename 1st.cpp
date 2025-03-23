#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findprofit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    
    for (int i = 0; i < n; i++) 
        cin >> prices[i];

    cout << findprofit(prices) << endl;
    return 0;
}
