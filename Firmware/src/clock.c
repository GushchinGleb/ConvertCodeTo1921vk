#include <stdint.h>
#include "board.h"

// Bare-metal register struct definitions omitted for brevity.
// Pseudocode using VK035 fields; replace BASE/fields with your header pack.

#define RCU_BASE  ((volatile uint32_t*)0x40000000) // placeholder
#define PLLCFG    (*(volatile uint32_t*)(RCU_BASE + 0x008/4))
#define SYSCLKCFG (*(volatile uint32_t*)(RCU_BASE + 0x010/4))
#define SYSCLKSTAT(*(volatile uint32_t*)(RCU_BASE + 0x014/4))
#define PLLDIV    (*(volatile uint32_t*)(RCU_BASE + 0x00C/4))

static void rcu_wait_busy(void) { /* poll SYSCLKSTAT.BUSY */ }

static void select_sysclk_osi(void) {
  rcu_wait_busy();
  SYSCLKCFG = (SYSCLKCFG & ~0x3) | 0; // SYSSEL=00 OSICLK
  rcu_wait_busy();
}

void clock_init_100mhz_from_hse(uint32_t fin_hz)
{
  // Configure PLL: choose REFSRC, M,N,OD within datasheet constraints:
  // Fin in [4..64] MHz, Fin/N in [4..20], Fin*M/N in [120..200] MHz, Fout in [15..200] MHz. :contentReference[oaicite:9]{index=9}
  // Example for Fin=8 MHz -> Fvco=160 MHz (M=40,N=2) -> OD=0 => 160 MHz SYSCLK.

  // 1) Program PLLCFG with REFSRC/ M / N / OD, then wait LOCK bit. :contentReference[oaicite:10]{index=10}
  // 2) Optionally enable PLLDIV if you want divided output. :contentReference[oaicite:11]{index=11}
  // 3) Switch SYSSEL to PLL output, check SYSCLKSTAT.SYSSTAT = 10b. :contentReference[oaicite:12]{index=12}

  // Fallback safety: if SYSFAIL later, system auto-falls back to OSI and raises NMI; handle and reselect stable clock. :contentReference[oaicite:13]{index=13}
}
