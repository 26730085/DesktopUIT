#include "Candidate.h"
#include <iomanip>

Candidate::Candidate() : maSo(""), hoTen(""), gioiTinh(true), namSinh(2000), dtb(0.0f) {}

Candidate::Candidate(string maSo, string hoTen, bool gioiTinh, int namSinh, float dtb)
    : maSo(maSo), hoTen(hoTen), gioiTinh(gioiTinh), namSinh(namSinh), dtb(dtb) {}

Candidate::Candidate(const Candidate& candidate) {
    this->maSo = candidate.maSo;
    this->hoTen = candidate.hoTen;
    this->gioiTinh = candidate.gioiTinh;
    this->namSinh = candidate.namSinh;
    this->dtb = candidate.dtb;
}

Candidate::~Candidate() {}

void Candidate::input() {
    cout << "Nhap ma so: ";
    getline(cin >> ws, maSo);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap gioi tinh (1 - Nam, 0 - Nu): ";
    cin >> gioiTinh;
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    cout << "Nhap diem trung binh: ";
    cin >> dtb;
}

void Candidate::output() const {
    cout << left << setw(10) << maSo
         << setw(25) << hoTen
         << setw(10) << (gioiTinh ? "Nam" : "Nu")
         << setw(10) << namSinh
         << fixed << setprecision(2) << dtb << endl;
}

int Candidate::getTuoi() const {
    return 2026 - namSinh;
}

istream& operator>>(istream& is, Candidate& candidate) {
    candidate.input();
    return is;
}

ostream& operator<<(ostream& os, const Candidate& candidate) {
    os << left << setw(10) << candidate.maSo
       << setw(25) << candidate.hoTen
       << setw(10) << (candidate.gioiTinh ? "Nam" : "Nu")
       << setw(10) << candidate.namSinh
       << fixed << setprecision(2) << candidate.dtb;
    return os;
}
