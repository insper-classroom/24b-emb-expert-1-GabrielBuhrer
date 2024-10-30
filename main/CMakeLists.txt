add_executable(main main.c)

# Adiciona dependências comuns e a biblioteca MPU6050
target_link_libraries(main pico_stdlib MPU6050)

# Cria arquivos binários (map/bin/hex/uf2)
pico_add_extra_outputs(main)

