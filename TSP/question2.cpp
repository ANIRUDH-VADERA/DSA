#include <bits/stdc++.h>
using namespace std;
#define V 4
int traverse(int **graph, int s, char *path, int n, char *sites)
{
    vector<int> vertex;
    for (int i = 0; i < n; i++)
    {
        if (i != s)
        {
            vertex.push_back(i);
        }
    }

    int min_path = INT_MAX;
    while (next_permutation(vertex.begin(), vertex.end()))
    {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);
        if (min_path == current_pathweight)
        {
            path[0] = sites[s];
            for (int i = 0; i < vertex.size(); i++)
            {
                k = vertex[i];
                path[i + 1] = sites[k];
            }
            path[n] = sites[s];
        }
    }

    return min_path;
}
int main()
{
    int n;
    cout << "Enter the number of historic sites : ";
    cin >> n;
    cout << "Enter the name of historic sites : " << endl;
    char *sites = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        cin >> sites[i];
    }

    int **distance = (int **)malloc(n * sizeof(int *));

    cout << "Enter the distance to travel from one city to all others : " << endl;
    for (int i = 0; i < n; i++)
    {
        distance[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                cout << "Enter the distance from " << sites[i] << " -> " << sites[j] << " : ";
                cin >> distance[i][j];
            }
            else
            {
                distance[i][j] = 0;
            }
        }
    }

    char *path = (char *)malloc((n + 1) * sizeof(char));

    int s = 0;
    cout << "The minimum Cost to Travel acroos all the cities and come back to the starting point is : " << traverse(distance, s, path, n, sites) << endl;
    cout << "The Path is : [ ";
    for (int i = 0; i < n + 1; i++)
    {
        cout << path[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}