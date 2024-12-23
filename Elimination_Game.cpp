//Elimination game
#include <iostream>
using namespace std;

int lastRemaining(int n) {
    int head = 1;     
    int step = 1;     
    bool left = true; 
    int remaining = n;

    while (remaining > 1) {
        if (left || remaining % 2 == 1) {
            head += step;
        }
        step *= 2;
        remaining /= 2;
        left = !left;
    }

    return head;
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Last remaining number is: " << lastRemaining(n) << endl;

    return 0;
}
