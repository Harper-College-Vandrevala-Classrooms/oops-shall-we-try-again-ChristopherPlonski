#include <iostream>
#include <limits.h>
#include <string>
#include <optional>
#include "UserPrompt.hpp"

using namespace std;

// Checks if the string can be converted to an integer
optional<int> tryGetIntFromString(const string stringToCheck)
{
	int convertedIntFromString;
	try
	{
		// Convert string to int
		convertedIntFromString = stoi(stringToCheck);
	}
	catch (const invalid_argument& e)
	{
		return nullopt;
	}
	catch (const out_of_range& e)
	{
		return nullopt;
	}

	return convertedIntFromString;
}

int UserPrompt::prompt_user_for_int(string userInputPrompt, string invalidInputPrompt, int lowerBoundInclusive, int upperBoundInclusive, optional<int> defaultValue) {
	int userIntInput;

	const bool HAS_DEFAULT_VALUE = defaultValue.has_value();
	cout << "HAS_DEFAULT_VALUE: " << HAS_DEFAULT_VALUE << endl;
	bool isValidPromptGotten = false;

	while (!isValidPromptGotten) {
		cout << userInputPrompt;
		if (HAS_DEFAULT_VALUE) {
			cout << " Enter \"default\" to use default of: " << defaultValue.value();
		}
		cout << endl;

		string userStringInput;

		getline(cin, userStringInput);
		optional<int> optionalUserIntInput = tryGetIntFromString(userStringInput);

		if (HAS_DEFAULT_VALUE && userStringInput == "default") {
			isValidPromptGotten = true;
			userIntInput = defaultValue.value();
		}
		else if (optionalUserIntInput.has_value() && lowerBoundInclusive <= optionalUserIntInput && optionalUserIntInput <= upperBoundInclusive) {
			// A valid prompt in the range was given
			isValidPromptGotten = true;
			userIntInput = optionalUserIntInput.value();
		}
		else {
			// An invalid prompt was given
			cout << invalidInputPrompt << endl;
		}
	}

	return userIntInput;
}
