#include "main.h"

int i = 1;
int iCnt2 = 1;
static int iCount = 1; //��ǰ�� �ִ��� ������ �˾� ���� ����
int iCa = 1;

int main()
{
	Start();
	menu();
	return 0;
}

void menu()
{
	char iState;
	while (1)
	{
		printf("\t  ����������������������������������������������������������������������������������������������������\n");
		printf("\t  ��						   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��						   ��\n");
		printf("\t  ����������������������������������������������������������������������������������������������������\n");
		printf("\t  ��						   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��	����	1.���				   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��	����	2.����				   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��	����	3.����				   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��	����	4.��ٱ���			   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��	����	5.���				   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��	����	6.�˻�				   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��	����	7.����				   ��\n");
		printf("\t  ��	����					   ��\n");
		printf("\t  ��						   ��\n");
		printf("\t  ����������������������������������������������������������������������������������������������������\n");

		iState = getch();
		fflush(stdin);
		if (iState == '1')
		{
			system("cls");

			Input(&Temp);
			Head = insert(&Temp, Head, 1, 1);
		}
		else if (iState == '2')
		{
			system("cls");
			print_list1(Head, 0);
			putchar('\n');
			putchar('\n');
			deletelist();
			print_list1(Head, 1);
		}
		else if (iState == '3')
		{
			system("cls");
			save_food(Head);
			fflush(stdout);
			Head = 0;
		}
		else if (iState == '4')
		{
			system("cls");
			print_list1(Head, 1);
			fflush(stdout);
		}
		else if (iState == '5')
		{
			system("cls");
			print_list2(Head, 1);
			fflush(stdout);
		}
		else if (iState == '6')
		{
			system("cls");
			food_in();
			fflush(stdout);
		}
		else if (iState == '7')
		{
			//�����뷮 ��� & ����� ���
			int used, base, tot;
			double plus, tax;
			printf("��ǰ���� �Է��ϼ��� : ");
			scanf("%d", &used);
			int uph;
			uph = used / 100;
			switch (uph)
			{
			case 0: base = 370; break;
			case 1: base = 660; break;
			case 2: base = 1130; break;
			case 3: base = 2710; break;
			case 4: base = 5130; break;
			case 5: base = 9330; break;
			case 6: printf("���빰�� 60���θ� �ѱ⶧���� ȿ������ ������� ������� ���մϴ�.\n����� ������ �ּ���. "); exit(0);
			}
			printf("base : %d\n", base);
			if (used <= 100)
			{
				plus = used * 52.0;
			}
			else if (used <= 200)
			{
				plus = (100 * 52.0) + ((used % 100)*88.5);
			}
			else if (used <= 300)
			{
				plus = (100 * 52.0) + (100 * 88.5) + ((used % 200)*127.8);
			}
			else if (used <= 400)
			{
				plus = (100 * 52.0) + (100 * 88.5) + (100 * 127.8) + ((used % 300)*184.3);
			}
			else if (used <= 500)
			{
				plus = (100 * 52.0) + (100 * 88.5) + (100 * 127.8) + (100 * 184.3) + ((used % 400)*274.3);
			}
			else
			{
				plus = (100 * 52.0) + (100 * 88.5) + (100 * 127.8) + (100 * 184.3) + (100 * 274.3) + ((used % 500)*494.0);
			}
			printf("�߰���� : %lf\n", plus);
			tax = (base + plus)*0.09;
			printf("���� : %lf\n", tax);
			tot = base + (int)plus + (int)tax;
			printf("���� �ݾ� %d\n", tot);
			exit(0);
			break;
		}
	}
}

void food_in()
{
	char bState;
	printf("\n\n\n                1.  ��ǰ ���� ����                \n\n");
	printf("                2.  ��ǰ ���� �˻�                \n\n");
	printf("                3.  �������� ���ư���             \n\n\n\n");

	bState = getch();
	fflush(stdin);
	if (bState == '1')
	{
		system("cls");
		foodSort();
	}
	else if (bState == '2')
	{
		system("cls");
		foodSerch();
	}
	else if (bState == '3')
	{
		menu();
		system("cls");
	}
}

void foodSerch()
{
	char sState;
	printf("\n\n\n                      1.  ��ǰ������ �˻�     \n\n");
	printf("                      2.  �����̸����� �˻�     \n\n");
	printf("                      3.  ���峯¥�� �˻�   \n\n");
	printf("                      4.  ����������� �˻�     \n\n");
	printf("                      5.  ������ �˻�     \n\n");
	printf("                      6.  ����/�˻� �޴���  ���ư���   \n\n");

	sState = getch();
	fflush(stdin);
	if (sState == '1')
	{
		system("cls");
		find(1);
	}
	else if (sState == '2')
	{
		system("cls");
		find(2);
	}
	else if (sState == '3')
	{
		system("cls");
		find(3);
	}
	else if (sState == '4')
	{
		system("cls");
		find(4);
	}
	else if (sState == '5')
	{
		system("cls");
		find(5);
	}
	else if (sState == '6')
	{
		system("cls");
		food_in();
	}
}

void foodlist()
{
	printf("����������������������������������������\n");
	printf("                         <    �� ǰ �� �� Ʈ    >                           \n");
	printf("����������������������������������������\n\n");
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf(" ����\t��ǰ��\t\t����\t\t���峯¥\t�������\t����\n");
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������\n\n");
}

void find(int kind)
{
	FILE *fp;
	food info;
	food *Head = 0;
	char f_name[20];
	char man[20];
	char put[20];
	char day[20];
	int num = 0;
	char chf_name[20];
	char chman[20];
	char chput[20];
	char chDay[20];
	int chnum;
	int Andex = 0;
	int i = 1;
	char choice;
	char ch;

	if ((fp = fopen("food.txt", "r")) == NULL)
	{
		printf("��ǰ�� �����ϴ�.\n");
		getchar();
		fflush(stdin);
	}

	if (kind == 1)
	{
		printf("\n\n\n->  �˻��� ��ǰ���� �Է��ϼ���\n ");
		scanf("%s", f_name);
		fflush(stdin);
	}
	else if (kind == 2)
	{
		printf("\n\n\n->  �˻��� ���� �̸��� �Է��ϼ��� \n ");
		scanf("%s", man);
		fflush(stdin);
	}
	else if (kind == 3)
	{
		printf("\n\n\n->  �˻��� ���峯¥�� �Է��ϼ��� (��:2019.09.10)\n");
		scanf("%s", put);
		fflush(stdin);
	}
	else if (kind == 4)
	{
		printf("\n\n\n->  �˻��� ��������� �Է��ϼ��� (��:2020.09.10) \n");
		scanf("%s", day);
		fflush(stdin);
	}
	else if (kind == 5)
	{
		printf("\n\n\n->  �˻��� ������ �Է��ϼ��� (1�̻� 5���ϸ� 1 �Է�) \n ");
		scanf("%d", &num);
		fflush(stdin);
	}

	foodlist();
	while ((fscanf(fp, "%d %c %c %s %c %s %s %s %c %d %c\n", &info.index, &ch, &ch, info.szF_name, &ch, info.szman, info.szput, info.szDay, &ch, &info.inum, &ch)) != EOF)
	{
		if (kind == 1)
		{
			if (strcmp(info.szF_name, f_name) == 0)
			{
				printf(" [%d]\t", info.index);
				printf("%-15s", info.szF_name);
				printf("%-16s", info.szman);
				printf("%-16s", info.szput);
				printf("%-17s", info.szDay);
				printf("%-7d\n", info.inum);
				i++;
			}
		}
		else if (kind == 2)
		{
			if (strcmp(info.szman, man) == 0)
			{
				printf(" [%d]\t", info.index);
				printf("%-15s", info.szF_name);
				printf("%-16s", info.szman);
				printf("%-16s", info.szput);
				printf("%-17s", info.szDay);
				printf("%-7d\n", info.inum);
				i++;
			}
		}
		else if (kind == 3)
		{
			if (strcmp(info.szput, put) == 0)
			{
				printf(" [%d]\t", info.index);
				printf("%-15s", info.szF_name);
				printf("%-16s", info.szman);
				printf("%-16s", info.szput);
				printf("%-17s", info.szDay);
				printf("%-7d\n", info.inum);
				i++;
			}
		}
		else if (kind == 4)
		{
			if (strcmp(info.szDay, day) == 0)
			{
				printf(" [%d]\t", info.index);
				printf("%-15s", info.szF_name);
				printf("%-16s", info.szman);
				printf("%-16s", info.szput);
				printf("%-17s", info.szDay);
				printf("%-7d\n", info.inum);
				i++;
			}
		}
		else if (kind == 5)
		{
			if (info.inum >= num && info.inum <= num + 5)
			{
				printf(" [%d]\t", info.index);
				printf("%-15s", info.szF_name);
				printf("%-16s", info.szman);
				printf("%-16s", info.szput);
				printf("%-17s", info.szDay);
				printf("%-7d\n", info.inum);
				i++;
			}
		}
	}
	fclose(fp);
	if (i == 1)
	{
		printf(" -> ã���ô� ��ǰ�� �����ϴ� \n\n\n");
		printf(" -> ��� �Ͻ÷��� �ƹ�Ű�� �Է��ϼ��� \n");
		getchar();
		fflush(stdin);
		system("cls");
		foodSerch();
	}
	printf("\n\n->  �����Ͻðڽ��ϱ� ? (Y / N) \n\n");
	choice = getch();
	fflush(stdin);
	if (choice == 'y')
	{
		while (1)
		{
			printf("�����Ͻ� ������ �Է��Ͽ� �ּ���.\n\n");
			scanf("%d", &Andex);
			fflush(stdin);
			if (Andex > info.index || Andex <= 0)
			{
				printf("->  �Է��Ͻ� ������ ���� �ʽ��ϴ�. \n");
				printf("->  �ٽ� ");
			}
			else break;
		}
		if ((fp = fopen("food.txt", "r")) == NULL)
		{
			printf("��ǰ�� �����ϴ�.\n");
			getchar();
			fflush(stdin);
		}

		printf("-> �����Ͻ� ��ǰ���� �Է����ּ���\n");
		scanf("%s", chf_name);
		fflush(stdin);
		printf("-> �����Ͻ� �����̸��� �Է����ּ���\n");
		scanf("%s", chman);
		fflush(stdin);
		printf("-> �����Ͻ� ���峯¥��  �Է����ּ���\n");
		scanf("%s", chput);
		fflush(stdin);
		printf("-> �����Ͻ� ��������� �Է����ּ���\n");
		scanf("%s", chDay);
		fflush(stdin);
		printf("-> �����Ͻ� ������ �Է����ּ���\n");
		scanf("%d", &chnum);
		fflush(stdin);

		while ((fscanf(fp, "%d %c %c %s %c %s %s %s %c %d %c\n", &info.index, &ch, &ch, info.szF_name, &ch, info.szman, info.szput, info.szDay, &ch, &info.inum, &ch)) != EOF)
		{
			if (info.index == Andex)
			{
				strcpy(info.szF_name, chf_name);
				strcpy(info.szman, chman);
				strcpy(info.szput, chput);
				strcpy(info.szDay, chDay);
				info.inum = chnum;
				Head = insert(&info, Head, 1, 1);
			}
			else Head = insert(&info, Head, 1, 1);
		}
		fclose(fp);
		savefood(Head, "food.txt");
		print_list2(Head, 2);
	}
	printf("\n\n  ����ϽǷ��� �ƹ�Ű�� �Է��ϼ��� \n\n\n");
	getchar();
	fflush(stdin);
	system("cls");
	foodSerch();
}

void foodSort()
{
	char bState;
	printf("\n\n\n                  1.  ��ǰ������ ����     \n\n");
	printf("                  2.  ���θ����� ����     \n\n");
	printf("                  3.  ���峯¥�� ����   \n\n");
	printf("                  4.  ����������� ����     \n\n");
	printf("                  5.  ������ ����     \n\n");
	printf("                  6.  ����� ��ǰ ����Ʈ ���  \n\n");
	printf("                  7.  ����/�˻� �޴���  ���ư���   \n\n");
	bState = getch();
	fflush(stdin);

	if (bState == '1')
	{
		system("cls");
		textSort(1);
	}
	else if (bState == '2')
	{
		system("cls");
		textSort(2);
	}
	else if (bState == '3')
	{
		system("cls");
		textSort(3);
	}
	else if (bState == '4')
	{
		system("cls");
		textSort(4);
	}
	else if (bState == '5')
	{
		system("cls");
		textSort(5);
	}
	else if (bState == '6')
	{
		system("cls");
		print_list2(Head, 1);
		system("cls");
		foodSort();
	}
	else if (bState == '7')
	{
		system("cls");
		food_in();
	}
}

void textSort(int kind)
{
	FILE *fp;
	food info;
	food *Head = 0;
	char iState;
	char Select;
	char f_name[20] = "food.txt";
	char ch;

	if ((fp = fopen("food.txt", "r")) == NULL)
	{
		printf("��ǰ�� �����ϴ�.\n");
		getchar();
		fflush(stdin);
	}

	printf("1. ��������\n2. ��������\n\n");
	iState = getch();
	fflush(stdin);

	while ((fscanf(fp, "%d %c %c %s %c %s %s %s %c %d %c\n", &info.index, &ch, &ch, info.szF_name, &ch, info.szman, info.szput, info.szDay, &ch, &info.inum, &ch)) != EOF)
	{

		if (kind == 1)
		{
			if (iState == '1') Head = insert(&info, Head, 1, 1);
			else if (iState == '2') Head = insert(&info, Head, 1, 2);
		}
		if (kind == 2)
		{
			if (iState == '1') Head = insert(&info, Head, 2, 1);
			else if (iState == '2') Head = insert(&info, Head, 2, 2);
		}
		if (kind == 3)
		{
			if (iState == '1') Head = insert(&info, Head, 3, 1);
			else if (iState == '2') Head = insert(&info, Head, 3, 2);
		}
		if (kind == 4)
		{
			if (iState == '1') Head = insert(&info, Head, 4, 1);
			else if (iState == '2') Head = insert(&info, Head, 4, 2);
		}
		if (kind == 5)
		{
			if (iState == '1') Head = insert(&info, Head, 5, 1);
			else if (iState == '2') Head = insert(&info, Head, 5, 2); 
		}
	}
	fclose(fp);
	print_list1(Head, 1);
	printf("->  ������ ��� ���� ���Ͽ� ���� (Y)     \n");
	printf("->  ������ ��� �ٸ� �̸����� ���� ���� (C)     \n");
	printf("->  CANCEL (N)     \n");

	Select = getch();
	if (Select == 'y') savefood(Head, f_name);
	else if (Select == 'c')
	{
		printf(" -> ���ϸ�� Ȯ���ڸ� �Է����ּ��� (��: food.txt) \n");
		scanf("%s", f_name);
		savefood(Head, f_name);
		printf("       ���� �Ǿ����ϴ�          \n\n\n");
		printf("-> ��� �Ͻ÷��� �ƹ�Ű�� �Է��ϼ��� \n");
		getchar();
		fflush(stdin);
	}
	system("cls");
	foodSort();
}

food *insert(food* item, food *list, int kind, int Sort)
{
	food *current = NULL, *follow = NULL, *new = NULL;
	current = follow = list;
	if ((new = (food *)malloc(sizeof(food))) == NULL || item == NULL)
	{
		printf("�Ҵ�� �޸𸮰� �����ϴ�.\n");
		return list;
	}
	*new = *item;
	while (1)
	{	//����list�� ó���̰ų� �������϶�
		if (current == NULL) break;
		if (kind == 1)
		{
			if (Sort == 1)
			{
				if (0 < strcmp(current->szF_name, item->szF_name)) break;// ������ ������ ���� ã�� ���  
			}
			else if (Sort == 2)
			{
				if (0 > strcmp(current->szF_name, item->szF_name)) break;
			}
		}
		else if (kind == 2)
		{
			if (Sort == 1)
			{
				if (0 < strcmp(current->szman, item->szman)) break;// ������ ������ ���� ã�� ���  
			}
			else if (Sort == 2)
			{
				if (0 > strcmp(current->szman, item->szman)) break;
			}
		}
		else if (kind == 3)
		{
			if (Sort == 1)
			{
				if (0 < strcmp(current->szput, item->szput)) break;// ������ ������ ���� ã�� ���  
			}
			else if (Sort == 2)
			{
				if (0 > strcmp(current->szput, item->szput)) break;
			}

		}
		else if (kind == 4)
		{
			if (Sort == 1)
			{
				if (0 < strcmp(current->szDay, item->szDay)) break;// ������ ������ ���� ã�� ���  
			}
			else if (Sort == 2)
			{
				if (0 > strcmp(current->szDay, item->szDay)) break;
			}

		}
		else if (kind == 5)
		{
			if (Sort == 1)
			{
				if (current->inum > item->inum) break;// ������ ������ ���� ã�� ���  
			}
			else if (Sort == 2)
			{
				if (current->inum < item->inum) break;
			}

		}
		follow = current;
		current = current->next;
	}
	new->next = current;
	if (current == list) list = new;
	else follow->next = new;
	return list;
}

void deletelist()
{
	char number[15];
	printf("������  ��ǰ����  �Է��ϼ���.\n");
	scanf("%s", &number);
	fflush(stdin);
	Head = deletef(number, Head);
}

void save_food(food *list)
{
	FILE *fp;
	count();
	if ((fp = fopen("food.txt", "a+")) == NULL)
	{
		printf("������ �����ϴ�.\n");
		exit(0);
	}

	while (0 != list)
	{
		fprintf(fp, " %d . ", iCnt2++);
		fprintf(fp, " ( %s ) ", list->szF_name);
		fprintf(fp, " %s ", list->szman);
		fprintf(fp, " %s ", list->szput);
		fprintf(fp, " %s ", list->szDay);
		fprintf(fp, " [ %d ] ", list->inum);
		fprintf(fp, "\n");
		list = list->next;
	}
	fclose(fp);
	printf("\n\n   ->   ����Ǿ����ϴ�. \n\n");
	printf("\n\n         ����ϽǷ��� �ƹ�Ű�� �Է��ϼ���.\n\n\n");
	getchar();
	fflush(stdin);
}

void savefood(food *list, char f_name[])
{
	FILE *fp;
	int i = 1;
	if ((fp = fopen(f_name, "w")) == NULL)
	{
		printf("������ �����ϴ�.\n");
		exit(0);
	}

	while (0 != list)
	{
		fprintf(fp, " %d . ", i);
		fprintf(fp, " ( %s ) ", list->szF_name);
		fprintf(fp, " %s ", list->szman);
		fprintf(fp, " %s ", list->szput);
		fprintf(fp, " %s ", list->szDay);
		fprintf(fp, " [ %d ] ", list->inum);
		fprintf(fp, "\n");
		list = list->next;
		i++;
	}
	fclose(fp);
}

void print_list1(food *list, int know)
{
	int i = 1;
	foodlist();
	while (0 != list)
	{

		printf(" [%d]\t", i);
		printf("%-15s", list->szF_name);
		printf("%-16s", list->szman);
		printf("%-16s", list->szput);
		printf("%-17s", list->szDay);
		printf("%-7d\n", list->inum);
		list = list->next;
		i++;
	}

	if (know == 1)
	{
		printf("\n\n         ����ϽǷ��� �ƹ�Ű�� �Է��ϼ���. \n\n\n");
		getchar();
	}
}

void print_list2(food *list, int know)
{
	int i = 1;
	FILE *fp;
	food info;
	char ch;
	foodlist();
	if ((fp = fopen("food.txt", "r")) == NULL)
	{
		printf("��ǰ�� �����ϴ�.\n");
		getchar();
		fflush(stdin);
	}
	else
	{
		while ((fscanf(fp, "%d %c %c %s %c %s %s %s %c %d %c\n", &info.index, &ch, &ch, info.szF_name, &ch, info.szman, info.szput, info.szDay, &ch, &info.inum, &ch)) != EOF)
		{
			printf(" [%d]\t", i);
			printf("%-15s", info.szF_name);
			printf("%-16s", info.szman);
			printf("%-16s", info.szput);
			printf("%-17s", info.szDay);
			printf("%-7d\n", info.inum);
			i++;
		}
		fclose(fp);
	}

	if (know == 1)
	{
		printf("\n\n         ����ϽǷ��� �ƹ�Ű�� �Է��ϼ���. \n\n\n");
		getchar();
	}
	else if (know == 2)
	{
		printf("\n\n         ����ϽǷ��� �ƹ�Ű�� �Է��ϼ���. \n\n\n");
		getchar();
		food_in();
	}
}

food *deletef(char *number, food *list)
{
	food *current, *follow;
	current = follow = list;
	while (1)
	{
		if (current == NULL) break;
		if (strcmp(number, current->szF_name) == 0) break;
		follow = current;
		current = current->next;
	}
	if (current == NULL)
	{
		printf("��ǰ�� ã�� �� �����ϴ�.\n");
		return list;
	}

	if (list == current) list = current->next;
	else if (current->next == NULL) follow->next = NULL;
	else follow->next = current->next;
	free(current);
	return list;
}

int Input(food *Temp)
{
	if (NULL == Temp) return -1;
	printf("��ǰ�� ���� ������ �Է��Ͻÿ�	\n\n\n");
	printf("-> ��ǰ �̸� �Է� :  ");
	scanf("%s", Temp->szF_name);
	printf("-> ���� �̸� �Է� :  ");
	scanf("%s", Temp->szman);
	printf("-> ���峯¥ �Է� (��:2019.05.27):  ");
	scanf("%s", Temp->szput);
	printf("-> ������� �Է� (��:2020.09.10) :  ");
	scanf("%s", Temp->szDay);
	printf("-> ���� �Է� :  ");
	scanf("%d", &Temp->inum);

	printf("-> ����  : %d ", iCa);
	iCa++;

	printf("\n-> �Է� �Ϸ�\n\n");
	printf("-> ����ϽǷ��� �ƹ�Ű�� �Է��ϼ���.\n\n\n");
	getch();
	return 0;
}

void Start()
{
	char s_in;
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��											 ��\n");
	printf("��											 ��\n");
	printf("��											 ��\n");
	printf("��											 ��\n");
	printf("��				 ��ǰ�����ý���						 ��\n");
	printf("��											 ��\n");
	printf("��											 ��\n");
	printf("��											 ��\n");
	printf("��											 ��\n");
	printf("��											 ��\n");
	printf("��											 ��\n");
	printf("��								 201801730 �����	 ��\n");
	printf("��											 ��\n");
	printf("��											 ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

	s_in = getch();
	if (s_in == 'q' || s_in == 'Q') exit(0);
	else system("cls");
}

int count()
{
	FILE *fp;
	food info;
	char ch;
	iCnt2 = 1;
	if ((fp = fopen("food.txt", "r")) == NULL)
	{
		printf("-> ����� ��ǰ�� �����ϴ�.\n");
		printf("-> ���� �����Ͻô� ��ǰ���� ����Ǿ����ϴ�.\n\n\n");
		getchar();
		fflush(stdin);
	}
	else
	{
		while ((fscanf(fp, "%d %c %c %s %c %s %s %s %c %d %c\n", &info.index, &ch, &ch, info.szF_name, &ch, info.szman, info.szput, info.szDay, &ch, &info.inum, &ch)) != EOF) 
			iCnt2++;
		fclose(fp);
	}
	return iCnt2;
}
