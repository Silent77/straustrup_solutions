#pragma once

#include "std_lib_facilities.h"
#include "iohelper.h"

const int not_a_reading = -7777;
const int not_a_month = -1;
constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

vector<string> month_input_tbl = {
	"jan", "feb", "mar", "apr", "may", "jun",
	"jul", "aug", "sep", "oct", "nov", "dec"
};

bool is_valid(const struct Reading & r);

int month_to_int(string s)
{
	for (int i = 0; i < 12; ++i)
		if (month_input_tbl[i] == s)
			return i;
	return -1;
}

string int_to_month(int i)
{
	if (i < 0 || i > 11)
		error("Incorrect month index");
	return month_input_tbl[i];
}

struct Day
{
	vector<double> hour{ vector<double>(24, not_a_reading) };
};

struct Month
{
	int month{ not_a_month };
	vector<Day> day{ 32 }; // 1..31, skip [0] element for simplicity
};

struct Year
{
	int year;
	vector<Month> month{ 12 };
};

struct Reading {
	int day;
	int hour;
	double temperature;
};

istream & operator>>(istream & is, Reading & r)
{
	char ch1;
	if (is >> ch1 && ch1 != '(') // is Reading?
	{
		is.unget();						// return char in stream
		is.clear(ios_base::failbit);	// set fail state
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')')
		error("Bad temperature record");
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

/************************************************************************/
/* Read Month from stream. Format : { month feb ...}                    */
/************************************************************************/
istream & operator>>(istream & is, Month & m)
{
	char ch = 0;
	if (is >> ch && ch != '{')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string month_marker;
	string mm;
	is >> month_marker >> mm;
	if (!is || month_marker != "month")
		error("Wrong Month record begin");
	m.month = month_to_int(mm);

	int duplicates = 0;
	int invalids = 0;
	for (Reading r; is >> r;)
	{
		if (is_valid(r))
		{
			// if Reading already exist
			if (m.day[r.day].hour[r.hour] != not_a_reading)
				++duplicates;
			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else
			++invalids;
	}
	if (invalids)
		error("Invalids data in Month, total ", invalids);
	if (duplicates)
		error("Duplicate records in Month, total ", duplicates);

	end_of_loop(is, '}', "Wrong Month ending");
	return is;
}

istream & operator>>(istream & ist, Year & y)
{
	char ch;
	ist >> ch;
	if (ch != '{')
	{
		ist.unget();
		ist.clear(ios_base::failbit);
		return ist;
	}

	string year_marker;
	int yy;
	ist >> year_marker >> yy;
	if (!ist || year_marker != "year")
		error("Incorrect Year record begin");
	y.year = yy;
	while (true)
	{
		Month m;	// Create Month object
		if (!(ist >> m))
			break;
		y.month[m.month] = m;
	}
	end_of_loop(ist, '}', "Wrong Year record ending");
	return ist;
}

bool is_valid(const Reading & r)
{
	if (r.day < 1 || r.day > 31)
		return false;
	if (r.hour < 0 || r.hour > 23)
		return false;
	if (r.temperature < implausible_min || r.temperature > implausible_max)
		return false;
	return true;
}

void print_year(ostream & ost, Year & y)
{
	ost << "{ year " << y.year;
	for (Month & m : y.month)
	{
		if (m.month != not_a_month)
		{
			ost << "{ month " << int_to_month(m.month);
			for (int d_num = 1; d_num <= 31; ++d_num)
			{
				for (int i = 0; i < 24; ++i)
					if (m.day[d_num].hour[i] != not_a_reading)
						ost << " (" << d_num << ' ' << i << ' ' << m.day[d_num].hour[i] << ')';
			} // readings
			ost << " }\n"; // month
		}
	}
	ost << "}\n"; // year
}