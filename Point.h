#pragma once
#ifndef POINT_H_
#define POINT_H_
#include "Direction.h"
#include <iostream>
#include <functional>
using namespace std;
class Point {
	int x;
	int y;
public:
	Point(int _x, int _y);
	void print(ostream& out = cout) const {
		out << "(" << x << "," << y << ")" << endl;
	}
	void setPoint(int _x, int _y) {
		x = _x;
		y = _y;
	}
	void move(Direction d) {
		//		// can be done also with a switch... but this is nicer
		//		// (well it's a matter of taste... anyhow, arrays/lists/vectors of operations are more extensible than switch,
		//		// for dynamic cases were things may be loaded dynamically, e.g. factories etc.)
		//		const static function<void(Point&)> do_move[] = { [](Point&p) {++p.y; }, // East
		//			[](Point&p) {--p.y; }, // West
		//			[](Point&p) {++p.x; }, // South
		//			[](Point&p) {--p.x; }  // North
		//		};
		//		do_move[(int)d](*this);
		switch (d) {
		case Direction::East:
			y++;
			break;
		case Direction::West:
			y--;
			break;
		case Direction::South:
			x++;
			break;
		case Direction::North:
			x--;
			break;
		case Direction::Stay:
			break;
		default:;
		}
	}
	friend ostream& operator<<(ostream& out, const Point& p) {
		p.print(out);
		return out;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}
};

#endif /* POINT_H_ */