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

string stycket;
set<ll> keys;
map<char, ll> keyboard;

ll rec() {
  if (keyboard.size() == keys.size()) {
    char prev = stycket[0];
    ll dist = 0;
    for (char key : stycket) {
      dist += abs(keyboard[prev] - keyboard[key]);
      prev = key;
    }
    return dist;
  }

  ll ans = 1e7;
  for (char key : stycket) {
    if (0 < keyboard.count(key))
      continue;

    keyboard.insert({key, keyboard.size()});
    ans = min(ans, rec());
    keyboard.erase(key);
  }

  return ans;
}

int main() {
  fast();

  // TODO: Why slow?

  cin >> stycket;
  for (char c : stycket) {
    keys.insert(c);
  }

  cout << rec() << endl;

  return 0;
}
