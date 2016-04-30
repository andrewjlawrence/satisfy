/*
 * Copyright 2015 Andrew Lawrence
 */


// STL includes
#include <vector> 
#include <chrono>
#include <random>
#include <functional>
#include <iostream> 
#include <algorithm>

// Include paralell foreach
#include <parforeach.h>

// Using declarations
using std::vector;
using namespace std::chrono;

// Annonymous Namespace
namespace
{

} // End annonymous namespace 



int main(int argc, char* argv[])
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 9999);
	auto random = std::bind(distribution, generator);

	vector<vector<int>> testdata, testdata2, testdata3;
	vector<int> temp;
	uint16_t vecsize(5000);
	uint16_t vecvecsize(100);

	for (int i = 0; i < vecvecsize; i++)
	{ 
		temp.clear();
		for (int j = 0; j < vecsize; j++)
		{
			temp.push_back(random());
		}
		testdata.push_back(temp);
	}

	testdata2 = testdata;
	testdata3 = testdata;

	// Test range based forloop with sort
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (auto& subvec : testdata)
	{
		std::sort(subvec.begin(), subvec.end());
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	double duration = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "Standard range based forloop CPU time in seconds: " << duration / 1000000 << std::endl;
	
	// Test std foreach
	t1 = high_resolution_clock::now();

	std::for_each(testdata2.begin(), testdata2.end(),
		[](auto& vec) {std::sort(vec.begin(), vec.end());});

	t2 = high_resolution_clock::now();
	duration = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "Std foreach CPU time in seconds: " << duration / 1000000 << std::endl;

	// Test paralell foreach
	t1 = high_resolution_clock::now();
	parallel::foreach(testdata3.begin(), testdata3.end(),
		[](auto& vec) {std::sort(vec.begin(), vec.end());});

	t2 = high_resolution_clock::now();
	duration = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "Paralell foreach CPU time in seconds: " << duration / 1000000 << std::endl;

	return 0;
}// main