#ifndef GREEDYROBOT_H
#define GREEDYROBOT_H

#include <iostream>
#include <string>
using namespace std;

const string west = "W";
const string east = "E";
const string south = "S";
const string north = "N";

class GreedyRobot
{
private:
	int robotX = 0;
	int robotY = 0;
	int treasureX = 0;
	int treasureY = 0;
	int distanceX = 0;
	int distanceY = 0;
	int maxDistance = 1;
	string path;
	int numOfPaths = 0;

public:
	//constructors
	GreedyRobot();
	GreedyRobot(int robX, int robY, int treX, int treY, int maxDist);

	//destructor
	~GreedyRobot();

	//getters
	int getRobotX(const int robX);
	int getRobotY(const int robY);
	int getTreasureX(const int treX);
	int getTreasureY(const int treY);
	void getDistance(const int robX, const int robY, const int treX, const int treY);


	//setters
	int setMaxDistance(int maxDist);

	//verbs
	void searchTreasure(int distX, int distY, int maxDist, int &numOfPaths, string &path);
	void moveWest();
	void moveEast();
	void moveSouth();
	void moveNorth();
	bool maxDistCheck(const string& path) const;

	//operator overloading
	friend ostream& operator<<(ostream& output, GreedyRobot& rhs);
	friend istream& operator>>(istream& input, GreedyRobot& rhs);
};

#endif