#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>

const std::map<size_t, std::string> crimes =

{

{1, "ride on red"},
{2,"exceed speed limit"},
{3,"crossed double line"},
{4,"drift on intersection"},
{5,"wrong place parking"},
{6,"said bad words to officer"},

};


class Crime
{
	size_t id;
	std::string place;

public:
	size_t get_id() const
	{

		return id;
	}

	const std::string& get_place() const
	{


		return place;
	}

	Crime(size_t id, const std::string& place) :id(id), place(place) {}
	
	~Crime() {}

	bool operator == (const Crime& other)const
	{
		return this->id == other.id && this->place == other.place;
	}
	bool operator != (const Crime& other)const
	{
		return this->id == other.id && this->place == other.place;
	}

};

std::ostream& operator<<(std::ostream& os, const Crime& obj);

std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj);
