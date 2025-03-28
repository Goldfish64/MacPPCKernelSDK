/*
 * Copyright (c) 2004 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 *
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef	LIBKERN_VERSION_H
#define LIBKERN_VERSION_H

#if defined(__cplusplus)
extern "C" {
#endif

/* Kernel versions conform to kext version strings, as described in:
 * http://developer.apple.com/technotes/tn/tn1132.html
 */

/* VERSION_MAJOR, version_major is an integer that represents that major version
 * of the kernel
 */
#define VERSION_MAJOR		10
extern const int version_major;

/* VERSION_MINOR, version_minor is an integer that represents the minor version
 * of the kernel
 */
#define VERSION_MINOR		4
extern const int version_minor;

/* VERSION_VARIANT, version_variant is a string that contains the revision,
 * stage, and prerelease level of the kernel
 */
#define VERSION_VARIANT		"0"
extern const char version_variant[];

/* VERSION_REVISION, version_revision is an integer that represents the revision
 * of the kernel
 */
#define VERSION_REVISION	0
extern const int version_revision;

/* VERSION_STAGE, version_stage, is an integer set to one of the following: */
#define VERSION_STAGE_DEV	0x20
#define VERSION_STAGE_ALPHA	0x40
#define VERSION_STAGE_BETA	0x60
#define VERSION_STAGE_RELEASE	0x80
#define VERSION_STAGE		VERSION_STAGE_RELEASE
extern const int version_stage;

/* VERSION_PRERELEASE_LEVEL, version_prerelease_level, is an integer sequence
 * number to distinguish between pre-release builds
 */
#define VERSION_PRERELEASE_LEVEL	0
extern const int version_prerelease_level;

/* OSTYPE, ostype, is a string as returned by uname -s */
#define	OSTYPE		"Darwin"
extern const char ostype[];

/* OSRELEASE, osrelease, is a string as returned by uname -r */
#define OSRELEASE	"10.4.0"
extern const char osrelease[];

/* osbuilder is a string as returned by uname -r */
extern const char osbuilder[];

/* version is a string of the following form, as returned by uname -v:
 * "Darwin Kernel Version <osrelease>: <build date>; <osbuilder>:<build root>"
 */

extern const char version[];

#define OSVERSIZE 256
extern char osversion[];


#if defined(__cplusplus)
}
#endif

#endif	/* LIBKERN_VERSION_H */
