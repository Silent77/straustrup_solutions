#pragma once
#pragma once

#include <vector>
#include <string>

class Name_pairs
{
public:
	Name_pairs();
	~Name_pairs();
	void sort();
	void read_names();
	void read_ages();
	friend std::ostream & operator << (std::ostream & outs, Name_pairs & namePairs);
private:
	int partition(int p, int r);
	void quick_sort(int p, int r);
	std::vector <std::string> name;
	std::vector<double> age;
};

