// import

#include <linux/module.h>
#include <linux/kfifo.h>
#include "import.h"


static __init int import_init(void)
{
	printk(KERN_INFO " %s : import_init() function start \n", THIS_MODULE->name);
	// 1.In init, print exported varibles from module export.
	printk(KERN_INFO " %s : size of kfifo = %d , length of kfifo = %d, kfifo avail = %d\n", THIS_MODULE->name, k_size, k_len, k_avail);

	return 0;
}

static __exit void import_exit(void)
{
	printk(KERN_INFO " %s : import_init() function start \n", THIS_MODULE->name);
	

}

module_init(import_init);
module_exit(import_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PARAG B PATIL 80732");
MODULE_DESCRIPTION("Linux device driver lab imam --> import section");







