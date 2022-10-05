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
ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
void solve() {
    ll a, b, c, x, y;
    cin >> a >> b >> c;

    ll g = gcd(a, b, x, y);
    ll lcm = a * b / g;
    ll dif_a = lcm / a, dif_b = lcm / b;
    ll x0 = x * c / g, y0 = y * c / g;
    ll need = floor((db) x0 / dif_a);
    x0 -= need * dif_a;
    y0 += need * dif_b;
    while (x0 <= 0) {
        x0 += dif_a;
        y0 -= dif_b;
    }
    cout << ceil((db)y0 / dif_b);
    

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
