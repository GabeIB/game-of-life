#include<chrono>
#include<iostream>
#include<cmath>
#include<thread>

using namespace std;

const chrono::milliseconds frameRate = chrono::milliseconds(50);

int get_pos(int);
void render(int);


int main(){
	int t = 0;
	while(1){
		int position = get_pos(t);
		render(position);
		this_thread::sleep_for(frameRate); //framerate will be less than this but whatever
		++t;
		//graphics loop
	}
	
}

int get_pos(int t){
	//we want ball to travel 50 chars in abt 10 seconds
	//= 5 chars per second
	//20 tics per second
	//1/4 char / tic
	return floor(t/4);
}

void render(int position){
	for(int i = 0; i < position; ++i){
		cout << " ";
	}
	cout << "*\r" << flush;
}
