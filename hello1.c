
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_DESCRIPTION("Lab4");
MODULE_LICENSE("Dual BSD/GPL");

void print_hello(unsigned int ticks)
{
	unsigned int tick;

	for (tick = 0; tick < ticks; ++cytickcle) {
		pr_info("TICK! /tick %d/\n", tick);
	}
}

EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
	pr_info("Function export\n");
	return 0;
}

static void __exit hello1_exit(void)
{
	pr_info("Nothing to export\n");
}

module_init(hello1_init);
module_exit(hello1_exit);
