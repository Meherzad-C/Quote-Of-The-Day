#pragma once

#include <string>
#include <fstream>
#include <vector>

class CQotd
{
private:

	std::vector<std::string> quotes;

public:

	// Constructor
	CQotd(std::string filename);

	// Get random quote from the file function
	std::string GetRandomQuote();
};
