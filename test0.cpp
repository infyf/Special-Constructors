#include <iostream>


using namespace std;

class Hotel
{
    const char* name;
    int freeSeats;
    int numberOfSeats;

public:
    Hotel() : name("Unknown"), freeSeats(0), numberOfSeats(0) {
        cout << "Hotel created using default constructor" << endl;
    }


    Hotel(const char* name) : name(name), freeSeats(0), numberOfSeats(0) {
        cout << "Hotel created with one parameter" << endl;
    }

    Hotel(const char* name, int freeSeats) : name(name), freeSeats(freeSeats), numberOfSeats(0) {
        cout << "Hotel created with two parameters" << endl;
    }

    Hotel(const char* name, int freeSeats, int numberOfSeats) : name(name), freeSeats(freeSeats), numberOfSeats(numberOfSeats) {
        cout << "Hotel created with three parameters" << endl;
    }

    Hotel(const Hotel& other) : name(other.name), freeSeats(other.freeSeats), numberOfSeats(other.numberOfSeats) {
        cout << "Hotel created using copy constructor" << endl;
    }


    explicit Hotel(int numberOfSeats) : name("Unknown") {
        cout << "Hotel created using explicit conversion constructor with one parameter" << endl;
    }


    Hotel(double price) : name("Unknown"), freeSeats(0), numberOfSeats(price / 100) {
        cout << "Hotel created using implicit conversion constructor with one parameter" << endl;
    }


    ~Hotel() {
        cout << "Hotel object destroyed" << endl;
    }

    const char* GetName() const {
        return name;
    }


    void SetName(const char* name) {
        this->name = name;
    }

    int GetFreeSeats() const {
        return freeSeats;
    }

    void SetFreeSeats(int freeSeats) {
        this->freeSeats = freeSeats;
    }

    int GetNumberOfSeats() const {
        return numberOfSeats;
    }

    void SetNumberOfSeats(int numberOfSeats) {
        this->numberOfSeats = numberOfSeats;
    }

};


void SummFree(Hotel* hotels, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += hotels[i].GetFreeSeats();
    }
    cout << "Sum of free seats: " << sum << endl;
}

void findByNumberHotels(Hotel* hotels, int size, const char* name)
{
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(name, (hotels + i)->GetName()))
        {
            cout << "id=" << i << endl;
        }
    }
}

void displayHotel(Hotel hotel) {
    cout << "Name: " << hotel.GetName() << ", Free Seats: " << hotel.GetFreeSeats() << ", Number of Seats: " << hotel.GetNumberOfSeats() << endl;
}

void displayHotelByReference(Hotel& hotel) {
    cout << "Name: " << hotel.GetName() << ", Free Seats: " << hotel.GetFreeSeats() << ", Number of Seats: " << hotel.GetNumberOfSeats() << endl;
}

int main()
{


    const int SIZE = 3;
    Hotel hotel;
    Hotel* ptrHotel = &hotel;
    Hotel* hotels = new Hotel[SIZE]{

        Hotel("lux1"),
        Hotel("lux2", 5),
        Hotel("lux3", 4, 5)

    };

    Hotel h("My Hotel", 12, 18);

    displayHotel(h);
    cout << "Displaying hotel by value" << endl;


    displayHotelByReference(h);
    cout << "Displaying hotel by reference" << endl;

    cout << "Search by number hotels: ";
    char numberHotels[5];
    cin.get(numberHotels, 5);
    findByNumberHotels(hotels, SIZE, numberHotels);

    delete[] hotels;
    return 0;
}
