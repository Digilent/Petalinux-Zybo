
#include <configs/platform-auto.h>

#define CONFIG_SYS_BOOTM_LEN 0xF000000

/*Required for uartless designs */
#ifndef CONFIG_BAUDRATE
#define CONFIG_BAUDRATE 115200
#ifdef CONFIG_DEBUG_UART
#undef CONFIG_DEBUG_UART
#endif
#endif

/* Read GEM MAC Address from EEPROM */
#define CONFIG_ZYNQ_I2C0
#define CONFIG_SYS_I2C_ZYNQ
#define CONFIG_CMD_I2C
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_ZYNQ_SPEED             100000
#define CONFIG_SYS_I2C_ZYNQ_SLAVE             0

#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN 1
#define CONFIG_CMD_EEPROM
#define CONFIG_ZYNQ_GEM_EEPROM_ADDR    0x50
#define CONFIG_ZYNQ_GEM_I2C_MAC_OFFSET 0xFA

/* Add ability to read uEnv.txt when not using SPI Flash for env */

#ifndef CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_IS_NOWHERE
#define CONFIG_ENV_SIZE	0x20000
#undef CONFIG_PREBOOT
#define CONFIG_PREBOOT	"echo U-BOOT for Zybo; setenv preboot; setenv bootenv uEnv.txt;  setenv loadbootenv_addr 0x1EE00000; if test $modeboot = sdboot && env run sd_uEnvtxt_existence_test; then if env run loadbootenv; then env run importbootenv; fi; fi; dhcp"
#endif
