#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

long long merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long swaps = 0;

    while (i < mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            swaps += (mid - i);
        }
    }

    while (i < mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];

    return swaps;
}

long long mergeSort(vector<int> &arr, vector<int> &temp, int left, int right) {
    long long swaps = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        swaps += mergeSort(arr, temp, left, mid);
        swaps += mergeSort(arr, temp, mid + 1, right);
        swaps += merge(arr, temp, left, mid + 1, right);
    }
    return swaps;
}

// Function to count minimum adjacent swaps
int minSwaps(string A, string B, int N) {
    if (A.size() != B.size()) return -1;

    string sortedA = A, sortedB = B;
    sort(sortedA.begin(), sortedA.end());
    sort(sortedB.begin(), sortedB.end());

    if (sortedA != sortedB) return -1;  // If character frequencies don’t match, return -1

    unordered_map<char, vector<int>> charPositions;
    for (int i = 0; i < N; i++) charPositions[A[i]].push_back(i);

    vector<int> targetPos;
    for (char c : B) {
        targetPos.push_back(charPositions[c].front());
        charPositions[c].erase(charPositions[c].begin());
    }

    vector<int> temp(N);
    return mergeSort(targetPos, temp, 0, N - 1);
}

int main() {
    int N;
    string A, B;
    cin >> N >> A >> B;
    
    cout << minSwaps(A, B, N) << endl;
    return 0;
}



