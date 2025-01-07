#include <iostream>

using namespace std;
int n;
string e0 = "Kip 12h30 - Tuan 17 - Ngay 27/12/2024\n";
string e1 = "Le Thi Hoa-74469-20241\n";

struct SV {
    int ma;
    string hoten;
    int somon;
    double cpa;
    string cpaS;
//    string MaMH[100];
//    vector<int> soTC(100), Tso(100), QT(100), CK(100), DMH(100);
    SV() {
        ma = 0, hoten = "", somon = 0, cpa = 0, cpaS = "";
    }
    SV(int _m, string _h, int _s, double _c, string _cS) {
        ma = _m, hoten = _h, somon = _s, cpa = _c, cpaS = _cS;
    }
};

struct DSV {
    string maMH[100], xeploai[100];
    int tin[100];
    double trongso[100], qt[100], ck[100], dmh[100];
};

SV sv[100];
DSV dsv[100];

string rankk(double x) {
    if (x >= 9) return "A+";
    else if (x >= 8.5) return "A";
    else if (x >= 7.5) return "B+";
    else if (x >= 6.5) return "B";
    else if (x >= 5) return "C";
    else if (x >= 4) return "D";
    else return "F";
}

string rankkMH(double x) {
    if (x >= 9.5) return "Xuat sac";
    else if (x >8.5) return "Gioi";
    else if (x > 6.5) return "Kha";
    else if (x >= 5.0) return "Trung binh";
    else return "Yeu";
}
void process1() {
    cout << e1;
    cout << "Ban da chon nhap ds SINH VIEN!\n";
    cout << "Nhap so luong sinh vien: "; cin >> n;
    for (int i = 0; i < n; i++) {
        int ma, somon;
        double cpa = 0, ans = 0, tongtin = 0;
        string hoten, cpaS;
        cout << "Nhap thong tin cua sinh vien thu " << i + 1 << " :\n";
        cout << "   Nhap ma sinh vien :"; cin >> ma; cout << '\n';
        cout << "   Nhap ten SV: "; cin >> hoten; cout << '\n';
        cout << "Nhap so mon hoc: "; cin >> somon; cout << '\n';
        for (int j = 0; j < somon; j++) {
            string maMH;
            int tin;
            double trongso, qt, ck;
            cout << "   Nhap mon hoc thu " << j + 1 << '\n';
            cout << "       Nhap Ma MH: "; cin >> dsv[i].maMH[j]; cout << '\n';
            cout << "       Nhap so tin chi: "; cin >> dsv[i].tin[j]; cout << '\n';
            cout << "       Nhap trong so CK:>0,<1: "; cin >> dsv[i].trongso[j]; cout << '\n';
            cout << "       Nhap diem QT: "; cin >> dsv[i].qt[j]; cout << '\n';
            cout << "       Nhap diem CK: "; cin >> dsv[i].ck[j]; cout << '\n';
            dsv[i].dmh[j] = dsv[i].ck[j] * dsv[i].trongso[j] + dsv[i].qt[j] * (1 - dsv[i].trongso[j]);
            dsv[i].xeploai[j] = rankkMH(dsv[i].dmh[j]);
            ans += dsv[i].dmh[j] * dsv[i].tin[j];
            tongtin += dsv[i].tin[j];
        }
        cpa = ans / tongtin;
        cpaS =rankk(cpa);
        sv[i] = SV(ma, hoten, somon, cpa, cpaS);
    }
}

void process2() {
    cout << e1;
    cout << "Ban da chon xuat DS SINH VIEN!\n";

    for (int i = 0; i < n; i++) {
        cout << "===========================================================\n";
        cout << "=================KET QUA HOC TAP SINH VIEN=================\n";
        cout << "MaSV: " << sv[i].ma << '\n';
        cout << "TenSV: " << sv[i].hoten << '\n';
        cout << "SoMH: " << sv[i].somon<< '\n';
        cout << "TT    MaMH    SoTC    T.so    D.QT    D.CK    D.MH    XLoaiMH\n";
        for (int j = 0; j < sv[i].somon; j++) {
            cout << j + 1 << "       " << dsv[i].maMH[j] << "       "<< dsv[i].tin[j] << "      " << dsv[i].trongso[j] << "      " << dsv[i].qt[j] << "       " << dsv[i].ck[j] << "       " << dsv[i].dmh[j] << "          " << dsv[i].xeploai[j] << '\n';
        }
        cout << "Diem CPA: " << sv[i].cpa << '\n';
        cout << "Diem chu: " << sv[i].cpaS << '\n';
        cout << "===========================================================\n";
    }
}


void process() {
    string type;
    while (cin >> type) {
        if (type == "1") process1();
        else if (type == "2") process2();
        else if (type == "0") {
            cout << "Le Thi Hoa-74469-20241\nBan da chon thoat chuong trinh!";
            break;
        }
        else cout << e1 << "\nKhong co chuc nang nay!\nBam phim bat ky de tiep tuc";
    }

}

int main()
{
    string a = "** CHUONG TRINH QUAN LY DIEM SINH VIEN  **\n";
    string b = "**1. Nhap cac SINH VIEN                 **\n";
    string c = "**2. In THONG TIN SV, KET QUA,..        **\n";
    string d = "**0. THOAT                              **\n";
    cout << e0 << e1 << a << b << c << d;
    cout << "*********************************************\n";
    cout <<    "**         Nhap lua chon cua ban        **\n";
    process();
}
