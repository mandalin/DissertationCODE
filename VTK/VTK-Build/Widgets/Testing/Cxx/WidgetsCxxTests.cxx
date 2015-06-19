#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Rendering/vtkTestingObjectFactory.h"



/* Forward declare test functions. */
int BoxWidget(int, char*[]);
int BoxWidget2(int, char*[]);
int TestAngleWidget2D(int, char*[]);
int TestAngleWidget3D(int, char*[]);
int TestBalloonWidget(int, char*[]);
int TestCaptionWidget(int, char*[]);
int TestCheckerboardWidget(int, char*[]);
int TestContourWidget2(int, char*[]);
int TestDistanceWidget(int, char*[]);
int TestHandleWidget(int, char*[]);
int TestImplicitPlaneWidget(int, char*[]);
int TestImplicitPlaneWidget2(int, char*[]);
int TestImplicitPlaneWidget2b(int, char*[]);
int TestOrientationMarkerWidget(int, char*[]);
int TestRectilinearWipeWidget(int, char*[]);
int TestSeedWidget(int, char*[]);
int TestSliderWidget(int, char*[]);
int TestSliderWidget2D(int, char*[]);
int TestTextWidget(int, char*[]);
int TerrainPolylineEditor(int, char*[]);
int TestDijkstraGraphGeodesicPath(int, char*[]);
int TestParallelopipedWidget(int, char*[]);
int TestSeedWidgetNonUniformRepresentations(int, char*[]);


/* Create map.  */

typedef int (*MainFuncPointer)(int , char*[]);
typedef struct
{
  const char* name;
  MainFuncPointer func;
} functionMapEntry;

functionMapEntry cmakeGeneratedFunctionMapEntries[] = {
    {
    "BoxWidget",
    BoxWidget
  },
  {
    "BoxWidget2",
    BoxWidget2
  },
  {
    "TestAngleWidget2D",
    TestAngleWidget2D
  },
  {
    "TestAngleWidget3D",
    TestAngleWidget3D
  },
  {
    "TestBalloonWidget",
    TestBalloonWidget
  },
  {
    "TestCaptionWidget",
    TestCaptionWidget
  },
  {
    "TestCheckerboardWidget",
    TestCheckerboardWidget
  },
  {
    "TestContourWidget2",
    TestContourWidget2
  },
  {
    "TestDistanceWidget",
    TestDistanceWidget
  },
  {
    "TestHandleWidget",
    TestHandleWidget
  },
  {
    "TestImplicitPlaneWidget",
    TestImplicitPlaneWidget
  },
  {
    "TestImplicitPlaneWidget2",
    TestImplicitPlaneWidget2
  },
  {
    "TestImplicitPlaneWidget2b",
    TestImplicitPlaneWidget2b
  },
  {
    "TestOrientationMarkerWidget",
    TestOrientationMarkerWidget
  },
  {
    "TestRectilinearWipeWidget",
    TestRectilinearWipeWidget
  },
  {
    "TestSeedWidget",
    TestSeedWidget
  },
  {
    "TestSliderWidget",
    TestSliderWidget
  },
  {
    "TestSliderWidget2D",
    TestSliderWidget2D
  },
  {
    "TestTextWidget",
    TestTextWidget
  },
  {
    "TerrainPolylineEditor",
    TerrainPolylineEditor
  },
  {
    "TestDijkstraGraphGeodesicPath",
    TestDijkstraGraphGeodesicPath
  },
  {
    "TestParallelopipedWidget",
    TestParallelopipedWidget
  },
  {
    "TestSeedWidgetNonUniformRepresentations",
    TestSeedWidgetNonUniformRepresentations
  },

  {0,0}
};

/* Allocate and create a lowercased copy of string
   (note that it has to be free'd manually) */

char* lowercase(const char *string)
{
  char *new_string, *p;

#ifdef __cplusplus
  new_string = static_cast<char *>(malloc(sizeof(char) *
    static_cast<size_t>(strlen(string) + 1)));
#else
  new_string = (char *)(malloc(sizeof(char) * (size_t)(strlen(string) + 1)));
#endif

  if (!new_string)
    {
    return 0;
    }
  strcpy(new_string, string);
  p = new_string;
  while (*p != 0)
    {
#ifdef __cplusplus
    *p = static_cast<char>(tolower(*p));
#else
    *p = (char)(tolower(*p));
#endif

    ++p;
    }
  return new_string;
}

int main(int ac, char *av[])
{
  int i, NumTests, testNum, partial_match;
  char *arg, *test_name;
  int count;
  int testToRun = -1;

  
    
  for(count =0; cmakeGeneratedFunctionMapEntries[count].name != 0; count++)
    {
    }
  NumTests = count;
  /* If no test name was given */
  /* process command line with user function.  */
  if (ac < 2)
    {
    /* Ask for a test.  */
    printf("Available tests:\n");
    for (i =0; i < NumTests; ++i)
      {
      printf("%3d. %s\n", i, cmakeGeneratedFunctionMapEntries[i].name);
      }
    printf("To run a test, enter the test number: ");
    fflush(stdout);
    testNum = 0;
    if( scanf("%d", &testNum) != 1 )
      {
      printf("Couldn't parse that input as a number\n");
      return -1;
      }
    if (testNum >= NumTests)
      {
      printf("%3d is an invalid test number.\n", testNum);
      return -1;
      }
    testToRun = testNum;
    ac--;
    av++;
    }
  partial_match = 0;
  arg = 0;
  /* If partial match is requested.  */
  if(testToRun == -1 && ac > 1)
    {
    partial_match = (strcmp(av[1], "-R") == 0) ? 1 : 0;
    }
  if (partial_match && ac < 3)
    {
    printf("-R needs an additional parameter.\n");
    return -1;
    }
  if(testToRun == -1)
    {
    arg = lowercase(av[1 + partial_match]);
    }
  for (i =0; i < NumTests && testToRun == -1; ++i)
    {
    test_name = lowercase(cmakeGeneratedFunctionMapEntries[i].name);
    if (partial_match && strstr(test_name, arg) != NULL)
      {
      testToRun = i;
      ac -=2;
      av += 2;
      }
    else if (!partial_match && strcmp(test_name, arg) == 0)
      {
      testToRun = i;
      ac--;
      av++;
      }
    free(test_name);
    }
  if(arg)
    {
    free(arg);
    }
  if(testToRun != -1)
    {
    int result;

    // Set defaults
    vtkTestingInteractor::ValidBaseline =
      std::string("VTK_DATA_ROOT-NOTFOUND") +
      std::string("/Baseline/") +
      std::string("Widgets/") +
      std::string(cmakeGeneratedFunctionMapEntries[testToRun].name) +
      std::string(".png");
    vtkTestingInteractor::TempDirectory =
      std::string("/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/Testing/Temporary");
    vtkTestingInteractor::DataDirectory =
      std::string("VTK_DATA_ROOT-NOTFOUND");

    int interactive = 0;
    for (int ii = 0; ii < ac; ++ii)
      {
      if ( strcmp(av[ii],"-I") == 0)
        {
        interactive = 1;
        continue;
        }
      if ( strcmp(av[ii],"-V") == 0)
        {
        vtkTestingInteractor::ValidBaseline = std::string(av[ii+1]);
        ++ii;
        continue;
        }
      if ( strcmp(av[ii],"-T") == 0)
        {
        vtkTestingInteractor::TempDirectory = std::string(av[ii+1]);
        ++ii;
        continue;
        }
      if ( strcmp(av[ii],"-D") == 0)
        {
        vtkTestingInteractor::DataDirectory = std::string(av[ii+1]);
        ++ii;
        continue;
        }
      }
    vtkSmartPointer<vtkTestingObjectFactory> factory = vtkSmartPointer<vtkTestingObjectFactory>::New();
    if (!interactive)
      {
      vtkObjectFactory::RegisterFactory(factory);
      }

    result = (*cmakeGeneratedFunctionMapEntries[testToRun].func)(ac, av);
    
   if (!interactive)
     {
     if (vtkTestingInteractor::TestReturnStatus != -1)
        {
        if( vtkTestingInteractor::TestReturnStatus != vtkTesting::PASSED)
          {
          result = EXIT_FAILURE;
          }
        else
          {
          result = EXIT_SUCCESS;
          }
        }
      vtkObjectFactory::UnRegisterFactory(factory);
      }

    return result;
    }
  
  
  /* Nothing was run, display the test names.  */
  printf("Available tests:\n");
  for (i =0; i < NumTests; ++i)
    {
    printf("%3d. %s\n", i, cmakeGeneratedFunctionMapEntries[i].name);
    }
  printf("Failed: %s is an invalid test name.\n", av[1]);
  
  return -1;
}
