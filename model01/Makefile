.PHONY: deps flash

ARDUINO_PATH := /usr/share/arduino

# TODO: This should just use the vanilla arduino install from their site.
# The Arch package does some weird stuff to it so it won't run for me.

deps:
	if [ -d "Model01-Firmware" ]; then \
		cd Model01-Firmware && git clean -df && git checkout -- . && git pull && \
		cd $(HOME)/Arduino/hardware/keyboardio/avr && make update-submodules; \
	else \
		git clone git@github.com:keyboardio/Model01-Firmware.git && \
		yaourt -S arduino arduino-ctags arduino-docs arduino-builder && \
		mkdir -p $(HOME)/Arduino/hardware/keyboardio && \
		git clone --recursive git@github.com:keyboardio/Arduino-Boards.git $(HOME)/Arduino/hardware/keyboardio/avr && \
		sudo gpasswd -a $(USER) uucp; \
		sudo gpasswd -a $(USER) lock; \
		@echo "You must relog to apply group changes." \
	fi

flash:
	cd Model01-Firmware && make flash

