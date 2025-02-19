#include <sstream>
#include <iomanip>
#include "movie.h"
#include "product.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating)
    : Product(category, name, price, qty), genre_(genre), rating_(rating) 
{
}

Movie::~Movie() 
{
}

std::set<std::string> Movie::keywords() const 
{
    set<string> keywords = parseStringToWords(name_);
    set<string> genre = parseStringToWords(genre_);

    keywords = setUnion(keywords, genre);

    return keywords;
}

std::string Movie::displayString() const 
{
    stringstream ss;
    ss << name_ << endl;
    ss << "Genre: " << genre_ << " Rating: " << rating_ << endl;
    ss << std::setprecision(2) << price_ << " " << qty_ << " left." << endl;

    return ss.str();
}

void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}