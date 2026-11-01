#include <iostream>
using namespace std;

// Recursive Function
int fib(int n)
{
    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    return fib(n-1) + fib(n-2);
}

int main()
{
    int n, a = 0, b = 1, c;

    cout << "Enter number of terms: ";
    cin >> n;

    // Non-Recursive Method
    cout << "\nNon-Recursive Series: ";

    for(int i = 1; i <= n; i++)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }

    // Recursive Method
    cout << "\nRecursive Series: ";

    for(int i = 0; i < n; i++)
    {
        cout << fib(i) << " ";
    }

    return 0;
}