#include <string>
#include <vector>

using namespace std;
int answer = 0;
vector<int> arr;
void nQueen(int col,int n);
int solution(int n) {
    for(int i =0;i<n;i++){
        arr.push_back(0);
    }
    for(int i = 0;i<n;i++){
        arr[0] = i;
        nQueen(1,n);
    }
    return answer;
}

void nQueen(int col,int n){
    if(col==n){
        answer++;
        return;
    }
    for(int i = 0;i<n;i++){
        int check = true;
        for(int j = 0;j<col;j++){
            arr[col] = i;
            if(arr[j]==arr[col]||((j-col)==(arr[j]-arr[col]))||((j-col)==(arr[col]-arr[j]))){
                check = false;
                break;
            }
        }
        if(check){
            nQueen(col+1,n);
        }
    }
}
