
#include <iostream>
using namespace std;

int n;
char a[20][20];

bool safe(int r, int c)
{
    for(int i = 0; i < r; i++)
        if(a[i][c] == 'Q')
            return false;

    for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--)
        if(a[i][j] == 'Q')
            return false;

    for(int i = r-1, j = c+1; i >= 0 && j < n; i--, j++)
        if(a[i][j] == 'Q')
            return false;

    return true;
}

bool solve(int r)
{
    if(r == n)
        return true;

    for(int c = 0; c < n; c++)
    {
        if(safe(r, c))
        {
            a[r][c] = 'Q';

            if(solve(r+1))
                return true;

            a[r][c] = '-';
        }
    }
    return false;
}

int main()
{
    cout << "Enter N: ";
    cin >> n;

    if(n < 1 || n > 20)
    {
        cout << "Invalid input";
        return 0;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = '-';

    a[0][0] = 'Q';

    if(solve(1))
    {
        cout << "\nN-Queens Matrix:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "Solution not possible";

    return 0;
}
