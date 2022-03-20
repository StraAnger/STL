#include <iostream>
#include <set>
#include <map>
#include <list>

#define tab "\t"


//#define STL_SET
//#define STL_MAP
#define STL_DICTIONARY


int main()
{


#ifdef STL_SET
	//set - уникальное дерево
	//multiset - неуникальное дерево

	std::set<int> myset = { 50, 25,75, 16, 32, 64, 80 };



	for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;

	int value;

	std::cout << "Enter value to insert" << std::endl;
	myset.insert(value);
	for (int i : myset) std::cout << i << tab; std::cout << std::endl;

	std::cout << "Enter value to delete" << std::endl;
	myset.erase(value);
	for (int i : myset) std::cout << i << tab; std::cout << std::endl;

	for (std::set<int>::iterator it = myset.lower_bound(25); it != myset.upper_bound(75); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;



#endif // STL_SET

#ifdef STL_MAP
	std::map<int, std::string> week =
	{
std::pair<int,std::string>(0,"Sunday"),
std::pair<int,std::string>(1,"Monday"),
std::pair<int,std::string>(2,"Tuesday"),
std::pair<int,std::string>(3,"Wednesday"),
std::pair<int,std::string>(4,"Thursday"),
		{5,"Friday"},
		{6,"Saturday"},
	};

	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		std::cout << it->first << tab << it->second << std::endl;
	}


#endif // STL_MAP


	std::map<std::string, std::list<std::string>> dictionary
	{
		std::pair<std::string, std::list<std::string>>("spice",{"сваривание, сращивание"}),
		{"reconnaisance",{"разведка","расследование"}},
		{"space",{"космос","пространство"}},


	};


	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
		{

			std::cout<<it->first<<":\t";
			std::cout.width(20);
			for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{
				std::cout << *jt << ", ";
			}
			std::cout << std::endl;
		}

	std::cout << "________________________________________________________\n";


	for (std::pair<std::string, std::list<std::string>>i : dictionary)
	{
		std::cout.width(20);
		std::cout << std::left;
		std::cout << i.first + ":";
		for (std::string j : i.second)std::cout << j << ", ";
		std::cout << "\b\b;\n";


	}

	return 0;
}