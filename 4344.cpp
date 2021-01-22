/*
   백준 4344번 평균은 넘겠지 문제
   첫째 줄에 테스트케이스가 주어진다
   둘째 줄부터 각 테스트케이스마다 학생 수가 첫 수로 주어지고
   이어서 학생들의 점수가 주어진다 (점수는 0이상 100이하)
   각 케이스 마다 한 줄씩 평균을 넘는 학생들의 비율을 
   반올림하여 소수점 셋째 자리까지 출력
*/
#include <iostream>
using namespace std;
int stu[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        double n;//학생 수
        cin >> n;
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            cin >>stu[j];
            sum += stu[j];
        }

        double ave = sum / n;
        int cnt = 0;

        for (int k = 1; k <= n; k++) {
            if (stu[k] > ave) {
                cnt++;
                
            }
        }
        cout.setf(ios::fixed);
        cout.precision(3);
        double result = cnt * 100 / n;
        cout << result<<"%\n";
    }
}