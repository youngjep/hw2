#ifndef BOOK_H
#define BOOK_H
#include "product.h"


class Book : public Product
{
  public:

    Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
    ~Book() override;

	  std::set<std::string> keywords() const override;
    std::string displayString() const override;
    void dump(std::ostream& os) const override;

  private:
    std::string isbn_, author_;
};



#endif //BOOK_H
