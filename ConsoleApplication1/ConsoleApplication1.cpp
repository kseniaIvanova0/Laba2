/**************************
 * Author: Ivanova Ksenia *
 * Variant: 7             *
 * Name: Laba 2           *
 **************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  double initialPressure, chamberVolume, pumpVolume;
  cout << "Enter the initial value p0: ";
  cin >> initialPressure;
  cout << "Enter the chamber volume V (л): ";
  cin >> chamberVolume;
  cout << "Enter the pump volume V0 (л): ";
  cin >> pumpVolume;

  // calculation of the constant
  double ratio = chamberVolume / (chamberVolume + pumpVolume);

  const int precision = 3;       // Precision for output
  const int startStroke1 = 10;   // Start of first section
  const int step1 = 10;          // Step of first section
  const int endStroke1 = 50;     // End of first section
  const int startStroke2 = 100;  // Start of second section
  const int step2 = 50;          // Step of second section
  const int endStroke2 = 250;    // End of second section

  int strokeCount;
  double residualPressure;

  cout << "\n Table of values p = f(n)\n"
      << "n\tp\n";
  cout << fixed << setprecision(precision);

  // loop do while 
  strokeCount = startStroke1;
  do {
      residualPressure = initialPressure * pow(ratio, strokeCount);
      cout << strokeCount << "\t" << residualPressure << "\n";
      strokeCount += step1;
  } while (strokeCount <= endStroke1);

  //  loop while 
  strokeCount = startStroke2;
  while (strokeCount <= endStroke2) {
      residualPressure = initialPressure * pow(ratio, strokeCount);
      cout << strokeCount << "\t" << residualPressure << "\n";
      strokeCount += step2;
  }

  return 0;
}