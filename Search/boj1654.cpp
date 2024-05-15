#include<iostream>
#include<vector>
using namespace std;

// 랜선자르기
// binary search

int K, N;
long long longest, range;
vector<long long> lines ;
void binarySearch(long long left, long long right);
int main(){

    cin >> K >> N;
    lines = vector<long long>(K, 0);
    
    for(int i =0; i < K; i++){
        cin >> lines[i];
        // cout << "line[i] : " << lines[i] <<"\n";
        range = max(range, lines[i]);
    }
    // 가능한 랜선의 길이 1 ~ 제일 긴 랜선
    // 탐색 시작 값 : (1+max)/2
    longest = 0;
    binarySearch(1, range);
    cout << longest;
    return 0;
}

void binarySearch(long long left, long long right){
     // 이 값으로 처리가능한지 확인
    long long mid = (left + right)/2;
    if(left > right) return;
    long long count = 0;
    for(int i = 0; i < K ; i++){
        count += lines[i]/mid;
    }
    // 만들기 가능한경우 => 더 큰 값으로 확인
    if(count >= N){
        longest = max(longest, mid);
        // mid = (mid + right) / 2; 
        left = mid+1;
    }else{ // 못만드는 경우
        // mid = (left + mid) / 2;
        right = mid-1;
    }
    binarySearch(left, right);
}

