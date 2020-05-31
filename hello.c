 
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

MODULE_DESCRIPTION("Lab4 task");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int TICKS = 1;

module_param(TICKS, uint, S_IRUGO);
MODULE_PARM_DESC(TICKS, "Number of Words to print");

static int __init hello_init(void)
{
	unsigned int tick;

	if (shouldWarn(TICKS)) {
		printk(KERN_WARNING "Warning\n");
	}

	if (shouldShowError(TICKS)) {
		printk(KERN_ERR "Too many TICKS\n");
		return -EINVAL;
	}

	for (tick = 0; tick < TICKS; ++tick) {
		printk(KERN_INFO "Word! /tick %d/\n", tick);
	}

	return 0;
}

static int shouldWarn(int number)
{
	if (TICKS == 0 || (TICKS >= 5 && TICKS <= 10)) 
		return 1;
	else 
		return 0;
}

static int shouldShowError(int number)
{
	if (TICKS > 10)
		return 1;
	else
		return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_EMERG "Exit\n");
}

module_init(hello_init);
module_exit(hello_exit);
