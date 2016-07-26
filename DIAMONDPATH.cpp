#include <iostream>
#include <algorithm>
using namespace std;

int diamond[200][200];
int lookup[200][200];

void solve(int nMid);
int getUpperMax(int i, int j);
int getLowerMax(int i, int j);

int main()
{
    int nTest;
    cin >> nTest;
    while (nTest--)
    {
        int nMid;
        cin >> nMid;

        for (int i = 0; i < nMid; i++)
        {
            for (int j = 0; j < i + 1; j++)
                cin >> diamond[i][j];
        }

        int nLine = 2 * nMid - 1;
        for (int i = nMid; i < nLine; i++)
        {
            for (int j = 0; j < nLine - i; j++)
                cin >> diamond[i][j];
        }

        solve(nMid);
        cout << lookup[nLine - 1][0] << endl;
    }
}

void solve(int nMid)
{
    int nLine = 2 * nMid - 1;
    for (int i = 0; i < nLine; i++)
    {
        if (i < nMid)
        {
            for (int j = 0; j < i + 1; j++)
                lookup[i][j] = diamond[i][j] + getUpperMax(i, j);
        }
        else
        {
            for (int j = 0; j < nLine - i; j++)
                lookup[i][j] = diamond[i][j] + getLowerMax(i, j);
        }
    }
}

int getUpperMax(int i, int j)
{
    if (i == 0) return 0;
    if (j == 0) return lookup[i - 1][j];
    if (j == i) return lookup[i - 1][j - 1];
    return max(lookup[i - 1][j - 1], lookup[i - 1][j]);
}

int getLowerMax(int i, int j)
{
    return max(lookup[i - 1][j], lookup[i - 1][j + 1]);
}
