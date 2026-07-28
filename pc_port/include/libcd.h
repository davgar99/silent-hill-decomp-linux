#ifndef SH_PC_PORT_LIBCD_WRAPPER_H
#define SH_PC_PORT_LIBCD_WRAPPER_H

/* Keep the PsyCross/PSY-Q declarations, then intercept CdInit only for the
 * Linux PC port. pc_port/include is intentionally searched before PsyCross's
 * headers, so this wrapper can add the startup guard without modifying the
 * upstream submodule. */
#include_next <libcd.h>

#if defined(__linux__) && !defined(SH_LIBCD_NO_DISC_GUARD)
#ifdef __cplusplus
extern "C" {
#endif
int PcLinux_CdInitChecked(void);
#ifdef __cplusplus
}
#endif
#define CdInit() PcLinux_CdInitChecked()
#endif

#endif /* SH_PC_PORT_LIBCD_WRAPPER_H */
