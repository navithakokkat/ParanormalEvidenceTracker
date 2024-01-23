#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constant definitions
#define C_OK       0
#define C_NOK     -1

#define MAX_STR   32
#define MAX_CAP    2

#define TOO_HIGH    4.0
#define TOO_COLD    0.0
#define TOO_QUIET  35.0
#define TOO_LOUD   70.0

// Structures
typedef struct {	
  int   id;
  char  room[MAX_STR];
  char  device[MAX_STR];
  float value;
  int   timestamp;
} EvidenceType;

typedef struct {
  EvidenceType *elements;
  int capacity;
  int size;
} EvidenceArray;

// Forward Declarations
void printMenu(int* choice);
void loadEvidenceData(EvidenceArray* dest);

void initEvidenceArray(EvidenceArray* evArr, int cap);
void initEvidence(int id, char* room, char* device, float value, int timestamp, EvidenceType* dest);

void addEvidence(EvidenceArray* dest, EvidenceType* src);
int  delEvidence(EvidenceArray* src , int id);
void copyEvidence(EvidenceType* dest, EvidenceType* src);
void printEvidence(EvidenceType*);
void growEvidenceArray(EvidenceArray*);

void printEvidenceArray(EvidenceArray*);
void cleanupEvidenceArray(EvidenceArray*);

// Forward Declarations for Helper functions
void printValue(char* device, float value);
void getDevice(char* device);