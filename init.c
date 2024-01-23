#include "defs.h"

/*  
  Function: Load Evidence Data
  Purpose:  Creates sample EvidenceType structures and adds them to the given EvidenceArray structure.

  Parameters:
  Output: EvidenceArray* arr    - a pointer to an EvidenceArray structure to load sample data into

  Returns: void, no return
*/
void loadEvidenceData(EvidenceArray* arr) {
  EvidenceType a;
  // Add sample evidence data
  // Evidence has an ID, room location, type (EMF/THERMAL/SOUND), value, and timestamp in seconds
  initEvidence(1000, "Living Room", "EMF", 4.869, 19554, &a);
  addEvidence(arr, &a);
  initEvidence(1001, "Nursery", "EMF", 2.08, 4260, &a);
  addEvidence(arr, &a);
  initEvidence(1002, "Nursery", "SOUND", 88.8, 4120, &a);
  addEvidence(arr, &a);
  initEvidence(1003, "Living Room", "EMF", 4.9, 17157, &a);
  addEvidence(arr, &a);
  initEvidence(1004, "Living Room", "SOUND", 35.154, 20970, &a);
  addEvidence(arr, &a);
  initEvidence(1005, "Bathroom", "THERMAL", 16.22806, 15936, &a);
  addEvidence(arr, &a);
  initEvidence(1006, "Kitchen", "EMF", 0.439, 609, &a);
  addEvidence(arr, &a);
  initEvidence(1007, "Kitchen", "THERMAL", 9.3643, 11797, &a);
  addEvidence(arr, &a);
  initEvidence(1008, "Bathroom", "EMF", 2.1254, 20166, &a);
  addEvidence(arr, &a);
  initEvidence(1009, "Living Room", "SOUND", 44.8, 12701, &a);
  addEvidence(arr, &a);
  initEvidence(1010, "Dining Room", "EMF", 3.871087, 17593, &a);
  addEvidence(arr, &a);
  initEvidence(1011, "Main Bedroom", "SOUND", 79.0739, 2862, &a);
  addEvidence(arr, &a);
  initEvidence(1012, "Bathroom", "THERMAL", 10.649717, 9292, &a);
  addEvidence(arr, &a);
  initEvidence(1013, "Living Room", "EMF", 4.142, 8384, &a);
  addEvidence(arr, &a);
  initEvidence(1014, "Nursery", "THERMAL", -8.2, 328, &a);
  addEvidence(arr, &a);
  initEvidence(1015, "Dining Room", "SOUND", 49.9, 20757, &a);
  addEvidence(arr, &a);
  initEvidence(1016, "Living Room", "THERMAL", 3.4364, 16043, &a);
  addEvidence(arr, &a);
  initEvidence(1017, "Dining Room", "THERMAL", -1.462089, 14241, &a);
  addEvidence(arr, &a);
  initEvidence(1018, "Living Room", "EMF", 3.484842, 6222, &a);
  addEvidence(arr, &a);
  initEvidence(1019, "Living Room", "EMF", 2.87804, 15926, &a);
  addEvidence(arr, &a);
  initEvidence(1020, "Living Room", "EMF", 4.782, 19880, &a);
  addEvidence(arr, &a);
  initEvidence(1021, "Nursery", "THERMAL", -6.9681, 2905, &a);
  addEvidence(arr, &a);

}

/*  
  Function: Init Evidence
  Purpose:  Initializes attributes of the given EvidenceType structure with the given values.

  Parameters:
  Input:  int id                - the ID corresponding to the evidence
  Input:  char* room            - the name of the room corresponding to the evidence
  Input:  char* device          - the name of the type of device used (EMF for electromagnetic field reader, THERMAL for thermometer, or SOUND for microphone)
  Input:  float value           - the reading from the device
  Input:  int timestamp         - the number of seconds, indicating when the evidence was obtained
  Output: EvidenceType* dest    - a pointer to an EvidenceType structure to initialize

  Returns: void, no return
*/
void initEvidence(int id, char* room, char* device, float value, int timestamp, EvidenceType* dest) {
  dest->id = id;
  strcpy(dest->room, room);
  strcpy(dest->device, device);
  dest->value = value;
  dest->timestamp = timestamp;
}

/*  
  Function: Init EvidenceArray
  Purpose:  Initializes attributes of the given EvidenceArray structure with the given values.

  Parameters:
  Output: EvidenceArray* evArr  - a pointer to an EvidenceType structure to initialize
  Input:  int cap               - the number of EvidenceType structures this EvidenceArray can store in its elements attribute

  Returns: void, no return
*/
void initEvidenceArray(EvidenceArray* evArr, int cap) {
  evArr->capacity = cap;
  evArr->size = 0;
  evArr->elements = (EvidenceType *) calloc(cap, sizeof(EvidenceType));
}
