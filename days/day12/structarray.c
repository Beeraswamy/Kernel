#include <stdio.h>

struct info
{
	int id_no;
	char name[20];	
};

main()
{
	int i;
	struct info std[3]={{1,"satish"},{2,"kumar"},{3,"naidu"}};
	for(i=0;i<3;i++)	
		printf("%d %s\n",std[i].id_no,std[i].name);
}
