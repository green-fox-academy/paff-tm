#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL)); // This initializes the random generator.
	int rnd = 0;
	for (int i = 0; i < 20; ++i) {
		rnd = rand() % 5; // generate a random number in the range [0, 4]
		try {
			switch (rnd) {
				case 0:
					throw 3.2f;
					break;
				case 1:
					throw double(43.56);
					break;
				case 3:
					throw "Abrakadabra";
					break;
				case 4:
					throw false;
					break;
				default:
					throw 12;
					break;
			}
		}
// Write catch blocks for each possibly thrown exception.
// In each catch block write out what the exception's type was. And what the exceptions value was.
        catch (float f) {
            cout << "float: " << f << endl;
        }
        catch (double d) {
            cout << "double: " << d << endl;
        }
        catch (const char *c) {
            cout << "char: " << c << endl;
        }
        catch (bool b) {
            cout << "bool: " << b << endl;
        }
        catch (int i) {
            cout << "integer: " << i << endl;
        }
        catch (...) {
            cout << "default error" << endl;
        }
	}

	return 0;
}
