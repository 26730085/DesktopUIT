#include "KhoaHoc.h"
#include <algorithm>
#include <cmath>
#include <iomanip>

KhoaHoc::KhoaHoc() {}

KhoaHoc::~KhoaHoc() {
    for (Candidate* c : dsThiSinh) {
        delete c;
    }
    dsThiSinh.clear();
}

bool KhoaHoc::them(Candidate* candidate) {
    if (candidate == nullptr) return false;
    if (timTheoMaSo(candidate->getMaSo()) != nullptr) {
        return false;
    }
    dsThiSinh.push_back(candidate);
    return true;
}

Candidate* KhoaHoc::xoa(string maso) {
    for (auto it = dsThiSinh.begin(); it != dsThiSinh.end(); ++it) {
        if ((*it)->getMaSo() == maso) {
            Candidate* removed = *it;
            dsThiSinh.erase(it);
            return removed;
        }
    }
    return nullptr;
}

Candidate* KhoaHoc::xoa(Candidate* candidate) {
    if (candidate == nullptr) return nullptr;
    return xoa(candidate->getMaSo());
}

Candidate* KhoaHoc::timTheoMaSo(string maSoThiSinh) {
    for (Candidate* c : dsThiSinh) {
        if (c->getMaSo() == maSoThiSinh) {
            return c;
        }
    }
    return nullptr;
}

vector<Candidate*> KhoaHoc::timTheoHoTen(string hoTenThiSinh) {
    vector<Candidate*> ketQua;
    for (Candidate* c : dsThiSinh) {
        if (c->getHoTen().find(hoTenThiSinh) != string::npos) {
            ketQua.push_back(c);
        }
    }
    return ketQua;
}

vector<Candidate*> KhoaHoc::timTheoDTB(float dtb) {
    vector<Candidate*> ketQua;
    for (Candidate* c : dsThiSinh) {
        if (fabs(c->getDTB() - dtb) < 1e-5) {
            ketQua.push_back(c);
        }
    }
    return ketQua;
}

int KhoaHoc::soSanh(Candidate* c1, Candidate* c2) {
    return soSanh(c1, c2, MA_SO);
}

int KhoaHoc::soSanh(Candidate* c1, Candidate* c2, ThuocTinh thuocTinh) {
    switch (thuocTinh) {
        case MA_SO:
            if (c1->getMaSo() < c2->getMaSo()) return -1;
            if (c1->getMaSo() > c2->getMaSo()) return 1;
            return 0;
        case HO_TEN:
            if (c1->getHoTen() < c2->getHoTen()) return -1;
            if (c1->getHoTen() > c2->getHoTen()) return 1;
            return 0;
        case NAM_SINH:
            if (c1->getNamSinh() < c2->getNamSinh()) return -1;
            if (c1->getNamSinh() > c2->getNamSinh()) return 1;
            return 0;
        case GIOI_TINH:
            if (c1->getGioiTinh() < c2->getGioiTinh()) return -1;
            if (c1->getGioiTinh() > c2->getGioiTinh()) return 1;
            return 0;
        case DTB:
            if (c1->getDTB() < c2->getDTB()) return -1;
            if (c1->getDTB() > c2->getDTB()) return 1;
            return 0;
    }
    return 0;
}

void KhoaHoc::sapXep(ThuocTinh thuocTinh) {
    std::sort(dsThiSinh.begin(), dsThiSinh.end(), [thuocTinh](Candidate* c1, Candidate* c2) {
        return soSanh(c1, c2, thuocTinh) < 0;
    });
}

void KhoaHoc::xuatDanhSach() const {
    if (dsThiSinh.empty()) {
        cout << "Danh sach rong!\n";
        return;
    }
    cout << left << setw(10) << "Ma So"
         << setw(25) << "Ho Ten"
         << setw(10) << "Gioi Tinh"
         << setw(10) << "Nam Sinh"
         << "DTB" << endl;
    cout << string(62, '-') << endl;
    for (const Candidate* c : dsThiSinh) {
        cout << *c << endl;
    }
    cout << endl;
}
