#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
ll clac(ll i, ll j)
{
    if (j <= -1 || j > i)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }
    return clac(i - 1, j - 1) + clac(i - 1, j);
}
int main()
{
    FASTIO();
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int Count = 0;
        for (int i = 0; i < N; i++)
        {
            ll Res = clac(N, i);
            if (Res % 2 == 0)
            {
                Count++;
            }
        }
        cout << Count << endl;
    }
    return 0;
}