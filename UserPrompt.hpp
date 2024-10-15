#include <iostream>
#include <limits.h>
#include <optional>

using namespace std;

class UserPrompt {
public:
	static optional<int> prompt_user_for_int(string userInputPrompt, string invalidInputPrompt, int lowerBoundInclusive = INT_MIN, int upperBoundInclusive = INT_MAX, optional<int> defaultValue = nullopt);
	static optional<string> prompt_user_for_string(string userInputPrompt, string invalidInputPrompt);
private:
	static optional<int> tryGetIntFromString(const string stringToCheck);
};