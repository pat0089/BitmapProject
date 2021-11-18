#ifndef BITMAPPROJECT_SELECTION_H
#define BITMAPPROJECT_SELECTION_H
#include "../Pixel/pixel.h"
#include <vector>
#include <set>
#include <utility>

using std::vector;
using std::set;
using std::pair;

//Selection
/* - A managed 2D array of booleans (and associated list of x & y coordinate points)
 * - Can be combined with and used with other Selections
 * - Will have overloaded operators for the ability to overlap and combine and detract
 * - Selections will be able to change shape
 * - will be used in ModificationLayer:
 *  -- Future planned class that wraps a Selection, PixelMap, and manipulation function
 * */
class Selection {
public:

    //Constructors:
    Selection(int w, int h);
    Selection(const Selection & selection);

    //Destructor:
    ~Selection();

    //Indexing Operator
    bool * operator[](int i) const;

    //Selection manipulation (select more/deselect all):
    void selectAll();
    void selectSquare(int x1, int y1, int x2, int y2);
    void selectSquare(pair<int, int> point1, pair<int, int> point2);
    void selectCircle(pair<int, int> point, int r);
    void selectCircle(pair<int, int> point, float r);
    void selectCircle(pair<int, int> point1, pair<int, int> point2);
    void selectPolygon(vector<pair<int, int>> points);
    void deselectAll();
    void deselectSquare(int x1, int y1, int x2, int y2);
    void deselectSquare(pair<int, int> point1, pair<int, int> point2);
    void deselectCircle(pair<int, int> point, int r);
    void deselectCircle(pair<int, int> point, float r);
    void deselectCircle(pair<int, int> point1, pair<int, int> point2);

    //Overloaded operators for Selection manipulation:
    Selection operator+(const Selection & rhs) const;
    Selection operator-(const Selection & rhs) const;
    Selection operator^(const Selection & rhs) const;
    Selection operator|(const Selection & rhs) const;
    Selection operator-() const;
    Selection operator!() const;
    bool operator==(const Selection & rhs) const;
    bool operator!=(const Selection & rhs) const;
    bool operator<(const Selection & rhs) const;
    bool operator<=(const Selection & rhs) const;
    bool operator>(const Selection & rhs) const;
    bool operator>=(const Selection & rhs) const;

    //Point set functions:
    int count() const;
    vector<pair<int, int>> getPoints() const;

private:

    bool ** selectionMap;
    int width, height;
    set<pair<int, int>> pointSet;

    void setCoord(pair<int, int> toSet, bool val, pair<int, int> origin);

};


#endif //BITMAPPROJECT_SELECTION_H