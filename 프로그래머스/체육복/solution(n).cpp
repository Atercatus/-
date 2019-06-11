#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> arr(n);
    fill(arr.begin(), arr.end(), 1);
    
    for(int i = 0; i < reserve.size(); i++){
        arr[reserve[i] - 1]++;
    }
    
    for(int i = 0; i < lost.size(); i++){
        arr[lost[i] - 1]--;
    }
    
    for(int i = 0; i < arr.size(); i++){
        int prev = i - 1;
        int next = i + 1;
        
        if(arr[i] <= 1) continue;
        
        if(prev >= 0 && arr[prev] == 0){
            arr[i]--;
            arr[prev]++;
        } 
        else if(next < arr.size() && arr[next] == 0){
            arr[i]--;
            arr[next]++;
        }
    }
        
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0)
            answer++;
    }
    
    return answer;
}