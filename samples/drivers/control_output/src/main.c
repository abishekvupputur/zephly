#include "kernel.h"
#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <custom_drivers/control_output.h>

#define PWMOUT_NODE DT_NODELABEL(pwmout)

int main() {
    const struct device *pwmout = DEVICE_DT_GET(PWMOUT_NODE);
    float outputs[4] = {};

    if(!device_is_ready(pwmout)) {
        printk("PWMOUT device is not ready!\n");
        return -EIO;
    }

    printk("Succesfully booted, doing shit.\n");

    while (true) {
        control_output_set(pwmout, outputs);
        outputs[0] += 0.1;
        if (outputs[0] > 1.0) {
            outputs[0] = 0.0;
        }
        printk("Updated PWM output.%d \n", (int)(outputs[0]*1000));
        k_sleep(K_SECONDS(1));
    }

    return 0;
}
