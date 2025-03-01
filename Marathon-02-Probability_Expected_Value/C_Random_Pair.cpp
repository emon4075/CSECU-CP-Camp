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
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int D = (N * (N - 1)) / 2;
        vector<int> V(N), CPY;
        for (int i = 0; i < N; i++)
        {
            cin >> V[i];
        }
        CPY = V;
        int MX1 = *max_element(V.begin(), V.end());
        V.erase(max_element(V.begin(), V.end()));
        int MX2 = *max_element(V.begin(), V.end());
        int Total = MX1 + MX2;
        int Count = 0;
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (CPY[i] + CPY[j] == Total)
                {
                    Count++;
                }
            }
        }
        double Res = Count / (D * 1.0);
        printf("%.8lf\n", Res);
    }
    return 0;
}