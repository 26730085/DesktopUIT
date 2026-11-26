#ifndef DEMOCODEB04_KHOAHOC_H
#define DEMOCODEB04_KHOAHOC_H
#include <vector>

#include "Candidate.h"

enum ThuocTinh {
    MA_SO,
    HO_TEN,
    NAM_SINH,
    GIOI_TINH,
    DTB
};

class KhoaHoc {
    std::vector<Candidate*> dsThiSinh;
public:
    KhoaHoc();
    ~KhoaHoc();

    bool them(Candidate* candidate);
    Candidate* xoa(string maso);
    Candidate* xoa(Candidate* candidate);

    Candidate* timTheoMaSo(string maSoThiSinh);
    vector<Candidate*> timTheoHoTen(string hoTenThiSinh);
    vector<Candidate*> timTheoDTB(float dtb);

    void sapXep(ThuocTinh thuocTinh);
    void xuatDanhSach() const;

private:
    static int soSanh(Candidate* c1, Candidate* c2);
    static int soSanh(Candidate* c1, Candidate* c2, ThuocTinh thuocTinh);
};

#endif
