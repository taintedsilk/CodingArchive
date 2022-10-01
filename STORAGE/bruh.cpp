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

// unordered_set<double, custom_hash>s;
#define MOD 1000000007

typedef long long ll;
typedef bool bl;
typedef string str;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<ll> vl;

#define fi first
#define se second
#define mp(p1, p2) make_pair(p1, p2)
#define f(i, n) for (ll i = 0; i < n; i += 1)
#define fu(i, start, end) for (int i = start; i < end; i += 1)
#define fd(i, start, end) for (int i = start; i >= end; i -= 1)
#define FOR(i, start, end, inc) for (int i = start; i != end; i += inc)
#define BIT(var, pos) ((bool)((var) & (1 << (pos))))
//#define ordered_set tree<pair<ll, ll>, null_type,less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXN 100
ll prime[1000001];
ll sum[1000001];
ll cnt[1000001];
vector<ll>primes;
void fast_sieve(ll n) {
    fu(i,2, n + 1) {
        if (!prime[i]) {primes.push_back(i); prime[i] = i;}
        for (int j = 0; primes[j] * i <= n && j < primes.size(); j++) {
            prime[primes[j] * i] = primes[j];
            if (!(i % primes[j])) break;
        }
    }
}
void solve()
{
    ll a, b;
    cin >> a >> b;
    cout << cnt[b] - cnt[a - 1] << " " << sum[b] - sum[a - 1] << "\n";
     

    
}
int main()
{
    fast_sieve(1e6);
    fu(i,2, 1e6 + 1) {
        ll temp = i;
        gp_hash_table<ll, ll, qhash>M;
        while (temp > 1) {
            M[prime[temp]]++;
            temp /= prime[temp];    
        }
        sum[i] = 1;
        for (aut )) {
            sum[i] *= (pow(v[j].fi, v[j].se + 1) / (v[j].fi - 1));
        }
        cnt[i] = 1;
        f(j, v.size()) {
            cnt[j] *= (v[j].se + 1);
        }

    }
    cout << cnt[100] << " " << sum[100] << "\n";
    cnt[1] = sum[1] = 1;
    fu(i, 1, 1000001) cnt[i] += cnt[i - 1], sum[i] += sum[i - 1];
    //freopen("test.INP", "r", stdin);
    //freopen("test.OUT", "w", stdout);
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
