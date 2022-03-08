#include <iostream>

using namespace std;

void setToNull(int*& iPtr)
{
    iPtr = nullptr;
}

int main()
{
    int iA = 5;
    int* iPtr = &iA;
    cout << "Chua gan null: " << iPtr << "\n";
    setToNull(iPtr);
    if (iPtr == nullptr)
    {
        cout << "Set null\n";
    }
    else
    {
        cout << "Not null: " << iPtr << "\n";
    }
}
