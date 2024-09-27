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

  ll n, x, y;
  cin >> n >> x >> y;

  vector<ll> lamps(n);
  for (ll i = 0; i < n; i++)
    cin >> lamps[i];

  sort(lamps.begin(), lamps.end());

  ll total = 0;
  ll count = 0;
  for (ll i = 0; i < n; i++) {
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
    } else
      break;
  }

  cout << count;

  return 0;
}
