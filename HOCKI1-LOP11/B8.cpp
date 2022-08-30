#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>
using namespace __gnu_pbds;
using namespace std;

struct qhash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x)
    const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//unordered_set<double, custom_hash>s;
#define MOD 1000000007


typedef long long ll;
typedef bool bl;
typedef string str;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef unordered_map<ll, ll, qhash> llumap;
typedef map<ll, ll> llmap;

#define it1 it->first
#define it2 it->second
#define fi first
#define se second
#define mp(p1, p2) make_pair(p1, p2)
#define f(i, n) for (ll i = 0; i < n; i += 1)
#define F(i, n, inc) for (ll i = 0; i < n; i += inc)
#define fu(i, start, end) for (int i = start; i < end; i += 1)
#define Fu(i, start, end, inc) for (int i = start; i < end; i += inc)
#define fd(i, start, end) for (int i = start; i >= end; i -= 1)
#define Fd(i, start, end, inc) for (int i = start; i >= end; i -= inc)
#define itr iterator
#define BIT(var,pos) ((var) & (1<<(pos)))
//#define ordered_set tree<pair<ll, ll>, null_type,less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
ll layer[300001];
ll low[300001];

ll bridges = 0, ap = 0;
vector<vector<ll>>v(300001);
void dfs(ll i, ll parent)
{
    layer[i] = low[i] = layer[parent] + 1;
    ll children = 0;
    for (auto val : v[i])
    {
        if (!layer[val])
        {
            children++;
            dfs(val, i);
            low[i] = min(low[i], low[val]);
        }
    }
    if (layer[i] == 1 && children >= 2) ap++;
    if (layer[i] > 1 && low[i] == layer[i] && children) ap++;
    for (auto val : v[i]) {

        if (val != parent)
            low[i] = min(low[i], layer[val]);
    }
    if (layer[i] > 1 && low[i] == layer[i]) bridges += 1;
}



void solve()
{
    ll n, m, a, b;
    cin >> n >> m;
    f(i, m)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    fu(i, 1, n + 1) {
        if (!layer[i]) dfs(i, 0);
    }
    cout << ap << " " << bridges;

}

int main()
{

    //freopen("SUMC.INP", "r" ,stdin); freopen("SUMC.OUT", "w", stdout);
    //std::ios_base::sync_with_stdio(0);
    //std::cin.tie(0);
    long long test = 1;

    //cin >> test;
    for (int i = 0; i < test; i += 1)
    {
        solve();
    }
    return 0;
}
