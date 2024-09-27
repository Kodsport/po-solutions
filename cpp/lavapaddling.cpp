#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define sz(container) ((int)container.size())
#define all(x) begin(x), end(x)

void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

int main() {
  fast();

  ll n, k, h;
  cin >> n >> k >> h;

  vector<ll> dist_m(n);
  for (ll i = 0; i < n; i++)
    cin >> dist_m[i];

  ll p = 0;
  for (ll i = n - 1; i >= 0; i--) { // Gå igenom listan baklänges
    ll extra_dist = max(dist_m[i] * h - p * (k - 1), (ll)0);
    // Här adderar vi täljaren med nämnaren - 1 för att göra om floor (/) till
    // ceil. Alltså avrunda uppåt istället för nedåt.
    p += (extra_dist + k - 1) / k;
  }

  cout << p << endl;

  return 0;
}
