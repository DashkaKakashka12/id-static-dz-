#include <iostream>
#include <ctime>

using namespace std;


class Human {
private:
    string name;
    int age;
    int* id;

    static int allList[100][5];
    static int count;

    bool isIdHere(int candidate[5]) {
        for (int i = 0; i < count; i++) {
            bool same = true;
            for (int p = 0; p < 5; p++) {
                if (candidate[p] != allList[i][p]) {
                    same = false;
                    break;
                }
            }
            if (same) return true;
        }
        return false;
    }

public:

    Human(string name, int age) {
        this->name = name;
        this->age = age;
        id = new int[5];

        int candidate[5];
        bool unique = false;

        while (!unique) {
            for (int i = 0; i < 5; i++) {
                candidate[i] = rand() % 9;
            }
            unique = !isIdHere(candidate);
        }

        for (int i = 0; i < 5; i++) {
            id[i] = candidate[i];
            allList[count][i] = candidate[i];
        }

        count++;
        
    }

    void Print() {
        cout << name << " " << age << endl;

        for (int i = 0; i < 5; i++) {
            cout << id[i];
        }

        cout << endl << endl;
    };

    ~Human() {
        delete[] id;
    }


};

int Human::allList[100][5] = { 0 };
int Human::count = 0;


int main()
{
    setlocale(LC_ALL, "RU");
    
    Human Dasha("Dasha", 12);
    Dasha.Print();
    Human Sasha("Sasha", 14);
    Sasha.Print();
    Human Masha("Masha", 14);
    Masha.Print();
}
