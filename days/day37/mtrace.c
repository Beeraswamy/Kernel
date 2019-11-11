#include <stdio.h>
#include <mcheck.h>

struct blist_s 
{
	struct blist_s *next;
	char *data_item;
	int item_size;
	int index;
};


main()
{mtrace();
	struct blist_s *p=malloc(sizeof(struct blist_s));
	
//free(p);
p=malloc(sizeof(struct blist_s));
//free(p);
p=malloc(sizeof(struct blist_s));
//free(p);
p=malloc(sizeof(struct blist_s));
//free(p);
p=malloc(sizeof(struct blist_s));
//free(p);

}	
