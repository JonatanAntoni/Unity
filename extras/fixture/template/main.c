
#include "RTE_Components.h"
#include  CMSIS_device_header
 
#ifdef RTE_Compiler_EventRecorder
#include "EventRecorder.h"
#endif

#include "unity_fixture.h"

static void runAllTests(void)
{
    RUN_TEST_GROUP(group);
}

/*=======MAIN=====*/
int main(void)
{
  // System Initialization
  SystemCoreClockUpdate();
  
#ifdef RTE_Compiler_EventRecorder
  // Initialize and start Event Recorder
  (void)EventRecorderInitialize(EventRecordError, 1U);
  (void)EventRecorderEnable    (EventRecordAll, 0xFEU, 0xFEU);
#endif
  
  UnityMain(0U, NULL, runAllTests);
  
  for(;;);
}
