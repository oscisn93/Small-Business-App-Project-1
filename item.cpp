//
// Created by Oscar Cisneros on 1/17/20.
//
#include <string>
#include <iostream>
#include "utils.cpp"

struct item {
    std::string name;
    double price;
    std::string special_instructions;
    item(std::string& s)
    {
      int first_idx=0;
      int substr_idx = s.find(' ');
      name=s.substr(first_idx, substr_idx);
      first_idx=substr_idx+1;
      substr_idx=s.find(' ',first_idx);
      std::string p=s.substr(first_idx, substr_idx).substr(0, substr_idx-first_idx);
      std::cout<<p<<std::endl;
      price = utils::to_double(p);
      special_instructions=s.substr(substr_idx+1, s.size());
    }
};
