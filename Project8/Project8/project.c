#include "main.h"

int i = 1;
int iCnt2 = 1;
static int iCount = 1; //衝ヶ檜 氈朝雖 橈朝雖 憲嬴 爾朝 滲熱
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
		printf("\t  旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("\t  早						   早\n");
		printf("\t  早	旨旬					   早\n");
		printf("\t  早	早早					   早\n");
		printf("\t  早	早早					   早\n");
		printf("\t  早	曲旭					   早\n");
		printf("\t  早						   早\n");
		printf("\t  曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("\t  早						   早\n");
		printf("\t  早	旨旬					   早\n");
		printf("\t  早	早早	1.蛔煙				   早\n");
		printf("\t  早	早早					   早\n");
		printf("\t  早	早早	2.餉薯				   早\n");
		printf("\t  早	早早					   早\n");
		printf("\t  早	早早	3.盪濰				   早\n");
		printf("\t  早	早早					   早\n");
		printf("\t  早	早早	4.濰夥掘棲			   早\n");
		printf("\t  早	早早					   早\n");
		printf("\t  早	早早	5.轎溘				   早\n");
		printf("\t  早	早早					   早\n");
		printf("\t  早	早早	6.匐儀				   早\n");
		printf("\t  早	早早					   早\n");
		printf("\t  早	早早	7.謙猿				   早\n");
		printf("\t  早	曲旭					   早\n");
		printf("\t  早						   早\n");
		printf("\t  曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

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
			//瞪晦餌辨榆 啗骯 & 瞪晦猿 啗骯
			int used, base, tot;
			double plus, tax;
			printf("衝ヶ榆擊 殮溘ж撮蹂 : ");
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
			case 6: printf("頂辨僭檜 60Щ煎蒂 剩晦陽僥縑 �螃窕�檣 寞徹戲煎 餌辨ж雖 跤м棲棻.\n傢濰堅蒂 薑葬п 輿撮蹂. "); exit(0);
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
			printf("蹺陛蹂旎 : %lf\n", plus);
			tax = (base + plus)*0.09;
			printf("撮旎 : %lf\n", tax);
			tot = base + (int)plus + (int)tax;
			printf("譆謙 旎擋 %d\n", tot);
			exit(0);
			break;
		}
	}
}

void food_in()
{
	char bState;
	printf("\n\n\n                1.  衝ヶ 薑爾 薑溺                \n\n");
	printf("                2.  衝ヶ 薑爾 匐儀                \n\n");
	printf("                3.  詭檣戲煎 給嬴陛晦             \n\n\n\n");

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
	printf("\n\n\n                      1.  衝ヶ貲戲煎 匐儀     \n\n");
	printf("                      2.  輿檣檜葷戲煎 匐儀     \n\n");
	printf("                      3.  盪濰陳瞼煎 匐儀   \n\n");
	printf("                      4.  嶸鱔晦и戲煎 匐儀     \n\n");
	printf("                      5.  偃熱煎 匐儀     \n\n");
	printf("                      6.  薑溺/匐儀 詭景煎  給嬴陛晦   \n\n");

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
	printf("㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑\n");
	printf("                         <    衝 ヶ 葬 蝶 お    >                           \n");
	printf("㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑\n\n");
	printf("收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收\n");
	printf(" 牖廓\t衝ヶ貲\t\t輿檣\t\t盪濰陳瞼\t嶸鱔晦и\t偃熱\n");
	printf("收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收\n\n");
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
		printf("衝ヶ檜 橈蝗棲棻.\n");
		getchar();
		fflush(stdin);
	}

	if (kind == 1)
	{
		printf("\n\n\n->  匐儀й 衝ヶ貲擊 殮溘ж撮蹂\n ");
		scanf("%s", f_name);
		fflush(stdin);
	}
	else if (kind == 2)
	{
		printf("\n\n\n->  匐儀й 輿檣 檜葷擊 殮溘ж撮蹂 \n ");
		scanf("%s", man);
		fflush(stdin);
	}
	else if (kind == 3)
	{
		printf("\n\n\n->  匐儀й 盪濰陳瞼蒂 殮溘ж撮蹂 (蕨:2019.09.10)\n");
		scanf("%s", put);
		fflush(stdin);
	}
	else if (kind == 4)
	{
		printf("\n\n\n->  匐儀й 嶸鱔晦и擊 殮溘ж撮蹂 (蕨:2020.09.10) \n");
		scanf("%s", day);
		fflush(stdin);
	}
	else if (kind == 5)
	{
		printf("\n\n\n->  匐儀й 偃熱蒂 殮溘ж撮蹂 (1檜鼻 5檜ж賊 1 殮溘) \n ");
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
		printf(" -> 瓊戲衛朝 衝ヶ檜 橈蝗棲棻 \n\n\n");
		printf(" -> 啗樓 ж衛溥賊 嬴鼠酈釭 殮溘ж撮蹂 \n");
		getchar();
		fflush(stdin);
		system("cls");
		foodSerch();
	}
	printf("\n\n->  熱薑ж衛啊蝗棲梱 ? (Y / N) \n\n");
	choice = getch();
	fflush(stdin);
	if (choice == 'y')
	{
		while (1)
		{
			printf("熱薑ж褒 牖廓擊 殮溘ж罹 輿撮蹂.\n\n");
			scanf("%d", &Andex);
			fflush(stdin);
			if (Andex > info.index || Andex <= 0)
			{
				printf("->  殮溘ж褐 牖廓檜 褲雖 彊蝗棲棻. \n");
				printf("->  棻衛 ");
			}
			else break;
		}
		if ((fp = fopen("food.txt", "r")) == NULL)
		{
			printf("衝ヶ檜 橈蝗棲棻.\n");
			getchar();
			fflush(stdin);
		}

		printf("-> 滲唳ж褒 衝ヶ貲擊 殮溘п輿撮蹂\n");
		scanf("%s", chf_name);
		fflush(stdin);
		printf("-> 滲唳ж褒 輿檣檜葷擊 殮溘п輿撮蹂\n");
		scanf("%s", chman);
		fflush(stdin);
		printf("-> 滲唳ж褒 盪濰陳瞼蒂  殮溘п輿撮蹂\n");
		scanf("%s", chput);
		fflush(stdin);
		printf("-> 滲唳ж褒 嶸鱔晦и擊 殮溘п輿撮蹂\n");
		scanf("%s", chDay);
		fflush(stdin);
		printf("-> 滲唳ж褒 偃熱擊 殮溘п輿撮蹂\n");
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
	printf("\n\n  啗樓ж褒溥賊 嬴鼠酈釭 殮溘ж撮蹂 \n\n\n");
	getchar();
	fflush(stdin);
	system("cls");
	foodSerch();
}

void foodSort()
{
	char bState;
	printf("\n\n\n                  1.  衝ヶ貲戲煎 薑溺     \n\n");
	printf("                  2.  輿檣貲戲煎 薑溺     \n\n");
	printf("                  3.  盪濰陳瞼煎 薑溺   \n\n");
	printf("                  4.  嶸鱔晦и戲煎 薑溺     \n\n");
	printf("                  5.  偃熱煎 薑溺     \n\n");
	printf("                  6.  滲唳脹 衝ヶ 葬蝶お 轎溘  \n\n");
	printf("                  7.  薑溺/匐儀 詭景煎  給嬴陛晦   \n\n");
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
		printf("衝ヶ檜 橈蝗棲棻.\n");
		getchar();
		fflush(stdin);
	}

	printf("1. 螃葷離牖\n2. 頂葡離牖\n\n");
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
	printf("->  薑溺и 渠煎 ⑷營 だ橾縑 盪濰 (Y)     \n");
	printf("->  薑溺и 渠煎 棻艇 檜葷戲煎 だ橾 盪濰 (C)     \n");
	printf("->  CANCEL (N)     \n");

	Select = getch();
	if (Select == 'y') savefood(Head, f_name);
	else if (Select == 'c')
	{
		printf(" -> だ橾貲婁 �挫敻皒� 殮溘п輿撮蹂 (蕨: food.txt) \n");
		scanf("%s", f_name);
		savefood(Head, f_name);
		printf("       盪濰 腎歷蝗棲棻          \n\n\n");
		printf("-> 啗樓 ж衛溥賊 嬴鼠酈釭 殮溘ж撮蹂 \n");
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
		printf("й渡脹 詭賅葬陛 橈蝗棲棻.\n");
		return list;
	}
	*new = *item;
	while (1)
	{	//翱唸list陛 籀擠檜剪釭 葆雖虞橾陽
		if (current == NULL) break;
		if (kind == 1)
		{
			if (Sort == 1)
			{
				if (0 < strcmp(current->szF_name, item->szF_name)) break;// 翱唸醞 鳶殮й 夠擊 瓊擎 唳辦  
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
				if (0 < strcmp(current->szman, item->szman)) break;// 翱唸醞 鳶殮й 夠擊 瓊擎 唳辦  
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
				if (0 < strcmp(current->szput, item->szput)) break;// 翱唸醞 鳶殮й 夠擊 瓊擎 唳辦  
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
				if (0 < strcmp(current->szDay, item->szDay)) break;// 翱唸醞 鳶殮й 夠擊 瓊擎 唳辦  
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
				if (current->inum > item->inum) break;// 翱唸醞 鳶殮й 夠擊 瓊擎 唳辦  
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
	printf("餉薯й  衝ヶ貲擊  殮溘ж撮蹂.\n");
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
		printf("だ橾檜 橈蝗棲棻.\n");
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
	printf("\n\n   ->   盪濰腎歷蝗棲棻. \n\n");
	printf("\n\n         啗樓ж褒溥賊 嬴鼠酈釭 殮溘ж撮蹂.\n\n\n");
	getchar();
	fflush(stdin);
}

void savefood(food *list, char f_name[])
{
	FILE *fp;
	int i = 1;
	if ((fp = fopen(f_name, "w")) == NULL)
	{
		printf("だ橾檜 橈蝗棲棻.\n");
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
		printf("\n\n         啗樓ж褒溥賊 嬴鼠酈釭 殮溘ж撮蹂. \n\n\n");
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
		printf("衝ヶ檜 橈蝗棲棻.\n");
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
		printf("\n\n         啗樓ж褒溥賊 嬴鼠酈釭 殮溘ж撮蹂. \n\n\n");
		getchar();
	}
	else if (know == 2)
	{
		printf("\n\n         啗樓ж褒溥賊 嬴鼠酈釭 殮溘ж撮蹂. \n\n\n");
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
		printf("衝ヶ擊 瓊擊 熱 橈蝗棲棻.\n");
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
	printf("衝ヶ縑 婦и 薑爾蒂 殮溘ж衛螃	\n\n\n");
	printf("-> 衝ヶ 檜葷 殮溘 :  ");
	scanf("%s", Temp->szF_name);
	printf("-> 輿檣 檜葷 殮溘 :  ");
	scanf("%s", Temp->szman);
	printf("-> 盪濰陳瞼 殮溘 (蕨:2019.05.27):  ");
	scanf("%s", Temp->szput);
	printf("-> 嶸鱔晦и 殮溘 (蕨:2020.09.10) :  ");
	scanf("%s", Temp->szDay);
	printf("-> 偃熱 殮溘 :  ");
	scanf("%d", &Temp->inum);

	printf("-> 牖廓  : %d ", iCa);
	iCa++;

	printf("\n-> 殮溘 諫猿\n\n");
	printf("-> 啗樓ж褒溥賊 嬴鼠酈釭 殮溘ж撮蹂.\n\n\n");
	getch();
	return 0;
}

void Start()
{
	char s_in;
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早											 早\n");
	printf("早											 早\n");
	printf("早											 早\n");
	printf("早											 早\n");
	printf("早				 衝ヶ婦葬衛蝶蠱						 早\n");
	printf("早											 早\n");
	printf("早											 早\n");
	printf("早											 早\n");
	printf("早											 早\n");
	printf("早											 早\n");
	printf("早											 早\n");
	printf("早								 201801730 梯棻��	 早\n");
	printf("早											 早\n");
	printf("早											 早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

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
		printf("-> 盪濰脹 衝ヶ檜 橈蝗棲棻.\n");
		printf("-> 雖旎 盪濰ж衛朝 衝ヶ睡攪 盪濰腎橫餵棲棻.\n\n\n");
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
