//
// Created by Oscar Cisneros on 1/21/20.
//
#include "Order.h"
//constructor calls grabData function
Order::Order(int n, int m)
  :order_num(n), table_num(m)
  {
    grabData();
  }
//converts table#.txt file to items list
void Order::grabData(){
  // int to string conversion:
  // TODO: test performance and possibly
  //  implement faster/less expensive method(s)
  std::stringstream ss;
  std::string index;
  ss<<table_num;
  ss>>index;
  // open file of the name by table number plus .txt extension
  std::ifstream iFile(std::string("table") + index + std::string(".txt"));
  // separate into strings that hold lines
  // of the file: these represent individual
  // orders, reserve space for ten(so we don't
  // resize often and maybe even leave space for add-ons
  if(iFile.fail())
    //TODO: define/add file exception
    std::cout<<"nope"<<std::endl;
  // first line will always be server name
  std::getline(iFile, server_name);
  // rest will fill item vector
  itemList.reserve(defaultOrderSize);
  std::string lineString;
  while(!iFile.eof())
  {
    std::getline(iFile, lineString);
    itemList.__emplace_back(lineString);
  }
}

void Order::setTotals(){
  int sum = 0;
  for(auto&&i: itemList)
    sum+=i.price;
  subtotal=sum;
  addTip();
  tax = ceil(.15f*subtotal);
  total=subtotal+tax+tip;
}

void Order::printOrder() {
  setTotals();
  std::cout<<"Order: "<<order_num<<"\n";
  std::cout<<"Server: "<<server_name<<"\ttable "<<table_num<<"\n";
  for(auto&&i : itemList)
    std::cout<<i.name<<" "<<i.price/100<<"\n";
  std::cout<<std::setprecision(5)<<std::left;
  std::cout<<"\t\tsubtotal: "<<subtotal/100<<"\n";
  std::cout<<"\t\ttaxes: "<<tax/100<<"\n";
  std::cout<<"\t\ttip: "<<tip/100<<"\n";
  std::cout<<"\t\ttotal: "<<total/100;
  std::cout<<std::endl;
}

void Order::addItem(std::string itemString) {
  itemList.__emplace_back(itemString);
}

void Order::addTip() {
  double t;
  std::cout<<"Enter what percentage you'd like to tip? ";
  std::cout<<"\nWe recommend\n10%\n15%\n20%\nNo tip, enter 0: ";
  std::cin>>t;
  t/=100.0;
  tip = floor(subtotal*t);
}
