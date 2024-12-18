#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define P 1000000007
using namespace std;
void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
ll Fact[10000000];

ll Power(ll A, ll B)
{
    ll Result = 1;
    while (B)
    {
        if (B % 2)
        {
            Result = (Result * A) % P;
            B--;
        }
        else
        {
            A = (A * A) % P;
            B /= 2;
        }
    }
    return Result;
}
ll Fun(int A, int B, int C, int D)
{
    ll Result;
    Result = Fact[A];
    Result = (Result * Power(Fact[B], P - 2)) % P;
    Result = (Result * Power(Fact[C], P - 2)) % P;
    Result = (Result * Power(Fact[D], P - 2)) % P;
    return Result;
}

int main()
{
    FASTIO();

    Fact[0] = Fact[1] = 1;
    for (int i = 2; i < 10000000; i++)
    {
        Fact[i] = (Fact[i - 1] * 1LL * i) % P;
    }
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << Fun(A, B, C, D) << endl;
    return 0;
}
