#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

void simple_module_exit(void) {
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
}

module_exit(simple_module_exit);
