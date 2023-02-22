#include <bits/stdc++.h>
using namespace std;

// Info on each valve
struct info{
    int flow;
    vector<int> tunnels;
    bool open;
    info(){
        flow = 0;
        open = false;
    }
};

// Valve operations and traveling through
int turning(vector<info>& valves, int curr_valve, int remaining_time){
    int max_pressure_released = 0;
    valves[curr_valve].open = true;
    for (auto tunnel : valves[curr_valve].tunnels){
        if (!valves[tunnel].open){
            int time_to_reach = 1 + turning(valves, tunnel, remaining_time - 1);
            int pressure_released = min(valves[curr_valve].flow * (remaining_time - time_to_reach), valves[tunnel].flow * time_to_reach);
            max_pressure_released = max(max_pressure_released, pressure_released);
        }
    }
    valves[curr_valve].open = false;
    return max_pressure_released;
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        vector<info> valves(n);
        
for (int i = 0; i < n; i++){
            char label;
            int flow, num_tunnels;
            cin >> label >> flow >> num_tunnels;
            valves[label - 'A'].flow = flow;
            while (num_tunnels--){
                char tunnel_label;
                cin >> tunnel_label;
                valves[label - 'A'].tunnels.push_back(tunnel_label - 'A');
            }
        }

        int max_pressure_released = 0;
        for (int i = 0; i < n; i++){
            if (valves[i].flow > 0){
                max_pressure_released = max(max_pressure_released, turning(valves, i, 30));
            }
        }
        cout << max_pressure_released;
    }
}
