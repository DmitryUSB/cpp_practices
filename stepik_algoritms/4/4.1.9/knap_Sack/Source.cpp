#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

struct Item final {
	int weight;
	int value;
};

struct CostByWeightSort final {
	bool operator () (Item i, Item j) {
		return (double(i.value) / i.weight > double(j.value) / j.weight);
	}
} sort_by_cost_per_weight;

bool comp(Item a, Item b) {
	return double(a.value)/a.weight > double(b.value)/b.weight;
}

double get_max_knapsack_value(int capacity, std::vector <Item> items) {
	double value = 0.0;
		std::cout << std::endl << " Items after sort: " << std::endl;
	// sort items by cost per weight
	std::sort(items.begin(), items.end(), comp);
		for (int i = 0; i < items.size(); i++) { std::cout << i << ")" << " v-" << items[i].value << " w-" << items[i].weight << std::endl; }
	// take items while there is empty space in knapsack
	for (auto& item : items) {
		if (capacity > item.weight) {
				std::cout << "Take this: v-" << item.value << " w-" << item.weight << std::endl;
			capacity -= item.weight;
				std::cout << " cap: " << capacity << std::endl;
			value += item.value;
				std::cout << " curr val: " << value << std::endl;
		}
		else {
				std::cout << "Take part of this: v-" << item.value << " w-" << item.weight << std::endl;
			value += item.value * (static_cast <double>(capacity) / item.weight);
				std::cout << " else val: " << value << std::endl;
			break;
		}
	}

	return value;
}

int main(void) {
	int number_of_items;
	int knapsack_capacity;
		std::cout << std::endl;
	std::cin >> number_of_items >> knapsack_capacity;
		std::cout << "Numb of items: " << number_of_items << " Sack cap: " << knapsack_capacity << std::endl;
	std::vector <Item> items(number_of_items);
	std::cout << " Items: " << std::endl;
	for (int i = 0; i < number_of_items; i++) {
		std::cin >> items[i].value >> items[i].weight;
			std::cout << i << ")" << " v-" << items[i].value << " w-" << items[i].weight << std::endl;
	}

	double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

	std::cout.precision(3);
	std::cout.setf(std::ios::fixed);
	std::cout << max_knapsack_value << std::endl;
	return 0;
}