#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

#include "Day.h"
#include "AoCUtilities.h"

template<class T>
struct Vec2
{
public:
	Vec2() : x{ 0 }, y{ 0 } {}

	const double Manhatten(const Vec2& other) {
		return std::abs(other.x - x) + std::abs(other.y - y);
	}
public:
	T x;
	T y;
};

template<class T>
bool operator==(const Vec2<T>& lhs, const Vec2<T>& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}
