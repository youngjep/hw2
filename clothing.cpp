#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "product.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand)
    : Product(category, name, price, qty), size_(size), brand_(brand)
{
}

Clothing::~Clothing()
{
}

std::set<std::string> Clothing::keywords() const
{
    set<string> keywords = parseStringToWords(name_);
    set<string> brand = parseStringToWords(brand_);
    keywords = setUnion(keywords, brand);

    //std::cout << "keywords" << std::endl;

    return keywords;
}

std::string Clothing::displayString() const
{
    stringstream ss;
    ss << name_ << endl;
    ss << "Size: " << size_ << " Brand: " << brand_ << endl;
    ss << price_ << " " << qty_ << " left." << endl;

    return ss.str();
}

void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}




