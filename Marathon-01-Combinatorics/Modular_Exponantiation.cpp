#include <bits/stdc++.h>
#define endl '\n'
#define ll 'long long'
using namespace std;
void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
int Power(int A, int B, int P)
{
    int Result = 1;
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
int main()
{
    FASTIO();
    cout << Power(2, 3, 1) << endl;
    return 0;
}