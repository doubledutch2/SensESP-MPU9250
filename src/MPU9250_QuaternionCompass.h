#ifndef _mpu9250_QC_H_
#define _mpu9250_QC_H_

#include <RemoteDebug.h>
#include "sensors/sensor.h"
#include <SPI.h>
#include <Wire.h>   
#include "sensesp.h"


class MPU9250 : public Sensor {
  public:
    MPU9250(uint8_t addr = 0x68, 
            uint TASK = 6,
            boolean True_North = true,
            float Declination = 0,
            uint read_delay = 1000,
            String config_path = "");
    MPU9250 myIMU;
    // uint8_t MPU9250_ADDRESS;
    boolean SensorRead = false;
    uint  read_delay;
    void read_values(boolean AHRS);
    
  private:
    uint8_t addr;
    boolean check_status();
    //  virtual JsonObject& get_configuration(JsonBuffer& buf) override;
    //  virtual bool set_configuration(const JsonObject& config) override;
    //  virtual String get_config_schema() override;
};


// Pass one of these in the constructor to MPU9250value() to tell which type of value you want to output
//enum mpu9250ValType { temperature, pressure, humidity };

enum MPU9250ValType { Roll,
                      Pitch,
                      Heading
                      temperature};

/*
// MPU9250value reads and outputs the specified value of a MPU9250 sensor.
class mpu9250value : public NumericSensor {
  public:
    mpu9250value( mpu9250* pMPU9250, 
                  MPU9250ValType val_type, 
                  uint read_delay = 500, 
                  String config_path="");
    void enable() override final;
    mpu9250* pMPU9250;

  private:
    MPU9250ValType val_type;
    float round2Decs(float input);
    uint read_delay;
    virtual JsonObject& get_configuration(JsonBuffer& buf) override;
    virtual bool set_configuration(const JsonObject& config) override;
    virtual String get_config_schema() override;    

};
*/
#endif
