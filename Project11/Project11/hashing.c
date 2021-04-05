#include<stdio.h>
struct student {
	char name[20];
	int num;
	unsigned short age;
	struct student *next;
};

#define SZ 30
struct student *hashtable[SZ];

int hash(char *str) {
	int sum = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		sum += str[i];
	}
	return (sum%SZ);
}

void addTohashtable(char *name, int num, unsigned short age) {
	struct student *cur;
	int idx;

	cur = (struct student *)malloc(sizeof(struct student));
	strcpy(cur->name, name);
	cur->num = num;
	cur->age = age;
	cur->next = 0;

	idx = hash(name);

	if (hashtable[idx]==0)
	{
		hashtable[idx] = cur;
		return;
	}
	else
	{
		struct student *temp = hashtable[idx];
		while (temp->next!=0)
		{
			temp = temp->next;
		}
		temp->next = cur;
		return;
	}
}

void search(char *name) {
	struct student *cur;
	int idx;
	idx = hash(name);
	cur = hashtable[idx];

	if (cur == 0) {
		printf("¾øÀ½");
		return;
	}

	while (strcmp(cur->name,name)!=0)
	{
		cur = cur->next;
		if (cur == 0) return;
	}
	printf("%s %d %d", cur->name, cur->num, cur->age);
}

void main() {
	addTohashtable("¹ÚÃ¶¼ö", 200, 19);
	addTohashtable("±èÃ¶¼ö", 201, 20);
	addTohashtable("ÀÌÃ¶¼ö", 202, 19);
	addTohashtable("¿ÀÃ¶¼ö", 203, 18);
	addTohashtable("¼ÛÃ¶¼ö", 204, 19);

	search("ÀÌÃ¶¼ö");
}