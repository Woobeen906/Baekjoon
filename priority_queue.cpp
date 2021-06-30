#include <iostream>
#include <queue>
using namespace std;


struct stu {
	string name;
	int id;
	double gpq;
};

bool operator<(stu a, stu b) {
	return a.gpq < b.gpq;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<stu,vector<stu> > pq;
	stu s1 = { "À±»ó",1,4.06 };
	stu s2 = { "¿ìºó",2,2.7 };
	stu s3 = { "±Ù¿µ",3,3.123 };
	pq.push(s1);
	pq.push(s2);
	pq.push(s3);

	for (int i = 0; i < 3; i++) {
		cout << pq.top().name<<" ";
		pq.pop();
	}
}