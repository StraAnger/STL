#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include "Crime.h"

void add(std::map<std::string, std::list<Crime>>& base);
void print(const std::map<std::string, std::list<Crime>>& base);
void print(const std::map<std::string, std::list<Crime>>& base, const std::string& licence_plate);
void print(const std::map<std::string, std::list<Crime>>& base, const std::string& first_plate, const std::string& last_plate);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& fileName);
void load(std::map<std::string, std::list<Crime>>& base, const std::string& fileName);



int main()
{

	std::map<std::string, std::list<Crime>> base;/* =
	{
		{"a777km",{Crime(1,"Lenin street"), Crime(2,"Frunze street")}},
		{"a557ab",{Crime(5,"Kosmonavtov street")}},
		{"a001mp",{Crime(4,"Lenin street&Oktyabrskaya"), Crime(3,"Oktyabrskaya street")}},

	};*/
    load(base, "base.txt");
    load(base, "base.txt");
    load(base, "base.txt");
	print(base);

	std::string licence_plate;
	std::cout << "Enter the license_plate number: "; std::cin >> licence_plate;
	print(base,licence_plate);
//	save(base, "base.txt");
	//	add(base);
	//	print(base);


	std::string first_plate, last_plate;
	std::cout << "Enter first plate: "; std::cin >> first_plate;
	std::cout << "Enter last plate: "; std::cin >> last_plate;
	print(base, first_plate, last_plate);

	return 0;
}

void add(std::map<std::string, std::list<Crime>>& base)
{
	std::string license_plate;
	int id;
	std::string place;

	std::cout << "Enter license_plate: "; std::cin >> license_plate;
	std::cout << "Enter the crime (law number): "; std::cin >> id;
	std::cout << "Enter the crime place: ";
	std::cin.clear();
	std::cin.ignore();
	std::getline(std::cin, place);
	base[license_plate].push_back(Crime(id, place));


}

void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		//std::cout << std::left;
		std::cout << it->first << ":\n";

		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			std::cout << "\t" << *jt << ";\n";
		}
		std::cout << "\n-----------------------------------------\n";
	}

}

void print(const std::map<std::string, std::list<Crime>>& base, const std::string& licence_plate)

{
	try
	{
		std::cout << licence_plate << ":\n";
		for (std::list<Crime>::const_iterator it = base.at(licence_plate).begin(); it != base.at(licence_plate).end(); ++it)
		{
			std::cout << *it << std::endl;
		}
	}
	catch (...)
	{
		std::cerr << "No such number in base" << std::endl;
	}

}

void print(const std::map<std::string, std::list<Crime>>& base, const std::string& first_plate, const std::string& last_plate)
{
	try
	{
		for (std::map<std::string, std::list<Crime>>::const_iterator it = base.lower_bound(first_plate);
			it != base.upper_bound(last_plate);
			++it
			)
		{
			std::cout << it->first << ":\n";
			for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{
				std::cout << *jt << std::endl;
			}
		}
    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

void save(const std::map<std::string, std::list<Crime>>& base, const std::string& fileName)
{
	std::ofstream fout(fileName);

	for (std::pair<std::string, std::list<Crime>> i : base)
	{
		fout << i.first << " :\t";
		for (Crime j : i.second)
		{
			fout << j << ", ";
		}
		fout.seekp(-2, std::ios::cur);//сдвигаем курсор на 2 позиции влево
		fout << ";\n";
	}

	fout.close();
	std::string command = std::string("start notepad ") + fileName;
	system(command.c_str());

	//c_str() возвращает C-string ( NULL Terminated line) для обратной совместимости
}

void load(std::map<std::string, std::list<Crime>>& base, const std::string& fileName)
{
	std::ifstream fin(fileName);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string license_plate;
			int id;
			std::string place;
			std::string crimes;
			std::getline(fin, license_plate,':');
			std::getline(fin, crimes);
			if (crimes.empty()) continue;


			/*if (crimes.find(',') != std::string::npos)
			{
				for (int start = 0, end = crimes.find(','); end != std::string::npos; start = end)
				{
					end = crimes.find(',', start + 1);
					place = crimes.substr(start + 1, end);// проверить с большим количеством правонарушений
					//substr- нач и конечн, а ф-ция принимает длину
					place.erase(0, place.find_first_not_of(' '));
					id = std::stoi(place.substr(0, place.find_first_of(' ')));
					place.erase(0, place.find_first_of(' ') + 1);
					base[license_plate].push_back(Crime(id, place));
				}
			}
			else
			{
				id = std::stoi(crimes.substr(0,crimes.find_first_of(' ')));
				crimes.erase(0, crimes.find_first_of(' '));
				base[license_plate].push_back(Crime(id, crimes));
			}*/

			char* sz_crimes = new char[crimes.size() + 1]{};  // sz_ - string zero ( c- строка, она заканчивается на 0), Венгерская нотация
			std::strcpy(sz_crimes, crimes.c_str());
			char sz_delimiters[] = ",;";

			for (char* pch = strtok(sz_crimes, sz_delimiters); pch; pch = strtok(NULL, sz_delimiters))
			{
				//atoi() - ASCII- string to int
				while (*pch == ' ')pch++;// Пока строка начинается с символа пробел ' ' , смещаем начало строки на один символ вправо
				id = std::atoi(pch); //Берём номер правонарушения, преобразуем его в в целочисленный формат (int) формат и сохраняем в id
				pch = std::strchr(pch, ' ') + 1;// Для того, чтобы убрать id из строки, находим первый пробел в строке, и смещаем начало строки на символ, следующий за пробелом
		/*if (
				std::find(base.at(license_plate).begin(), base.at(license_plate).end(), Crime(id, pch))
			== base.at(license_plate).end()
			)*/

			if (
			std::find(base[license_plate].begin(), base[license_plate].end(), Crime(id, pch))
		== base[license_plate].end()
		)

			base[license_plate].push_back(Crime(id, pch));

			}
			delete[] sz_crimes;

		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << std::endl;
	}


}
