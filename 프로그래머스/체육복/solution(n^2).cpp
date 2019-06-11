#include <string>
#include <vector>

using namespace std;

int lower_bound(vector<int> &a, int b){
    int start = 0;
    int end = a.size() - 1;
    int mid = 0;
    
    while(start < end){
        mid = (start + end) / 2;
        if(a[mid] < b){
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    
    return mid;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int borrow = 0;
    
    // 중복 제거
    for(int i = 0; i < lost.size(); i++){
        int bound = lower_bound(reserve, lost[i]);
        if(lost[i] == reserve[bound]){
            lost.erase(lost.begin() + i);
            reserve.erase(reserve.begin() + bound);
        }
    }
    
    
    for(int i = 0; i < lost.size(); i++){
        for(int j = 0; j < reserve.size(); j++){
            if(abs(lost[i] - reserve[j]) <= 1){
                borrow++;
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }
    
    return n - (lost.size() - borrow);
}