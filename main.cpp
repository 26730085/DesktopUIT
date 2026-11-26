#include <iostream>
#include "KhoaHoc.h"

using namespace std;

int main() {
    KhoaHoc kh;

    cout << "=== 1. THEM THI SINH ===" << endl;
    kh.them(new Candidate("TS03", "Nguyen Van C", true, 2004, 8.5));
    kh.them(new Candidate("TS01", "Tran Thi A", false, 2005, 9.2));
    kh.them(new Candidate("TS02", "Le Van B", true, 2003, 7.8));
    
    Candidate* trungMa = new Candidate("TS01", "Trung Ma", true, 2000, 5.0);
    if (!kh.them(trungMa)) {
        cout << "-> Da chan them trung ma TS01 thanh cong!\n\n";
        delete trungMa;
    }
    kh.xuatDanhSach();

    cout << "=== 2. SAP XEP THEO DTB TANG DAN ===" << endl;
    kh.sapXep(DTB);
    kh.xuatDanhSach();

    cout << "=== 3. SAP XEP THEO HO TEN ===" << endl;
    kh.sapXep(HO_TEN);
    kh.xuatDanhSach();

    cout << "=== 4. TIM KIEM MA SO TS01 ===" << endl;
    Candidate* tim = kh.timTheoMaSo("TS01");
    if (tim != nullptr) {
        cout << "Ket qua: " << *tim << "\n\n";
    }

    cout << "=== 5. TIM KIEM THEO HO TEN 'Van' ===" << endl;
    vector<Candidate*> dsTen = kh.timTheoHoTen("Van");
    for (Candidate* c : dsTen) {
        cout << *c << endl;
    }
    cout << endl;

    cout << "=== 6. TIM KIEM THEO DTB 8.5 ===" << endl;
    vector<Candidate*> dsDtb = kh.timTheoDTB(8.5f);
    for (Candidate* c : dsDtb) {
        cout << *c << endl;
    }
    cout << endl;

    cout << "=== 7. XOA THI SINH TS02 ===" << endl;
    Candidate* daXoa = kh.xoa("TS02");
    if (daXoa != nullptr) {
        cout << "Da xoa: " << daXoa->getHoTen() << "\n\n";
        delete daXoa;
    }
    kh.xuatDanhSach();

    return 0;
}
