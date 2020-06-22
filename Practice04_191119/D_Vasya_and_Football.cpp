#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
 
using i64 = long long;
 
int main() {
    string h, a;
    int n;
    vector<int> hs(100, 0);
    vector<int> as(100, 0); 
    
    cin >> h >> a >> n;
    
    for(int i = 0; i < n; i++){
        int time, player;
        char team, card;
        scanf("%d %c %d %c", &time, &team, &player, &card);
        
        if(team == 'a'){
            if(card == 'y'){
                if(as[player] == 1)
                    cout << a << " " << player << " " << time << endl;  
                as[player]++;
            }
            else {
                if(as[player] == 1 || as[player] == 0)
                    cout << a << " " << player << " " << time << endl;  
                as[player] += 2;
            }
        }
        else {
            if(card == 'y'){
                if(hs[player] == 1)
                    cout << h << " " << player << " " << time << endl;  
                hs[player]++;
            }
            else {
                if(hs[player] == 1 || hs[player] == 0)
                    cout << h << " " << player << " " << time << endl;  
                hs[player] += 2;
            }
        }
    }
    
    
    return 0;
}