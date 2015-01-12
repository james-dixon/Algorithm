#include <iostream>
#include <iomanip>

#include <limits>
#include <cstdint>
#include <random>
#include <type_traits>

#include <chrono>

#include <vector>
#include <algorithm>

#include "algo.hpp"

template<typename T>
std::vector<typename std::enable_if<std::is_integral<T>::value,T>::type >
random_ints(const uint64_t number,
			const T min = std::numeric_limits<T>::lowest(),
			const T max = std::numeric_limits<T>::max())
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<T> dis(min, max);
	std::vector<T> output;
	output.reserve(number);
	for(uint64_t i=0; i<number; ++i)
	{
		output.push_back( dis(gen) );
		}
	return output;
}

using namespace std;

int main()
{
	using time_period = std::chrono::nanoseconds;
	auto t1 = chrono::high_resolution_clock::now();
	auto t2 = chrono::high_resolution_clock::now();
	auto dur = std::chrono::duration_cast<time_period>(t2-t1).count();
	
	cout<<"Hello world"<<endl;

	vector<uint32_t> v = random_ints<uint32_t>(10000000);
	v.push_back(1000);
	std::sort(v.begin(), v.end());
	
	
	t1 = chrono::high_resolution_clock::now();
	if(algo::binary_search::exists(v.begin(), v.end(), 1000))
	{
		t2 = chrono::high_resolution_clock::now();
		cout<<"Found"<<endl;
		dur = std::chrono::duration_cast<time_period>(t2-t1).count();
		cout<<"MY-find took: "<<dur<<"ms"<<endl;
	}

	
	t1 = chrono::high_resolution_clock::now();
	if(std::binary_search(v.begin(), v.end(), 1000))
	{
		t2 = chrono::high_resolution_clock::now();
		cout<<"Found"<<endl;
		dur = std::chrono::duration_cast<time_period>(t2-t1).count();
		cout<<"STD-find took: "<<dur<<"ms"<<endl;
	}

	t1 = chrono::high_resolution_clock::now();
	if(std::binary_search(v.begin(), v.end(), 1000))
	{
		t2 = chrono::high_resolution_clock::now();
		cout<<"Found"<<endl;
		dur = std::chrono::duration_cast<time_period>(t2-t1).count();
		cout<<"STD-find took: "<<dur<<"ms"<<endl;
	}
	
	t1 = chrono::high_resolution_clock::now();
	if(algo::binary_search::exists(v.begin(), v.end(), 1000))
	{
		t2 = chrono::high_resolution_clock::now();
		cout<<"Found"<<endl;
		dur = std::chrono::duration_cast<time_period>(t2-t1).count();
		cout<<"MY-find took: "<<dur<<"ms"<<endl;
	}

	t1 = chrono::high_resolution_clock::now();
	if(algo::binary_search::exists(v.begin(), v.end(), 1000))
	{
		t2 = chrono::high_resolution_clock::now();
		cout<<"Found"<<endl;
		dur = std::chrono::duration_cast<time_period>(t2-t1).count();
		cout<<"MY-find took: "<<dur<<"ms"<<endl;
	}

	
}
