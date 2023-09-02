/*

MD5 collision generator
=======================
Source code files:
  block0.cpp
  block1.cpp
  main.cpp
  main.hpp
  md5.cpp
Win32 executable:
  fastcoll_v1.0.0.1.exe

Version
=======
version 1.0.0.1, March 2006.

Copyright
=========
© M. Stevens, 2006. All rights reserved.

Disclaimer
==========
This software is provided as is. Use is at the user's risk.
No guarantee whatsoever is given on how it may function or malfunction.
Support cannot be expected.
This software is meant for scientific and educational purposes only.
It is forbidden to use it for other than scientific or educational purposes.
In particular, commercial and malicious use is not allowed.
Further distribution of this software, by whatever means, is not allowed
without our consent.
This includes publication of source code or executables in printed form,
on websites, newsgroups, CD-ROM's, etc.
Changing the (source) code without our consent is not allowed.
In all versions of the source code this disclaimer, the copyright
notice and the version number should be present.

*/

#include <iostream>
#include "main.hpp"

uint32 seed32_1, seed32_2;

uint32 block0complexity;

void find_block0(uint32 block[], const uint32 IV[])
{
	block0complexity = 0;
	uint32 Q[68] = { IV[0], IV[3], IV[2], IV[1] };

	while (true)
	{
		Q[Qoff + 1] = xrng64();
		Q[Qoff + 3] = xrng64() & 0xfff7f7bf;
		Q[Qoff + 4] = (xrng64() & 0x7f00000f) | 0x80080830 | (Q[Qoff + 3] & 0x0077f780);
		Q[Qoff + 5] = (xrng64() & 0x0130000a) | 0x88400025;
		Q[Qoff + 6] = 0x027fbc41 | (Q[Qoff + 5] & 0x0100000a);
		Q[Qoff + 7] = 0x03fef820;
		Q[Qoff + 8] = (xrng64() & 0x00605000) | 0x01910540;
		Q[Qoff + 9] = (xrng64() & 0x00e04000) | 0xfb102f3d | (Q[Qoff + 8] & 0x00001000);
		Q[Qoff + 10] = (xrng64() & 0x0f600e3c) | 0x701fd040;
		Q[Qoff + 11] = (xrng64() & 0x00700000) | 0x2081c0c2;
		Q[Qoff + 12] = (xrng64() & 0x1cf00e7f) | 0x00081100;
		Q[Qoff + 13] = (xrng64() & 0x3cf01e77) | 0x410fe008;
		Q[Qoff + 14] = (xrng64() & 0x5cf01e77) | 0x000be188;
		Q[Qoff + 15] = (xrng64() & 0x5cfe7ff7) | 0x21008000;
		Q[Qoff + 16] = (xrng64() & 0x1ffdffff) | 0x20000000 | (~Q[Qoff + 15] & 0x40020000);

		MD5_REVERSE_STEP(0, 0xd76aa478, 7);
		MD5_REVERSE_STEP(6, 0xa8304613, 17);
		MD5_REVERSE_STEP(7, 0xfd469501, 22);
		MD5_REVERSE_STEP(11, 0x895cd7be, 22);
		MD5_REVERSE_STEP(14, 0xa679438e, 17);
		MD5_REVERSE_STEP(15, 0x49b40821, 22);

		const uint32 tt1 = FF(Q[Qoff + 1], Q[Qoff + 0], Q[Qoff - 1]) + Q[Qoff - 2] + 0xe8c7b756;
		const uint32 tt17 = GG(Q[Qoff + 16], Q[Qoff + 15], Q[Qoff + 14]) + Q[Qoff + 13] + 0xf61e2562;
		const uint32 tt18 = Q[Qoff + 14] + 0xc040b340 + block[6];
		const uint32 tt19 = Q[Qoff + 15] + 0x265e5a51 + block[11];
		const uint32 tt20 = Q[Qoff + 16] + 0xe9b6c7aa + block[0];
		const uint32 tt5 = RR(Q[Qoff + 6] - Q[Qoff + 5], 12) - FF(Q[Qoff + 5], Q[Qoff + 4], Q[Qoff + 3]) - 0x4787c62a;

		unsigned counter = 0;
		while (counter < (1 << 9))
		{
			++counter;

			const uint32 q16 = Q[Qoff + 16];
			uint32 q17 = ((xrng64() & 0x3ffd7ff7) | (q16&0x40008008)) ^ 0x40000000;

			uint32 q18 = GG(q17, q16, Q[Qoff + 15]) + tt18;
			q18 = RL(q18, 9); q18 += q17;
			if (0x00020000 != ((q18^q17)&0xa0020000))
				continue;

			uint32 q19 = GG(q18, q17, q16) + tt19;
			q19 = RL(q19, 14); q19 += q18;
			if (0 != (q19 & 0x80020000))
				continue;

			uint32 q20 = GG(q19, q18, q17) + tt20;
			q20 = RL(q20, 20); q20 += q19;
			if (0x00040000 != ((q20^q19) & 0x80040000))
				continue;

			uint32 m1 = q17-q16; m1 = RR(m1, 5); m1 -= tt17;
			uint32 q2 = m1 + tt1; q2 = RL(q2, 12); q2 += Q[Qoff + 1];
			uint32 m5 = tt5 - q2;

			uint32 q21 = GG(q20, q19, q18) + q17 + 0xd62f105d + m5;
			q21 = RL(q21, 5); q21 += q20;
			if (0 != ((q21^q20) & 0x80020000))
				continue;

			Q[Qoff + 2] = q2;
			Q[Qoff + 17] = q17;
			Q[Qoff + 18] = q18;
			Q[Qoff + 19] = q19;
			Q[Qoff + 20] = q20;
			Q[Qoff + 21] = q21;

			block[1] = m1;
			block[5] = m5;
			MD5_REVERSE_STEP(2, 0x242070db, 17);
			MD5_REVERSE_STEP(3, 0xc1bdceee, 22);
			MD5_REVERSE_STEP(4, 0xf57c0faf, 7);

			counter = 0;
			break;
		}
		if (counter != 0)
			continue;

		const uint32 mask9 = 0x00e04000 & Q[Qoff + 11];
		const uint32 mask10 = 0x0f600e3c & ~Q[Qoff + 11];

		const uint32 q9b = Q[Qoff + 9] & ~mask9;
		const uint32 q10b = Q[Qoff + 10] & ~mask10;

		const uint32 tt22 = GG(Q[Qoff + 21], Q[Qoff + 20], Q[Qoff + 19]) + Q[Qoff + 18] + 0x02441453;
		const uint32 tt23 = Q[Qoff + 19] + 0xd8a1e681 + block[15];
		const uint32 tt24 = Q[Qoff + 20] + 0xe7d3fbc8 + block[4];

		const uint32 tt9 = Q[Qoff + 6] + 0x8b44f7af;
		const uint32 tt10 = Q[Qoff + 7] + 0xffff5bb1;
		const uint32 tt8 = FF(Q[Qoff + 8], Q[Qoff + 7], Q[Qoff + 6]) + Q[Qoff + 5] + 0x698098d8;
		const uint32 tt11 = RR(Q[Qoff+12]-Q[Qoff+11],22) - Q[Qoff+8] - 0x895cd7be;
		const uint32 tt12 = RR(Q[Qoff+13]-Q[Qoff+12],7) - 0x6b901122;
		const uint32 tt13 = RR(Q[Qoff+14]-Q[Qoff+13],12) - FF(Q[Qoff+13],Q[Qoff+12],Q[Qoff+11]) - 0xfd987193;

		++block0complexity;
		counter = 0;
		while (counter < (1 << 15))
		{
			++counter;
			uint32 shiftcnt = (counter >> 9)
								+ ((counter & 0x380) << 2)
								+ ((counter & 0x400) << 4)
								+ (counter << 21);

			uint32 q10 = q10b | (shiftcnt & mask10);
			uint32 m10 = RR(Q[Qoff+11]-q10,17);
			uint32 q9 = q9b | (shiftcnt & mask9);
			m10 -= FF(q10, q9, Q[Qoff+8]) + tt10;

			uint32 a = Q[Qoff + 21];
			uint32 d = tt22+m10; d = RL(d, 9) + a;
			if (0 != (d & 0x80000000)) continue;

			uint32 b = Q[Qoff + 20];
			uint32 c = tt23 + GG(d, a, b);
			if (0 != (c & 0x20000)) continue;
			c = RL(c, 14) + d;
			if (0 != (c & 0x80000000)) continue;

			b = tt24 + GG(c, d, a); b = RL(b, 20) + c;
			if (0 == (b & 0x80000000)) continue;

			block[10] = m10;

			uint32 m8 = q9 - Q[Qoff + 8];
			block[8] = RR(m8, 7) - tt8;
			uint32 m9 = q10 - q9;
			block[9] = RR(m9, 12) - FF(q9, Q[Qoff + 8], Q[Qoff + 7]) - tt9;
			block[11] = tt11 - FF(Q[Qoff + 11], q10, q9);
			block[12] = tt12 - FF(Q[Qoff + 12], Q[Qoff + 11], q10) - q9;
			block[13] = tt13 - q10;

			MD5_STEP(GG, a, b, c, d, block[9], 0x21e1cde6, 5);
			MD5_STEP(GG, d, a, b, c, block[14], 0xc33707d6, 9);
			MD5_STEP(GG, c, d, a, b, block[3], 0xf4d50d87, 14);
			MD5_STEP(GG, b, c, d, a, block[8], 0x455a14ed, 20);
			MD5_STEP(GG, a, b, c, d, block[13], 0xa9e3e905, 5);
			MD5_STEP(GG, d, a, b, c, block[2], 0xfcefa3f8, 9);
			MD5_STEP(GG, c, d, a, b, block[7], 0x676f02d9, 14);
			MD5_STEP(GG, b, c, d, a, block[12], 0x8d2a4c8a, 20);
			MD5_STEP(HH, a, b, c, d, block[5], 0xfffa3942, 4);
			MD5_STEP(HH, d, a, b, c, block[8], 0x8771f681, 11);

			c += HH(d, a, b) + block[11] + 0x6d9d6122;
			if (0 != (c & (1 << 15)))
				continue;
			c = (c<<16 | c>>16) + d;

			MD5_STEP(HH, b, c, d, a, block[14], 0xfde5380c, 23);
			MD5_STEP(HH, a, b, c, d, block[1], 0xa4beea44, 4);
			MD5_STEP(HH, d, a, b, c, block[4], 0x4bdecfa9, 11);
			MD5_STEP(HH, c, d, a, b, block[7], 0xf6bb4b60, 16);
			MD5_STEP(HH, b, c, d, a, block[10], 0xbebfbc70, 23);
			MD5_STEP(HH, a, b, c, d, block[13], 0x289b7ec6, 4);
			MD5_STEP(HH, d, a, b, c, block[0], 0xeaa127fa, 11);
			MD5_STEP(HH, c, d, a, b, block[3], 0xd4ef3085, 16);
			MD5_STEP(HH, b, c, d, a, block[6], 0x04881d05, 23);
			MD5_STEP(HH, a, b, c, d, block[9], 0xd9d4d039, 4);
			MD5_STEP(HH, d, a, b, c, block[12], 0xe6db99e5, 11);
			MD5_STEP(HH, c, d, a, b, block[15], 0x1fa27cf8, 16);
			MD5_STEP(HH, b, c, d, a, block[2], 0xc4ac5665, 23);
			if (0 != ((b^d) & 0x80000000))
				continue;

			MD5_STEP(II, a, b, c, d, block[0], 0xf4292244, 6);
			if (0 != ((a^c) >> 31)) continue;
			MD5_STEP(II, d, a, b, c, block[7], 0x432aff97, 10);
			if (0 == ((b^d) >> 31)) continue;
			MD5_STEP(II, c, d, a, b, block[14], 0xab9423a7, 15);
			if (0 != ((a^c) >> 31)) continue;
			MD5_STEP(II, b, c, d, a, block[5], 0xfc93a039, 21);
			if (0 != ((b^d) >> 31)) continue;
			MD5_STEP(II, a, b, c, d, block[12], 0x655b59c3, 6);
			if (0 != ((a^c) >> 31)) continue;
			MD5_STEP(II, d, a, b, c, block[3], 0x8f0ccc92, 10);
			if (0 != ((b^d) >> 31)) continue;
			MD5_STEP(II, c, d, a, b, block[10], 0xffeff47d, 15);
			if (0 != ((a^c) >> 31)) continue;
			MD5_STEP(II, b, c, d, a, block[1], 0x85845dd1, 21);
			if (0 != ((b^d) >> 31)) continue;
			MD5_STEP(II, a, b, c, d, block[8], 0x6fa87e4f, 6);
			if (0 != ((a^c) >> 31)) continue;
			MD5_STEP(II, d, a, b, c, block[15], 0xfe2ce6e0, 10);
			if (0 != ((b^d) >> 31)) continue;
			MD5_STEP(II, c, d, a, b, block[6], 0xa3014314, 15);
			if (0 != ((a^c) >> 31)) continue;
			MD5_STEP(II, b, c, d, a, block[13], 0x4e0811a1, 21);
			if (0 == ((b^d) >> 31)) continue;
			MD5_STEP(II, a, b, c, d, block[4], 0xf7537e82, 6);
			if (0 != ((a^c) >> 31)) continue;
			MD5_STEP(II, d, a, b, c, block[11], 0xbd3af235, 10);
			if (0 != ((b^d) >> 31)) continue;
			MD5_STEP(II, c, d, a, b, block[2], 0x2ad7d2bb, 15);
			if (0 != ((a^c) >> 31)) continue;
			MD5_STEP(II, b, c, d, a, block[9], 0xeb86d391, 21);

			uint32 ihv1 = b + IV[1];
			if (0 != (ihv1 & 0x06000020)) continue;
			uint32 ihv2 = c + IV[2];
			if (0x02000000 != ((ihv2^ihv1) & 0x86000000)) continue;
			uint32 ihv3 = d + IV[3];
			if (0 != ((ihv1^ihv3) & 0x82000000)) continue;




			std::cout << "." << std::flush;

			uint32 IV1[4], IV2[4];
			for (int t = 0; t < 4; ++t)
				IV2[t] = IV1[t] = IV[t];

			uint32 block2[16];
			for (int t = 0; t < 16; ++t)
				block2[t] = block[t];
			block2[4] += 1<<31;
			block2[11] += 1<<15;
			block2[14] += 1<<31;

			md5_compress(IV1, block);
			md5_compress(IV2, block2);
            if (	   (IV2[0] == IV1[0] + (1<<31))
					&& (IV2[1] == IV1[1] + (1<<31) + (1<<25))
					&& (IV2[2] == IV1[2] + (1<<31) + (1<<25))
					&& (IV2[3] == IV1[3] + (1<<31) + (1<<25)))
				return;

			if (IV2[0] != IV1[0] + (1<<31))
				std::cout << "!" << std::flush;
		}
	}
}
