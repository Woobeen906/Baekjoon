/*
   ���� 10814 ���̼� ���� ����
   ���̿� �̸��� �ԷµǾ����� ��
   ���� ������ �����Ѵ�.
   ��, ���̰� ���� ��� �̸��� ���̰� �Էµ� ������� �����Ѵ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<pair<int, string>> v;  //stl (Stable_sort �� �̿��� ���)
//bool compare(pair<int,string>a,pair<int,string>b) {
//    if (a.first < b.first) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    int n; //ȸ�� ��
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        int age;
//        string name;
//        cin >> age >> name;
//        v.push_back(make_pair(age, name));
//    }
//    stable_sort(v.begin(), v.end(),compare);
//
//    for (int i = 0; i < n; i++) {
//        cout << v[i].first << " " << v[i].second << "\n";
//    }
//}

typedef struct com { //����ü�� ������ �־� �̸��� �Էµ� ������ �����ϴ� ���
    int age;
    string name;
    int cnt;
}com;

bool compare(const com& a, const com& b) {
    if (a.age == b.age) {
        return a.cnt < b.cnt;
    }
    else {
        return a.age < b.age;
    }
}
vector<com> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
        cin >> n;
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        v.push_back({ age,name,i });
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++) {
        cout << v[i].age << " " << v[i].name << "\n";
    }

}