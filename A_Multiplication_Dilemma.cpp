#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
int main()
{
    FASTIO();
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, M;
        cin >> N >> M;
        if (N % 10 != 0 && M % 10 == 0)
        {
            ll Upper = ceil(N / 10.0) * 10;
            ll Diff = Upper - N;
            cout << Upper << " x " << M << " - " << Diff << " x " << M << endl;
        }
        else
        {
            ll Upper = ceil(M / 10.0) * 10;
            ll Diff = M - Upper;
            cout << Diff << " x " << N << " + " << N << " x " << Upper;
        }
    }
    return 0;
}