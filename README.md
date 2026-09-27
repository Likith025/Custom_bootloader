# STM32F756ZG Custom Bootloader

A custom bare-metal bootloader for the STM32F756ZG, built to understand bootloader development from the ground up — MCU boot flow, flash memory layout, linker scripts, vector tables, VTOR, MSP, and application handover — while doubling as a professional embedded-firmware portfolio project.

---

## Current Status

### Completed
- Bootloader and application memory separation
- Application linker configuration (application linked to start at `0x08010000`)
- Button-based boot-mode selection
- Application handover (bootloader → application)
- GPIO driver (push button, 2 LEDs)
- USART driver
- Bare-metal driver integration (via submodule)
- Hardware-tested bootloader → application handover

### In Progress
- USART bootloader command set
- Firmware reception over USART
- Application flash erase/programming
- Firmware validation
- PC-side GUI for firmware update workflow

> Note: USART communication is implemented, but firmware reception and flash programming are not yet functional. The two onboard LEDs are wired but do not currently have a defined functional purpose.

---

## Memory Layout

```text
0x08000000  ┌─────────────────────┐
            │     Bootloader      │
            │                     │
0x08010000  ├─────────────────────┤
            │     Application     │
            │                     │
            └─────────────────────┘
```

- Bootloader: `0x08000000`
- Application: `0x08010000` (64 KB offset)

---

## Boot-Mode Selection

```text
                    RESET
                      │
                      ▼
              Check Button State
                 /           \
            PRESSED        NOT PRESSED
                │               │
                ▼               ▼
        Application Mode    Bootloader Mode
                │
                ▼
        Application Handover
                │
                ▼
           Application
```

- **Button pressed** → application handover is performed and the application starts.
- **Button not pressed** → device remains in bootloader mode.

---

## Application Handover

The application vector table starts at `0x08010000`. On handover, the bootloader:

1. Reads the application's initial MSP from the vector table.
2. Reads the application's Reset Handler address.
3. Stores the Reset Handler as a function pointer.
4. Updates VTOR to the application's vector table.
5. Loads the application's initial MSP.
6. Calls the application's Reset Handler through the function pointer.

This allows the relocated application to run using its own startup code and vector table.

---

## Software Architecture

```text
Application
     │
 Services
     │
    ECAL
     │
    MCAL
     │
Bare-Metal Drivers
```

---

## Hardware & Tools

**MCU:** STM32F756ZG

**Programming / Debugging:** ST-LINK, STM32CubeIDE

**Peripherals:**
- GPIO (push button, 2 LEDs)
- USART

**Firmware approach:** Bare-metal — no ST-provided drivers (no HAL, no LL). All peripheral drivers are self-developed, maintained in a separate [STM32F756ZG Bare-Metal Driver](.) repository and included here as a Git submodule.

---

## Repository Layout

```text
STM32F756ZG-Custom-Bootloader/
│
├── Application/
├── Services/
├── ECAL/
├── MCAL/
├── Drivers/
│   └── STM32F756ZG-Bare-Metal-Driver-Development/
├── Inc/
├── Src/
└── README.md
```

---

## Next Step

Completing the USART firmware update mechanism:

```text
Finalize Commands
       ↓
Receive Firmware
       ↓
Erase Application Flash
       ↓
Program Application
       ↓
Validate Application
       ↓
Launch Application
```

A PC-side GUI (Python) is planned to drive this flow; the framework (Tkinter vs. PyQt) is not yet finalized.

---

## Learning Focus

This project is primarily a vehicle for learning:
- MCU reset and boot flow
- Flash memory layout and linker scripts
- Vector tables, VTOR, and MSP
- Application handover
- Boot-mode selection
- Bare-metal peripheral drivers
- Bootloader communication and flash programming

---

## Author


**Likith R**

Embedded Firmware Engineer | Bare-Metal & Automotive Embedded Systems
