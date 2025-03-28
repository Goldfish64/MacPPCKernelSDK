/*
 * Copyright (c) 2000-2008 Apple Inc. All rights reserved.
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
/*
 */

#ifndef	_KERN_CLOCK_H_
#define	_KERN_CLOCK_H_

#include <stdint.h>
#include <mach/mach_types.h>
#include <mach/clock_types.h>
#include <mach/message.h>
#include <mach/mach_time.h>

#include <kern/kern_types.h>

#include <sys/cdefs.h>

#ifdef	__LP64__

typedef unsigned long		clock_sec_t;
typedef unsigned int		clock_usec_t, clock_nsec_t;

#else	/* __LP64__ */

typedef uint32_t			clock_sec_t;
typedef uint32_t			clock_usec_t, clock_nsec_t;

#endif	/* __LP64__ */


__BEGIN_DECLS


extern void			clock_get_calendar_microtime(
						clock_sec_t			*secs,
						clock_usec_t		*microsecs);

extern void			clock_get_calendar_nanotime(
						clock_sec_t			*secs,
						clock_nsec_t		*nanosecs);

extern void			clock_get_system_microtime(
						clock_sec_t			*secs,
						clock_usec_t		*microsecs);

extern void			clock_get_system_nanotime(
						clock_sec_t			*secs,
						clock_nsec_t		*nanosecs);

extern void				clock_timebase_info(
							mach_timebase_info_t	info);

extern void				clock_get_uptime(
							uint64_t		*result);

extern void				clock_interval_to_deadline(
							uint32_t		interval,
							uint32_t		scale_factor,
							uint64_t		*result);

extern void				clock_interval_to_absolutetime_interval(
							uint32_t		interval,
							uint32_t		scale_factor,
							uint64_t		*result);

extern void				clock_absolutetime_interval_to_deadline(
							uint64_t		abstime,
							uint64_t		*result);

extern void				clock_delay_until(
							uint64_t		deadline);

extern void				absolutetime_to_nanoseconds(
							uint64_t		abstime,
							uint64_t		*result);

extern void             nanoseconds_to_absolutetime(
							uint64_t		nanoseconds,
							uint64_t		*result);

#if		!defined(MACH_KERNEL_PRIVATE) && !defined(ABSOLUTETIME_SCALAR_TYPE)

#include <libkern/OSBase.h>

#define clock_get_uptime(a)		\
	clock_get_uptime(__OSAbsoluteTimePtr(a))

#define clock_interval_to_deadline(a, b, c)		\
	clock_interval_to_deadline((a), (b), __OSAbsoluteTimePtr(c))

#define clock_interval_to_absolutetime_interval(a, b, c)	\
	clock_interval_to_absolutetime_interval((a), (b), __OSAbsoluteTimePtr(c))

#define clock_absolutetime_interval_to_deadline(a, b)	\
	clock_absolutetime_interval_to_deadline(__OSAbsoluteTime(a), __OSAbsoluteTimePtr(b))

#define clock_deadline_for_periodic_event(a, b, c)	\
	clock_deadline_for_periodic_event(__OSAbsoluteTime(a), __OSAbsoluteTime(b), __OSAbsoluteTimePtr(c))

#define clock_delay_until(a)	\
	clock_delay_until(__OSAbsoluteTime(a))

#define absolutetime_to_nanoseconds(a, b)	\
	absolutetime_to_nanoseconds(__OSAbsoluteTime(a), (b))

#define nanoseconds_to_absolutetime(a, b)	\
	nanoseconds_to_absolutetime((a), __OSAbsoluteTimePtr(b))

#define AbsoluteTime_to_scalar(x)	(*(uint64_t *)(x))

/* t1 < = > t2 */
#define CMP_ABSOLUTETIME(t1, t2)				\
	(AbsoluteTime_to_scalar(t1) >				\
		AbsoluteTime_to_scalar(t2)? (int)+1 :	\
	 (AbsoluteTime_to_scalar(t1) <				\
		AbsoluteTime_to_scalar(t2)? (int)-1 : 0))

/* t1 += t2 */
#define ADD_ABSOLUTETIME(t1, t2)				\
	(AbsoluteTime_to_scalar(t1) +=				\
				AbsoluteTime_to_scalar(t2))

/* t1 -= t2 */
#define SUB_ABSOLUTETIME(t1, t2)				\
	(AbsoluteTime_to_scalar(t1) -=				\
				AbsoluteTime_to_scalar(t2))

#define ADD_ABSOLUTETIME_TICKS(t1, ticks)		\
	(AbsoluteTime_to_scalar(t1) +=				\
						(int32_t)(ticks))

#endif

__END_DECLS

#endif	/* _KERN_CLOCK_H_ */
