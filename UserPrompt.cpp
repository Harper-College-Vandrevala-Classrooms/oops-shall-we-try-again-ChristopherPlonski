#include <iostream>
#include <limits.h>
#include <string>
#include "UserPrompt.hpp"

using namespace std;

int UserPrompt::prompt_user_for_int(string userInputPrompt, string invalidInputPrompt, int lowerBoundInclusive, int upperBoundInclusive, int defaultValue) {
	int userIntInput;

	const bool HAS_DEFAULT_VALUE = defaultValue != 0;
	cout << "DEBUG: Default Value: " << defaultValue << ". HAS_DEFAULT_VALUE: " << HAS_DEFAULT_VALUE << endl;
	bool isValidPromptGotten = false;

	while (!isValidPromptGotten) {
		cout << userInputPrompt;
		if (HAS_DEFAULT_VALUE) {
			cout << " Enter \"default\" to use default of: " << defaultValue;
		}
		cout << endl;

		string userInput;

		getline(cin, userInput);
		userIntInput = stoi(userInput);

		if (HAS_DEFAULT_VALUE && userInput == "default") {
			isValidPromptGotten = true;
			userIntInput = defaultValue;
		}
		else if (lowerBoundInclusive <= userIntInput && userIntInput <= upperBoundInclusive) {
			// A valid prompt in the range was given
			isValidPromptGotten = true;
		}
		else {
			// An invalid prompt was given
			cout << invalidInputPrompt << endl;
		}
	}

	return userIntInput;
}
