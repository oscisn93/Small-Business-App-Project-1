//
// Created by Oscar Cisneros on 1/17/20.
//

#include <sstream>

class utils {
public:
    struct dailyTotals{
        int orders = 0;
        int newOrder(){
          orders++;
          return orders;
        }
    };
    static double to_double(std::string& d){
      double value;
      std::stringstream num_stream(d);
      num_stream>>value;
      return value;
    }
};
