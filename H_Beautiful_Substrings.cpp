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
        int N, M, K;
        cin >> N >> M >> K;
        string S1, S2;
        cin >> S1 >> S2;
        unordered_set<string> S;
        for (int i = 0; i <= N - K; ++i)
        {
            string substring = S1.substr(i, K);
            string Key = string(1, substring.front()) + string(1, substring.back());
            S.insert(Key);
        }
        int Count = 0;
        for (int i = 0; i < S2.size(); i++)
        {
            for (int j = i; j < S2.size(); j++)
            {
                string Key = string(1, S2[i]) + string(1, S2[j]);
                if (S.find(Key) != S.end())
                {
                    Count++;
                }
            }
        }
        cout << Count << endl;
    }
    return 0;
}