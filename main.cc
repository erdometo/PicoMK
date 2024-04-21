#include <stdio.h>

#include "FreeRTOS.h"
#include "pico/stdlib.h"
#include "runner.h"
#include "storage.h"
#include "sync.h"
#include "utils.h"
#include "pico/sleep.h"

extern "C" void vApplicationMallocFailedHook(void) {
  LOG_ERROR("Failed malloc. OOM");
}
extern "C" void vApplicationIdleHook(void) {}
extern "C" void vApplicationStackOverflowHook(TaskHandle_t pxTask,
                                              char *pcTaskName) {
  LOG_ERROR("Stack overflow for task %s", pcTaskName);
}
extern "C" void vApplicationTickHook(void) {}

int main() {
//   gpio_init(24);
//   gpio_set_dir(24, GPIO_IN);
//   //if plugged to usb (VBUS on), first pull up boot pin and then float all pins until plugged in
//   if(!gpio_get(24)){
//     gpio_init(17);
//     gpio_set_dir(17, GPIO_OUT);
//     gpio_put(17, 1);
//     sleep_ms(3000);
//     int count =29;
//     for (size_t i = 0; i < count; i++)
//     {
//     gpio_init(i);
//     gpio_set_dir(i, GPIO_IN);
//     gpio_set_pulls(i, false, false);
//     }
//     sleep_run_from_xosc();
//     sleep_goto_dormant_until_edge_high(24);
//   }else{
// // if usb mode is being used, pull boot pin down during boot (other mcu disabled)
//     gpio_init(17);
//     gpio_set_dir(17, GPIO_OUT);
//     gpio_put(17, 0);
//     sleep_ms(3000);
//   }

// load PicoMk firmware
  if (InitializeStorage() == OK &&   //
  runner::RunnerInit() == OK &&  //
  runner::RunnerStart() == OK) {
    vTaskStartScheduler();
  }
  // gpio_put(27, 0);
  // gpio_set_pulls(27, false, true);

// Todo: instead of NoOp, try dormant modes
  while (true){
    tight_loop_contents();
  }

  return 0;
}
