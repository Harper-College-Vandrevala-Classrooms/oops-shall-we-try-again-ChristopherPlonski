#include <iostream>
#include <limits.h>
#include <optional>

using namespace std;

class UserPrompt {
public:
	static int prompt_user_for_int(string userInputPrompt, string invalidInputPrompt, int lowerBoundInclusive = INT_MIN, int upperBoundInclusive = INT_MAX, int defaultValue = 0);
};