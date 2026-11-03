#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, k, h;
  cin >> n >> k >> h;

  vector<ll> dist_m(n);
  rep(i, 0, n)
    cin >> dist_m[i];

  ll p = 0;
  for (ll i = n - 1; i >= 0; i--) { // Gå igenom listan baklänges
    ll extra_dist = max(dist_m[i] * h - p * (k - 1), (ll)0);
    // Här adderar vi täljaren med nämnaren - 1 för att göra om floor (/) till
    // ceil. Alltså avrunda uppåt istället för nedåt.
    p += (extra_dist + k - 1) / k;
  }

  cout << p << endl;
}
