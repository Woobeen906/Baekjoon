#include <iostream>
#include <cmath>

using namespace std;
int n,r,c,result;

void solve(int row,int col,int len){
    if(row==r&&col==c){
        cout<<result<<"\n";
        return;
    }
    if(r<row+len&&r>=row&&c<col+len&&c>=col){
        len/=2;
        solve(row,col,len);
        solve(row, col+len, len);
        solve(row+len,col,len);
        solve(row+len,col+len,len);
    }else{
        result+=len*len;
    }
}

int main(){
    cin>>n>>r>>c;
    n=pow(2,n);
    solve(0, 0, n);
}

