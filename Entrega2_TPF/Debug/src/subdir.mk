################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Entrega2_TPF.c \
../src/computadora.c \
../src/funciones.c \
../src/jugador.c 

C_DEPS += \
./src/Entrega2_TPF.d \
./src/computadora.d \
./src/funciones.d \
./src/jugador.d 

OBJS += \
./src/Entrega2_TPF.o \
./src/computadora.o \
./src/funciones.o \
./src/jugador.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gio-unix-2.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/fribidi -I/usr/include/atk-1.0 -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng16 -I/usr/include/x86_64-linux-gnu -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Entrega2_TPF.d ./src/Entrega2_TPF.o ./src/computadora.d ./src/computadora.o ./src/funciones.d ./src/funciones.o ./src/jugador.d ./src/jugador.o

.PHONY: clean-src

