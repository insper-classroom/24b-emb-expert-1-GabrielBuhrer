/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hardware/gpio.h"
#include "hardware/i2c.h"  
#include "mpu6050.h"
#include "pico/stdlib.h"
#include "stdio.h"

int main() {
    stdio_init_all();

    const uint SDA_PIN = 4; 
    const uint SCL_PIN = 5; 

    // Configurar o MPU6050
    imu_c imu_config;
    mpu6050_set_config(&imu_config, i2c0, SDA_PIN, SCL_PIN, 2); // Configure com os pinos SCL e SDA

    if (!mpu6050_init(imu_config)) {
        printf("Erro ao inicializar o MPU6050.\n");
        return -1;
    }

   // mpu6050_reset(imu_config);

    while (1) {
        int16_t accel[3];  
        int16_t gyro[3];   
        int16_t temp;      

        // Ler os dados do MPU6050
        if (mpu6050_read_acc(imu_config, accel)) {
            printf("Acelerômetro - X: %d, Y: %d, Z: %d\n", accel[0], accel[1], accel[2]);
        } else {
            printf("Erro na leitura do acelerômetro.\n");
        }

        if (mpu6050_read_gyro(imu_config, gyro)) {
            printf("Giroscópio - X: %d, Y: %d, Z: %d\n", gyro[0], gyro[1], gyro[2]);
        } else {
            printf("Erro na leitura do giroscópio.\n");
        }

        if (mpu6050_read_temp(imu_config, &temp)) {
            printf("Temperatura: %d\n", temp);
        } else {
            printf("Erro na leitura da temperatura.\n");
        }

        sleep_ms(100); 
    }

    return 0;
}
