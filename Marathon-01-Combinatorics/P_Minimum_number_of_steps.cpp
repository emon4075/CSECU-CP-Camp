#include <bits/stdc++.h>
#define endl '\n'
#define ll 'long long'
#define P 1000000007;
using namespace std;
void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
int main()
{
    FASTIO();
    string S;
    cin >> S;
    int Count_B = 0;
    int Count_Result = 0;
    for (int i = S.size() - 1; i >= 0; i--)
    {
        if (S[i] == 'b')
        {
            Count_B = (Count_B + 1) % P;
        }
        else
        {
            Count_Result = (Count_B + Count_Result) % P;
            Count_B = (Count_B * 2) % P;
        }
    }
    cout << Count_Result << endl;

    return 0;
}