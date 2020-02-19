#include "GreedyRobot.h"

//default constructor
GreedyRobot::GreedyRobot()
{
}

//destructor
GreedyRobot::~GreedyRobot()
{
}

//constructor takes the coordinates from the robot and treasure,
//and the maximum distance.
GreedyRobot::GreedyRobot( int robX, int robY,
	 int treX, int treY, int maxDist)
{
	this->robotX = robX;
	this->robotY = robY;
	this->treasureX = treX;
	this->treasureY = treY;
	getDistance(robotX, robotY, treasureX, treasureY);
	setMaxDistance(maxDist);
	searchTreasure(distanceX, distanceY, maxDistance, numOfPaths, path);
	cout << "Number of paths: " << numOfPaths << endl;
}



int GreedyRobot::getRobotX(const int robX)
{
	robotX = robX;
	return robotX;
}

int GreedyRobot::getRobotY(const int robY)
{
	robotY = robY;
	return robotY;
}

int GreedyRobot::getTreasureX(const int treX)
{
	treasureX = treX;
	return treasureX;
}

int GreedyRobot::getTreasureY(const int treY)
{
	treasureY = treY;
	return treasureY;
}

//get the shortest distance from robot to treasure.
void GreedyRobot::getDistance(const int robX, const int robY, 
	const int treX, const int treY)
{
	distanceX = treX - robX;
	distanceY = treY - robY;
}

//set the maximum distance the robot can move in one direction.
int GreedyRobot::setMaxDistance(int maxDist)
{
	maxDistance = maxDist;
	return maxDistance;
}

//cauculate the paths the robot can move without exceeding 
//the max distance in one direction.
void GreedyRobot::searchTreasure(int distX, int distY, int maxDist,
	int &numOfPaths, string &path)
{
	if (distY != 0)
	{
		if (distY > 0)
		{
			//move North
			moveNorth();
			searchTreasure(distX, distY - 1, maxDist, numOfPaths, path);
			path.pop_back();

		}
		else
		{
			//move south
			moveSouth();
			searchTreasure(distX, distY + 1, maxDist, numOfPaths, path);
			path.pop_back();
		}
	}

	if (distX != 0)
	{
		if (distX > 0)
		{
			//move east
			moveEast();
			searchTreasure(distX - 1, distY, maxDist, numOfPaths, path);
			path.pop_back();
		}
		else
		{
			//move west
			moveWest();
			searchTreasure(distX + 1, distY, maxDist, numOfPaths, path);
			path.pop_back();
		}
	}

	//base case
	if (distX == 0 && distY == 0 && maxDistCheck(path))
	{
		//add one more path in the number of paths.
		numOfPaths++;
		cout << path << endl;
	}
}
//Check if move times exceed maxDistance by counting how
//many times the robot has moved in the same direction and
//comparing it with the maxDistance.
bool GreedyRobot::maxDistCheck(const string& path) const
{
	int movedTime = 1;
	int length = path.length() - 1;
	for (int i = 0; i < length; i++)
	{
		//comparing directions to see if they are repeated.
		if (path.at(i) == path.at(i + 1))
		{
			movedTime++; //counting the move in the same direction.
			if (movedTime > maxDistance)
			{
				//can't make the move because the robot has moved on
				//the same direction more time than it can.
				return false;
			}
		}
		else
		{
			movedTime = 1;
		}
	}
	//continues if the move doesn't exceed the constraint.
	if (movedTime <= maxDistance)
	{
		return true;
	}
	else
	{
		return false;
	}
	//allows the robot to continue on the same direction after checking.
	return true;
}

//add 'N' to the path string.
void GreedyRobot::moveNorth()
{
	path += north;
}

//add 'S' to the path string.
void GreedyRobot::moveSouth()
{
	path += south;
}

//add 'W' to the path string.
void GreedyRobot::moveWest()
{
	path += west;
}

//add 'E' to the path string.
void GreedyRobot::moveEast()
{
	path += east;
}

//operator << overloading
ostream & operator<<(ostream & output, GreedyRobot & rhs)
{
	output << rhs.path << endl;
	return output;
}

//operator >> overloading
istream & operator>>(istream & input, GreedyRobot & rhs)
{
	int robX, robY, treX, treY, maxDist;
	cout << "Enter the coordinates and the max distance: " << endl;
	input >> robX >> robY >> treX >> treY >> maxDist;
	rhs.getRobotX(robX);
	rhs.getRobotY(robY);
	rhs.getTreasureX(treX);
	rhs.getTreasureY(treY);
	rhs.setMaxDistance(maxDist);
	rhs.getDistance(robX, robY, treX, treY);
	rhs.searchTreasure(rhs.distanceX, rhs.distanceY, rhs.maxDistance, rhs.numOfPaths, rhs.path);
	cout << "Number of paths: " << rhs.numOfPaths << endl;
	return input;
}

