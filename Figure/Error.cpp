#include "Error.h"
#include <string>
#include <iostream>
using namespace std;
Error::Error(string message)
{
	this->message = message;
}

Error::~Error()
{

}
void Error::Show()
{
    cout << "Error " << message << endl;
}
