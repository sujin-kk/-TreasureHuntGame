#include "head.h"

int map[HEIGHT][WIDTH]; //����

int playGame(int level) {
	RemoveCursor();
	int item; //item 1.�ð�2������ 2.�ð�2�ʰ��� 3.�����ƴ��÷��׿��� 4.2�ʵ��� ����Ű �ݴ�� //5 �Ⱥ��̱�

	//�� ���� 
	int map[HEIGHT][WIDTH]; //20*20 �������迭
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			map[i][j] = 0;
		}
	} //��� 0���� �ʱ�ȭ

	//�÷���, ���� ����
	int num = 0, flag = 0, time_limit = 0, isTre = 0;
	if (level == 1) {
		flag = 5;
		time_limit = 15;
	}
	else if (level == 2) {
		flag = 9;
		time_limit = 10;
	}
	else if (level == 3) {
		flag = 13;
		time_limit = 6;
	}

	while (num != flag) {
		int n = 0;
		int tx = rand() % WIDTH;
		int ty = rand() % HEIGHT;
		if (map[tx][ty] == 0) {
			map[tx][ty] = 1; // �÷��� ����
			if (!isTre) {
				map[tx][ty] = 3; // ���� ����, ������ �׻� 1��
				isTre = 1;
			}
			num++;
		}
	}

	system("cls");
	showInterf();
	int mx = STA_X + 1; //21
	int my = STA_Y + 1; //3
	gotoxy(mx, my);
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			gotoxy(mx + 2 * j, my + i);
			if (map[i][j] == 0) {
				printf("  "); //�̿���
			}
			else if (map[i][j] == 1) {
				printf("��"); //�÷���
			}
			else if (map[i][j] == 2) {
				printf("��"); //�÷��� ����
			}
			else {
				printf("��"); //����
			}
		}
		printf("\n");
	}


	int x = 21, y = 22; //Ŀ�� ����
	int sec = time_limit * 100;

	//100sec -> 1��
	//10sec -> 0.1��
	while (1) {
		gotoxy(74, 2);
		printf("%d", level); //level ���

		Sleep(10); // 0.1�ʽ���
		if (sec % 100 == 0) { //2000, 1900, 1800,,,
			if (sec / 100 < 0) { // 0�� ��, fail
				system("cls");
				return 0;
			}
			gotoxy(74, 4);
			printf("%02d", sec / 100);
		}
		sec--; //time ���

		gotoxy(x, y);
		printf("��"); //Ŀ��
		if (_kbhit()) { //Ű�Է°���
			int key = _getch(); // key Ű���� ��
			int space = 0;

			switch (key) {
			case LEFT:
				if (x > 21)x -= 2;
				break;
			case RIGHT:
				if (x < 59)x += 2;
				break;
			case UP:
				if (y > 3)y--;
				break;
			case DOWN:
				if (y < 22)y++;
				break;
			case SPACE:
				space = 1;
				break;
			}

			if (x < 21)x = 21;
			else if (x > 59)x = 59;
			if (y < 3)y = 3;
			else if (y > 22)y = 22;

			printf("\b\b  ");
			gotoxy(x, y);
			printf("��");

			if (space == 1) //�����ϸ�
			{
				if (map[y - 3][(x - 21) / 2] == 1) { //�Ϲ� �÷��� �����ϸ�
					item = rand() % 6; // 0 1 2 3 4 5 

					map[y - 3][(x - 21) / 2] = 2; //�÷��� ����
					system("cls");

					if (item == 1) { //�ð� 4���߰�
						gotoxy(74, 8);
						printf("+ 4�� ����");
						sec += 400;
					}

					else if (item == 2) { //�ð� 2�ʰ���
						gotoxy(74, 8);
						printf("- 2�� ����");
						sec -= 200;
					}

					else if (item == 3) { //���� �ƴ� �÷��� ����
						int isOpen = 0;
						gotoxy(74, 8);
						printf("�ٸ� �÷��� ����");

						for (int i = 0; i < HEIGHT; i++) {
							for (int j = 0; j < WIDTH; j++) {
								if (!isOpen) {
									if (map[j][i] == 1) {
										map[j][i] = 2;
										isOpen = 1;
									}
								}
							}
						}

						showInterf();
						gotoxy(mx, my);
						for (int i = 0; i < HEIGHT; i++) {
							for (int j = 0; j < WIDTH; j++) {
								gotoxy(mx + 2 * j, my + i);
								if (map[i][j] == 0) {
									printf("  "); //�̿���
								}
								else if (map[i][j] == 1) {
									printf("��"); //�÷���
								}
								else if (map[i][j] == 2) {
									printf("��"); //�÷��� ����
								}
								else {
									printf("��"); //����
								}
							}
							printf("\n");
						}

					}

					else if (item == 4) { //����Ű �ݴ��
						clock_t t1, t2;
						t1 = clock();
						gotoxy(74, 8);
						printf("2�ʵ��� ����Ű �ݴ�(�¡��&�����)");

						do {
							gotoxy(x, y);
							printf("��"); //Ŀ��
							if (_kbhit()) { //Ű�Է°���
								int key = _getch(); // key Ű���� ��
								int space = 0;

								switch (key) {
								case LEFT:
									if (x > 20)x += 2;
									break;
								case RIGHT:
									if (x < 60)x -= 2;
									break;
								case UP:
									if (y > 2)y++;
									break;
								case DOWN:
									if (y < 23)y--;
									break;
								case SPACE:
									space = 1;
									break;
								}

								if (x < 21)x = 21;
								else if (x > 59)x = 59;
								if (y < 3)y = 3;
								else if (y > 22)y = 22;

								printf("\b\b  ");
								gotoxy(x, y);
								printf("��");
							}
							showInterf();
							gotoxy(mx, my);
							for (int i = 0; i < HEIGHT; i++) {
								for (int j = 0; j < WIDTH; j++) {
									gotoxy(mx + 2 * j, my + i);
									if (map[i][j] == 0) {
										printf("  "); //�̿���
									}
									else if (map[i][j] == 1) {
										printf("��"); //�÷���
									}
									else if (map[i][j] == 2) {
										printf("��"); //�÷��� ����
									}
									else {
										printf("��"); //����
									}
								}
								printf("\n");
							}
							t2 = clock();
						} while ((t2 - t1) < (2 * CLOCKS_PER_SEC)); //2�ʵ���

					}

					else if (item == 5) { //�� ���� �Ⱥ��̰� ��
						clock_t t1, t2;
						gotoxy(74, 8);
						printf("2�ʵ��� ���� ����");
						t1 = clock();
						do {
							gotoxy(74, 2);
							printf("%d", level); //level ���

							gotoxy(x, y);
							printf("��"); //Ŀ��
							if (_kbhit()) { //Ű�Է°���
								int key = _getch(); // key Ű���� ��
								int space = 0;

								switch (key) {
								case LEFT:
									if (x > 21)x -= 2;
									break;
								case RIGHT:
									if (x < 59)x += 2;
									break;
								case UP:
									if (y > 3)y--;
									break;
								case DOWN:
									if (y < 22)y++;
									break;
								case SPACE:
									space = 1;
									break;
								}

								if (x < 21)x = 21;
								else if (x > 59)x = 59;
								if (y < 3)y = 3;
								else if (y > 22)y = 22;

								printf("\b\b  ");
								gotoxy(x, y);
								printf("��");
							}
							showInterf();
							gotoxy(mx, my);
							for (int i = 0; i < HEIGHT; i++) {
								for (int j = 0; j < WIDTH; j++) {
									gotoxy(mx + 2 * j, my + i);
									if (map[i][j] == 0) {
										printf("  ");
									}
									else if (map[i][j] == 1) {
										printf("  ");
									}
									else if (map[i][j] == 2) {
										printf("  ");
									}
									else {
										printf("  ");
									}
								}
								printf("\n");
							}
							t2 = clock();
						} while ((t2 - t1) < (2 * CLOCKS_PER_SEC));
					}

					else { // item�ߵ�X
						gotoxy(74, 8);
						printf("�� ������");
					}

					showInterf();
					gotoxy(mx, my);
					for (int i = 0; i < HEIGHT; i++) {
						for (int j = 0; j < WIDTH; j++) {
							gotoxy(mx + 2 * j, my + i);
							if (map[i][j] == 0) {
								printf("  "); //�̿���
							}
							else if (map[i][j] == 1) {
								printf("��"); //�÷���
							}
							else if (map[i][j] == 2) {
								printf("��"); //�÷��� ����
							}
							else {
								printf("��"); //����
							}
						}
						printf("\n");
					}
				} //�÷��� ���� ��

				else if (map[y - 3][(x - 21) / 2] == 3) { //��������
					system("cls");
					showInterf();
					int mx = STA_X + 1; //21
					int my = STA_Y + 1; //3
					gotoxy(mx, my);
					for (int i = 0; i < HEIGHT; i++) {
						for (int j = 0; j < WIDTH; j++) {
							gotoxy(mx + 2 * j, my + i);
							if (map[i][j] == 0) {
								printf("  "); //�̿���
							}
							else if (map[i][j] == 1) {
								printf("��"); //�÷���
							}
							else if (map[i][j] == 2) {
								printf("��"); //�÷��� ����
							}
							else {
								printf("��"); //����
							}
						}
						printf("\n");
					}
					gotoxy(74, 8);
					printf("���� �߰�!\n");
					gotoxy(74, 9);
					system("pause");

					return 1;
				} //�������� ��

				else { //���� �����ϸ�
					system("cls");
					showInterf();
					gotoxy(mx, my);
					for (int i = 0; i < HEIGHT; i++) {
						for (int j = 0; j < WIDTH; j++) {
							gotoxy(mx + 2 * j, my + i);
							if (map[i][j] == 0) {
								printf("  "); //�̿���
							}
							else if (map[i][j] == 1) {
								printf("��"); //�÷���
							}
							else if (map[i][j] == 2) {
								printf("��"); //�÷��� ����
							}
							else {
								printf("��"); //����
							}
						}
						printf("\n");
					}
				}

			}
		}
	} //while ��
} //play�Լ� ��