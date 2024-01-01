// import

#include <linux/module.h>
#include <linux/kfifo.h>
#include "import.h"


static __init int import_init(void)
{
	char ch[15];
	strcpy(ch, "paragpatil");
	printk(KERN_INFO " %s : import_init() function start \n", THIS_MODULE->name);
	// 1.In init, print exported varibles from module export.
	printk(KERN_INFO " %s : size of kfifo = %d , length of kfifo = %d, kfifo avail = %d\n", THIS_MODULE->name, k_size, k_len, k_avail);
	printk(KERN_INFO " %s : the popped characters is = %s", THIS_MODULE->name, ch);
	
	//2. b. In init, push your name characters into kfifo using fuction kfifo_push() exported form module export.

	kfifo_push(ch);
	
	//3.c. In init, again print exported varibles from module export.
	printk(KERN_INFO " %s : size of kfifo = %d , length of kfifo = %d, kfifo avail = %d\n", THIS_MODULE->name, k_size, k_len, k_avail);
	
	printk(KERN_INFO " %s : import_init() function over \n", THIS_MODULE->name);






	return 0;
}

static __exit void import_exit(void)
{
	printk(KERN_INFO " %s : import_exit() function start \n", THIS_MODULE->name);
	//4. In exit, print exported varibles from module export.
	printk(KERN_INFO " %s : size of kfifo = %d , length of kfifo = %d, kfifo avail = %d\n", THIS_MODULE->name, k_size, k_len, k_avail);
	char ch[5];
	strcpy(ch, kfifo_pop());
	printk(KERN_INFO " %s : the popped characters is = %s", THIS_MODULE->name, ch);
	
	
	//5. print exported varibles from module export.
	printk(KERN_INFO " %s : size of kfifo = %d , length of kfifo = %d, kfifo avail = %d\n", THIS_MODULE->name, k_size, k_len, k_avail);
	
	printk(KERN_INFO " %s : import_exit() function over \n", THIS_MODULE->name);
	

}

module_init(import_init);
module_exit(import_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PARAG B PATIL 80732");
MODULE_DESCRIPTION("Linux device driver lab imam --> import section");







