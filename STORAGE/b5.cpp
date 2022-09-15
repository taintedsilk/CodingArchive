#include <bits/stdc++.h>

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
#define BIT(var,pos) ((bool) ((var) & (1<<(pos))))
#define pb push_back
//#define ordered_set tree<pair<ll, ll>, null_type,less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
ll n, m;
vector<ll>adj[100000];
ll layer[100000], low[100000];
ll id[100000];
ll cnt;
stack<ll>s;
void dfs(ll i, ll parent) {
    layer[i] = low[i] = layer[parent]++;
    s.push(i);
    for (auto val : adj[i]) {
        if (!layer[val]) {
            dfs(val, i);
            low[i] = min(low[i], low[val]);
        }
        else if (val != parent && layer[val] < layer[i]) {
            while (s.top() != val) {
                id[s.top()] = cnt;
                s.pop();
            }
            cnt++;
            low[i] = min(low[i], layer[val]);
        }
    }
    if (low[i] == layer[i]) id[i] = 
    s.pop();

}
void solve() {
    cin >> n >> m;
    cnt = n + 1;
    ll a, b;
    f(i, m) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0);
    f(i, n) {
        cout << id[i] << " ";
    }
}



int main()
{

    //freopen("pushing.INP", "r" ,stdin); freopen("pushing.OUT", "w", stdout);
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
