.PHONY: deps

deps:
	if [ -d "qmk_firmware" ]; then \
		cd qmk_firmware; git pull; \
	else \
		git clone git@github.com:qmk/qmk_firmware.git; \
	fi
	sudo ./qmk_firmware/util/install_dependencies.sh
