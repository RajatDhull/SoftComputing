#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(long long i=a; i<n; i++)
#define ll long long int
#define pb push_back
#define vi vector<long long>
#define pi pair<long long, long long>
const int mod = 1e9 + 7;

void view(vector<vi> &arr){
    rep(i, 0, 3){
        rep(j, 0, 3){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"------------------------------------------------------------------";
    cout<<"\n";
}

int heuristic(vector<vi> &state, vector<vi> &final){
    int c = 0;
    for(int i =0; i<3; i++){
        for(int j =0; j<3; j++){
            if(state[i][j] != final[i][j] && state[i][j] != 0) c++;
        }
    }
    return c;
}

void hill_climb(vector<vi> state, int i, int j, vector<vi> &final_state){
    view(state);
    int cost = heuristic(state, final_state);
    int min_cost = cost;
    if(i+1 < 3) {
        swap(state[i][j] , state[i+1][j]);
        min_cost = min(min_cost, heuristic(state, final_state));
            
        if(min_cost < cost){
            hill_climb(state,  i+1, j, final_state);
            return;
        }
        
        swap(state[i][j], state[i+1][j]);
    }

    if(j+1 < 3){
        swap(state[i][j] , state[i][j+1]);
       
        min_cost = min(min_cost, heuristic(state, final_state));
           
        if(min_cost < cost){
            hill_climb(state,  i, j+1, final_state);
            return;
        }
        
        swap(state[i][j], state[i][j+1]);
    }

    if(i - 1 >= 0){
        swap(state[i][j] , state[i-1][j]);
        
        min_cost = min(min_cost, heuristic(state, final_state));
           
        if(min_cost < cost){
            hill_climb(state,  i-1, j, final_state);
            return;
        }
        
        swap(state[i][j], state[i-1][j]);
    }

    if(j - 1 >= 0){
        swap(state[i][j] , state[i][j-1]);
        
        min_cost = min(min_cost, heuristic(state, final_state));
            
        if(min_cost < cost){
            hill_climb(state, i, j-1, final_state);
            return;
        }
        
        swap(state[i][j], state[i][j-1]);
    }
}

void steepest_hill_climb(vector<vi> state, int i, int j, vector<vi> &final_state){
    // cout<<"h";
    view(state);
    int cost = heuristic(state, final_state);
    int min_cost = cost;
    vector<vi> best_State;
    // cout<<cost<<"_";
    int ni, nj;
    if(i+1 < 3) {
        swap(state[i][j] , state[i+1][j]);
        min_cost = min(min_cost, heuristic(state, final_state));
            
        if(min_cost < cost){
            cost = min_cost;
            best_State = state;
            ni = i+1; nj = j;
        }
        
        swap(state[i][j], state[i+1][j]);
       
    }

    if(j+1 < 3){
        swap(state[i][j] , state[i][j+1]);
       
        min_cost = min(min_cost, heuristic(state, final_state));
           
        if(min_cost < cost){
            cost = min_cost;
            best_State = state;
            ni = i; nj = j+1;
        }
        
        swap(state[i][j], state[i][j+1]);
    }

    if(i - 1 >= 0){
        swap(state[i][j] , state[i-1][j]);
        
        min_cost = min(min_cost, heuristic(state, final_state));
           
        if(min_cost < cost){
            cost = min_cost;
            best_State = state;
            ni = i-1; nj = j;
        }
        
        swap(state[i][j], state[i-1][j]);
    }

    if(j - 1 >= 0){
        swap(state[i][j] , state[i][j-1]);
        
        min_cost = min(min_cost, heuristic(state, final_state));
            
        if(min_cost < cost){
            cost = min_cost;
            best_State = state;
            ni = i; nj = j-1;
        }
        
        swap(state[i][j], state[i][j-1]);
    }
    if(best_State.size()){
        steepest_hill_climb(best_State,  ni, nj, final_state);
        // view(best_State);
        // cout<<ni<<" "<<nj;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vi> initial_state = {{1,2,3},{7,8,4},{6,0,5}};
    vector<vi> final_state = {{1,2,3},{8,0,4},{7,6,5}};
    hill_climb(initial_state,  2, 1, final_state);
    cout<<"\n\n\n\n";
    steepest_hill_climb(initial_state, 2, 1, final_state);
    return 0;
}
/*
*/