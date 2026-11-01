#include <iostream>
using namespace std;

struct Node
{
    char ch;
    int f;
    Node *left, *right;
};

Node* make(char c, int f)
{
    Node *p = new Node;
    p->ch = c;
    p->f = f;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void display(Node *root, string code)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " = " << code << endl;
        return;
    }

    display(root->left, code + "0");
    display(root->right, code + "1");
}

int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    Node *a[100];

    for (int i = 0; i < n; i++)
    {
        char c;
        int f;
        cout << "Enter character and frequency: ";
        cin >> c >> f;
        a[i] = make(c, f);
    }

    int count = n;

    while (count > 1)
    {
        int x = 0, y = 1;

        if (a[x]->f > a[y]->f)
        {
            int t = x;
            x = y;
            y = t;
        }

        for (int i = 2; i < count; i++)
        {
            if (a[i]->f < a[x]->f)
            {
                y = x;
                x = i;
            }
            else if (a[i]->f < a[y]->f)
                y = i;
        }

        Node *p = make('$', a[x]->f + a[y]->f);
        p->left = a[x];
        p->right = a[y];

        if (x > y)
        {
            int t = x;
            x = y;
            y = t;
        }

        a[x] = p;
        a[y] = a[count - 1];
        count--;
    }

    cout << "\nHuffman Codes:\n";
    display(a[0], "");

    cout << "\nOptimal Tree Root Frequency: " << a[0]->f;

    return 0;
}