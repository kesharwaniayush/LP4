
#include <iostream>
using namespace std;

int main()
{
    int n, W;
    int wt[20], p[20], dp[20][50];

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    for(int i = 1; i <= n; i++)
    {
        cout << "Enter weight and profit of item " << i << ": ";
        cin >> wt[i] >> p[i];
    }

    

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(wt[i] <= w)
            {
                int a = p[i] + dp[i-1][w-wt[i]];
                int b = dp[i-1][w];

                if(a > b)
                    dp[i][w] = a;
                else
                    dp[i][w] = b;
            }
            else
                dp[i][w] = dp[i-1][w];
        }
    }

   

    cout << "\nDP Table:\n";

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= W; w++)
            cout << dp[i][w] << "\t";

        cout << endl;
    }

    cout << "\nMaximum Profit = " << dp[n][W];



   
    cout << "\nSelected Items: ";

    int w = W;

    for(int i = n; i >= 1; i--)
    {
        if(dp[i][w] != dp[i-1][w])
        {
            cout << i << " ";
            w = w - wt[i];
        }
    }

    return 0;
}
