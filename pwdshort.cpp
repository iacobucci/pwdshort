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

int main()
{

  char _cwd[PATH_MAX];
  if (getcwd(_cwd, sizeof(_cwd)) == NULL)
    return -1;

  string cwd(_cwd);
  string home(getenv("HOME"));

  if (cwd.rfind(home, 0) == 0) {
    cout << HOMESIGN << SEPARATOR;
    cwd = cwd.substr(home.length() + 1, cwd.length());
  } else {
    cout << SEPARATOR;
    cwd = cwd.substr(1, cwd.length());
  }

  stringstream dir(cwd);
  string t;

  int s = 0;
  for (auto c : cwd)
    if (c == '/')
      s++;

  int i = 0;
  int dot = 0;
  while (getline(dir, t, SEPARATOR) && i != s) {

    if (t[0] == '.' && DOTFILES)
      dot = 1;

    if (t.length() > MAXCHAR)
      cout << t.substr(0, MAXCHAR - 1 + dot) << TRAILINGSIGN
           << SEPARATOR;
    else
      cout << t << SEPARATOR;

    i++;
    dot = 0;
  }

  cout << t;

  return 0;
}
