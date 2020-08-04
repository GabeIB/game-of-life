#include <vector>
#include <string>
#include <thread>

class GameBoard{
	int width;
	int height;
	public:
		GameBoard();
		GameBoard(int, int);
		void render(std::vector<std::vector<bool>>);
		void setWidth(int);
		void setHeight(int);
	private:
		std::string refresh;
};
