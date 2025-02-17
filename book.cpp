#include <sstream>
#include <iomanip>
#include "book.h"
#include "product.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author)
    : Product(category, name, price, qty), isbn_(isbn), author_(author)
{
}

Book::~Book()
{
}

std::set<std::string> Book::keywords() const
{
    set<string> keywords = parseStringToWords(name_);
    set<string> author = parseStringToWords(author_);
    keywords = setUnion(keywords, author);

    keywords.insert(isbn_);

    return keywords;
}

std::string Book::displayString() const
{
    stringstream ss;
    ss << name_ << endl;
    ss << "Author: " << author_ << " ISBN: " << isbn_ << endl;
    ss << price_ << " " << qty_ << " left." << endl;

    return ss.str();
}

void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}



