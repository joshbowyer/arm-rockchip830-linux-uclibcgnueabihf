/* Copyright (C) 1995, 1996, 1997, 1998, 2000 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _SYS_SEM_H
# error "Never include <bits/sem.h> directly; use <sys/sem.h> instead."
#endif

#include <sys/types.h>
#include <bits/wordsize.h>

/* Flags for `semop'.  */
#define SEM_UNDO	0x1000		/* undo the operation on exit */

/* Commands for `semctl'.  */
#define GETPID		11		/* get sempid */
#define GETVAL		12		/* get semval */
#define GETALL		13		/* get all semval's */
#define GETNCNT		14		/* get semncnt */
#define GETZCNT		15		/* get semzcnt */
#define SETVAL		16		/* set semval */
#define SETALL		17		/* set all semval's */


/* Data structure describing a set of semaphores.  */
struct semid_ds
{
  struct ipc_perm sem_perm;		/* operation permission struct */
  unsigned long int __sem_otime_internal_1;
  unsigned long int __sem_otime_internal_2;
#if (__WORDSIZE == 32 && !defined(__ARC64_ARCH32__) && !defined(__arc__) && !defined(__arm__) && !defined(__or1k__) && !defined(__xtensa__)) || \
    ((defined(__ARC64_ARCH32__) || defined(__arc__) || defined(__arm__) || defined(__or1k__) || defined(__xtensa__)) && !defined(__UCLIBC_USE_TIME64__))
  unsigned long int __uclibc_unused1;
#endif
  unsigned long int __sem_ctime_internal_1;
  unsigned long int __sem_ctime_internal_2;
#if (__WORDSIZE == 32 && !defined(__ARC64_ARCH32__) && !defined(__arc__) && !defined(__arm__) && !defined(__or1k__) && !defined(__xtensa__)) || \
    ((defined(__ARC64_ARCH32__) || defined(__arc__) || defined(__arm__) || defined(__or1k__) || defined(__xtensa__)) && !defined(__UCLIBC_USE_TIME64__))
  unsigned long int __uclibc_unused2;
#endif
  unsigned long int sem_nsems;		/* number of semaphores in set */
  __time_t sem_otime;			/* last semop() time */
  __time_t sem_ctime;			/* last time changed by semctl() */
  unsigned long int __uclibc_unused3;
  unsigned long int __uclibc_unused4;
};

/* The user should define a union like the following to use it for arguments
   for `semctl'.

   union semun
   {
     int val;				<= value for SETVAL
     struct semid_ds *buf;		<= buffer for IPC_STAT & IPC_SET
     unsigned short int *array;		<= array for GETALL & SETALL
     struct seminfo *__buf;		<= buffer for IPC_INFO
   };

   Previous versions of this file used to define this union but this is
   incorrect.  One can test the macro _SEM_SEMUN_UNDEFINED to see whether
   one must define the union or not.  */
#define _SEM_SEMUN_UNDEFINED	1

#ifdef __USE_MISC

/* ipcs ctl cmds */
# define SEM_STAT 18
# define SEM_INFO 19

struct  seminfo
{
  int semmap;
  int semmni;
  int semmns;
  int semmnu;
  int semmsl;
  int semopm;
  int semume;
  int semusz;
  int semvmx;
  int semaem;
};

#endif /* __USE_MISC */
