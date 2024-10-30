# Define a biblioteca do MPU6050
add_library(MPU6050 mpu6050.c)

# Inclui o diretório para o arquivo de cabeçalho (mpu6050.h)
target_include_directories(MPU6050 PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# Adiciona as bibliotecas de dependência
target_link_libraries(MPU6050 hardware_i2c pico_stdlib)
