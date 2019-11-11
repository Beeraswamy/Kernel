#include <sys/stat.h>

main()
{
	chmod("dumpdemo.txt",S_IRWXU|S_IRWXG|S_IROTH);
}
