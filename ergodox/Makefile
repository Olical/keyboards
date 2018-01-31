.PHONY: deps compile

deps:
	if [ -d "controller" ]; then \
		cd controller && git clean -df && git checkout -- . && git pull; \
	else \
		git clone git@github.com:kiibohd/controller.git; \
	fi
	sudo pacman -S --needed \
		git cmake make python libusb ctags \
		arm-none-eabi-binutils arm-none-eabi-gcc \
		arm-none-eabi-newlib dfu-util lsb-release

compile:
	mkdir -p ./controller/kll/layouts/custom
	cp ./*.kll ./controller/kll/layouts/custom
	cp ./*.bash ./controller/Keyboards
	cd ./controller/Keyboards && ./ergodox.bash

flash-left:
	cd ./controller/Keyboards/linux-gnu.ERGO-L.gcc.make/ && sudo ./load

flash-right:
	cd ./controller/Keyboards/linux-gnu.ERGO-R.gcc.make/ && sudo ./load
