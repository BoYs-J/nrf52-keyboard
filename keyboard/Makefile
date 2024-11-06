OUTPUT_DIR = _build
SUBDIRS=$(filter-out $(OUTPUT_DIR),$(shell ls -l | grep ^d | grep -v 'ergoconn\|farad69\|g84-4100\|gt-ble60\|gt-pad\|gt-planck\|Hal67\|lkb-core\|lot60-ble\|newhope64\|Omega40\|Omega45\|Omega50\|Omega64\|Omega84\|template\|volta9\|test' | awk '{print $$9}'))
export RELEASE_DIR = ../$(OUTPUT_DIR)

.PHONY: clean release dist_clean help
release: $(SUBDIRS)

$(SUBDIRS): $(OUTPUT_DIR)
	@-mkdir $(OUTPUT_DIR)/$@
	@make -C $@ release OUTPUT_DIRECTORY=$(RELEASE_DIR)/$@ BUILD_PREFIX=$@

$(OUTPUT_DIR):
	@-mkdir -p $(OUTPUT_DIR)

dist_clean: 
	-rm -r $(OUTPUT_DIR)/*/

clean:
	-rm -rf $(OUTPUT_DIR)

# Print all targets that can be built
help:
	@echo following targets are available:
	@echo		nrf52_kbd           - default： build KBD firmware
	@echo		setting             - generate dfu setting
	@echo		bootloader          - build BootLoader firmware
	@echo		package             - pack firmware for DFU
	@echo		all                 - merge bootloader softdevice and dfu setting with application
	@echo		erase               - erase the chip
	@echo		merge_setting       - merge dfu setting with application
	@echo		merge_softdevice    - merge softdevice with application
	@echo		flash               - Flashing KBD firmware
	@echo		flash_setting       - Flashing KBD firmware and dfu setting
	@echo		flash_bootloader    - Flashing bootloader
	@echo		flash_softdevice    - Flashing softdevice
	@echo		flash_all           - Flashing bootloader softdevice and application with dfu setting
	@echo		release             - make all keyboards firmware in the keyboard folder
	@echo All targets starts with "flash" could has prefix "pyocd_" or "openocd", which \
	means use pyocd  or openocd to flash chip. 
