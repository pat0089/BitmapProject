#include "selection.h"
#include <cmath>
#include <stdexcept>

//Selection(int width, int height):
//Creates a new Selection with dimensions (width,height)
//Defaults to none selected
Selection::Selection(int w, int h) : width(w), height(h) {
    selectionMap = new bool*[h];
    for (int i = 0; i < h; i++) {
        selectionMap[i] = new bool[w];
        for (int j = 0; j < w; j++) {
            selectionMap[i][j] = false;
        }
    }
}

//Copy Constructor
Selection::Selection(const Selection & selection) {
    //TODO: implement
}

//Destructor:
//Deallocates the managed double-pointer
Selection::~Selection() {
    for (int i = 0; i < height; i++) {
        delete[] selectionMap[i];
    }
    delete[] selectionMap;
}

//Indexing Operator:
//returns a pointer to row i
bool * Selection::operator[](int i) const {
    return selectionMap[i];
}

//SelectAll():
//Sets all to selected
void Selection::selectAll() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            selectionMap[i][j] = true;
            pointSet.insert(pair<int, int>(j, i));
        }
    }
}

//SelectSquare(int x1, int y1, int x2, int y2):
//Sets a square from (x1, y1) to (x2, y2)
void Selection::selectSquare(int x1, int y1, int x2, int y2) {
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            selectionMap[i][j] = true;
            pointSet.insert(pair<int, int>(j, i));
        }
    }
}

//SelectSquare((pair<int, int> point1, pair<int, int> point2):
//Sets a square from (point1.first, point1.second) to (point2.first, point2.second)
void Selection::selectSquare(pair<int, int> point1, pair<int, int> point2) {
    selectSquare(point1.first, point1.second, point2.first, point2.second);
}

//SelectCircle(pair<int, int> point, int radius):
//Sets a circle with center (point.first, point.second) and radius r
void Selection::selectCircle(pair<int, int> point, int r) {
    int r2 = r*r;
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            if ((j * j) + (i * i) <= (r2)) {
                pair<int, int> toSet(j, i);
                setCoord(toSet, true, point);
            }
        }
    }
}

//SelectCircle(pair<int, int> point, float radius):
//Sets a circle with center (point.first, point.second) and radius r
void Selection::selectCircle(pair<int, int> point, float r) {
    selectCircle(point, (int)r);
}

//SelectCircle(pair<int, int> point1, pair<int, int> point2):
//Sets a circle with center (point1.first, point1.second) and radius sqrt((point2.first - point1.first)^2 + (point2.second, point1.second)^2)
void Selection::selectCircle(pair<int, int> point1, pair<int, int> point2) {
    int difX = (point2.first - point1.first);
    int difY = (point2.second, point1.second);
    int lengthSquared = (difX * difX + difY * difY);
    selectCircle(point1, (int)std::sqrt(lengthSquared));
}

//SelectPolygon(vector<pair<int, int>> points):
//Select an area described by points that are connected by connecting the closest points as an
void Selection::selectPolygon(vector<pair<int, int>> points) {
    //TODO: implement
}

void Selection::deselectAll() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            selectionMap[i][j] = false;
        }
    }
    pointSet.erase(pointSet.begin(),  pointSet.end());
}

void Selection::deselectSquare(int x1, int y1, int x2, int y2) {
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            selectionMap[i][j] = false;
            pointSet.erase(pair<int, int>(j, i));
        }
    }
}

void Selection::deselectSquare(pair<int, int> point1, pair<int, int> point2) {
    deselectSquare(point1.first, point1.second, point2.first, point2.second);
}

void Selection::deselectCircle(pair<int, int> point, int r) {
    int r2 = r*r;
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            if ((j * j) + (i * i) <= (r2)) {
                pair<int, int> toSet(j, i);
                setCoord(toSet, false, point);
            }
        }
    }
}

void Selection::deselectCircle(pair<int, int> point, float r) {
    deselectCircle(point, (int)r);
}

void Selection::deselectCircle(pair<int, int> point1, pair<int, int> point2) {
    int difX = (point2.first - point1.first);
    int difY = (point2.second, point1.second);
    int lengthSquared = (difX * difX + difY * difY);
    deselectCircle(point1, (int)std::sqrt(lengthSquared));}

//Overloaded operators for Selection manipulation:
Selection Selection::operator+(const Selection & rhs) const {
    //TODO: implement
}

Selection Selection::operator-(const Selection & rhs) const {
    //TODO: implement
}

Selection Selection::operator^(const Selection & rhs) const {
    //TODO: implement
}

Selection Selection::operator|(const Selection & rhs) const {
    //TODO: implement
}

Selection Selection::operator-() const {
    //TODO: implement
}

Selection Selection::operator!() const {
    //TODO: implement
}

bool Selection::operator==(const Selection & rhs) const {
    return pointSet == rhs.pointSet;
}

bool Selection::operator!=(const Selection & rhs) const {
    return pointSet != rhs.pointSet;
}

bool Selection::operator<(const Selection & rhs) const {
    return pointSet.size() < rhs.pointSet.size();
}

bool Selection::operator<=(const Selection & rhs) const {
    return pointSet.size() <= rhs.pointSet.size();}

bool Selection::operator>(const Selection & rhs) const {
    return pointSet.size() > rhs.pointSet.size();}

bool Selection::operator>=(const Selection & rhs) const {
    return pointSet.size() >= rhs.pointSet.size();}

void Selection::setCoord(pair<int, int> toSet, bool val, pair<int, int> origin) {
    int newX, newY;
    newX = (width / 2) + toSet.first + origin.first;
    newY = (height/ 2) + toSet.second + origin.second;
    if (newX < width && newX >= 0 && newY < height && newY >= 0) {
        selectionMap[newY][newX] = val;
        if (val) {
            pointSet.insert(origin);
        } else {
            pointSet.erase(origin);
        }
    }
}

//count():
//Returns the number of selected pixels in the Selection
int Selection::count() const {
    return pointSet.size();
}

//getPoints():
//Returns a vector containing coordinate pairs to all the selected pixels of the Selection
vector<pair<int, int>> Selection::getPoints() const {
    return vector<pair<int, int>>(pointSet.begin(), pointSet.end());
}