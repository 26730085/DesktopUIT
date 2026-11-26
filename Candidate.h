#ifndef DEMOCODEB04_CANDIDATE_H
#define DEMOCODEB04_CANDIDATE_H

#include <string>
#include <iostream>

using namespace std;

class Candidate {
    string maSo;
    string hoTen;
    bool gioiTinh;
    int namSinh;
    float dtb;

public:
    Candidate();
    Candidate(string maSo, string hoTen, bool gioiTinh, int namSinh, float dtb);
    Candidate(const Candidate& candidate);
    virtual ~Candidate();

    string getMaSo() const { return maSo; }
    string getHoTen() const { return hoTen; }
    bool getGioiTinh() const { return gioiTinh; }
    int getNamSinh() const { return namSinh; }
    float getDTB() const { return dtb; }

    void input();
    void output() const;
    int getTuoi() const;

    friend istream& operator>>(istream& is, Candidate& candidate);
    friend ostream& operator<<(ostream& os, const Candidate& candidate);
};

#endif
