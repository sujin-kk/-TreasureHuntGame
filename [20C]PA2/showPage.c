#include "head.h"

char* backspace = "<Press backspace to go back>";


int loadPage(void) {
	RemoveCursor();
	char selection; //���� ���������� ����� �Է�
	int isMainPageOn = 0, isLevelPageOn = 0, isGameGuideOn = 0, isStoryPageOn = 0, level = 0; //���� ����������, ��������������, ���ӹ���������� ȭ�鿡 ��Ÿ������ �ǹ��ϴ� ������/���� �ʱ޸��, �߱޸��, ��޸�尡 ����Ǿ����� �ǹ��ϴ� ������
	showMain();
	isMainPageOn = 1;
	do {
		if (_kbhit() == 1) { //Ű���� �Է� ����

			selection = _getch();

			if (selection == 27) { //esc
				break;
			}
			else if (isMainPageOn) {
				if (selection == '1') { //���� ���� ��ư�� ���� ���
					isMainPageOn = 0;
					isLevelPageOn = 1;
					system("cls");
					showLevelPage();
				}
				else if (selection == '2') { //���� ��� ��ư�� ���� ���
					isMainPageOn = 0;
					isGameGuideOn = 1;
					system("cls");
					showGameGuide();
				}
			
				else if (selection == '3') { //�ó�ý� ��ư�� ���� ���
					isMainPageOn = 0;
					isStoryPageOn = 1;
					system("cls");
					printOpening();
				}
				else if (selection == '4') { //���� Ű�� ���� ���
					level = 0; //���� ����
					break;
				}
			}
			else if (isLevelPageOn) {
				/*
				selection �Է°�:
				'1' => �ʱ�
				'2' => �߱�
				'3' => ���
				 8  => �齺���̽��� �ƽ�Ű �ڵ�
				 */
				if (selection == '1') {
					isLevelPageOn = 0;
					level = 1; //�ʱ�
					system("cls");
					break;
				}
				else if (selection == '2') {
					isLevelPageOn = 0;
					level = 2; //�߱�
					system("cls");
					break;
				}
				else if (selection == '3') {
					isLevelPageOn = 0;
					level = 3; //���
					system("cls");
					break;
				}
				else if (selection == 8) { //�齺���̽�
					isLevelPageOn = 0;
					isMainPageOn = 1;
					system("cls");
					showMain();
				}
			}
			else if (isGameGuideOn) {
				if (selection == 8) { 
					isGameGuideOn = 0;
					isMainPageOn = 1;
					system("cls");
					showMain();
				}
			}
			else if (isStoryPageOn) {
				if (selection == 8) { 
					isStoryPageOn = 0;
					isMainPageOn = 1;
					system("cls");
					showMain();
				}
			}
		}
	} while (1);

	system("cls");

	return level;
}

void showBorder() {
	int i; //���������� â 40*20
	gotoxy(20, 2);
	printf("��");
	for (i = 1; i < INTERF_WIDTH/2; i++) {
		printf("��");
	}
	printf("��");

	for (i = 1; i < INTERF_HEIGHT; i++) {
		gotoxy(20, 2 + i); printf("��");
	}
	gotoxy(20, 2 + INTERF_HEIGHT);
	printf("��");

	for (i = 1; i < INTERF_WIDTH/2; i++) {
		printf("��");
	}
	printf("��");

	gotoxy(20 + INTERF_WIDTH, 2);
	for (i = 1; i < INTERF_HEIGHT; i++) {
		gotoxy(20 + INTERF_WIDTH, 2 + i); printf("��");
	}

}

void showMain() {
	showBorder();

	gotoxy(30, 7);
	printf("��-------------------��");
	gotoxy(30, 9);
	printf("��-------------------��");

	gotoxy(35, 8);
	Sleep(100);
	printf("T");
	Sleep(100);
	printf("I");
	Sleep(100);
	printf("M");
	Sleep(100);
	printf("E ");

	Sleep(100);
	printf("I");
	Sleep(100);
	printf("S ");

	Sleep(100);
	printf("G");
	Sleep(100);
	printf("O");
	Sleep(100);
	printf("L");
	Sleep(100);
	printf("D");
	

	int textPositionY = MID_Y;//�ؽ�Ʈ�� y��ǥ
	char* textMainPage[5] = { "1. Game start","2. How to play", "3. Synopsys", "4. Exit", "<Press number on keyboard>" };

	Sleep(300);
	textPositionY -= 1;
	showString(textMainPage[0], textPositionY);

	Sleep(300);
	textPositionY += 2;
	showString(textMainPage[1], textPositionY);

	Sleep(300);
	textPositionY += 2;
	showString(textMainPage[2], textPositionY);

	Sleep(300);
	textPositionY += 2;
	showString(textMainPage[3], textPositionY);

	Sleep(300);
	textPositionY += 3;
	showString(textMainPage[4], textPositionY);
}


void showGameGuide() { 

	showBorder();

	char* guideLines[3] = { "�� ��,��,��,�� : Move",
				"�� SPACE BAR : Open flag",
				"�� Esc : Quit" }; //���� ��� ���ڿ�
	char textPositionY = MID_Y; //���ڿ� Y��ǥ
	int count; //���κ� ���ڿ� ��� ����

	textPositionY -= 2;
	for (count = 0; count < 3; count++) {
		showString(guideLines[count], textPositionY);
		textPositionY += 1;
	}
	textPositionY += 6;
	showString(backspace, textPositionY);
}


void showLevelPage(void) { //�������������� �ε�

	showBorder();

	int textPositionY = MID_Y; //���ڿ� Y��ǥ
	char* textLevelPage[] = { "Choose a level", "1. Beginner", "2. Intermediate", "3. Advanced" };

	textPositionY -= 2;
	showString(textLevelPage[0], textPositionY);

	textPositionY += 2;
	showString(textLevelPage[1], textPositionY);

	textPositionY += 2;
	showString(textLevelPage[2], textPositionY);

	textPositionY += 2;
	showString(textLevelPage[3], textPositionY);

	textPositionY += 2;
	showString(backspace, textPositionY);
}

void showClear() {
	showBorder();
	gotoxy(MID_X-4, MID_Y);
	printf("Clear!");
	gotoxy(MID_X - 15, MID_Y+1);
	system("pause");
}

void showLoading() {
	showBorder();
	gotoxy(MID_X-4, MID_Y);
	printf("Loading . . .");
}
void showFail() {
	showBorder();
	gotoxy(MID_X-4, MID_Y-1);
	printf("Fail . . .");
}

void showReturnMain() {
	showBorder();
	gotoxy(MID_X - 9, MID_Y - 1);
	printf("Back to main . . .");
}

void askReplay() {
	showBorder();
	gotoxy(MID_X-10, MID_Y +2);
	printf("If you want to replay");
	gotoxy(MID_X - 7, MID_Y + 3);
	printf("Please press 'y'");
}

void printOpening() {
	showBorder();
	char* startScenario[] = { "\"����� �ϱ�Ȱ��!\"",
				"\"�׳� ���ͽ��ϴ�!\"",
				"������ ����� ���� ����(22,��)",
				"����� �޻꿡 ��û�� ����",
				"Ȳ���� �����ִٴ� �ҹ��� �������..",
				"��ȹõ���� ���ΰ��� �Ǳ�����",
				"���ڴ� ������ ����.",
				"���ڴ� ���� �̷�� ������?"
	};
	
	gotoxy(MID_X - 8, MID_Y -6);
	printf("%s", startScenario[0]);
	Sleep(1000);
	gotoxy(MID_X - 8, MID_Y - 5);
	printf("%s", startScenario[1]);
	Sleep(1000);


	gotoxy(MID_X - 13, MID_Y - 3);
	printf("%s", startScenario[2]);
	Sleep(1000);
	gotoxy(MID_X - 10, MID_Y - 2);
	printf("%s", startScenario[3]);
	Sleep(1000);
	gotoxy(MID_X - 16, MID_Y - 1);
	printf("%s", startScenario[4]);
	Sleep(1000);

	gotoxy(MID_X -13, MID_Y +1);
	printf("%s", startScenario[5]);
	Sleep(1000);
	gotoxy(MID_X - 8, MID_Y + 2);
	printf("%s", startScenario[6]);
	Sleep(1000);

	gotoxy(MID_X - 11, MID_Y + 4);
	printf("%s", startScenario[7]);
	Sleep(1000);

	gotoxy(MID_X - 13, MID_Y + 6);
	printf("%s", backspace);
	
}

void printEnding() {
	char* endScenario[] = { "���ڴ� ��ħ�� ������ ã�Ƴ´�.",
				"������ Ȳ������ ������������",
				"���ݲ� ���� �Ⱥ��϶��� �־���",
				"���δ� ���� �������� ���������߾���.",
				"�ð��� ��� ���ƴ� ���� �͵��� ���ø���",
				"��μ� ���ڴ� �ð��� ���̶�� ����� �ȴ�.",
				"�츮�� �󸶳� ���� ���� ��������?",
				"���� �� ���ڴ� �ƴϿ�����?"
	};

	for (int i = 0; i < sizeof(endScenario) / sizeof(endScenario[0]); i++) {
		gotoxy(STA_X + 44, STA_Y+(i*2));
		printf("%s", endScenario[i]);
		Sleep(1500);
	}

}

void showEnding() {
	int i = 1;
	printEnding();
	while (1) {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		showBorder();

		gotoxy(STA_X + 2, STA_Y + 12);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GOLD);
		printf("$$$$$$$$$$$$$$$$$");
		gotoxy(STA_X + 19, STA_Y + 11);
		printf("$");
		gotoxy(STA_X + 20, STA_Y + 10);
		printf("$");
		gotoxy(STA_X + 21, STA_Y + 9);
		printf("$");
		gotoxy(STA_X + 22, STA_Y + 8);
		printf("$");
		gotoxy(STA_X + 23, STA_Y + 8);
		printf("$");
		gotoxy(STA_X + 24, STA_Y + 9);
		printf("$");
		gotoxy(STA_X + 25, STA_Y + 10);
		printf("$");
		gotoxy(STA_X + 26, STA_Y + 11);
		printf("$");
		gotoxy(STA_X + 27, STA_Y + 12);
		printf("$");
		gotoxy(STA_X + 28, STA_Y + 12);
		printf("$$$$$$$$$$$$");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		gotoxy(STA_X + 2, STA_Y + 11);
		printf("��"); //����

		Sleep(100);
		gotoxy(STA_X + 2, STA_Y + 11);
		printf("  ");
		gotoxy(STA_X + 6, STA_Y + 11);
		printf("��");

		Sleep(100);
		gotoxy(STA_X + 6, STA_Y + 11);
		printf("  ");
		gotoxy(STA_X + 10, STA_Y + 11);
		printf("��");

		Sleep(100);
		gotoxy(STA_X + 10, STA_Y + 11);
		printf("  ");
		gotoxy(STA_X + 13, STA_Y + 11);
		printf("��");

		Sleep(100);
		gotoxy(STA_X + 13, STA_Y + 11);
		printf("  ");
		gotoxy(STA_X + 15, STA_Y + 11);
		printf("��");

		Sleep(100);
		gotoxy(STA_X + 15, STA_Y + 11);
		printf("  ");
		gotoxy(STA_X + 17, STA_Y + 9);
		printf("��");

		Sleep(100);
		gotoxy(STA_X + 17, STA_Y + 9);
		printf("  ");
		gotoxy(STA_X + 18, STA_Y + 8);
		printf("��");


		Sleep(100);
		gotoxy(STA_X + 18, STA_Y + 8);
		printf("  ");
		gotoxy(STA_X + 19, STA_Y + 7);
		printf("��");


		Sleep(100);
		gotoxy(STA_X + 19, STA_Y + 7);
		printf("  ");
		gotoxy(STA_X + 19, STA_Y + 6);
		printf("��");

		Sleep(100);
		gotoxy(STA_X + 19, STA_Y + 6);
		printf("  ");
		gotoxy(STA_X + 19, STA_Y + 7);
		printf("��");

		gotoxy(STA_X + 19, STA_Y + 7);
		printf("  ");

		Sleep(100);
		if (i > 15)
			i = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		i++;
		gotoxy(STA_X + 14, STA_Y + 5);
		printf("TIme is gold !");
		
	}
}


void showString(char string[], int positionY) { //�������� ���� ���ڿ��� ���η� ����� ���� ���
	int strMiddle = strlen(string) / 2;
	int positionX = MID_X - strMiddle;
	gotoxy(positionX, positionY);
	puts(string);
}
