#include "stdafx.h"
#include "Book.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "std_lib_facilities.h"

Book::Book()
	: bookName{},
	authorName{},
	isbn{},
	registeredDate{},
	bIsRented{false},
	genre{EBookGenre::BG_Unknown}
{
}

Book::~Book()
{
}

void Book::getBookData()
{
	std::cout << "Enter book name: ";
	while (!getline(std::cin, bookName) || bookName == "")
	{
		std::cout << "Enter correct book name\n";
	}

	std::cout << "Enter book genre: \n";
	std::cout << "1 - Fiction, 2 - Children, 3 - Thriller, 4 - Fantasy\n";
	int iGenre;
	while (!(cin >> iGenre) || iGenre > 4 || iGenre < 1)
	{
		std::cout << "Enter correct genre\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	genre = static_cast<EBookGenre>(iGenre);

	std::cout << "Enter book author: ";
	while (!getline(std::cin, bookName) || bookName == "")
	{
		std::cout << "Enter correct book name\n";
	}
	std::cout << "Enter book author: ";
	while (!getline(std::cin, authorName) || authorName == "")
	{
		std::cout << "Enter correct author name\n";
	}
	unsigned int isbn1, isbn2, isbn3;
	char isbn_delim1, isbn_delim2, isbn_delim3;
	char isbn4;
	std::cout << "Enter book ISBN number in form N-N-N-X, where N is a number and X digit or letter: ";
	while (
		!(std::cin >> isbn1 >> isbn_delim1 >> isbn2 >> isbn_delim2 >> isbn3 >> isbn_delim3 >> isbn4) 
		|| isbn_delim1 != '-' || isbn_delim2 != '-' || isbn_delim3 != '-'
		|| !isalnum(isbn4)
		)
	{
		std::cout << "Enter correct ISBN number\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	}
	isbn = to_string(isbn1) + '-' + to_string(isbn2) + '-' + to_string(isbn3) + '-' + isbn4;

	unsigned int yyyy, mm, dd;
	char date_delim1, date_delim2;
	std::cout << "Enter author rights registration date (yyyy-mm-dd): ";
	while (
		!(std::cin >> yyyy >> date_delim1 >> mm >> date_delim2 >> dd)
		|| yyyy < 1000 || mm > 12 || dd > 31
		)
	{
		std::cout << "Enter correct date\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	registeredDate = to_string(yyyy) + '-' + to_string(mm) + '-' + to_string(dd);

	std::cout << "Is book borrowed (y or n):\n";
	char yes_no;
	while (!(std::cin >> yes_no) || (tolower(yes_no) != 'y' && tolower(yes_no) != 'n') )
	{

		std::cout << "Enter 'y' or 'n'\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	bIsRented = yes_no == 'y';
}


std::ostream & operator<<(std::ostream & outs, const Book book)
{
	std::cout << "Name: " << book.getBookName() << std::endl;
	std::cout << "Author: " << book.getAuthorName() << std::endl;
	std::cout << "ISBN: " << book.getISBN() << std::endl;
	std::cout << "Date of author right registration: " << book.getRightRegistrationDate() << std::endl;;
	std::cout << std::boolalpha << "Book is rented: " << book.isrented() << std::endl;

	return outs;
}
