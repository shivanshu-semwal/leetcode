#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define reverseall(x) reverse(all(x))
#define to_upper(x) transform(x.begin(), x.end(), x.begin(), ::toupper)
#define to_lower(x) transform(x.begin(), x.end(), x.begin(), ::tolower)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define repn(i, n) for (int i = 0; i < (n); ++i)
#define send \
  { ios_base::sync_with_stdio(false); }
#define help        \
  {                 \
    cin.tie(NULL);  \
    cout.tie(NULL); \
  }
#define clr(x) memset(x, 0, sizeof(x))
#define middle(x) ceil2(x, 2) - 1
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef priority_queue<int, vi, greater<int>> minpq;
typedef priority_queue<ll, vl, greater<ll>> minpql;

// DEBUG
void print(const int& x) { cout << x; }
void print(const long& x) { cout << x; }
void print(const long long& x) { cout << x; }
void print(const unsigned& x) { cout << x; }
void print(const unsigned long& x) { cout << x; }
void print(const unsigned long long& x) { cout << x; }
void print(const float& x) { cout << x; }
void print(const double& x) { cout << x; }
void print(const long double& x) { cout << x; }
void print(const char& x) { cout << '\'' << x << '\''; }
void print(const bool& x) { cout << (x ? "true" : "false"); }
void print(const char* x) { cout << '\"' << x << '\"'; }
void print(const string& x) { cout << '\"' << x << '\"'; }

template <typename T, typename V>
void print(const pair<T, V>& x);
template <typename T>
void print(const vector<T>& x);
template <typename T>
void print(const T& x);

template <typename T, typename V>
void print(const pair<T, V>& x) {
  cout << '{';
  print(x.first);
  cout << ',';
  print(x.second);
  cout << "}";
}
template <typename T, typename V, typename U>
void print(const tuple<T, V, U>& x) {
  cout << '{';
  print(get<0>(x));
  cout << ',';
  print(get<1>(x));
  cout << ',';
  print(get<2>(x));
  cout << "}";
}
template <typename T>
void print(const vector<T>& x) {
  cout << "{";
  for (int i = 0; i < x.size(); i++) {
    print(x[i]);
    cout << (i + 1 == x.size() ? "" : ",");
  };
  cout << "}";
}
template <typename T>
void print(const T& x) {
  int f = 0;
  cout << '{';
  for (auto& i : x) cout << (f++ ? "," : ""), print(i);
  cout << "}";
}
void dprint() { cout << "]\n"; }
template <typename T, typename... V>
void dprint(T t, V... v) {
  print(t);
  if (sizeof...(v)) cout << ", ";
  dprint(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)             \
  cout << "[" << #x << "] = ["; \
  dprint(x)
#else
#define debug(x...)
#endif
//
const int mod = 1000000007;
const double eps = 1e-14;
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
inline ll ceil2(ll a, ll b) { return (a + b - 1) / b; } // BE CAREFUL FOR NEGATIVES
ll mpow(ll b, ll e, int modu = 0, int mod = 1000000007) {
  ll result = 1, base = b, exp = e;
  if (modu) base %= mod;
  while (exp > 0) {
    if (exp & 1) {
      result = result * base;
      if (modu) result %= mod;
    }
    base = base * base;
    if (modu) base %= mod;
    exp >>= 1;
  }
  return result;
}

ll accurateFloor(ll a, ll b) {
  ll val = a / b;
  while (val * b > a)
    val--;
  return val;
}

inline bool isPowerOfTwo(ll x) { return x && (!(x & (x - 1))); }
bool isPerfectSquare(ll x) {
  ll sr = sqrt(x);
  return ((sr * sr) == x);
}
bool isIn(string& s2, string& s1) {
  if (s1.find(s2) != string::npos) return true;
  return false;
}
bool isSorted(vi& arr) {
  for (int i = 0; i < (int)arr.size() - 1; i++)
    if (arr[i] > arr[i + 1]) return false;
  return true;
}

int TEST_CASES = 1;
void submain() {
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  send help
      // Preprocessing space
      cout.precision(12);
  int t = 1;
  if (TEST_CASES) {
    cin >> t;
  }

  while (t--) {
    submain();
  }
  return 0;
}
