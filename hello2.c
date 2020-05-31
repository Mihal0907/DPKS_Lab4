#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_DESCRIPTION("Lab4");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int ticks = 1;

module_param(ticks, uint, S_IRUGO);
MODULE_PARM_DESC(ticks, "Number of Hello to print");

static int __init hello2_init(void)
{
	if (ticks == 0 || (ticks >= 5 && ticks <= 10)) {
		pr_warn("Warning about amount of ticks\n");
	}

	if (ticks > 10) {
		pr_err("Number of ticks is more than 10\n");
		return -EINVAL;
	}

	print_hello(ticks);

	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info(KERN_EMERG "Exit module\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
