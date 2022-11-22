#include <bits/stdc++.h>
#define N 3
using namespace std;
struct PuzzleState {
	vector<vector<int>> data;
	int cost;
	int x;
	int y;
	PuzzleState(vector<vector<int>>& data, vector<vector<int>>& goalState, int x, int y) {
		this->data = data;
		this->x = x;
		this->y = y;
		cost = calCost(goalState);
	}
    PuzzleState(){
        cost = INT_MAX;
    }

	//to calculate the tiles mismatches
	int calCost(vector<vector<int>>& goalState) {
		int mismatch = 0;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				if(data[i][j] != goalState[i][j] && data[i][j] != 0) mismatch++;
			}
		}
		return mismatch;
	}

	string stringify() {
		string build = "";
		
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				build += data[i][j];
			}
		}
		
		return build;
	}
	
	void print() {
		cout << "\n";
		
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				cout << data[i][j] << " ";
			}
			cout << "\n";
		}
		
		cout << "\n";
	}

    bool equals(vector<vector<int>> &goal){
        for(int i =0; i<N; i++){
            for(int j =0; j<N; j++){
                if(data[i][j] != goal[i][j]) return false;
            }
        }
        return true;
    }
};


vector<PuzzleState> getNeighbours(PuzzleState &curr, vector<vector<int>> &goalState){
    int rowOff[] = {-1, 1, 0, 0};
	int colOff[] = {0, 0, -1, 1};
    vector<vector<int>> data = curr.data;
    vector<PuzzleState> ne;
    for(int i =0; i<4; i++){
        int x = curr.x + rowOff[i];
		int y = curr.y + colOff[i];
			
		if(x < 0 || y < 0 || x >= N || y >= N) continue;
						
		swap(data[curr.x][curr.y], data[x][y]);
			
		PuzzleState currState(data, goalState, x, y);
        ne.push_back(currState);
		swap(data[curr.x][curr.y], data[x][y]);
    }
    return ne;
}

int main() {
	srand(time(0));
	
	vector<vector<int>> initialState = {
		{1, 2, 3},
		{8, 0, 4},
		{7, 6, 5}
	};
	
	vector<vector<int>> goalState = {
		{1, 2, 3},
		{5, 8, 6},
		{0, 7, 4}
	};

	// vector<vector<int>> initialState = {
	// 	{1, 2, 3},
	// 	{7, 8, 4},
	// 	{6, 0, 5}
	// };
	
	// vector<vector<int>> goalState = {
	// 	{1, 2, 3},
	// 	{8, 0, 4},
	// 	{7, 6, 5}
	// };
	
    vector<string> tabuList;
    PuzzleState bestState;

    int times = 15;
    PuzzleState initial(initialState, goalState, 1, 1);
    bestState = initial;
    PuzzleState currState = initial; 

    tabuList.push_back(currState.stringify());

    while(times--){
        currState.print();
        if(currState.equals(goalState)) {
            break;
        }

        PuzzleState currBest;
        vector<PuzzleState> neighbours = getNeighbours(currState, goalState);
    
        for(auto it : neighbours){
            // it.print();
            if(find(tabuList.begin(), tabuList.end(), it.stringify()) == tabuList.end() && it.cost < currBest.cost){
                currBest = it;
            }
        }


        if(currBest.cost < bestState.cost) bestState = currBest;
        // currBest.print();
        currState = currBest;
        tabuList.push_back(currBest.stringify());
        if(tabuList.size() > 4) tabuList.erase(tabuList.begin());	//starvation condition
    }

    cout<<"Best possible state is : \n";
    bestState.print();
	return 0;
}