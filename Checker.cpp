#include <assert.h>
#include <iostream>
using namespace std;

void printOutOfRange(const string& parameter){
  cout << parameter << " out of range!\n";
}

bool isValueInRange(float minimum, float maximum, float value, const string& parameter)
{
  if (value < minimum || value > maximum)
  {
    printOutOfRange(parameter);
    return false;
  }
  return true;
}

bool isValueGreaterThan(float maximum, float value, const string& parameter)
{
  if (value > maximum)
  {
    printOutOfRange(parameter);
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool temperatureStatus = false;
  bool socStatus = false;
  bool chargeRateStatus = false;

  temperatureStatus = isValueInRange(0, 45, temperature, "Temperature");
  socStatus = isValueInRange(20, 80, soc, "State of Charge");
  chargeRateStatus = isValueGreaterThan(0.8, chargeRate, "Charge Rate");

  return temperatureStatus && socStatus && chargeRateStatus;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
