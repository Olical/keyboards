.PHONY: deps compile flash

deps:
	if [ -d "qmk_firmware" ]; then \
		cd qmk_firmware && git clean -df && git checkout -- . && git pull; \
	else \
		git clone git@github.com:qmk/qmk_firmware.git; \
		sudo qmk_firmware/util/install_dependencies.sh; \
		yaourt -S dfu-programmer; \
	fi

compile:
	mkdir -p qmk_firmware/keyboards/planck/keymaps/olical
	cp config.h keymap.c rules.mk qmk_firmware/keyboards/planck/keymaps/olical
	cd qmk_firmware && make planck/rev4:olical

flash:
	cd qmk_firmware && make planck/rev4:olical:dfu
