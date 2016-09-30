// Sử dụng C-Free 5
// Giải thuật Quay lui

#include <iostream> // cin, cout, endl
#include <cstdlib> // srand, rand
#include <ctime> // time

using namespace std;

/* CÁC HẰNG SỐ */

const unsigned SOHAUCANDAT = 8;
const unsigned TRONGSOTOIDA = 10;

/* KIỂU DỮ LIỆU */

struct QuanCo;
struct ToaDo;
struct BanCo;
struct DauVet;
struct CSDL;

struct QuanCo {
  bool chiem;
  unsigned trongso;
};

struct ToaDo {
  unsigned x, y;
  ToaDo (unsigned _x = 0, unsigned _y = 0): x(_x), y(_y) {}
};

struct BanCo {
  static const unsigned KICHTHUOC = SOHAUCANDAT;
  static const unsigned SOQUANCO = KICHTHUOC * KICHTHUOC;
  union {
    QuanCo luoi[KICHTHUOC][KICHTHUOC];
    QuanCo day[SOQUANCO];
  } quanco; // 'luoi' và 'day' thực ra là một, cùng chiếm 1 vùng nhớ, chỉ khác về số chiều
  QuanCo & operator [] (ToaDo toado) {
    return quanco.luoi[toado.x][toado.y];
  }
};

struct DauVet {
  static const unsigned KICHTHUOC = BanCo::KICHTHUOC;
  ToaDo dadat[KICHTHUOC];
  unsigned soluong;
};

struct CSDL {
  BanCo banco;
  DauVet dauvet;
};

/* CÁC HÀM CẦN XÂY DỰNG */

// Chương trình chính
int main ();

// Các hàm khởi tạo
void khoitao (CSDL & csdl);
void khoitao (BanCo & banco);
void khoitao (DauVet & dauvet);

// Các hàm xuất
void xuat (CSDL csdl);
void xuat (BanCo banco);

// Các hàm tính toán
void giaibaitoan (CSDL & csdl, unsigned soluong);
void datquanhau (CSDL & csdl, bool & thanhcong, unsigned & trongso, unsigned soluong);
void datquanhau (DauVet & dauvet, ToaDo toado);
bool kiemtra (DauVet dauvet, ToaDo taodo);
bool kiemtra (ToaDo a, ToaDo b);

// Các hàm tiện ích
unsigned ngaunhien (unsigned max);
void xuatmang (unsigned * mang, unsigned soluong);

/* NỘI DUNG */

int main () {
  CSDL csdl;
  srand(time(NULL));
  khoitao(csdl);
  giaibaitoan(csdl, SOHAUCANDAT);
  xuat(csdl);
  cin.get();
  return 0;
}

void khoitao (CSDL & csdl) {
  khoitao(csdl.banco);
  khoitao(csdl.dauvet);
}

void khoitao (BanCo & banco) {
  for (QuanCo * i = banco.quanco.day, * e = i + BanCo::SOQUANCO; i != e; ++i) {
    i->chiem = false;
    i->trongso = ngaunhien(TRONGSOTOIDA);
  }
}

void khoitao (DauVet & dauvet) {
  dauvet.soluong = 0;
}

void xuat (CSDL csdl) {
  xuat(csdl.banco);
}

void xuat (BanCo banco) {
  unsigned tongtrongso = 0;
  unsigned trongso[SOHAUCANDAT];
  unsigned x[SOHAUCANDAT];
  unsigned y[SOHAUCANDAT];
  unsigned dem = 0;
  cout << "Ban co:\n";
  for (unsigned i = 0; i != BanCo::KICHTHUOC; ++i) {
    cout << endl;
    for (unsigned j = 0; j != BanCo::KICHTHUOC; ++j) {
      const QuanCo * const quanco = & banco.quanco.luoi[i][j];
      cout << "\x20\x20";
      if (quanco->chiem) {
        cout << '*';
        tongtrongso += quanco->trongso;
        trongso[dem] = quanco->trongso;
        x[dem] = j;
        y[dem] = i;
        ++dem;
      } else {
        cout << '.';
      }
      cout << quanco->trongso;
    }
    cout << endl;
  }
  cout << endl <<
    "Chu thich:\n"
    " - Con trong:  .w\n"
    " - Co hau:     *w\n"
  ;
  cout << "\nTong trong so (w): " << tongtrongso << endl;
  cout << "\nCac quan hau da dat:\n";
  cout << " - x:";
  xuatmang(x, SOHAUCANDAT);
  cout << " - y:";
  xuatmang(y, SOHAUCANDAT);
  cout << " - w:";
  xuatmang(trongso, SOHAUCANDAT);
}

void giaibaitoan (CSDL & csdl, unsigned soluong) {
  unsigned trongso;
  bool thanhcong;
  datquanhau(csdl, thanhcong, trongso, soluong);
}

void datquanhau (CSDL & csdl, bool & thanhcong, unsigned & trongso, unsigned soluong) {
  if (soluong) {
    thanhcong = false;
    if (csdl.dauvet.soluong != DauVet::KICHTHUOC) {
      bool thanhcongmoi;
      trongso = 0;
      --soluong;
      for (unsigned x = 0; x != BanCo::KICHTHUOC; ++x) {
        for (unsigned y = 0; y != BanCo::KICHTHUOC; ++y) {
          const ToaDo toado(x, y);
          CSDL csdlss = csdl;
          QuanCo & quanco = csdlss.banco[toado];
          unsigned trongsoss = 0;
          if (kiemtra(csdlss.dauvet, toado)) {
            quanco.chiem = true;
            datquanhau(csdlss.dauvet, toado);
            datquanhau(csdlss, thanhcongmoi, trongsoss, soluong);
            trongsoss += quanco.trongso;
            if (thanhcongmoi) {
              thanhcong = true;
              if (trongsoss > trongso) {
                csdl = csdlss;
                trongso = trongsoss;
              }
            }
          }
        }
      }
    }
  } else {
    thanhcong = true;
    trongso = 1;
  }
}

void datquanhau (DauVet & dauvet, ToaDo toado) {
  dauvet.dadat[dauvet.soluong] = toado;
  ++dauvet.soluong;
}

bool kiemtra (DauVet dauvet, ToaDo toado) {
  for (unsigned i = 0; i != dauvet.soluong; ++i) {
    if (! kiemtra(toado, dauvet.dadat[i])) {
      return false;
    }
  }
  return true;
}

bool kiemtra (ToaDo a, ToaDo b) {
  return (
    a.x != b.x &&
    a.y != b.y &&
    a.x - b.x != a.y - b.y &&
    a.x + b.x != a.y + b.y
  );
}

unsigned ngaunhien (unsigned max) {
  return max * rand() / RAND_MAX;
}

void xuatmang (unsigned * mang, unsigned soluong) {
  for (unsigned i = 0; i != soluong; ++i) {
    cout << ' ' << mang[i];
  }
  cout << endl;
}
