#include <cstdlib>
#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <tuple>
#include <sstream>
#include <list>

using namespace std;

class Product
{
public:
	string ProductName;
	double Price;
	double Weight;
	int Quantity;
	string PricingMethod;
};

int main(int argc, char **argv)
{
	list<Product> items;
	Product item1;
	item1.ProductName = "Pulled Pork";
	item1.Price = 6.99;
	item1.Weight = 0.5;
	item1.PricingMethod = "PerPound";
	items.push_back(item1);

	Product item2;
	item2.ProductName = "Coke";
	item2.Price = 3;
	item2.Quantity = 2;
	item2.PricingMethod = "PerItem";
	items.push_back(item2);

	tuple<string, list<Product>> order("John Doe", items);

	double price = 0;
	ostringstream orderSummary;

	orderSummary << "ORDER SUMMARY FOR " << std::get<0>(order) 
	       << ":" << endl;

	for(auto orderProduct = get<1>(order).begin();
			orderProduct != get<1>(order).end();
			++orderProduct) {
		double productPrice = 0;
		orderSummary << orderProduct->ProductName;

		if (orderProduct->PricingMethod == "PerPound")
		{
			productPrice = orderProduct->Weight * orderProduct->Price;
			price += productPrice;
			orderSummary << " $" << fixed << setprecision(2)
				<< productPrice << " (" 
				<< fixed << setprecision(1)
				<< orderProduct->Weight
				<< " pounds at $"
				<< fixed << setprecision(2)
				<< orderProduct->Price
				<< " per pound)";
		}
		else {
			productPrice = orderProduct->Quantity * orderProduct->Price;
			price += productPrice;
			orderSummary << " $" << productPrice << " ("
				<< fixed << setprecision(1)
				<< orderProduct->Quantity
				<< " items at $"
				<< fixed << setprecision(2)
				<< orderProduct->Price
				<< " each)";
		}
		orderSummary << endl;
	}

	cout << orderSummary.str() << endl;
	cout << "Total Price: $" << fixed << setprecision(2) 
		<< price << endl;

	return EXIT_SUCCESS;
}
