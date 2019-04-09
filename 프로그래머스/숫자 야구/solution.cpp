#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    for(int i = 123; i < 988; i++){
        int j = 0;
        for(j = 0; j < baseball.size(); j++){
            string prediction = to_string(baseball[j][0]);
            string num = to_string(i);
            
            if(num[0] == '0' || num[1] == '0' || num[2] == '0'
              || num[0] == num[1] || num[1] == num[2] || num[2] == num[0])
                break;
            
            int strike = 0;
            int ball = 0;
            for(int k = 0; k < 3; k++){
                // check strike
                if(num[k] == prediction[k]){
                    strike++;
                }
                for(int l = 1; l < 3; l++){
                    if(num[k] == prediction[(k + l) % 3]){
                        ball++;
                    }
                }
            }
            
            if(strike != baseball[j][1] || ball != baseball[j][2])
                break;
        }
        if(j == baseball.size()){
            answer++;
        }
    }
    
    return answer;
}