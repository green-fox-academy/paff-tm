#include <iostream>
#include <string>

using namespace std;

class Pirate{
    private:
        unsigned int drinked_rum;

    public:
        Pirate() {
            drinked_rum = 0;
        }

        ~Pirate() {
            if (drinked_rum > 5) {
                cout << "I died drunk, yeah...! " << endl;;
            } else {
                cout << "Hey, I was still thirsty... Arrr..." << endl;
            }
        }

        void drink_rum() {
            drinked_rum++;
        }

        void hows_goin_mate() {
            if (drinked_rum > 5) {
                cout << "Arrrr!" << endl;
            } else {
                cout << "Nothin\'" << endl;
            }
        }

};

int main()
{
    // create a pirate class
    // it should have 2 methods
    // drink_rum()
    // hows_goin_mate()
    // if the drink_rum was called at least 5 times:
    // hows_goin_mate should return "Arrrr!"
    // "Nothin'" otherwise

    Pirate pirate;


    return 0;
}
