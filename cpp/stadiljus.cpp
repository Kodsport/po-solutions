#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, x, y;
  cin >> n >> x >> y;

  vector<ll> lamps(n);
  rep(i, 0, n)
    cin >> lamps[i];

  sort(lamps.begin(), lamps.end());

  ll total = 0;
  ll count = 0;
  rep(i, 0, n) {
    ll new_total = total + x * lamps[i];
    // Nedan vill vi i vänsterledet beräkna ceil(new_total / (count + 1)), men
    // vi vill helst inte behöva jobba med icke-heltal. Därför gör vi ett litet
    // smart knep. I täljaren (new_total) adderar vi nämnaren - 1 (alltså
    // count + 1 - 1 = count). Divisionen av heltal (/) avrundar nedåt.
    // Tillsammans ger det vårt eftersökta värde utan att någonsin använda oss
    // av icke-heltal
    if ((new_total + count) / (count + 1) <= y) {
      total += x * lamps[i];
      count += 1;
    } else {
      break;
    }
  }

  cout << count;
}
