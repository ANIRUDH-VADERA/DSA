#include <bits/stdc++.h>
using namespace std;

// Driver's Code
int main()
{
    int l1, l2;
    cout << "Enter the length of the Text : ";
    cin >> l1;
    char *text = (char *)malloc(l1 * sizeof(char));
    cout << "Enter the Text : ";
    cin >> text;
    cout << "Enter the length of the Pattern : ";
    cin >> l2;
    char *pattern = (char *)malloc(l2 * sizeof(char));
    cout << "Enter the Pattern : ";
    cin >> pattern;
    /* A loop to slide pat[] one by one */
    int f = 0;
    for (int i = 0; i <= l1 - l2; i++)
    {
        int j;
        /* Check for pattern starting from index i */
        for (j = 0; j < l2; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }

        if (j == l2) // if we found a match
        {
            f = 1;
            cout << "Pattern found at index : " << i << endl;
        }
    }
    if (f == 0)
    {
        cout << "The pattern is not in given Text";
    }
    return 0;
}
