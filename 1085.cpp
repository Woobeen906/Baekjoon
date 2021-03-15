#include <iostream>
using namespace std;
int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	w -= x; h -= y;
	x = x >= w ? w : x;
	y = y >= h ? h : y;
	cout << (x >= y ? y : x);
}