#include <iostream>
#include <fstream>
#include "mydatastore.h"
#include "util.h"

using namespace std;

MyDataStore::~MyDataStore()
{
    for (int i = 0; i < products_.size(); i++) {
        delete products_[i];
    }
    for (int i = 0; i < users_.size(); i++) {
        delete users_[i];
    }

}

void MyDataStore::addProduct(Product* p)
{
    products_.push_back(p);

    set<string> keywords = p->keywords();
    for (set<string>::iterator it = keywords.begin(); it != keywords.end(); ++it)
    {
        string lowered = convToLower(*it);
        productsKeyMap_[lowered].insert(p);
        //cout << lowered << endl;
    }
}

void MyDataStore::addUser(User *u)
{
    users_.push_back(u);
}

//also should be case in-sensitive
std::vector<Product*> MyDataStore::search(std::vector<std::string> &terms, int type) //0 is AND, 1 is OR
{
    std::set<Product*> result;

    for (int i = 0; i < terms.size(); ++i)
    {
        if (productsKeyMap_.find(terms[i]) != productsKeyMap_.end())
        {
            if (type == 0) //AND
            {
                if (i == 0)
                {
                    result = productsKeyMap_[terms[i]];
                }
                else result = setIntersection(result, productsKeyMap_[terms[i]]);
            }
            else if (type == 1) //OR
            {
                result = setUnion(result, productsKeyMap_[terms[i]]);
            }
        }
        else if (type == 0) return {}; //AND and failed to find
    }

    return std::vector<Product*>(result.begin(), result.end());
}


void MyDataStore::dump(std::ostream &ofile)
{
    ofile << "<products>" << endl;
    for (int i = 0; i < products_.size(); i++)
    {
        products_[i]->dump(ofile);
    }
    ofile << "</products>" << endl << "<users>" << endl;
    for (int i = 0; i < users_.size(); i++)
    {
        users_[i]->dump(ofile);
    }
    ofile << "</users>" << endl;
}