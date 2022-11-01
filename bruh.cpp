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
#define fv(i, v) for (typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define fu(i, start, end) for (int i = start; i < end; i += 1)
#define fd(i, start, end) for (int i = start; i >= end; i -= 1)
#define BIT(var, pos) ((bool)((var) & (1 << (pos))))
#define pb push_back
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>

#define MOD 1000000007
ll even[10];
void solve()
{
    str a;
    cin >> a;
    f(i, a.size()) a[i] -= '0';
    if (a.size() % 2 == 0)
    {
        bl special = 0;
        if (a[0] == 1)
        {
            special = 1;
            fu(i, 1, a.size())
            {
                if (a[i] != 0)
                {
                    special = 0;
                    break;
                }
            }
        }
       
        if (!special)
        {
            
            fd(i, a.size() - 1, 0)
            {
                if (a[i] != 0)
                {
                    a[i]--;
                    fu(j, i + 1, a.size())
                    {
                        a[j] = 9;
                    }
                    break;
                }
            }
            
            f(i, a.size()) even[a[i]] = 1 - even[a[i]];
            special = 1;
            f(i, 10)
            {
                if (even[i])
                    special = 0;
            }
            if (special)
            {
                f(i, a.size()) cout << (int)a[i];
                return;
            }
            fd(i, a.size() - 1, 0)
            {
                even[a[i]] = 1 - even[a[i]];
                set<ll>v;
                f(j, 10) if (even[j]) v.insert(j);
                if (v.size()) { 
                    vector<ll>res;
                       f(j, i) res.push_back((int)a[j]);
                    while (v.size()) {
                        auto it = v.lower_bound(a[i]);
                        if (it == v.begin()) break;
                        else {
                            it = prev(it);
                            res.push_back(*it);
                            v.erase(it);
                        }
                    }
                    if (!v.size()) {
                        for (auto val : res) cout << val;
                        f(i, a.size() - res.size()) cout << 9;
                        return;
                    }                    
                }
                else {
                    bl yay = 1;
                    fu(j, i + 1, a.size()) if (a[j] < a[i]) 
                        yay = 0;
                    if (yay) {
                        
                    }   
                    else {

                    }                
                    
                }
            }
            cout << (int)--a[0];
            f(i, a.size() - 2) cout << 9;
            cout << (int)a[0];

            
        }
        else {
            f(i, a.size() - 2) cout << 9;
        }
    }
    else {
        f(i, a.size() - 1) cout << 9;
    }
}

int main()
{

    // freopen("pushing.INP", "r" ,stdin); freopen("pushing.OUT", "w", stdout);
    // std::ios_base::sync_with_stdio(0);
    // std::cin.tie(0);
    long long test = 1;

    cin >> test;
    for (int i = 0; i < test; i += 1)
    {
        solve();
        cout << "\n";
    }
    return 0;
}
