.PHONY: deps flash

deps:
	if [ -d "Model01-Firmware" ]; then \
		cd Model01-Firmware && git clean -df && git checkout -- . && git pull && \
		cd $(HOME)/Arduino/hardware/keyboardio/avr && make update-submodules; \
	else \
		curl https://downloads.arduino.cc/arduino-1.8.5-linux64.tar.xz -o arduino.tar.xz && \
		tar -xvf arduino.tar.xz -C arduino && \
		rm arduino.tar.xz && \
		sudo curl https://raw.githubusercontent.com/keyboardio/Kaleidoscope/master/etc/99-kaleidoscope.rules -o /etc/udev/rules.d/99-kaleidoscope.rules && \
		git clone git@github.com:keyboardio/Model01-Firmware.git && \
		mkdir -p $(HOME)/Arduino/hardware/keyboardio && \
		git clone --recursive git@github.com:keyboardio/Arduino-Boards.git $(HOME)/Arduino/hardware/keyboardio/avr; \
	fi

flash:
	cp ./Model01-Firmware.ino ./Model01-Firmware && \
	sudo usermod -a -G uucp $(USER) && \
	sudo usermod -a -G lock $(USER) && \
	su - $(USER) -c "bash -c \"cd $(shell pwd)/Model01-Firmware && ARDUINO_PATH=../arduino make flash\""
