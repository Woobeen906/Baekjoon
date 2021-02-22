#include <iostream>
using namespace std;

int main() {
	int L, P, V, i = 1;

	while (true)
	{
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)break;
		int sum = 0;

		sum = (V / P)* L;
		if ((V % P) <= L)sum += (V % P);
		else if((V%P)>L)sum += L;
	
		cout << "Case " << i << ": " << sum << "\n";
		i++;
	}

	return 0;
}