BOARD?=arduino:avr:uno
PORT?=/dev/tty.usbmodem101
BUILD=build

.PHONY: default all flash clean

default: all flash clean

all:
	arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD) ./

flash:
	arduino-cli upload --fqbn $(BOARD) --port $(PORT) --input-dir $(BUILD)

clean:
	rm -r build