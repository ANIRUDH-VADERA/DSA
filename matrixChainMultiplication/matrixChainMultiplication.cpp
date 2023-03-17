
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Driver Code
int main()
{
    cout << "Enter the Number of Elements of the dimension array : ";
    int n;
    cin >> n;
    int *arr = (int *)malloc(n * sizeof(int));
    cout << "Enter the elements of the dimension array : "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element "
             << i << " : ";
        cin >> arr[i];
    }

    // Main Logic
    /* One extra row and one extra column are
    allocated in dp[][]. 0th row and 0th
    column of dp[][] are not used */
    // The DP matrix -> Used for memoization
    int dp[n][n];
    int i, j, k, L;
    /* dp[i, j] = Minimum number of scalar
    multiplications needed to compute the
    matrix A[i]A[i+1]...A[j] = A[i..j] where
    dimension of A[i] is arr[i-1] x arr[i] */
    // arr is the given dimension array

    // cost is zero when multiplying
    // one matrix.
    for (i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    // L is chain length.
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            // Initialize with a very high value so that we can find minimum
            dp[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
            }
        }
    }
    cout << "Minimum number of multiplications is : " << dp[1][n - 1];
    getchar();
    return 0;
}