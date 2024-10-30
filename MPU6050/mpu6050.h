#ifndef MPU6050_H
#define MPU6050_H

#include "hardware/i2c.h"
#include "pico/stdlib.h"

// Estrutura de configuração do MPU6050
typedef struct imu6050 {
    i2c_inst_t *i2c;    // Instância do I2C
    int pin_sda;        // Pino SDA
    int pin_scl;        // Pino SCL
    int acc_scale;      // Escala do acelerômetro
} imu_c;

// Funções do driver MPU6050
void mpu6050_set_config(imu_c *config, i2c_inst_t *i2c, int pin_sda, int pin_scl, int acc_scale);
int mpu6050_init(imu_c config);
int mpu6050_reset(imu_c config);
int mpu6050_read_acc(imu_c config, int16_t accel[3]);
int mpu6050_read_gyro(imu_c config, int16_t gyro[3]);
int mpu6050_read_temp(imu_c config, int16_t *temp);

#endif // MPU6050_H
