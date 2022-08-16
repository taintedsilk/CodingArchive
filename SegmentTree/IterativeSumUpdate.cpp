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
ll t[200002], lazy[200002];
ll n, h;

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void add(ll p, ll val)
{
    t[p] += val;
    if (p < n) lazy[p] += val;
}
void push(int p)
{
    for (int s = h; s > 0; --s)
    {
        int i = p>>s;
        if (!lazy[i])
        {
            add(i<<1, lazy[i] / 2);
            add(i<<1|1, lazy[i] / 2);
            lazy[i] = 0;
        }
    }
}

void build(int p)
{
    ll sum = 0;
    while (p > 1)
    {
        p >>= 1;
        t[p] = t[p<<1] + t[p<<1|1] + lazy[p];


    }
}
void range_update(ll l, ll r, ll val)
{
    l += n;
    r += n;
    ll l0 = l, r0 = r;
    ll cnt = 1;
    for (; l < r; l >>= 1, r >>= 1, cnt *= 2)
    {
        if (l&1) add(l++, val * cnt);

        if (r&1) add(--r, val * cnt);
    }
    build(l0);
    build(r0 - 1);
}
ll query(ll l, ll r)
{
    l += n;
    r += n;
    ll res = 0;
    push(l);
    push(r - 1);
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];

    }
    return res;
}
void solve()
{

    cin >> n;
    h = sizeof(int) * 8 - __builtin_clz(n);
    f(i, n) cin >> t[n + i];
    build();
}
int main()
{

    //freopen("SUMC.INP", "r" ,stdin); freopen("SUMC.OUT", "w", stdout);
    //std::ios_base::sync_with_stdio(0);
    //std::cin.tie(0);
    long long test = 1;

    //cin >> t;
    for (int i = 0; i < test; i += 1)
    {
        solve();
        std::cout << "\n";
    }
    return 0;
}
