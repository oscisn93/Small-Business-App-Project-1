#include "Order.h"
#include "utils.h"
#include <string>
#include <vector>
#include <stack>

#define TABLES 20

class OrderManager {
	// the stack will contain all unstarted orders
	std::stack<Order> orders;
	//orders being displayed, will
	// vary based on user
	std::vector<Order> displayedOrders:
	displayedOrders.reserve(10);
	std::map<int, std::string> servers;
	// array of table statuses. 
	// False means in-use, True means empty
	bool table_status[TABLES];
	
	Order createOrder(std::string server_id);

	void addToOrder();
	void deleteItems();
	void startOrder();
	void finshOrder();

}
template<typename T>
void setAllTo(T[] arr, T value){
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i<size; i++)
		arr[i] = value;
}
