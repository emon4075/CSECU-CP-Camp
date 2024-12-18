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

ll C(ll N, ll K)
{
    ll Result;
    if (K > N)
    {
        return 0;
    }
    Result = Fact[N];
    Result = (Result * Power(Fact[K], P - 2)) % P;
    Result = (Result * Power(Fact[N - K], P - 2)) % P;
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

    cout << C(5, 2) << endl;
    cout << C(8, 1) << endl;
    cout << C(9, 5) << endl;
    return 0;
}
