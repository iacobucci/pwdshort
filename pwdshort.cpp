#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>
#include <unistd.h>

#define MAXCHAR 4
#define SEPARATOR '/'
#define HOMESIGN '~'
#define TRAILINGSIGN '+'
#define DOTFILES true

using namespace std;

void print(string cwd, string home);

int main() {
	string cwd(getenv("PWD"));
	string home(getenv("HOME"));

	if (cwd.compare(home) == 0) {
		cout << HOMESIGN;
		return 0;
	}

    stringstream output;

	if (cwd.rfind(home, 0) == 0) {
		output << HOMESIGN << SEPARATOR;
		cwd = cwd.substr(home.length() + 1, cwd.length());
	} else {
		output << SEPARATOR;
		cwd = cwd.substr(1, cwd.length());
	}

	stringstream dir(cwd);
	string segment;

	int s = 0;
	for (char c : cwd)
		if (c == '/')
			s++;

	int i = 0;
	int dot = 0;
	while (getline(dir, segment, SEPARATOR) && i != s) {

		if (segment[0] == '.' && DOTFILES)
			dot = 1;

		if (segment.length() > MAXCHAR)
			output << segment.substr(0, MAXCHAR - 1 + dot) << TRAILINGSIGN << SEPARATOR;
		else
			output << segment << SEPARATOR;

		i++;
		dot = 0;
	}

	cout << output.str() << segment;

	return 0;
}
