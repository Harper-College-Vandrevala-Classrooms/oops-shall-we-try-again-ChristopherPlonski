#include <iostream>
#include "UserPrompt.hpp"

using namespace std;

int main() {
	int userInput = UserPrompt::prompt_user_for_int("Please input a number between 0 and 100: ", "Invalid value, try again.", 0, 100);

	cout << "User inputted: " << userInput << endl;

	userInput = UserPrompt::prompt_user_for_int("Please input any number: ", "Invalid value, try again.");

	cout << "User inputted: " << userInput << endl;

	userInput = UserPrompt::prompt_user_for_int("Please input any number greater than 0: ", "Invalid value, try again.", 0);

	cout << "User inputted: " << userInput << endl;

	userInput = UserPrompt::prompt_user_for_int("Please input any number between 0 and 1: ", "Invalid value, try again.", 0, 1);

	cout << "User inputted: " << userInput << endl;

	userInput = UserPrompt::prompt_user_for_int("Please input any number between -100 and 100.", "Invalid value, try again.", -100, 100, 1);

	cout << "User inputted: " << userInput << endl;
}