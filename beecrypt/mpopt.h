/** \ingroup MP_m
 * \file mpopt.h
 *
 * Multiprecision integer assembler-optimized routined for 32 bit cpu, header.
 */

/*
 * Copyright (c) 2003 Bob Deblier
 *
 * Author: Bob Deblier <bob@virtualunlimited.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef _MPOPT_H
#define _MPOPT_H

#ifdef __cplusplus
extern "C" {
#endif

#if WIN32
# if __MWERKS__ && __INTEL__
#  define ASM_MPZERO
#  define ASM_MPFILL
#  define ASM_MPEVEN
#  define ASM_MPODD
#  define ASM_MPADDW
#  define ASM_MPADD
#  define ASM_MPSUBW
#  define ASM_MPSUB
#  define ASM_MPSETMUL
#  define ASM_MPADDMUL
#  define ASM_MPADDSQRTRC
# elif defined(_MSC_VER) && defined(_M_IX86)
#  define ASM_MPZERO
#  define ASM_MPFILL
#  define ASM_MPEVEN
#  define ASM_MPODD
#  define ASM_MPADDW
#  define ASM_MPADD
#  define ASM_MPSUBW
#  define ASM_MPSUB
#  define ASM_MPDIVTWO
#  define ASM_MPMULTWO
#  define ASM_MPSETMUL
#  define ASM_MPADDMUL
#  define ASM_MPADDSQRTRC
# endif
#endif

#if defined(__GNUC__)
# if defined(OPTIMIZE_ARM)
#  define ASM_MPSETMUL
#  define ASM_MPADDMUL
# endif
# if defined(OPTIMIZE_I386) || defined(OPTIMIZE_I486) || defined(OPTIMIZE_I586) || defined(OPTIMIZE_I686)
#  define ASM_MPZERO
#  define ASM_MPFILL
#  define ASM_MPEVEN
#  define ASM_MPODD
#  define ASM_MPADDW
#  define ASM_MPADD
#  define ASM_MPSUBW
#  define ASM_MPSUB
#  define ASM_MPDIVTWO
#  define ASM_MPMULTWO
#  define ASM_MPSETMUL
#  define ASM_MPADDMUL
#  define ASM_MPADDSQRTRC
# endif
# if defined(OPTIMIZE_IA64)
#  define ASM_MPZERO
#  define ASM_MPCOPY
#  define ASM_MPADD
#  define ASM_MPSUB
#  undef ASM_MPSETMUL
#  undef ASM_MPADDMUL
# endif
# if defined(OPTIMIZE_POWERPC)
#  define ASM_MPADDW
#  define ASM_MPADD
#  define ASM_MPSUBW
#  define ASM_MPSUB
#  define ASM_MPMULTWO
#  define ASM_MPSETMUL
#  define ASM_MPADDMUL
#  define ASM_MPADDSQRTRC
# endif
# if defined(OPTIMIZE_SPARCV8)
#  define ASM_MPSETMUL
#  define ASM_MPADDMUL
#  define ASM_MPADDSQRTRC
# endif
# if defined(OPTIMIZE_SPARCV8PLUS) || defined(OPTIMIZE_SPARCV9)
#  define ASM_MPADDW
#  define ASM_MPADD
#  define ASM_MPSUBW
#  define ASM_MPSUB
#  define ASM_MPMULTWO
#  define ASM_MPSETMUL
#  define ASM_MPADDMUL
#  define ASM_MPADDSQRTRC
# endif
#endif

#if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
# if defined(OPTIMIZE_SPARCV8PLUS) /* || defined(OPTIMIZE_SPARCV9) */
#  define ASM_MPADDW
#  define ASM_MPADD
#  define ASM_MPSUBW
#  define ASM_MPSUB
#  define ASM_MPSETMUL
#  define ASM_MPADDMUL
#  define ASM_MPADDSQRTRC
#  endif
# if defined(OPTIMIZE_I386) || defined(OPTIMIZE_I486) || defined(OPTIMIZE_I586) || defined(OPTIMIZE_I686)
#  define ASM_MPADDW
#  define ASM_MPADD
#  define ASM_MPSUBW
#  define ASM_MPSUB
#  define ASM_MPMULTWO
#  define ASM_MPSETMUL
#  define ASM_MPADDMUL
#  define ASM_MPADDSQRTRC
# endif
#endif

#ifdef __cplusplus
}
#endif

#endif
