#include "gameboard.h"
#include<iostream>
#include<chrono>
#include<random>

using namespace std;

const chrono::milliseconds frameRate = chrono::milliseconds(100);

const double probability = 0.1;

void setup(vector<vector<bool>> &state, default_random_engine &r){
	uniform_real_distribution<> dist(0,1);
	for(int i=0; i<state.size(); ++i){
		for(int j=0; j<state[0].size(); ++j){
			double random_double = dist(r);
			if(random_double < probability) state[i][j] = true;
		}
	}
}

int countNeighbors(const vector<vector<bool>> &current, int i, int j){
	vector<vector<int>> adjacents = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	int n = 0;
	for(vector<int> a : adjacents){
		int x = i+a[0];
		int y = j+a[1];

		if(x < 0) x = current.size()-1;
		if(y < 0) y = current[x].size()-1;
		if(x >= current.size()) x = 0;
		if(y >= current[x].size()) y = 0;

		if(current[x][y]) ++n;
	}
	return n;
}
	
bool god(const vector<vector<bool>> &current, int i, int j){
	int neighbors = countNeighbors(current, i, j);
	if(current[i][j]){
		if(neighbors >= 2 && neighbors <= 3){
			return true;
		}
	}else{
		if(neighbors == 3){
			return true;
		}
	}
	return false;
}

void getNextState(const vector<vector<bool>> &current, vector<vector<bool>> &next){
	for(int i=0; i<current.size(); ++i){
		for(int j=0; j<current[i].size(); ++j){
			next[i][j] = god(current, i, j);
		}
	}
}

int main(){
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator (seed);

	int width = 100;
	int height = 20;
	vector<vector<bool>> current(width, vector<bool>(height, 0));
	vector<vector<bool>> next = current;
	GameBoard g(width, height);
	setup(current, generator);

	while(1){
		g.render(current);
		getNextState(current, next);
		current = next;
		this_thread::sleep_for(frameRate);
	}
}
