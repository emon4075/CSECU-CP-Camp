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
    double A, B, C, D;
    cin >> A >> B >> C >> D;
    double SIR = A / B;
    double Z = C / D;
    double Pw = SIR / (1 - (1 - SIR) * (1 - Z));
    printf("%.12lf\n", Pw);
    return 0;
}
