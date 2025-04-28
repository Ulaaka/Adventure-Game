#include <string>
#ifndef Item_H
#define Item_H
using namespace std;
#include <vector>

class Item {
private:
    string name;
    void setName(const std::string &newName);
public:

    virtual ~Item(void) = default;
    Item(const std::string &newName);
    string getName() const;
};

#endif