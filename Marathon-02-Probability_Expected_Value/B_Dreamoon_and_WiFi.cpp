#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
int X, Y, Z, Count = 0;
void Possible(int N, int M)
{
    if (M == 0)
    {
        if (N == X)
        {
            Count++;
        }
        return;
    }
    Possible(N + 1, M - 1);
    Possible(N - 1, M - 1);
}
int main()
{
    FASTIO();
    string S1, S2;
    cin >> S1 >> S2;
    for (auto i : S1)
    {
        if (i == '+')
        {
            X++;
        }
        else
        {
            X--;
        }
    }
    for (auto i : S2)
    {
        if (i == '+')
        {
            Y++;
        }
        else if (i == '-')
        {
            Y--;
        }
        else
        {
            Z++;
        }
    }
    Possible(Y, Z);
    double Ans = (1.0 * Count) / pow(2, Z);
    printf("%.12lf", Ans);
    return 0;
}