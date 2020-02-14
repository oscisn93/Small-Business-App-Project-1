#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "item.cpp"

#define defaultOrderSize 5

class Order {
public:
    Order(int n, int m);
    void printOrder();
    void addItem(std::string itemString);
private:
    void setTotals();
    int order_num;
    int table_num;
    std::string server_name;
    std::vector<item> itemList;
    double subtotal;
    double tax;
    double tip;
    double total;
    void addTip();
    void grabData();
};
