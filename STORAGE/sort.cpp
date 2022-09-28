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
typedef vector<ll> llv;

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
//#define ordered_set tree<pair<ll, ll>, null_type,less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
ll a1[100000];
ll a2[100000];
ll st[200000];

ll next_idx[100000];
ll n;
void build() {
    f(i, n) {
        st[i + n] = a1[i];
    }
    fd(i, n - 1, 1) {
        st[i] = min(st[i << 1], st[i << 1 | 1]);
    }
}
ll query(ll l, ll r) {
    ll res = LLONG_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, st[l++]);
        if (r & 1) res = min(res, st[--r]);
    }
    return res;
}
void update(ll i, ll val) {
    for (st[i += n] = val; i > 1; i >>= 1) st[i>>1] =min(st[i], st[i ^ 1]);
}
void solve() {
    cin >> n;
    fill(next_idx, next_idx + n, 0);
    f(i, n) cin >> a1[i];
    f(i, n) cin >> a2[i];

    build();
    ll i = 0, j = 0;
    gp_hash_table<ll, ll>last;
    fd(i, n - 1, 0) {
        if (last.find(a2[i]) != last.end()) {
            next_idx[i] = last[a2[i]];
        }
        last[a1[i]] = i;
    }
    while (j < n) {
        if (a1[i] == a2[j]) {
            i++;
            while (i < n && st[i + n] == LLONG_MAX) i++;
            j++;
        }
        else if (next_idx[j]) {
            if (query(i, next_idx[j] + 1) == a2[j]) {
                update(next_idx[j], LLONG_MAX);
                next_idx[j] = next_idx[next_idx[j]];
                j++;
            }
            else {
                cout << "NO" << "\n";
                return;
            }

        }
        else {

            cout << "NO" << "\n";
            return;
        }

    }
    cout << "YES" << "\n";

}
int main()
{
    //freopen("CPRDIV.INP", "r" ,stdin); freopen("CPRDIV.OUT", "w", stdout);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    long long test = 1;

    cin >> test;
    for (int i = 0; i < test; i += 1)
    {
        solve();
    }
    return 0;
}
