#include <iostream>

#define MAX 100

using namespace std;

void SUM(int iA, int iB)
{
    int iS = iA + iB;
    cout << "n = " << iS << "\n";
}

void NhapMang(int* iArr, int iLength)
{
    for (int i = 0; i < iLength; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> iArr[i];
    }
}

void XuatMang(const int* iArr, int iLength)
{
    for (int i = 0; i < iLength; i++)
    {
        cout << iArr[i] << " ";
    }
}

int main()
{
    /*
    * Biến con trỏ có 2 loại chính.
    * 1. Biến con trỏ biến: dùng để trỏ vào biến.
    * 2. Biến con trỏ hàm: dùng để trỏ vào hàm.
    * 
    * Biến thường có 2 phần:
    * 1. Giá trị.
    * 2. Địa chỉ lưu giá trị - thuộc vùng nhớ stack.
    * Biến con trỏ có 3 phần:
    * 1. Giá trị.
    * 2. Địa chỉ thật - thuộc vùng nhớ stack.
    * 3. Miền địa chỉ(hay gọi là vùng nhớ):
    *   _ Số lượng địa chỉ tuỳ thuộc vào cấp độ con trỏ.
    *   _ Cấp 1 -> 1 địa chỉ, cấp 2 -> 2 địa chỉ,...
    *   _ Thuộc vùng nhớ stack hoặc heap -> xem ví dụ.
    */

    // Biến thường.
    // int iA = 5; // Gán cho a giá trị 5.
    // cout << "Bien Thuong\n";
    // cout << "1. Gia tri: " << iA << "\n";
    // cout << "2. Dia chi: " << &iA << "\n";

    // Biến con trỏ.
    // Trường hợp 1
    // <kieu du lieu>* <tên biến con trỏ>;
    // int* iPtr = &iA; // Trỏ vào biến a.
    // cout << "\nBien Con Tro\n";
    // cout << "TH1: Tro Vao Bien a\n";
    // cout << "1. Gia tri: " << *iPtr << "\n";
    // cout << "2. Dia chi that = " << &iPtr << "\n";
    // cout << "3. Vung nho: " << iPtr << "\n";

    // Trường hợp 2
    // int* iPtrInt = new int; // Cấp phát bộ nhớ.
    // *iPtrInt = 9; // Gán giá trị cho biến con trỏ.
    // cout << "\nTH2: Cap Phat Bo Nho.\n";
    // cout << "1. Gia tri: " << *iPtrInt << "\n";
    // cout << "2. Dia chi that: " << &iPtrInt << "\n";
    // cout << "3. Vung nho: " << iPtrInt << "\n";
    
    // Tăng giá trị.
    // (*iPtrInt)++;
    // cout << "Gia tri con tro iPtrInt sau khi tang: " << *iPtrInt << "\n";

    // Tăng vùng nhớ
    // iPtrInt++;
    // cout << "Gia tri: " << *iPtrInt << "\n";
    // cout << "Vung nho: " << iPtrInt << "\n";

    // Con trỏ vô kiểu void.
    // void* iPtrVoid;

    // short iN = 5;

    // iPtrVoid = &iN;
    // cout << "\nCon Tro Vo Kieu(void)\n";
    // cout << "Gia tri khi tro vao iN: " << *static_cast<short*>(iPtrVoid) << "\n";

    // int* iPtrInt = new int;
    // *iPtrInt = 9;

    // iPtrVoid = iPtrInt;
    // cout << "Gia tri khi tro vao iPtr1: " << *static_cast<int*>(iPtrVoid) << "\n";

    // double* iPtrDbl = new double;
    // *iPtrDbl = 6.6;

    // iPtrVoid = iPtrDbl;
    // cout << "Gia tri khi tro vao iPtrDbl: " << *static_cast<double*>(iPtrVoid) << "\n";

    // delete iPtrDbl;
    // delete iPtrInt; // Giải phóng bộ nhớ.

    // Con trỏ hằng.
    // const int iN = 5;
    // int iA = 8;
    // const int* iPtrC1; // Cách 1.
    // int const* iPtrC2; // Cách 2.

    // 1. Dùng để trỏ vào vùng nhớ hằng.
    //int* iPtrInt = iN;
    // iPtrC1 = &iN;
    // cout << "Gia tri tro vung nho hang: " << *iPtrC1 << "\n";

    // 2. Có thể thay đổi địa chỉ.
    // iPtrC1 = &iA;
    // cout << "Gia tri tro vung nho thuong: " << *iPtrC1 << "\n";

    // 3. Không thể thay đổi giá trị.
    //*iPtrC1 = 6;
    //(*iPtrC1)++;

    // Hằng con trỏ
    // 1. Lỗi không khởi tạo.
    //int* const iPtr1;

    // 2. Không thể thay đổi địa chỉ.
    //int iA = 8;
    //int* const iPtr2 = &iA;

    //int iB = 5;
    //iPtr2 = &iB;

    // 3. Thay đổi giá trị.
    //cout << "Gia tri.\n";
    //cout << "Chua thay doi: " << iA << "\n";
    //(*iPtr2)++;
    //cout << "Da thay doi: " << iA << "\n";

    // 4. Không thể trỏ vào vùng nhớ hằng.
    //const int iN = 5;
    //int* const iPtr3 = &iN;

    // int* iPtr = nullptr;

    // cout << "Con tro nullptr: " << (int*)nullptr << "\n";
    // cout << "Gia tri NULL: " << (int*)NULL << "\n";
    // cout << "Vung nho cua iPtr: " << iPtr << "\n";
    // cout << "Dia chi that cua con tro iPtr: " << &iPtr << "\n";

    // ******
    // int iN = 5;
    // SUM(6, 8);
    // cout << "Ket Thuc Chuong Trinh\n";

    // Mảng 1 chiều tĩnh.
    // int iLengthS = 6;
    // int iArrStatic[MAX]; // Xin OS cấp phát cho 100 ô nhớ, và đồng thời 100 ô nhớ này không được thay đổi(cố định).
    // NhapMang(iArrStatic, iLengthS);
    // XuatMang(iArrStatic, iLengthS);

    // Cấp phát động cho mảng 1 chiều(mảng 1 chiều động).
    // int iLength = 6;
    // int* iArr = new int[iLength]; // Xin OS cấp phát ô nhớ theo biến length, có thể co dãn ô nhớ.

    // NhapMang(iArr, iLength);
    // cout << "Mang sau khi vao la: ";
    // XuatMang(iArr, iLength);

    // delete[] iArr;

    const int iCons = 6; // Khai báo và khởi tạo.
    const int* iPtrCons; // Khai báo hoặc khởi tạo. C1.
    int const* iPtrConsC2; // C2.
    //iPtrCons = &iCons;
    //*iPtrCons = 10;

    int iB = 8;
    iPtrCons = &iB;
    //*iPtrCons = 10;

    //int* iPtrInt = &iCons; // Error.
    int* iPtrInt = &iB;
    *iPtrInt = 16;
    cout << "iB thay doi boi iPtrInt: " << iB << "\n";

    int* const iPtrConst = &iB; // Bắt buột phải khởi tạo khi khai báo.
    *iPtrConst = 20;
    cout << "iB thay doi boi iPtrConst: " << iB << "\n";
    //int iC = 26;
    //iPtrConst = &iC;
    int a[] = { 6, 10, 16, 100, 66 };
    cout << "Dia chi cua mang 1 chieu tinh\n";
    // cout << "Cach 1: " << &a << "\n";
    // cout << "Cach 2: " << &a[0] << "\n";
    // cout << "Cach 3: " << a << "\n";
    // cout << "Phan tu thu 2: " << &a[1] << "\n";
    // cout << "Phan tu thu 3: " << &a[2] << "\n";
    // cout << "Phan tu thu 4: " << &a[3] << "\n";
    // cout << "Phan tu thu 5: " << &a[4] << "\n";

    // cout << "Phan tu thu 1: " << *a << "\n";
    // cout << "Phan tu thu 2: " << *(a + 1) << "\n"; // a[1]
    // cout << "Phan tu thu 3: " << *(a + 2) << "\n"; // a[2]
    // cout << "Phan tu thu 4: " << *(a + 3) << "\n";
    // cout << "Phan tu thu 5: " << *(a + 4) << "\n";

    // int* iPtr = &a[2];
    // cout << "Gia tri o a2 tu con tro Ptr: " << *iPtr << "\n";
    // cout << "Gia tri o a1 tu con tro Ptr: " << *(iPtr - 1) << "\n";
    // cout << "Gia tri o a4 tu con tro Ptr: " << *(iPtr + 2) << "\n";
    // iPtr++;
    // cout << "Gia tri Ptr sau khi di chuyen: " << *iPtr << "\n"; // 100
    // cout << "Gia tri o a1 tu con tro Ptr: " << *(iPtr + 1) << "\n"; // 66
    // cout << "Gia tri o a4 tu con tro Ptr: " << *(iPtr - 2) << "\n"; // 10

    // for (int* i = &a[0]; i <= &a[4]; i++)
    // {
    //     cout << *i << " "; // cout << a[i] << " ";
    //     cout << "Dia chi: " << i << "\n";
    // }

    int* iPtr = a;
    // for (int i = 0; i < 5; i++)
    // {
    //     // cout << a[i] << " ";
    //     cout << *(iPtr + i) << " ";
    // }

    cout << typeid(a).name() << endl; // int [5]
    cout << sizeof(a) << endl; // 20
    cout << typeid(iPtr).name() << endl; // int *
    cout << sizeof(iPtr) << endl; // 4
    int iM;
    cout << "b = " << typeid(a).name() << "\n";
}
