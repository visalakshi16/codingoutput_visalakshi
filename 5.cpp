#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<vector<int>> sensors(5, vector<int>(4)); 
    for (int i = 0; i < 4; i++)  
        for (int j = 0; j < 5; j++) {  
            cin >> sensors[j][i]; 
            if (sensors[j][i] < 10 || sensors[j][i] > 200) {  
                cout << "INVALID INPUT" << endl;
                return 0;
            }
        }

    vector<int> avg(5, 0);  
    int maxAvg = 0; 

    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 4; j++)  
            avg[i] += sensors[i][j];  
        avg[i] = round(avg[i] / 4.0);  
        maxAvg = max(maxAvg, avg[i]);  
    }

    if (maxAvg < 50) {  
        cout << "Energy consumption is optimal." << endl;
    } else {  
        cout << "Sensor Number : ";
        for (int i = 0; i < 5; i++)  
            if (avg[i] == maxAvg) cout << (i + 1) << " ";
        cout << endl;
    }

    return 0;
}
