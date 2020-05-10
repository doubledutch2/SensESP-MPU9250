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
    //  MPU9250 myIMU;
    // uint8_t MPU9250_ADDRESS;
    uint TASK = 6;
    boolean True_North = true;
    float Declination = 0;
    boolean SensorRead = false;
    uint  read_delay;
    void read_values(boolean AHRS);
    float temperature=0;
    float heading=0;
    float roll=0;
    float pitch=0;
    
  private:
    uint8_t addr;
    boolean check_status();
    boolean perform_setup();
    void  read_values();
    void  getMres();
    void  getGres();
    void  getAres();
    void  readAccelData(short *);
    void  readGyroData(short *);
    void  readMagData(short *);
    short readTempData();
    void  initAK8963(float *);
    void  initMPU9250();
    void  calibrateMPU9250(float *,float *);
    void  magCalMPU9250(float *,float *);
    void  MPU9250SelfTest(float *);
    void  writeByte(byte,byte,byte);
    byte  readByte(byte,byte);
    void  readBytes(byte, byte, byte, byte *);
    void  MadgwickQuaternionUpdate(float,float,float,float,float,float,float,float,float);
    void  MahonyQuaternionUpdate(float, float, float, float, float, float, float, float,float);
    void  refresh_data();
    void  calc_quaternion();
    void  compass_cal();
    void  compass_rose();
    void  view_registers_SM();
    void  view_heading_SM();
    void  view_heading_LCD();
    void  print_number(float);
    void  print_number(short);
    float round2Decs(float);
    
    //  virtual JsonObject& get_configuration(JsonBuffer& buf) override;
    //  virtual bool set_configuration(const JsonObject& config) override;
    //  virtual String get_config_schema() override;
};

  enum MPU9250ValType { Roll,
                        Pitch,
                        Heading,
                        Temperature};


class MPU9250value: public NumericSensor
{

private:
    MPU9250ValType val_type;
    float round2decs(float input);
    uint read_delay;
    virtual JsonObject& get_configuration(JsonBuffer& buf) override;
    virtual bool set_configuration(const JsonObject& config) override;
    virtual String get_config_schema() override;    

public:
  MPU9250value( MPU9250 *       pMPU9250,
                MPU9250ValType  val_type,
                uint            read_delay,
                String          config_path);
  void enable() override final;
  MPU9250* pMPU9250;
};



// Pass one of these in the constructor to MPU9250value() to tell which type of value you want to output
//enum mpu9250ValType { temperature
//  void enable() override final;
//  mpu9250* pMPU9250;, pressure, humidity };
/*
enum MPU9250ValType { Roll,
                      Pitch,
                      Heading,
                      Temperature};

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
