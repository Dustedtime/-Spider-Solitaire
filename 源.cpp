#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	srand((unsigned)time(NULL));
	int a[800] = { 0 }, b[50] = { 0 }, c = 0, i, j, max = 0, max1, i0, p, y = 0, d1, d2, z, s = 0, f, k = 0;
	int k0 = 0, i1, f1 = 0, i2, c1, gg = 0, z1, y0 = 0;
	for (i = 0;;)
	{
		a[i] = rand() % 13 + 1;
		if (i % 80 != 0)
		{
			for (j = 0; j <= (i % 80); j++)
			{
				for (;;)
				{
					if (i == j)
						break;
					if (a[i] == a[j])
						c++;
					if (c >= 8)
						break;
					j += 80;
					if (j >= 800)
						j -= 799;
				}
				if (i == j)
					break;
				if (c >= 8)
					break;
			}
			if (c >= 8)
			{
				c = 0;
				continue;
			}
		}
		else
		{
			for (j = 0; j < i; j += 80)
			{
				if (i != j)
					if (a[i] == a[j])
						c++;
			}
			if (c >= 8)
			{
				c = 0;
				continue;
			}
		}
		if (i == 245)
			break;
		i += 80;
		if (i >= 800)
			i -= 799;
	}
	for (j = 0, c = 0; j <=49; j++)
	{
		b[j] = rand() % 13 + 1;
		for (i = 0; i <= 724; i++)
		{
			if (a[i] == b[j])
				c++;
		}
		for (i = 0; i < j; i++)
		{
			if (b[i] == b[j])
				c++;
		}
		if (c >= 8)
		{
			c = 0;
			continue;
		}
	}
	for (i = 5; i <= 245; i += 80)
		a[i] += 100;
	for (i = 324; i <= 724; i += 80)
		a[i] += 100;
	for (i = 0; i <= 49; i++)
		b[i] += 100;
	printf("                                                                                      欢迎来到蜘蛛纸牌游戏！\n");
	printf("                                                                                       按下回车键开始游戏\n");
	char ch = getchar();
	for (;;)
	{
		if (f1 == 1)
		{
			for (i = 0, j = 0; i <= 799; i += 80, j++)
			{
				c = i;
				i0 = int(i / 80);
				for (; i <= i0 * 80 + 79; i++)
				{
					if (a[i] == 0)
					{
						a[i] = b[j];
						break;
					}
				}
				i = c;
			}
			for (j = 0; j <= p * 10 - 11; j++)
				b[j] = b[j + 10];
			for (j = (p - 1) * 10; j <= 49; j++)
				b[j] = 0;
			f1 = 0;
		}
		printf("          1        2        3        4        5        6        7        8        9       10\n\n");
		for (i = 0, max = 0; i <= 799; i++)
		{
			if (a[i] != 0 && (i % 80) >= max)
				max = i % 80;
		}
		for (i = 0, j = 1; j <= max + 1; j++)
		{
			printf("%2d       ", j);
			for (;;)
			{
				c = i;
				i0 = int(i / 80);
				for (; i <= i0 * 80 + 79; i++)
				{
					if (a[i] == 0)
					{
						if (i % 80 != 0 && a[i - 1] < 100 && a[i - 1])
							a[i - 1] += 100;
						break;
					}
				}
				i = c;
				if (a[i] < 100 && a[i] > 0)
					printf(" *       ");
				else
				{
					if (a[i] == 0)
						printf("         ");
					else if (a[i] % 100 == 1)
						printf(" A       ");
					else if (a[i] % 100 == 11)
						printf(" J       ");
					else if (a[i] % 100 == 12)
						printf(" Q       ");
					else if (a[i] % 100 == 13)
						printf(" K       ");
					else
						printf("%2d       ", a[i] % 100);
				}
				i += 80;
				if (i > 799)
				{
					i -= 799;
					printf("\n");
					break;
				}
			}
		}
		for (p = 0, c = 0;;)
		{
			if (b[c] != 0)
			{
				p++;
				c += 10;
			}
			else
				break;
			if (c == 50)
				break;
		}
		printf("                                                                                                                                                                      剩余发牌次数：%d\n", p);
		printf("                                                                                                                                                                      已整理牌副数：%d\n", y);
		printf("                                                                                                                                                                      未整理牌副数：%d\n", 8 - y);
		for (f = 0;;)
		{
			for (i = 0; i <= 799; i += 80)
				if (a[i] == 0)
				{
					k = 1;
					break;
				}
			if (k == 0)
			{
				for (i = 0; i <= 799; i += 80)
				{
					c = i;
					i0 = int(i / 80);
					for (max1 = 0; i <= i0 * 80 + 79; i++)
					{
						if (a[i] == 0)
						{
							max1 = i - 1;
							break;
						}
					}
					for (i1 = 0; i1 <= 799; i1 += 80)
					{
						c1 = i1;
						i2 = int(i1 / 80);
						if (i1 / 80 == c / 80)
							continue;
						for (; i1 <= i2 * 80 + 79; i1++)
						{
							if (a[max1] == a[i1] + 1)
							{
								k = 1;
								for (; a[i1 + 1] != 0; i1++)
								{
									if (a[i1] != a[i1 + 1] + 1)
									{
										k = 0;
										break;
									}
								}
								if (k == 0)
									continue;
							}
							if (k == 1)
								break;
						}
						if (k == 1)
							break;
						i1 = c1;
					}
					if (k == 1)
						break;
					i = c;
				}
			}
			if (k == 0 && p != 0)
			{
				printf("检测到无可移动的牌\n");
				printf("按下回车键发牌\n");
				ch = getchar();
				f1 = 1;
				break;
			}
			if (k == 0 && p == 0)
			{
				gg = 1;
				break;
			}
			if (p == 0)
				printf("已无牌可发，第一步跳过\n");
			else
			{
				printf("第一步：\n");
				for (;;)
				{
					printf("是否发牌：1.是      2.否\n");
					scanf_s("%d", &f1);
					printf("\n");
					if (f1 != 1 && f1 != 2)
					{
						printf("输入无效！重新输入：\n");
						continue;
					}
					break;
				}
			}
			if (f1 == 1)
				break;
			for (;;)
			{
				if (s == 1)
				{
					printf("\n无效输入！\n");
					s = 0;
					for (;;)
					{
						printf("是否返回第一步：\n1.是      2.否\n");
						scanf_s("%1d", &f);
						printf("\n");
						if (f != 1 && f != 2)
						{
							printf("无效输入！\n");
							continue;
						}
						else
							break;
					}
					if (f == 1)
						break;
				}
				printf("第二步：\n");
				if (f == 2)
					printf("重新");
				printf("输入被移动牌的列数：");
				scanf_s("%d", &d1);
				printf("\n");
				if (d1 <= 10 && d1 >= 1 && a[(d1 - 1) * 80] != 0)
					break;
				else
				{
					s = 1;
					continue;
				}
			}
			if (f == 1)
			{
				f = 0;
				continue;
			}
			for (;;)
			{
				if (s == 1)
				{
					printf("\n无效输入！\n");
					s = 0;
					for (;;)
					{
						printf("是否返回第一步：\n1.是      2.否\n");
						scanf_s("%1d", &f);
						printf("\n");
						if (f != 1 && f != 2)
						{
							printf("无效输入！\n");
							continue;
						}
						else
							break;
					}
					if (f == 1)
						break;
				}
				printf("第三步：\n");
				if (f == 2)
					printf("重新");
				printf("输入被移动牌截止行数：");
				scanf_s("%d", &z);
				printf("\n");
				z += (d1 - 1) * 80;
				z1 = z;
				for (max1 = (d1 - 1) * 80; a[max1] != 0 && max1 <= 799; max1++);
				if (z > max1 || z <= 0)
				{
					s = 1;
					continue;
				}
				for (; z < max1; z++)
				{
					if (a[z - 1] != a[z] + 1)
						s = 1;
				}
				if (s == 1)
					continue;
				break;
			}
			if (f == 1)
			{
				f = 0;
				continue;
			}
			for (;;)
			{
				if (s == 1)
				{
					printf("\n无效输入！\n");
					s = 0;
					for (;;)
					{
						printf("是否返回第一步：\n1.是      2.否\n");
						scanf_s("%1d", &f);
						printf("\n");
						if (f != 1 && f != 2)
						{
							printf("无效输入！\n");
							continue;
						}
						else
							break;
					}
					if (f == 1)
						break;
					else
						printf("重新");
				}
				printf("第四步：\n");
				if (f == 2)
					printf("重新");
				printf("输入移动去到的列数：");
				scanf_s("%d", &d2);
				printf("\n");
				if (d2 <= 0 || d2 >= 11 || d2 == d1)
				{
					s = 1;
					continue;
				}
				for (max1 = (d2 - 1) * 80; a[max1] != 0 && max1 <= 799; max1++);
				if (a[(d2 - 1) * 80] == 0)
					break;
				if (a[z1 - 1] != a[max1 - 1] - 1)
				{
					s = 1;
					continue;
				}
				else
					break;
			}
			if (f == 1)
			{
				f = 0;
				continue;
			}
			for (;a[z1 - 1] != 0 && z1 <= 800; z1++, max1++)
			{
				a[max1] = a[z1 - 1];
				a[z1 - 1] = 0;
			}
			for (i = 0; i <= 799; i += 80)
			{
				c = i;
				i0 = i / 80;
				for (; i <= i0 * 80 + 79 && a[i] != 0; i++)
				{
					if (a[i] == 113)
					{
						for (; a[i] > 100 && a[i] == a[i + 1] + 1 && i + 1 <= i0 * 80 + 79; i++)
						{
							if (a[i + 1] == 101)
							{
								y0 = 1;
								break;
							}
						}
					}
					if (y0 == 1)
						break;
				}
				if (y0 == 1)
					break;
				i = c;
			}
			if (y0 == 1)
			{
				for (i -= 11; y0 <= 13; i++, y0++)
				{
					a[i] = 0;
				}
				y0 = 0;
				y++;
			}
			break;
		}
		if (y == 8)
			break;
		if (gg == 1)
			break;
		if (f1 == 1)
			continue;
	}
	if (y == 8)
		printf("恭喜你赢了！！！");
	if (gg == 1)
		printf("很遗憾，你输了。");
	return 0;
}