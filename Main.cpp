#include <iostream>
#include "UserPrompt.hpp"

using namespace std;

// Add-on #2 Implementation Explanation:
// I chose the prompt_user_for_int method to return an optional<int> as it will allow the program to return an integer if a number was provided,
// or to return 'nullopt' if none was provided. This will make it so the developer will know if a valid integer was provided or not, instead of
// returning one of the bounds (which would be bad if the user didn't actually want those to be inputted, or throwing off our data) 
// or throwing an error (this would be bad if it through an error everytime a user tried to exit).

template<typename T>
void try_print_user_input(optional<T> userInput) {
	if (!userInput.has_value()) {
		cout << "User exited the input prompt." << endl;
		cout << "" << endl;
		return;
	}

	cout << "User inputted: " << userInput.value() << endl;
	cout << "" << endl;
}	

void test_int_user_input() {
	optional<int> userInput = UserPrompt::prompt_user_for_int("Please input a number between 0 and 100: ", "Invalid value, try again.", 0, 100);
	try_print_user_input(userInput);

	userInput = UserPrompt::prompt_user_for_int("Please input any number: ", "Invalid value, try again.");
	try_print_user_input(userInput);

	userInput = UserPrompt::prompt_user_for_int("Please input any number greater than 0: ", "Invalid value, try again.", 0);
	try_print_user_input(userInput);

	userInput = UserPrompt::prompt_user_for_int("Please input any number between 0 and 1: ", "Invalid value, try again.", 0, 1);
	try_print_user_input(userInput);

	userInput = UserPrompt::prompt_user_for_int("Please input any number between -100 and 100.", "Invalid value, try again.", -100, 100, 1);
	try_print_user_input(userInput);
}

void test_string_user_input() {
	optional<string> userStringInput = UserPrompt::prompt_user_for_string("Please input any string: ", "Invalid string, try again.");
	try_print_user_input(userStringInput);

	userStringInput = UserPrompt::prompt_user_for_string("Please input any string again: ", "Invalid string, try again.");
	try_print_user_input(userStringInput);
}

void test_driver() {
	test_int_user_input();
	test_string_user_input();
}

int main() {
	test_driver();

	return 0;
}