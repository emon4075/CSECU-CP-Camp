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
    int Y, W;
    cin >> Y >> W;
    int Down = 6;
    int Up = (6 - max(Y, W)) + 1;
    if (Up == 0)
    {
        cout << "0/1" << endl;
    }
    else
    {
        int gcd = __gcd(Up, Down);
        Up /= gcd;
        Down /= gcd;
        cout << Up << "/" << Down << endl;
    }
    return 0;
}
