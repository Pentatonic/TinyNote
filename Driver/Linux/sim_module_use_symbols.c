#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

int func2(void);

//__init, __initdata, will remove thie function in memory, to save some memory

__init int simple_module_init(void) {
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    func2();
    return 0;
}

void simple_module_exit(void) {
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
}

module_init(simple_module_init);
module_exit(simple_module_exit);

