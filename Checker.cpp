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

bool isValuLesserThan(float maximum, float value, const string& parameter)
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
  chargeRateStatus = isValuLesserThan(0.8, chargeRate, "Charge Rate");

  return temperatureStatus && socStatus && chargeRateStatus;
}

#define TEMP_IN_RANGE_LOW 25.0f
#define TEMP_IN_RANGE_HIGH 45.0f
#define TEMP_OUT_OF_RANGE_LOW -10.0f
#define TEMP_OUT_OF_RANGE_HIGH 50.0f

#define SOC_IN_RANGE_LOW 20.0f
#define SOC_IN_RANGE_HIGH 80.0f
#define SOC_OUT_OF_RANGE_LOW 15.0f
#define SOC_OUT_OF_RANGE_HIGH 85.0f

#define CHARGE_RATE_IN_RANGE 0.5f
#define CHARGE_RATE_OUT_OF_RANGE 0.9f

void testBatteryIsOk() {
  assert(batteryIsOk(TEMP_IN_RANGE_LOW, SOC_IN_RANGE_LOW, CHARGE_RATE_IN_RANGE) == true);
  assert(batteryIsOk(TEMP_OUT_OF_RANGE_HIGH, SOC_IN_RANGE_LOW, CHARGE_RATE_IN_RANGE) == false);
  assert(batteryIsOk(TEMP_OUT_OF_RANGE_LOW, SOC_IN_RANGE_LOW, CHARGE_RATE_IN_RANGE) == false);
  assert(batteryIsOk(TEMP_IN_RANGE_LOW, SOC_OUT_OF_RANGE_HIGH, CHARGE_RATE_IN_RANGE) == false);
  assert(batteryIsOk(TEMP_IN_RANGE_LOW, SOC_OUT_OF_RANGE_LOW, CHARGE_RATE_IN_RANGE) == false);  
  assert(batteryIsOk(TEMP_IN_RANGE_LOW, SOC_IN_RANGE_LOW, CHARGE_RATE_OUT_OF_RANGE) == false);  
  assert(batteryIsOk(TEMP_IN_RANGE_LOW, SOC_IN_RANGE_LOW, CHARGE_RATE_IN_RANGE) == true);
  assert(batteryIsOk(TEMP_IN_RANGE_HIGH, SOC_IN_RANGE_HIGH, CHARGE_RATE_IN_RANGE) == true);  
  assert(batteryIsOk(TEMP_IN_RANGE_LOW, SOC_IN_RANGE_LOW, CHARGE_RATE_OUT_OF_RANGE) == false);  
  assert(batteryIsOk(TEMP_OUT_OF_RANGE_LOW, SOC_OUT_OF_RANGE_HIGH, CHARGE_RATE_OUT_OF_RANGE) == false);
}
int main() {
  testBatteryIsOk();
  
  return 0;
}
