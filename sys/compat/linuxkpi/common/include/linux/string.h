/*-
 * Copyright (c) 2010 Isilon Systems, Inc.
 * Copyright (c) 2010 iX Systems, Inc.
 * Copyright (c) 2010 Panasas, Inc.
 * Copyright (c) 2013-2016 Mellanox Technologies, Ltd.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */
#ifndef	_LINUX_STRING_H_
#define	_LINUX_STRING_H_

#include <sys/ctype.h>

#include <linux/types.h>
#include <linux/gfp.h>
#include <linux/slab.h>

#include <sys/libkern.h>

#define	strnicmp(...) strncasecmp(__VA_ARGS__)

extern void *memdup_user(const void __user *, size_t);


static inline int
match_string(const char * const *table, size_t n, const char *key)
{
	int i;

	for (i = 0; i < n && table[i] != NULL; i++) {
		if (strcmp(table[i], key) == 0)
			return (i);
	}
	return (-EINVAL);
}

static inline void *
kmemdup(const void *src, size_t len, gfp_t gfp)
{
	void *dst;

	dst = kmalloc(len, gfp);
	if (dst)
		memcpy(dst, src, len);
	return (dst);
}

static inline char *
kstrdup(const char *string, gfp_t gfp)
{
	size_t len;
	char *copy;

	len = strlen(string) + 1;
	copy = malloc(len, M_KMALLOC, gfp);
	bcopy(string, copy, len);
	return (copy);
}

static inline char *
kstrndup(const char *string, size_t len, gfp_t gfp)
{
	char *copy;

	copy = malloc(len + 1, M_KMALLOC, gfp);
	strncpy(copy, string, len);
	return (copy);
}

static inline const char *
kstrdup_const(const char *src, gfp_t gfp)
{
	return (kmemdup(src, strlen(src) + 1, gfp));
}

void *memchr_inv(const void *start, int c, size_t bytes);

static inline char *
skip_spaces(const char *str)
{
	while (isspace(*str))
		++str;
	return __DECONST(char *, str);
}

#endif	/* _LINUX_STRING_H_ */
