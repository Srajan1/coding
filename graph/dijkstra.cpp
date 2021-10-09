// Solution for https://cses.fi/problemset/task/1671
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define loop(i, n) for (ll i = 0; i < n; ++i)
#define loopf(i, k, n) for (ll i = k; i <= n; ++i)
#define loopr(i, k, n) for (ll i = k; i >= n; --i)
#define test(cases) \
    ll cases;       \
    input(cases);   \
    while (cases--)
#define print(a) printf("%lld\n", a)
#define input(a) scanf("%lld", &a)
#define inarr(a, n)            \
    for (ll i = 0; i < n; ++i) \
    scanf("%lld", &a[i])
#define assign(arr, x, n) loop(i, n) arr[i] = x
#define v(x) vector<x>
#define p(x,y) pair<x, y>
 
int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<pair<ll, ll>>> graph(n+1);
    while(m--){
        ll a, b, c;
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
    }
    vector<ll> distance(n+1, LLONG_MAX);
    vector<bool> visited(n+1, false);
    distance[1] = 0;
    multiset<pair<ll, ll>> s;
    s.insert({0, 1});
    while(!s.empty()){
        auto front = *s.begin();
        s.erase(s.begin());
        ll node = front.second, weight = front.first;
        if(visited[node])
        continue;
        visited[node] = true;
        for(auto pr: graph[node]){
            ll nbr = pr.first;
            if(distance[nbr] > distance[node]+pr.second){
                distance[nbr] = distance[node]+pr.second;
                s.insert({distance[nbr], nbr});
            }
        }
    }
    loopf(i, 1, n)
    cout<<distance[i]<<" ";
}