#pragma once
#include <string>
using namespace std;
class Error
{
private:
    string message;
public:
    Error(string message);
    ~Error();
	void Show();
};

