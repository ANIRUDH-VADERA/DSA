#include <iostream>

using namespace std;
const int n = 4;
const int MAX = 1000000;

// memoization for top down recursion
int memo[n + 1][1 << (n + 1)];

int tsp(int i, int mask, int **dist)
{
    if (mask == ((1 << i) | 3))
        return dist[1][i];
    // memoization
    if (memo[i][mask] != 0)
        return memo[i][mask];

    int res = MAX;

    for (int j = 1; j <= n; j++)
        if ((mask & (1 << j)) && j != i && j != 1)
            res = std::min(res, tsp(j, mask & (~(1 << i)), dist) + dist[j][i]);
    return memo[i][mask] = res;
}
int main()
{
    int n;
    cout << "Enter the number cites : ";
    cin >> n;

    int **dist = (int **)malloc((n + 1) * sizeof(int *));

    cout << "Enter the dist to travel from one city to all others : " << endl;
    for (int i = 0; i < n + 1; i++)
    {
        dist[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dist[i][j] = 0;
            }
            else
            {
                if (i != j)
                {
                    cout << "Enter the dist from " << i << " -> " << j << " : ";
                    cin >> dist[i][j];
                }
                else
                {
                    dist[i][j] = 0;
                }
            }
        }
    }
    int ans = MAX;
    for (int i = 1; i <= n; i++)
        ans = std::min(ans, tsp(i, (1 << (n + 1)) - 1, dist) + dist[i][1]);
    cout << "The minimum Cost to Travel acroos all the cities and come back to the starting point is : " << ans << endl;
    return 0;
}