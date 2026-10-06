/*************************
 * Avtor: Ivanova Ksenia *
 * Variant: 7            *
 * Nazvanie: Laba 2      *
 *************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  // vvod dannix
  double initialPressure, chamberVolume, pumpVolume;
  cout << "vvedite nachalnoe davlenie p0: ";
  cin >> initialPressure;
  cout << "vvedite obiom kameri V (л): ";
  cin >> chamberVolume;
  cout << "vvedite rabochii obiom nasosa V0 (л): ";
  cin >> pumpVolume;

  // vichislenie konstanti 
  double ratio = chamberVolume / (chamberVolume + pumpVolume);

  int strokeCount;
  double residualPressure;

  // vivod zagalovka 
  cout << "\nTablica znachenii p = f(n)\n";
  cout << "n\tp\n";
  cout << fixed << setprecision(3); // Округление до 3 знаков

  // --- pervi ychastok: cikl c postysloviem do while (n = 10..50, shag 10) ---
  strokeCount = 10;
  do {
      residualPressure = initialPressure * pow(ratio, strokeCount);
      cout << strokeCount << "\t" << residualPressure << "\n";
      strokeCount += 10;
  } while (strokeCount <= 50);

  // --- 2 ychastok: cikl c predysloviem while (n = 100..250, shag 50) ---
  strokeCount = 100;
  while (strokeCount <= 250) {
      residualPressure = initialPressure * pow(ratio, strokeCount);
      cout << strokeCount << "\t" << residualPressure << "\n";
      strokeCount += 50;
  }

  return 0;
}