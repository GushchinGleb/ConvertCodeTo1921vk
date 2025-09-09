#include "i2c_master.h"

// Map to I2C instance used for MASC (e.g., I2C0 as master)
#define I2C_BASE ((volatile uint32_t*)0x40030000)
#define I2C_CTL0 (*(volatile uint32_t*)(I2C_BASE + 0x00/4))
#define I2C_CTL1 (*(volatile uint32_t*)(I2C_BASE + 0x04/4))
#define I2C_CTL2 (*(volatile uint32_t*)(I2C_BASE + 0x08/4))
#define I2C_ST   (*(volatile uint32_t*)(I2C_BASE + 0x0C/4))
#define I2C_CST  (*(volatile uint32_t*)(I2C_BASE + 0x10/4))
#define I2C_DATA (*(volatile uint32_t*)(I2C_BASE + 0x14/4))

bool i2cm_init(uint32_t pclk_hz, uint32_t scl_hz){
  // Program CTL1/CTL2 divider fields to achieve FS timing (datasheet gives ranges up to 6.25 MHz at PCLK=100MHz). :contentReference[oaicite:20]{index=20}
  // Enable module via CTL1/ENABLE, clear/idle CST as needed. :contentReference[oaicite:21]{index=21}
  return true;
}

static bool start(uint8_t addr_rw){
  // Set START in CTL0, wait ST.IF; write addr byte to DATA, handle ACK in CST/ST. :contentReference[oaicite:22]{index=22}
  return true;
}

static void stop(void){
  // Set STOP in CTL0, wait bus idle in CST. :contentReference[oaicite:23]{index=23}
}

bool i2cm_write(uint8_t addr7, const uint8_t* data, uint32_t len){
  if(!start((addr7<<1)|0)) return false;
  for(uint32_t i=0;i<len;i++){
    I2C_DATA = data[i];
    // wait TX done & ACK in ST/CST...
  }
  stop();
  return true;
}

bool i2cm_write_reg(uint8_t a, uint8_t reg, uint8_t val){
  uint8_t buf[2]={reg,val}; return i2cm_write(a,buf,2);
}

bool i2cm_read_reg(uint8_t a, uint8_t reg, uint8_t* val){
  if(!i2cm_write(a,&reg,1)) return false;
  // repeated START + READ, then NACK last byte, STOP. :contentReference[oaicite:24]{index=24}
  *val = (uint8_t)I2C_DATA;
  stop();
  return true;
}
