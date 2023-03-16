#include <bits/stdc++.h>
using namespace std;

#define d 10 // any arbitary value

void rabinKarp(char *pattern, char *text, int q, int l1, int l2)
{
    int p = 0;
    int t = 0;
    int h = 1; // hash value
    int j;     // Looping varaible

    int f = 0; // Flag variable

    for (int i = 0; i < l2 - 1; i++)
    {
        h = (h * d) % q;
    }

    // Calculate hash value for pattern and text
    for (int i = 0; i < l2; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= l1 - l2; i++)
    {
        if (p == t)
        {
            for (j = 0; j < l2; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == l2) // The match is found
            {
                f = 1;
                printf("Pattern is found at index:  %d \n", i);
            }
        }

        if (i < l1 - l2)
        {
            t = (d * (t - text[i] * h) + text[i + l2]) % q;

            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
    if (f == 0)
    {
        printf("The pattern is not in given Text");
    }
}

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
    int q = 13;
    rabinKarp(pattern, text, q, l1, l2);
}