#include <asm/neon.h>
#include <linux/linkage.h>

asmlinkage void *memchr_neon(const void *s, int c, size_t n);
asmlinkage char *strchr_neon(const char *s, int c);
asmlinkage char *strrchr_neon(const char *s, int c);

void *memchr(const void *s, int c, size_t n)
{
	kernel_neon_begin();
	s = memchr_neon(s,c,n);
	kernel_neon_end();
	return (void *)s;
}

char *strchr(const char *s, int c)
{
	kernel_neon_begin();
	s = strchr_neon(s,c);
	kernel_neon_end();
	return (char *)s;
}

char *strrchr(const char *s, int c)
{
	kernel_neon_begin();
	s = strrchr_neon(s,c);
	kernel_neon_end();
	return (char *)s;
}
