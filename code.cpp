#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define int            long long
#define ul             unsigned long long
#define ld             long double
const int mod =        1e9 + 7;
const int MM =         998244353;
const int inf =        LLONG_MAX;
const int dif =        LLONG_MIN;
#define vt             vector
#define vi             vector<int>
#define vb             vector<bool>
#define vs             vector<string>
#define pii            pair<int, int>
#define pq_max         priority_queue<int>
#define pq_min         priority_queue<int, vi, greater<int>>
#define ump            unordered_map
#define us             unordered_set
#define ff             first
#define ss             second
#define pb             push_back
#define pf             push_front
#define pbb            pop_back
#define pff            pop_front
#define loop(i, a, b)  for(int i = a; i < b; ++i)
#define rev(i, a, b)   for(int i = a; i >= b; --i)
#define uniq(v)        sort(all(v)); (v).erase(unique(all(v)),(v).end())
#define bs(v,a)        binary_search(all(v), a)
#define uprb(v,a)      upper_bound(v.begin(), v.end(), a)
#define lowb(v,a)      lower_bound(v.begin(), v.end(), a)
#define mx(v)          *max_element(all(v))
#define mn(v)          *min_element(all(v))
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define sz(x)          (int)((x).size())
#define ps(x, y)       fixed << setprecision(y) << x
#define range(a, b)    substr(a, b - a + 1)
#define out(x)         cout << x << '\n';
#define log(x)         cout << #x << " : " << x << " " << '\n';
#define LOG(x)         for(auto& i : x) cout << i << " "; cout << '\n';
#define graph(adj, e)  loop(i, 0, e) { int u, v; cin >> u >> v; adj[u].pb(v); adj[v].pb(u); }
#define lcm(a,b)       ((a)*(b)) / __gcd((a),(b))
#define setbits(n)     __builtin_popcountll(n)
#define zerobits(n)    __builtin_ctzll(n)
#define countbits(n)   (int)log2(n) + 1
static mt19937         rng(chrono::steady_clock::now().time_since_epoch().count());

/*------------------------------------------------------------------------------------------------------*/

template<typename A> ostream& operator<<(ostream &cout, vt<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << p.ff << " " << p.ss; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    loop(i, 0, sz(v)) {cout << v[i] << " ";} return cout << "\n";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first;
    return cin >> p.second;
}
template<typename A> istream& operator>>(istream& cin, vt<A> &v) {
    for (auto &x : v)
        cin >> x;
    return cin;
}

/* Template reference from "tourist" */
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vb v) { bool first = true; string res = "{"; for (int i = 0; i < static_cast<int>(v.size()); ++i) { if (!first) { res += ", "; } first = false; res += to_string(v[i]); } res += "}"; return res; }
template <size_t N>
string to_string(bitset<N> v) { string res = ""; for (size_t i = 0; i < N; ++i) { res += static_cast<char>('0' + v[i]); } return res; }
template <typename A>
string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
void dbg_out() { cout << "\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cout << " " << to_string(H); dbg_out(T...); }
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)

/*------------------------------------------------------------------------------------------------------*/

/**
 * 1) Read Properly (Dry run the question with sample cases too)
 * 2) Thinking Phase (Don't just get stuck with one approach)
 * 3) Formulation Phase (Think well before you code)
 * 4) Coding
 * 5) Debugging
 *
 * */

void solve() {

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tc = 1;
    cin >> tc;

    while (tc--)
        solve();
}
