/*
   백준 10814 나이순 정렬 문제
   나이와 이름이 입력되어있을 때
   나이 순서로 정렬한다.
   단, 나이가 같은 경우 이름과 나이가 입력된 순서대로 정렬한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<pair<int, string>> v;  //stl (Stable_sort 를 이용한 방법)
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
//    int n; //회원 수
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

typedef struct com { //구조체에 순서를 넣어 이름이 입력된 순서를 저장하는 방법
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