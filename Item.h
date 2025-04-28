#include <string>
#ifndef Item_H
#define Item_H
using namespace std;
#include <vector>

class Item {
private:
    string name;

public:
    virtual ~Item(void) = default;
    void setName(const std::string &newName);
    string getName() const;
};

#endif