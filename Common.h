#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <set>

#include "DayBase.h"

template<class T>
struct Vec2
{
public:
	Vec2() : x{ 0 }, y{ 0 } {}

	const double manhatten(const Vec2& other) {
		return std::abs(other.x - x) + std::abs(other.y - y);
	}
public:
	T x;
	T y;
};

template<typename T>
bool operator==(const Vec2<T>& lhs, const Vec2<T>& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

static std::string defaultConverter(std::string& item)
{
	return item;
}