#include <iostream>
#include <string>

using namespace std;

class House {
  private:
    string address;
    unsigned int area;
    unsigned int price;

  public:
    House(string address, unsigned int area) {
        this->address = address;
        this->area = area;
        this->price = 400;
    }

    ~House() {

    }

    unsigned int get_price() {
      return this->price * this->area;
    }

};

int main() {

  // The market price of the houses is 400 EUR / square meters
  // Make the get_price() function work
  // Create a constructor for the House class that takes it's address and area.

  House house = House("Andrassy 66", 349);
  cout << house.get_price();

  return 0;
}
