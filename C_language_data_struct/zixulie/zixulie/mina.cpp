#include<iostream>
using namespace std;
int main() {
    long value = -1000, now_value;
    int a[1000];
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> a[i];
    int fin = num;
    while (fin > 0) {
        for (int i = 0; i <= num - fin; i++)
        {
            now_value = 0;
            for (int j = 0; j < fin; j++)
                now_value += a[j + i];
            if (now_value > value)
                value = now_value;
        }

        fin--;
    }
    cout << value;
}