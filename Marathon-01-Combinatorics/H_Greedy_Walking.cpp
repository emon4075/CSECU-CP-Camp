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
ll Fact[10000001];
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
int N;
vector<int> V_Final;
ll C(ll N)
{
    ll Result = Fact[N];
    for (int i = 0; i < V_Final.size(); i++)
    {
        Result = (Result * Power(Fact[V_Final[i]], P - 2)) % P;
    }
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

    while (1)
    {
        cin >> N;
        if (N == 0)
        {
            break;
        }
        vector<int> V1(N), V2(N);
        V_Final.resize(N);
        for (int i = 0; i < N; i++)
        {
            cin >> V1[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> V2[i];
        }

        ll Sum = 0;
        for (int i = 0; i < N; i++)
        {
            V_Final[i] = V2[i] - V1[i];
            Sum += V_Final[i];
        }
        cout << C(Sum) << endl;
    }

    return 0;
}
