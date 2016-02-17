/************************************************************************/
/* file_vocam.cpp Yaroslav Tarnavskiy, 2016                             */
/* Output vocabulary for a file with word frequencies                   */
/************************************************************************/

#include "..\Punct_stream.h"
#include <map>;

int main()
{
	string iname;
	cout << "Enter file name:\n";
	cin >> iname;
	ifstream ifs{iname};
	if (!ifs)
		error("Unable open file ", iname);
	Punct_stream ps{ifs};
	ps.whitespace(",.:;\"/\\[]{}<>@!$%^&*()-=_+|~`");
	ps.case_sensetive(false);

	vector<string> vocabulary;
	map<string, unsigned> map_voc;

	for (string s; ps >> s;)
	{
		map_voc[s]++;
	}
	//sort(vocabulary.begin(), vocabulary.end());

	for (auto word: map_voc)
	{
			cout << word.first << '{' << word.second << '}' << endl;
	}

	keep_window_open();
	return 0;
}
