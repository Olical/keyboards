.PHONY: planck-repo planck-build planck-flash ergodox-repo ergodox-build ergodox-flash

planck-repo:
	if [ -d "repos/qmk_firmware" ]; then \
		cd repos/qmk_firmware; \
		git pull; \
	else \
		mkdir -p repos; \
		cd repos; \
		git clone git@github.com:qmk/qmk_firmware.git; \
	fi

ergodox-repo:
	if [ -d "repos/controller" ]; then \
		cd repos/controller; \
		git pull; \
	else \
		mkdir -p repos; \
		cd repos; \
		git clone git@github.com:kiibohd/controller.git; \
	fi

