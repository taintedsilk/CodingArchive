#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

ll n,m;
ll s;
ll valid[100000];
vector<vector<ll>>adj[100000];
ll path[1200][3600];
void get_valid(ll st) {
    set<pair<ll, ll>>q;
    valid[st] = 1;
    q.insert({1, st});
    while (q.size()) {
        pair<ll, ll>p = *q.begin();
        q.erase(q.begin());
        for (auto val: adj[p.se]) {
            ll dis = val[1] * val[2];
            ll idx = val[0];
            if (!valid[idx]) {
                valid[idx] = p.fi + dis;
                q.insert({valid[idx], idx});

            }
            else if (valid[idx] > p.fi + dis) {
                q.erase({valid[idx], idx});
                valid[idx] = p.fi + dis;
                q.insert({valid[idx], idx});
            }
        }
    }
}
struct S{
    ll t, cost, idx;
    S(ll a, ll b, ll c) :
        t(a), cost(b), idx(c) {}

};
inline bool operator< (const S &a,const S& b) {
    return a.t < b.t;
}
void dij(ll st) {
    set<S>q;
    q.insert({1, 0, st});
    while (q.size()) {
        S p = *q.begin();
        if (p.idx == n - 1) return;
        q.erase(q.begin());
        for (auto val : adj[p.idx]) {
            ll dis = p.t + val[1];
            ll cost = p.cost + val[1] * val[2];
            ll idx = val[0];
            if (cost + valid[idx] > (s + 1)) continue;
            else if (!path[idx][cost]) {
                path[idx][cost] = dis;
                q.insert(S(dis, cost, idx));
            }
            else if (path[idx][cost] > dis) {
                q.erase(S(path[idx][cost], cost, idx));
                path[idx][cost] = dis;
                q.insert(S(dis, cost, idx));
            }
        }
    }
}
void solve() {
    cin >> s;
    cin >> n >> m;
    f(i, m) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].push_back(vector<ll>{b, c, d});
        adj[b].push_back(vector<ll>{a, c, d});
    }
    get_valid(n - 1);
    f(i, n) valid[i]--;
    dij(0);
    ll res = LLONG_MAX;
    f(i, s + 1) {
        if (path[n - 1][i]) res = min(res, path[n - 1][i]);
    }
    cout << res;
}


int main()
{

    //freopen("SUMC.INP", "r" ,stdin); freopen("SUMC.OUT", "w", stdout);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    long long test = 1;

    //cin >> test;
    for (int i = 0; i < test; i += 1)
    {
        solve();
        //std::cout << "\n";
    }
    return 0;
}
