
#include <iostream>
using namespace std;

int main() {
    int n;
    float cap, total = 0, temp;

    cout << "Enter number of items: ";
    cin >> n;

    float w[n], p[n], r[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter weight and profit: ";
        cin >> w[i] >> p[i];
        r[i] = p[i] / w[i];
    }

    cout << "Enter capacity: ";
    cin >> cap;

    // Sort items by profit/weight ratio
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(r[i] < r[j]) {
                temp = r[i]; r[i] = r[j]; r[j] = temp;
                temp = w[i]; w[i] = w[j]; w[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    cout << "\nItem\tWeight\tProfit\tTaken\n";

    for(int i = 0; i < n; i++) {
        float x;

        if(cap >= w[i]) {
            x = 1;
            cap = cap - w[i];
            total = total + p[i];
        }
        else {
            x = cap / w[i];
            total = total + p[i] * x;
            cap = 0;
        }

        cout << i+1 << "   \t" << w[i] << "   \t"
             << p[i] << "   \t" << x << endl;

        if(cap == 0)
            break;
    }

    cout << "\nMaximum Profit = " << total;

    return 0;
}
