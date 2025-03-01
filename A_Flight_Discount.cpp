#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define PB push_back
#define All(V) V.begin(), V.end()
#define F first
#define S second
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<ll> Dijkstra(ll src, vector<pair<ll, ll>> adj[], ll N)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ;
    vector<ll> Distant(N + 1, INF);
    Distant[src] = 0;
    PQ.push({0, src});

    while (!PQ.empty())
    {
        ll Cost = PQ.top().first;
        ll Node = PQ.top().second;
        PQ.pop();

        if (Cost > Distant[Node])
        {
            continue;
        }

        for (auto Child : adj[Node])
        {
            ll ChildNode = Child.first;
            ll ChildCost = Child.second;

            if (Distant[Node] + ChildCost < Distant[ChildNode])
            {
                Distant[ChildNode] = Distant[Node] + ChildCost;
                PQ.push({Distant[ChildNode], ChildNode});
            }
        }
    }
    return Distant;
}

int32_t main()
{
    FASTIO();
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> A1[N + 1], A2[N + 1];
    while (M--)
    {
        ll U, V, W;
        cin >> U >> V >> W;
        A1[U].PB({V, W});
        A2[V].PB({U, W});
    }

    auto MinDis = Dijkstra(1, A1, N);
    auto MinDisReversed = Dijkstra(N, A2, N);

    ll Ans = INF;
    for (ll i = 1; i <= N; i++)
    {
        for (auto Child : A1[i])
        {
            ll To = Child.F;
            ll Cost = Child.S;
            if (MinDis[i] == INF || MinDisReversed[To] == INF)
            {
                continue;
            }
            Ans = min(Ans, (MinDis[i] + (Cost / (2 * 1LL)) + MinDisReversed[To]));
        }
    }
    cout << Ans << endl;

    return 0;
}