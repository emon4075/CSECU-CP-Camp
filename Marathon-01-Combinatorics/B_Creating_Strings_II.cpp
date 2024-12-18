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
ll Fact[1000001];
int Track[26] = {0};
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
ll Permutation(ll N)
{
    ll Result = Fact[N];
    ll Denominator = 1;
    for (int i = 0; i < 26; i++)
    {
        if (Track[i] > 1)
        {
            Denominator = (Denominator * Fact[Track[i]]) % P;
        }
    }
    Result = (Result * Power(Denominator, P - 2)) % P;
    return Result;
}
int main()
{
    FASTIO();
    Fact[0] = Fact[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        Fact[i] = (Fact[i - 1] * 1LL * i) % P;
    }
    string S;
    cin >> S;
    for (auto C : S)
    {
        Track[C - 'a']++;
    }
    cout << Permutation(S.size()) << endl;
    return 0;
}
