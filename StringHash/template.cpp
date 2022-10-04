#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

typedef long long ll;
typedef bool bl;
typedef string str;
typedef unsigned long long ull;
typedef double db;

#define fi first
#define se second
#define mp(p1, p2) make_pair(p1, p2)
#define f(i, n) for (ll i = 0; i < n; i += 1)
#define fu(i, start, end) for (int i = start; i < end; i += 1)
#define fd(i, start, end) for (int i = start; i >= end; i -= 1)
#define BIT(var, pos) ((bool)((var) & (1 << (pos))))
#define pb push_back
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>

#define MOD 1000000007
ll n;
str a, b;

struct StringHash
{
private:
    static const ll p = 33;
    static const ll m = MOD;

    static vector<ll> pow;
    vector<ll> str_hash;

public:
    StringHash(const str &a) : str_hash(a.size() + 1)
    {
        while (pow.size() < a.size())
            pow.push_back((pow.back() * p) % m);

        str_hash[0] = 0;
        f(i, a.size())
        {
            str_hash[i + 1] = ((str_hash[i] * p) % m + a[i]) % m;
        }
    }
    ll get_val(ll l, ll r)
    {
        ll val = str_hash[r + 1] - str_hash[l] * pow[r - l + 1];
        return (val % m + m) % m;
    }
};
vector<ll> StringHash::pow = {1};

void solve() {
    
}
int main()
{
    // freopen("pushing.INP", "r" ,stdin); freopen("pushing.OUT", "w", stdout);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    long long test = 1;

    // cin >> test;
    for (int i = 0; i < test; i += 1)
    {
        solve();
    }
    return 0;
}
