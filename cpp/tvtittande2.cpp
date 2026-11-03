#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, k;
  cin >> n >> k;

  vector<ll> lens(k);
  rep(i, 0, k) cin >> lens[i];

  vector<pair<ll, ll>> timestamps;
  ll acc = 0;
  rep(i, 0, n) {
    ll d, c;
    cin >> d >> c;
    vector<ll> movies(c);
    rep(i, 0, c) {
      ll movie;
      cin >> movie;

      // Notera att lens är 0-indexerad medan movie är 1-indexerad
      acc += lens[movie - 1];

      // När vi har sett en film behöver vi inte se den igen
      lens[movie - 1] = 0;
    };

    timestamps.emplace_back(d, acc);
  }

  ll last_party = 0, watch_time = 0;
  for (auto party : timestamps) {
    ll day, stamp;
    tie(day, stamp) = party;

    watch_time += 10 * (day - last_party);
    if (watch_time < stamp) {
      cout << "Nej" << endl;
      return 0;
    }

    // Bob kan inte titta på film när han är på kalas
    last_party = day + 1;
  }

  cout << "Ja" << endl;
}
