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

#define MAXN 21
ll n, m;
str arr[50];
ll steps[50][50];
bl check[50][50] = {0};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
bl inside(ll x, ll y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
struct S
{
    ll step;
    ll dir;
    ll x;
    ll y;

    S(ll n1, ll n2, ll n3, ll n4) : step(n1),x(n2), y(n3), dir(n4)
    {
    }

    bool operator<(const struct S& other) const
    {
        //Your priority logic goes here
        return step < other.step;
    }
};
ll get_value(ll dir1, ll dir2) {
    if (dir1 == dir2) return 0;
    else if (dir1 == (3 - dir2)) return 2;
    else return 1;
}
void bfs(pair<ll, ll>START) {
    priority_queue<S>q;
    q.push(S(0, START.fi, START.se, 0));
    steps[START.fi][START.se] = 1;
    while(q.size()) {
        S cur = q.top();
        q.pop();
        f(i, 4) {
            ll x = cur.x + dx[i], y = cur.y + dy[i];
            if (inside(x, y) && !steps[x][y] && arr[x][y] != '#') {
                steps[x][y] = steps[cur.x][cur.y] + 1 + get_value(cur.dir, i);
                q.push(S(steps[x][y], x, y, i));
            }
        }
    }
}
bl extra = 1;
void dfs(ll i, ll j) {
    if (!extra || check[i][j]) return;
    else {
        vector<pair<ll, ll>>v;
        f(k, 4) {
            ll x = i+ dx[k], y = j + dy[k];
            if (inside(x, y) && steps[x][y] && steps[x][y] < steps[i][j]) {
                v.push_back({x, y});
            }
        }
        if (v.size() >= 2) extra = 0;
        else {
            f(i, v.size()) {
                dfs(v[i].fi, v[i].se);
            }

        }
    }
}
/*
ll dfs(ll i, ll j) {
    if (check[i][j]) return LLONG_MAX;
    check[i][j] = 1;
    ll res = path[i][j];
    f(i, 4) {
        ll x = cur.fi + dx[i], y = cur.se + dy[i];
        if (inside(x, y) && !check[i][j] && arr[i][j] == '1') res = min(res,
                                                                        dfs(x, y));
    }
    return res;
}
*/
void solve() {
    cin >> n >> m;
    ll s, e;
    cin >> s >> e;
    f(i, n) cin >> arr[i];
    pair<ll, ll> E;
    f(i, n) {
        f(j, m) {
            if (arr[i][j] == 'S') bfs({i, j});
        }
    }

    f(i, n) {
        f(j, m) {
            if (arr[i][j] == 'T') dfs(i, j)
        }
    }
    ll current = steps[E.fi][E.se];
    ll res = steps[E.fi][E.se];
    while (current % 5 != (e - s) % 5) {
        current += 2;
        res += 6 + extra;

    }
    cout << res;

}
int main()
{

    //freopen("pushing.INP", "r" ,stdin); freopen("pushing.OUT", "w", stdout);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    long long test = 1;

    //cin >> t;
    for (int i = 0; i < test; i += 1)
    {
        solve();
    }
    return 0;
}
