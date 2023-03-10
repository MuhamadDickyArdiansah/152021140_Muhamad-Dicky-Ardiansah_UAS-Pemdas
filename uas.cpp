#include <iostream>
#include <cmath>

using namespace std;

struct Data
{
  int data_x;
  int data_y;
};

int main()
{
  system("cls");
  int banyak;
  int sigma_x;
  int sigma_y;
  int sigma_xy;
  float sigma_x2;
  float sigma_y2;
  float pearsonAtas;
  float pearsonBawahKiri;
  float pearsonBawahKanan;
  double koefisien;

  cout << "Banyak data : ";
  cin >> banyak;
  double data_xy[banyak];

  Data dta[banyak];

  for (int i = 0; i < banyak; i++)
  {
    cout << "masukkan data X-" << i + 1 << " : ";
    cin >> dta[i].data_x;

    cout << "masukkan data Y-" << i + 1 << " : ";
    cin >> dta[i].data_y;

    sigma_x += dta[i].data_x;
    sigma_y += dta[i].data_y;

    data_xy[i] = dta[i].data_x * dta[i].data_y;
    sigma_xy += data_xy[i];
  }
  sigma_x2 = pow(sigma_x, 2);
  sigma_y2 = pow(sigma_y, 2);

  // sqrt() untuk akar
  // pow(a,b) untuk pangkat

  pearsonAtas = (banyak * sigma_xy) - (sigma_x * sigma_y);
  pearsonBawahKiri = sqrt((banyak * sigma_x2) - (pow(sigma_x, 2)));
  pearsonBawahKanan = sqrt((banyak * sigma_y2) - (pow(sigma_y, 2)));

  double r = pearsonAtas / (pearsonBawahKiri * pearsonBawahKanan);
  koefisien = pow(r, 2) * (1 / 100);
  // for (int i = 0; i < banyak; i++)
  // {
  //   cout << "r = " << sigma_xy << endl;
  // }

  cout << "sigma x = " << sigma_x << endl;
  cout << "sigma y = " << sigma_y << endl;
  cout << "sigmaXY = " << sigma_xy << endl;
  cout << "sigma x2 = " << sigma_x2 << endl;
  cout << "sigmaY2 = " << sigma_y2 << endl;

  cout << "Nilai Korelasi r = " << pearsonAtas << " / " << pearsonBawahKiri * pearsonBawahKanan << " = " << r << endl;
  cout << "koefisien determinasi = " << koefisien << endl;

  if (r == 0)
  {
    cout << "Tidak Ada Hubungan Antara variabel X dan Y adalah Positif" << endl;
  }

  else if (r > 0)
  {
    cout << "Hubungan Antara variabel X dan Y adalah Positif" << endl;
  }
  else if (r < 0)
  {
    cout << "Hubungan Antara variabel X dan Y adalah Negatif" << endl;
  }

  return 0;
}