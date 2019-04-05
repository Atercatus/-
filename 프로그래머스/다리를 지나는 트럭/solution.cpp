#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int cur_weight = 0;
    int idx = 0; // #현재 트럭
    
    for(int i = 0; i < bridge_length; i++){
        q.push(0);
    }
    
    while(!q.empty()){
        // 1step
        cur_weight -= q.front();
        q.pop();
        
        if(idx < truck_weights.size()){
            // 최대 하중보다 작으면 적재
            int cur_truck = truck_weights[idx];
            if(cur_weight + cur_truck <= weight){
                q.push(cur_truck);
                cur_weight += cur_truck;
                idx++;
            }
            else{
                q.push(0);
            }
        }
        
        answer++;

    

        
    }
    
    return answer;
}