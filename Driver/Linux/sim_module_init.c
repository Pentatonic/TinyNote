#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

int simple_module_init(void) {
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

module_init(simple_module_init);
