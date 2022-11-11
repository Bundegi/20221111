#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
using namespace std;
string a, b;
int flag;
//17609 회문문제 회문문제를 처음봐서 꽤 오래 거렸지만 풀기는 풀었따.
int Palin(int start, int end, string Dan) {
	while (start < end) {
		if (Dan[start] != Dan[end]) {
			if (flag--) {
				a = Dan;
				b = Dan;
				a.erase(a.begin() + start);
				b.erase(b.begin() + end);
			}
			return 1;
		}
		start++;
		end--;
	}
	return 0;
}
int main() {
	fast;
	int T;
	cin >> T;
	string Dan;
	while (T--) {
		cin >> Dan;
		flag = 1;
		if (Palin(0, Dan.size() - 1, Dan)) {
			int index = Palin(0, a.size() - 1, a);
			int index1 = Palin(0, b.size() - 1, b);
			if (index == 0 || index1 == 0) cout << 1 << endl;
			else cout << 2 << endl;
		}
		else cout << 0 << endl;
	}
}
