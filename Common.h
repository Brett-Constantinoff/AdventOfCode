#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <set>
#include <unordered_map>

#include "DayBase.h"
#include "AoCUtilities.h"

// DATA STRUCTURES
template<class T>
struct Vec2
{
public:
	Vec2() : x{ 0 }, y{ 0 } {}

	Vec2(T& x, T& y) : x{ x }, y{ y } {}

	Vec2(std::initializer_list<T> list)
	{
		auto it{ list.begin() };
		x = *it;
		it++;
		y = *it;
	}

	const double manhatten(const Vec2& other) 
	{
		return std::abs(other.x - x) + std::abs(other.y - y);
	}

	bool operator==(const Vec2& other) const 
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vec2& other) const 
	{
		return !(*this == other);
	}

	struct Vec2Hash 
	{
		size_t operator()(const Vec2& v) const 
		{
			return std::hash<T>()(v.x) ^ std::hash<T>()(v.y);
		}
	};

public:
	T x;
	T y;
};
namespace std {
	template <typename T>
	struct hash<Vec2<T>> : public Vec2<T>::Vec2Hash {};
}


// CONVERTERS
static int32_t strToIntConverter(const std::string& str)
{
	return AoCUtilities::getInstance().strToInt(str);
}

template <typename T>
static std::string& intToStrConverter(const T& i)
{
	return AoCUtilities::getInstance().intToStr<T>(i);
}
