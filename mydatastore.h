#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include <set>
#include <string>
#include <map>

class MyDataStore : public DataStore
{
  public:
    ~MyDataStore() override;
    void addProduct(Product* p) override;
    void addUser(User* u) override;
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    void dump(std::ostream& ofile) override;
    std::vector<User*> getUsers()
    {
        return users_;
    }
    User* getUser(std::string username) {
        for (int i =0; i < users_.size(); i++) {
            if (users_[i]->getName() == username) {
                return users_[i];
            }
        }

        return nullptr;
    }

  private:
    std::vector<Product*> products_;
    std::vector<User*> users_;
    std::map<std::string, std::set<Product*>> productsKeyMap_;
};

#endif //MYDATASTORE_H
