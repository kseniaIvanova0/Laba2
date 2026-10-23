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
  cout << "Enter the chamber volume V (l): ";
  cin >> chamberVolume;
  cout << "Enter the pump volume V0 (l): ";
  cin >> pumpVolume;

  // calculation of the constant
  double ratio = chamberVolume / (chamberVolume + pumpVolume);

  // Precision for output
  const int precision = 3;       
  // Step for the first section (n = 10..50)
  const double firstStep = 10.0;
  // Step for the second section (n = 100..250)
  const double secondStep = 50.0;
  // Initial number of strokes (n)
  const double start = 10.0;
  //Boundary between the first and second sections
  const double changePoint = 50.0;
  // Maximum number of strokes (end of the table)
  const double finish = 250.0;

  int stepIndex = 0;
  double argument = start;
  double result;

  cout << "\n Table of values p = f(n)\n"
      << "n\tp\n";
  cout << fixed << setprecision(precision);

  // loop do while 
  do {
      result = initialPressure * pow(ratio, argument);
      cout << argument << "\t" << result << "\n";
      ++stepIndex;
      argument = start + stepIndex * firstStep;
  } while (argument <= changePoint);

  //  loop while 
  stepIndex = 1;
  argument = changePoint + stepIndex * secondStep;
  while (argument <= finish) {
      result = initialPressure * pow(ratio, argument);
      cout << argument << "\t" << result << "\n";
      ++stepIndex;
      argument = changePoint + stepIndex * secondStep;
  }

  return 0;
}