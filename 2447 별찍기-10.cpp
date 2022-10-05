//
//  2447 별찍기-10.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/10/05.
//

#include <iostream>
using namespace std;
int N;

void star(int i, int j, int N)
{
    if((i / N)%3 == 1 && (j / N)%3 == 1) {
        cout << " ";
    }
    else
    {
        if(N / 3 == 0)
            cout <<"*";
        else
            star(i,j,N/3);
    }
}
int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            star(i,j,N);
        cout << "\n";
    }
}
