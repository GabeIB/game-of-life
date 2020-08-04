#include "gameboard.h"
#include <iostream>

GameBoard::GameBoard()
	: width{0}, height{0}, refresh{"\e[0A"}
{}

GameBoard::GameBoard(int w, int h)
	: width{w}, height{h}, refresh{"\e["+std::to_string(h)+"A"}
{}

void GameBoard::setWidth(int w){
	this->width = w;
}

void GameBoard::setHeight(int h){
	this->height = h;
	this->refresh = "\e["+std::to_string(h)+"A";
}

void GameBoard::render(std::vector<std::vector<bool>> state){
	for(int i=0; i<this->height; ++i){
		for(int j=0; j<this->width; ++j){
			char c = (state[j][i]) ? '*' : ' ';
			std::cout << c;
		}
		std::cout << std::endl;
	}
	std::cout << this->refresh << std::flush;
}
