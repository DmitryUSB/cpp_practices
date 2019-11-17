#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int tree_H(const vector<int>& input_vec, int in_node, vector<int>& hights)
{
	int h = 1;
	if (input_vec[in_node] == -1) return h;
	if (hights[in_node] != 0) {
		return hights[in_node];
	}
	else h = 1 + tree_H(input_vec, input_vec[in_node], hights);
	hights[in_node] = h;
	return h;
}

int calc_tree_H(const vector<int>& input_vec, vector<int>& hights)
{
	int result = 0;
	for (int i = 0; i < input_vec.size(); ++i)
	{
		result = max(result, tree_H(input_vec, i, hights));
	}
	return result;
}*/

int tree_H(const vector<int>& input_vec, int in_node)
{
	int h = 1;
	if (input_vec[in_node] == -1) return h;
	else h = 1 + tree_H(input_vec, input_vec[in_node]);
	return h;
}

int calc_tree_H(const vector<int>& input_vec)
{
	int result = 0;
	for (int i = 0; i < input_vec.size(); ++i)
	{
		result = max(result, tree_H(input_vec, i));
	}
	return result;
}

int main()
{
	int n, input;
	int output = 0;
	vector<int> in_vec;
	cin >> n;
	vector<int> tree_hights(n, 0);
	while (cin >> input)
	{
		in_vec.push_back(input);
	}
	
	cout << calc_tree_H(in_vec/*, tree_hights*/);
	return 0;
}