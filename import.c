// import

#include <linux/module.h>
#include <linux/kfifo.h>


static __init int import_init(void)
{
	printk(KERN_INFO " %s : import_init() function start \n", THIS_MODULE->name);
	

	return 0;
}

static __exit void import_exit(void)
{
	printk(KERN_INFO " %s : import_imit() function start \n", THIS_MODULE->name);
	

}

module_init(import_init);
module_exit(import_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PARAG B PATIL 80732");
MODULE_DESCRIPTION("Linux device driver lab imam --> import section");







