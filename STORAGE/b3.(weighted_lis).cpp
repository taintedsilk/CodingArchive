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

ll arr[100000];
ll weight[100000];
void solve()
{
    ll n;
    cin >> n;
    f(i, n)
        cin >> arr[i];
    f(i, n)
        cin >> weight[i];
    set<vector<ll>>s;
    f(i, n)
    {
        auto it = s.lower_bound(llv{arr[i], LLONG_MAX, LLONG_MAX});
        ll val = 0;
        if (it == s.begin())
        {
            val = weight[i];
            s.insert(llv{arr[i], weight[i], 1});
        }
        else
        {
            it = prev(it);
            val = (*it)[1] + weight[i];
            s.insert(llv{arr[i], (*it)[1] + weight[i], (*it)[2] + 1});
            it++;
            it++;

        }
        while (it != s.end())
        {

            if ((*it)[1] < val) it = s.erase(it);
            else break;
        }
    }
    cout << (*prev(s.end()))[2] << "\n";
}
int main()
{

    //freopen("pushing.INP", "r" ,stdin); freopen("pushing.OUT", "w", stdout);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    long long test = 1;

    //cin >> test;
    for (int i = 0; i < test; i += 1)
    {
        solve();
    }
    return 0;
}
