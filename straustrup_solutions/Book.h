#pragma once

#include <string>

enum class EBookGenre
{
	BG_Unknown = 0,
	BG_Fiction = 1,
	BG_Children = 2,
	BG_Thriller = 3,
	BG_Fantasy = 4
};
class Book
{
public:
	Book();
	~Book();
	bool isrented() const { return bIsRented; };
	std::string getAuthorName() const { return authorName; };
	std::string getBookName()   const { return bookName; };
	std::string getISBN()       const { return isbn; };
	std::string getRightRegistrationDate() const { return registeredDate; };
	void getBookData();
	
private:
	/** Book author */
	std::string authorName;

	/** Book title*/
	std::string bookName;

	/** ISBN book number N-N-N-X, N - int, X - digit or char*/
	std::string isbn;

	/** Is someone took book? */
	bool bIsRented;

	/** Date of author rights registration */
	std::string registeredDate;

	EBookGenre genre;
};

std::ostream & operator<<(std::ostream & outs, const Book book);
inline bool operator==(const Book book1, const Book book2) { return book1.getISBN() == book2.getISBN(); };
inline bool operator!=(const Book book1, const Book book2) { return ! (book1.getISBN() == book2.getISBN()); };