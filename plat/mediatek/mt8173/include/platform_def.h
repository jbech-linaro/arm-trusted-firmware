/*
 * Copyright (c) 2014-2015, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __PLATFORM_DEF_H__
#define __PLATFORM_DEF_H__

#if RESET_TO_BL31
#error "MT8173 is incompatible with RESET_TO_BL31!"
#endif

#define MT8173_PRIMARY_CPU	0x0

/* Register base address */
#define IO_PHYS			(0x10000000)
#define INFRACFG_AO_BASE	(IO_PHYS + 0x1000)
#define SRAMROM_SEC_BASE	(IO_PHYS + 0x1800)
#define PERI_CON_BASE		(IO_PHYS + 0x3000)
#define GPIO_BASE		(IO_PHYS + 0x5000)
#define SPM_BASE		(IO_PHYS + 0x6000)
#define RGU_BASE		(IO_PHYS + 0x7000)
#define PMIC_WRAP_BASE		(IO_PHYS + 0xD000)
#define DEVAPC0_BASE		(IO_PHYS + 0xE000)
#define MCUCFG_BASE		(IO_PHYS + 0x200000)
#define APMIXED_BASE		(IO_PHYS + 0x209000)
#define TRNG_BASE		(IO_PHYS + 0x20F000)
#define CRYPT_BASE		(IO_PHYS + 0x210000)
#define MT_GIC_BASE		(IO_PHYS + 0x220000)
#define PLAT_MT_CCI_BASE	(IO_PHYS + 0x390000)

/* Aggregate of all devices in the first GB */
#define MTK_DEV_RNG0_BASE	IO_PHYS
#define MTK_DEV_RNG0_SIZE	0x400000
#define MTK_DEV_RNG1_BASE	(IO_PHYS + 0x1000000)
#define MTK_DEV_RNG1_SIZE	0x4000000

/* SRAMROM related registers */
#define SRAMROM_SEC_CTRL	(SRAMROM_SEC_BASE + 0x4)
#define SRAMROM_SEC_ADDR	(SRAMROM_SEC_BASE + 0x8)

/* DEVAPC0 related registers */
#define DEVAPC0_MAS_SEC_0	(DEVAPC0_BASE + 0x500)
#define DEVAPC0_APC_CON		(DEVAPC0_BASE + 0xF00)

/*******************************************************************************
 * UART related constants
 ******************************************************************************/
#define UART0_BASE	(IO_PHYS + 0x01002000)
#define UART1_BASE	(IO_PHYS + 0x01003000)
#define UART2_BASE	(IO_PHYS + 0x01004000)
#define UART3_BASE	(IO_PHYS + 0x01005000)

#define UART_BAUDRATE		(921600)
#define UART_CLOCK		(26000000)

/*******************************************************************************
 * System counter frequency related constants
 ******************************************************************************/
#define SYS_COUNTER_FREQ_IN_TICKS	13000000

/*******************************************************************************
 * GIC-400 & interrupt handling related constants
 ******************************************************************************/

/* Base MTK_platform compatible GIC memory map */
#define BASE_GICD_BASE		(MT_GIC_BASE + 0x1000)
#define BASE_GICC_BASE		(MT_GIC_BASE + 0x2000)
#define BASE_GICR_BASE		0	/* no GICR in GIC-400 */
#define BASE_GICH_BASE		(MT_GIC_BASE + 0x4000)
#define BASE_GICV_BASE		(MT_GIC_BASE + 0x6000)
#define INT_POL_CTL0		0x10200620

#define GIC_PRIVATE_SIGNALS	(32)

/*******************************************************************************
 * CCI-400 related constants
 ******************************************************************************/
#define PLAT_MT_CCI_CLUSTER0_SL_IFACE_IX	4
#define PLAT_MT_CCI_CLUSTER1_SL_IFACE_IX	3

/*******************************************************************************
 * WDT related constants
 ******************************************************************************/
#define MTK_WDT_BASE		(RGU_BASE + 0)
#define MTK_WDT_SWRST		(MTK_WDT_BASE + 0x0014)

#define MTK_WDT_MODE_DUAL_MODE	0x0040
#define MTK_WDT_MODE_IRQ	0x0008
#define MTK_WDT_MODE_KEY	0x22000000
#define MTK_WDT_MODE_EXTEN	0x0004
#define MTK_WDT_SWRST_KEY	0x1209

/* FIQ platform related define */
#define MT_IRQ_SEC_SGI_0	8
#define MT_IRQ_SEC_SGI_1	9
#define MT_IRQ_SEC_SGI_2	10
#define MT_IRQ_SEC_SGI_3	11
#define MT_IRQ_SEC_SGI_4	12
#define MT_IRQ_SEC_SGI_5	13
#define MT_IRQ_SEC_SGI_6	14
#define MT_IRQ_SEC_SGI_7	15

/*
 *  Macros for local power states in MTK platforms encoded by State-ID field
 *  within the power-state parameter.
 */
/* Local power state for power domains in Run state. */
#define MTK_LOCAL_STATE_RUN     0
/* Local power state for retention. Valid only for CPU power domains */
#define MTK_LOCAL_STATE_RET     1
/* Local power state for OFF/power-down. Valid for CPU and cluster power
 * domains
 */
#define MTK_LOCAL_STATE_OFF     2

#if PSCI_EXTENDED_STATE_ID
/*
 * Macros used to parse state information from State-ID if it is using the
 * recommended encoding for State-ID.
 */
#define MTK_LOCAL_PSTATE_WIDTH		4
#define MTK_LOCAL_PSTATE_MASK		((1 << MTK_LOCAL_PSTATE_WIDTH) - 1)

/* Macros to construct the composite power state */

/* Make composite power state parameter till power level 0 */

#define mtk_make_pwrstate_lvl0(lvl0_state, pwr_lvl, type) \
	(((lvl0_state) << PSTATE_ID_SHIFT) | ((type) << PSTATE_TYPE_SHIFT))
#else
#define mtk_make_pwrstate_lvl0(lvl0_state, pwr_lvl, type) \
		(((lvl0_state) << PSTATE_ID_SHIFT) | \
		((pwr_lvl) << PSTATE_PWR_LVL_SHIFT) | \
		((type) << PSTATE_TYPE_SHIFT))

#endif /* __PSCI_EXTENDED_STATE_ID__ */

/* Make composite power state parameter till power level 1 */
#define mtk_make_pwrstate_lvl1(lvl1_state, lvl0_state, pwr_lvl, type) \
		(((lvl1_state) << MTK_LOCAL_PSTATE_WIDTH) | \
		mtk_make_pwrstate_lvl0(lvl0_state, pwr_lvl, type))

/* Make composite power state parameter till power level 2 */
#define mtk_make_pwrstate_lvl2( \
		lvl2_state, lvl1_state, lvl0_state, pwr_lvl, type) \
		(((lvl2_state) << (MTK_LOCAL_PSTATE_WIDTH * 2)) | \
		mtk_make_pwrstate_lvl1(lvl1_state, lvl0_state, pwr_lvl, type))



// FIXME after

/*******************************************************************************
 * Platform binary types for linking
 ******************************************************************************/
#define PLATFORM_LINKER_FORMAT		"elf64-littleaarch64"
#define PLATFORM_LINKER_ARCH		aarch64

/*******************************************************************************
 * Generic platform constants
 ******************************************************************************/

/* Size of cacheable stacks */
#if defined(IMAGE_BL1)
#define PLATFORM_STACK_SIZE 0x440
#elif defined(IMAGE_BL2)
#define PLATFORM_STACK_SIZE 0x400
#elif defined(IMAGE_BL31)
#define PLATFORM_STACK_SIZE 0x800
#elif defined(IMAGE_BL32)
#define PLATFORM_STACK_SIZE 0x440
#endif

#define FIRMWARE_WELCOME_STR		"Booting Trusted Firmware\n"

#define PLATFORM_MAX_AFFLVL		MPIDR_AFFLVL2
#if !ENABLE_PLAT_COMPAT
#define PLAT_MAX_PWR_LVL		2
#define PLAT_MAX_RET_STATE		1
#define PLAT_MAX_OFF_STATE		2
#endif
#define PLATFORM_SYSTEM_COUNT		1
#define PLATFORM_CLUSTER_COUNT		2
#define PLATFORM_CLUSTER0_CORE_COUNT	4
#define PLATFORM_CLUSTER1_CORE_COUNT	2
#define PLATFORM_CORE_COUNT		(PLATFORM_CLUSTER1_CORE_COUNT +	\
					 PLATFORM_CLUSTER0_CORE_COUNT)
#define PLATFORM_MAX_CPUS_PER_CLUSTER	4
#define PLATFORM_NUM_AFFS		(PLATFORM_SYSTEM_COUNT +	\
					 PLATFORM_CLUSTER_COUNT +	\
					 PLATFORM_CORE_COUNT)

/*******************************************************************************
 * Platform memory map related constants
 ******************************************************************************/
/*
 * MT8173 SRAM memory layout
 * 0x100000 +-------------------+
 *          | shared mem (4KB)  |
 * 0x101000 +-------------------+
 *          |                   |
 *          |   BL3-1 (124KB)   |
 *          |                   |
 * 0x120000 +-------------------+
 *          |  reserved (64KB)  |
 * 0x130000 +-------------------+
 */
/* TF txet, ro, rw, xlat table, coherent memory ... etc.
 * Size: release: 128KB, debug: 128KB
 */
#define TZRAM_BASE		(0x100000)
#if DEBUG
#define TZRAM_SIZE		(0x20000)
#else
#define TZRAM_SIZE		(0x20000)
#endif

/* Reserved: 64KB */
#define TZRAM2_BASE		(TZRAM_BASE + TZRAM_SIZE)
#define TZRAM2_SIZE		(0x10000)

/*******************************************************************************
 * BL31 specific defines.
 ******************************************************************************/
/*
 * Put BL3-1 at the top of the Trusted SRAM (just below the shared memory, if
 * present). BL31_BASE is calculated using the current BL3-1 debug size plus a
 * little space for growth.
 */
#define BL31_BASE		(TZRAM_BASE + 0x1000)
#define BL31_LIMIT		(TZRAM_BASE + TZRAM_SIZE)
#define TZRAM2_LIMIT		(TZRAM2_BASE + TZRAM2_SIZE)

/*******************************************************************************
 * Platform specific page table and MMU setup constants
 ******************************************************************************/
#define PLAT_PHY_ADDR_SPACE_SIZE	(1ull << 32)
#define PLAT_VIRT_ADDR_SPACE_SIZE	(1ull << 32)
#define MAX_XLAT_TABLES		4
#define MAX_MMAP_REGIONS	16

/*******************************************************************************
 * Declarations and constants to access the mailboxes safely. Each mailbox is
 * aligned on the biggest cache line size in the platform. This is known only
 * to the platform as it might have a combination of integrated and external
 * caches. Such alignment ensures that two maiboxes do not sit on the same cache
 * line at any cache level. They could belong to different cpus/clusters &
 * get written while being protected by different locks causing corruption of
 * a valid mailbox address.
 ******************************************************************************/
#define CACHE_WRITEBACK_SHIFT	6
#define CACHE_WRITEBACK_GRANULE	(1 << CACHE_WRITEBACK_SHIFT)


#define PLAT_ARM_GICD_BASE      BASE_GICD_BASE
#define PLAT_ARM_GICC_BASE      BASE_GICC_BASE

#define PLAT_ARM_G1S_IRQS       MT_IRQ_SEC_SGI_0, \
				MT_IRQ_SEC_SGI_1, \
				MT_IRQ_SEC_SGI_2, \
				MT_IRQ_SEC_SGI_3, \
				MT_IRQ_SEC_SGI_4, \
				MT_IRQ_SEC_SGI_5, \
				MT_IRQ_SEC_SGI_6, \
				MT_IRQ_SEC_SGI_7

#define PLAT_ARM_G0_IRQS

#endif /* __PLATFORM_DEF_H__ */
