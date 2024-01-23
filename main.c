#include "defs.h"

int main() {
  // Initializes EvidenceArray and loads EvidenceType structures into it
  EvidenceArray evArr;
  initEvidenceArray(&evArr, MAX_CAP);
  loadEvidenceData(&evArr);

  // Creates EvidenceType to be initialized with data from user
  EvidenceType ev;

  // Variables to store data from user
  int   choice;
  int   id;
  char  room[MAX_STR];
  char  device[MAX_STR];
  float value;
  int   hour;
  int   minute;
  int   second;
  int   timestamp;

  // Loops until user enters 0 to quit
  while(1) {
    printMenu(&choice);

    if(choice == 0) {
      // Exit the program
      break;

    } else if(choice == 2) {
      // Delete evidence
      printf("Enter the evidence ID: ");
      scanf("%d", &id);

      int deleted = delEvidence(&evArr, id);

      if(deleted == C_NOK) {
        printf("This ID is not in the collection of evidence.");
      } else {
        printf("Evidence deleted successfully.");
      }

    } else if(choice == 3) {
      // Print all evidence
      printEvidenceArray(&evArr);

    } else if(choice == 1) {
      // Add evidence
      printf("Enter the evidence ID: ");
      scanf("%d", &id);
      while (getchar() != '\n');

      printf("Enter the room name: ");
      fgets(room, MAX_STR, stdin);
      room[strlen(room)-1] = 0;

      // Gets valid device code from user
      getDevice(device);

      printf("Enter the evidence value: ");
      scanf("%f", &value);
      while (getchar() != '\n');

      printf("Enter the timestamp (Hours minutes seconds, space separated): ");
      scanf("%d %d %d", &hour, &minute, &second);
      while (getchar() != '\n');

      timestamp = second + (minute*60) + (hour*3600);
      
      // Initializes the EvidenceType structure with the data that was entered
      initEvidence(id, room, device, value, timestamp, &ev);
      // Adds evidence to the collection of evidence
      addEvidence(&evArr, &ev);
    }
  }
  
  // Deallocates memory from the heap
  cleanupEvidenceArray(&evArr);
  return(0);
}

/* 
  Function: Print Menu
  Purpose:  Print the main menu and get the user's choice via user input
  Params:   
    Output: int* choice - the choice typed by the user
*/
void printMenu(int* choice) {
  // NOTE: Do not make _any_ modifications to this function.
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Add evidence\n");
  printf("  (2) Delete evidence\n");
  printf("  (3) Print evidence\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}

/* 
  Function: Get Device
  Purpose:  Gets valid device code from user and copies corresponding device name into the device variable.
  
  Parameters:
  Output: char* device  - the string storing the name of the device

  Returns: void, no return
*/
void getDevice(char* device) {
  int device_code;
  int numOptions = 3;
  int minOption = 1;
  while (1) {
    printf("Enter the devide code [EMF: 1, THERMAL: 2, SOUND: 3]: ");
    scanf("%d", &device_code);

    if(device_code < minOption || device_code > numOptions) {
      printf("Invalid device code.\n");
      continue;
    } else if(device_code == 1) {
      strcpy(device, "EMF");
    } else if(device_code == 2) {
      strcpy(device, "THERMAL");
    } else if(device_code == 3) {
      strcpy(device, "SOUND");
    } 
    break;
  } 
}