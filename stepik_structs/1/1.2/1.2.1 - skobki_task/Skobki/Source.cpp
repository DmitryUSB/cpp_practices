#include <iostream>
#include <stack>
#include <string>
#include <utility>

using namespace std;

string skobki(string input_string) {
	stack<pair<char, int>> char_stack;
	char top_char;
	for (int i = 0; i < input_string.size(); ++i) {
			/*if (!char_stack.empty()) {
				top_char = get<0>(char_stack.top());
				if ((top_char == '(' && input_string[i] == ')') ||
					(top_char == '[' && input_string[i] == ']') ||
					(top_char == '{' && input_string[i] == '}'))
				{
					char_stack.pop();
					continue;
				}
			}
			if (char_stack.empty() && (input_string[i] == ')' || input_string[i] == ']' || input_string[i] == '}'))
			{
				return to_string(i+1);
			}
			else if (input_string[i] == '(' || input_string[i] == '[' || input_string[i] == '{' ||
					 input_string[i] == ')' || input_string[i] == ']' || input_string[i] == '}'   )
			{
				char_stack.push(make_pair(input_string[i], i));
			}*/
		if (input_string[i] == '(' || input_string[i] == '[' || input_string[i] == '{')
		{
			char_stack.push(make_pair(input_string[i], i));
		}
		else if (input_string[i] == ')' || input_string[i] == ']' || input_string[i] == '}')
		{
			if (char_stack.empty()) return to_string(i + 1);
			top_char = get<0>(char_stack.top());
			if ((top_char == '(' && input_string[i] != ')') ||
				(top_char == '[' && input_string[i] != ']') ||
				(top_char == '{' && input_string[i] != '}'))
			{
				return to_string(i + 1);
			}
			else char_stack.pop();
		}
	}
	if (char_stack.empty()) return "Success";
	else return to_string(get<1>(char_stack.top())+1);
}

int main()
{
	
	string input_str;
	getline(cin,input_str);
	
	cout << skobki(input_str) << endl;

	return 0;
}