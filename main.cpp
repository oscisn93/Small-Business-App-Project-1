#include "Order.h"
#include <string>
#include <iostream>

int main() {
  // std::string s = "shrimpcocktail 995 noonions";
  // item *i = new item(s);
  // std::cout<<"Name: "<<i->name<<"\nPrice: "<<i->price<<"\nNote! -->"<<i->special_instructions<<std::endl;
   int o_num = utils::dailyTotals().newOrder();
   int table = 1;
   Order o(o_num, table);
   o.printOrder();
    return 0;
}
