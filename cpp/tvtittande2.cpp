#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define per(i, high) for (int i = high - 1; i >= 0; i--)
#define perr(i, high, low) for (int i = high - 1, i >= low; i++)
#define sz(container) ((int)container.size())
#define all(x) begin(x), end(x)

void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

int main() {
  fast();

  ll n, k;
  cin >> n >> k;

  vector<ll> lens(k);
  rep(i, k) cin >> lens[i];

  vector<pair<ll, ll>> timestamps;
  ll acc = 0;
  rep(i, n) {
    ll d, c;
    cin >> d >> c;
    vector<ll> movies(c);
    rep(i, c) {
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

  return 0;
}
