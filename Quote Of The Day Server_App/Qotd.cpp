#include "Qotd.h"
#include <cstdlib>
#include <time.h>

// Constructor
CQotd::CQotd(std::string filename)
{
	std::ifstream file;
	file.open(filename);

	if (file.is_open())
	{
		std::string line;
		std::string running = "";

		while (getline(file, line))
		{
			if (line != "%")
			{
				running = running + line + "\n";
			}

			else
			{
				quotes.push_back(running);
				running = "";
			}
		}
	}
}

// Get random quote from the file function
std::string CQotd::GetRandomQuote()
{
	srand(time(0));
	int r = rand() % quotes.size();
	return quotes[r];
}