#include "../inc/masc37029.h"
#include "../inc/i2c_master.h"

bool masc_read_id(uint8_t* id){
  return i2cm_read_reg(I2C_ADDR_MASC, MASC_CHIPID, id);
}

bool masc_init_defaults(void){
  // Write your power-up register set via i2cm_write_reg()
  return true;
}
