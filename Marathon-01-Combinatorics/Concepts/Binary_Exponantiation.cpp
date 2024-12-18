#include <bits/stdc++.h>
#define endl '\n'
#define ll 'long long'
using namespace std;
void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
int Power(int A, int B)
{
    int Result = 1;
    while (B)
    {
        if (B % 2)
        {
            Result *= A;
            B--;
        }
        else
        {
            A *= A;
            B /= 2;
        }
    }
    return Result;
}
int main()
{
    FASTIO();
    cout << Power(2, 5) << endl;
    cout << Power(2, 13) << endl;
    return 0;
}