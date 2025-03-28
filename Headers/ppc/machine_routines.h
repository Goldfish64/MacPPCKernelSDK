/*
 * Copyright (c) 2000-2006 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 * 
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */
/*
 * @OSF_COPYRIGHT@
 */

#ifndef	_PPC_MACHINE_ROUTINES_H_
#define	_PPC_MACHINE_ROUTINES_H_

#include <mach/mach_types.h>
#include <mach/boolean.h>
#include <kern/kern_types.h>
#include <pexpert/pexpert.h>

#include <sys/cdefs.h>
#include <sys/appleapiopts.h>

__BEGIN_DECLS

/* Get Interrupts Enabled */
extern boolean_t	ml_get_interrupts_enabled(
						void);

/* Set Interrupts Enabled */
extern boolean_t	ml_set_interrupts_enabled(
						boolean_t				enable);

/* Check if running at interrupt context */
extern boolean_t	ml_at_interrupt_context(
						void);

/* Type for the IPI Hander */
typedef void (*ipi_handler_t)(void);

/* Type for the Time Base Enable function */
typedef void (*time_base_enable_t)(cpu_id_t cpu_id, boolean_t enable);

/* Struct for ml_processor_register */
struct ml_processor_info {
	cpu_id_t			cpu_id;
	boolean_t			boot_cpu;
	vm_offset_t			start_paddr;
	boolean_t			supports_nap;
	unsigned long		l2cr_value;
	time_base_enable_t	time_base_enable;
};

typedef struct ml_processor_info ml_processor_info_t;

/* Register a processor */
kern_return_t ml_processor_register(
	ml_processor_info_t *processor_info,
	processor_t *processor,
	ipi_handler_t *ipi_handler);

__END_DECLS

#endif /* _PPC_MACHINE_ROUTINES_H_ */
