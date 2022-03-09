#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>


#define tab "\t"
#define delimiter "************************************"
//#define STL_AARAY
//#define STL_VECTOR
//#define STL_DEQUE
//#define STL_LIST
#define STL_FORWARD_LIST

int main()
{
#ifdef STL_AARAY
	std::array<int,5> arr = { 3,5,8,13,21 };

	for (int i = 0; i < arr.size(); ++i)
	{

		std::cout << arr[i] << tab;
	}

	std::cout << std::endl;

#endif // STL_AARAY


#ifdef STL_VECTOR
	// это контейнер, который хранит данные в виде динамического массива

	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,5,8,13,21,34,5,8,13,21,34,5,5,8,13,21,34 };
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << tab;

	}
	std::cout << std::endl;
	std::cout << delimiter<<std::endl;
	std::cout << "Size:\t\t" << vec.size() << std::endl;
	std::cout << "MaxSize:\t" << vec.max_size() << std::endl;
	std::cout << "Capacity:\t" << vec.capacity() << std::endl;
	std::cout << std::endl;
	std::cout << delimiter << std::endl;
	vec.push_back(15);

	try {
		for (int i = 0; i < vec.capacity(); ++i)
		{
			//std::cout << vec[i] << std::endl;
			std::cout << vec.at(i) << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout<< *it << tab;

	}

	for (std::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit)
	{
		std::cout << *rit << tab;

	}

		
	int index;
	int value;

	std::cout << "Enter index to add"; std::cin >> index;
	std::cout << "Enter meaining to add"; std::cin >> value;

	//std::vector<int>::const_iterator position = vec.begin() + index;
	//vec.insert(position, value);
	
	
	
	vec.insert(vec.begin()+index, value);

	//or
	
	vec.insert(vec.begin() + index, { 3,4,5,6,7 });
	
	for (int i : vec) std::cout << i << tab; std::cout << std::endl;

	//list2 2h svyazn spisok range based for branch teplate

#endif // _VECTOR

#ifdef STL_DEQUE


	std::deque<int> deque = { 3,5,8,13,21 };
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);

	for (int i = 0; i < deque.size(); ++i)
	{
		std::cout << deque[i] << tab;
	}

	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);

	for (int i : deque) std::cout << i << tab; std::cout << std::endl;

#endif // STL_DEQUE
#ifdef STL_LIST

	int index;
	int value;
	std::list<int>::iterator it;
	std::list<int> newList = { 0,1,2,3,4,5 };
	
	std::cin >> index;
	std::cin >> value;
	it = newList.begin();

	for (int i = 0; i < index; ++i) ++it;

	newList.insert(it,value);
	
	std::cout << "newlist contains:";
	for (it = newList.begin(); it != newList.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

#endif // STL_LIST

#ifdef STL_FORWARD_LIST

	int index;
	int value;
	std::forward_list<int>::iterator it;
	std::forward_list<int> newForwardList = { 0,1,2,3,4,5 };

	std::cin >> index;
	std::cin >> value;
	it = newForwardList.before_begin();

	for (int i = 0; i < index; ++i) ++it;

	newForwardList.insert_after(it, value);

	std::cout << "newForwardist contains:";
	for (int& x : newForwardList) std::cout << ' ' << x;
	std::cout << '\n';



#endif // STL_FORWARD_LIST




	return 0;
}

