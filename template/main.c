
#include "RTE_Components.h"
#include  CMSIS_device_header
 
#ifdef RTE_Compiler_EventRecorder
#include "EventRecorder.h"
#endif

#include "unity.h"

#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT()) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);


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

  UnityBegin("");
  
  // RUN_TEST(test, 20);

  (void)UnityEnd();
  
  for(;;);
}
