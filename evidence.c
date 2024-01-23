#include "defs.h"

/*  
  Function: Print Evidence
  Purpose:  Prints and formats attributes of the given EvidenceType structure.

  Parameters:
  Input: EvidenceType *ev  - a pointer to an EvidenceType structure to print the attributes of

  Returns: void, no return
*/
void printEvidence(EvidenceType *ev) {

    // Prints ID, Room name, and Device name
    printf("%4d | %16.16s | %8s | ", ev->id, ev->room, ev->device);   

    // Prints value
    printValue(ev->device, ev->value);
    
    // Converts seconds to clock time and prints it
    int hour = ev->timestamp / 3600;
    int minute = (ev->timestamp % 3600) / 60;
    int second = ev->timestamp - minute*60 - hour*3600;
    printf("%02d:%02d:%02d\n", hour, minute, second);
}

/*  
  Function: Copy Evidence
  Purpose:  Initializes a given EvidenceType structure with the same attributes of another given EvidenceType structure, making a copy.

  Parameters:
  Output: EvidenceType* dest  - a pointer to an EvidenceType structure to set attributes of
  Input:  EvidenceType* src   - a pointer to an EvidenceType structure to read attributes of 

  Returns: void, no return
*/
void copyEvidence(EvidenceType* dest, EvidenceType* src) {
    initEvidence(src->id, src->room, src->device, src->value, src->timestamp, dest);
}

/*  
  Function: Grow EvidenceArray
  Purpose:  Doubles the capacity of the given EvidenceArray.

  Parameters:
  Input/Output: EvidenceArray* evArr   - a pointer to an EvidenceArray structure to double the capacity of 

  Returns: void, no return
*/
void growEvidenceArray(EvidenceArray* evArr) {

    // Initializes new temporary EvidenceArray to have double the capacity
    int newCapacity = evArr->capacity*2;
    EvidenceArray temp;
    initEvidenceArray(&temp, newCapacity);

    // Copies all evidence into the temporary EvidenceArray
    for(int i=0; i < evArr->size; i++) {
        copyEvidence(&(temp.elements[i]), &(evArr->elements[i]));
    }

    // Points the elements array to the elements of the temporary EvidenceArray and updates capacity
    free(evArr->elements);
    evArr->elements = temp.elements;
    evArr->capacity = newCapacity;
}

/*  
  Function: Add Evidence
  Purpose:  Adds given EvidenceType to the elements attribute of the given EvidenceArray and maintains its sorted order.
            It is sorted first in decreasing order of room name alphabetically, then in increasing order of timestamp.
            
  Parameters:
  Input:        EvidenceType* src    - a pointer to an EvidenceType structure to add to the EvidenceArray structure
  Input/Output: EvidenceArray* dest  - a pointer to an EvidenceArray structure to add the new EvidenceType to

  Returns: void, no return
*/
void addEvidence(EvidenceArray* dest, EvidenceType* src) {

    // Grows the array if adding one more EvidenceType will be above the capacity
    if (dest->size == dest->capacity) {
        growEvidenceArray(dest);
    }
    
    int location;
    
    // Array has no evidence yet
    if(dest->size == 0){
        location = 0;

    } else {
        for(int i = 0; i < dest->size; i++) {
            // src room is equal to current element's room alphabetically
            if (strcmp(src->room, dest->elements[i].room) == 0){

                // src time is equal to or before current element's time
                if(src->timestamp <= dest->elements[i].timestamp){
                    location = i;
                    break;
                }

            // src room is after current element's room alphabetically
            } else if (strcmp(src->room, dest->elements[i].room) > 0){
                location = i;
                break;
            }

            // Last element, end of the array
            if(i+1 == dest->size){
                location = dest->size;
            }
        }
       
        // Shift elements to make space for new one
        for(int j = dest->size; j > location; j--){
            copyEvidence(&(dest->elements[j]), &(dest->elements[j-1]));
        }
    }
    
    // Copy evidence into the array at the insertion point
    copyEvidence(&(dest->elements[location]), src);
     
    // Increase size of array
    dest->size += 1;
}

/*  
  Function: Del Evidence
  Purpose:  Deletes the first EvidenceType from the given EvidenceArray's elements that has an ID corresponding to the given ID.

  Parameters:
  Input/Output: EvidenceArray* src  - a pointer to an EvidenceArray structure to delete the evidence from
  Input:        int id              - the ID corresponding to the evidence to remove

  Returns: C_OK as a success flag if evidence with id was removed
           C_NOK as an error code if evidence with id does not exist in the EvidenceArray
*/
int delEvidence(EvidenceArray* src, int id) {
    
    for(int i=0; i < src->size; i++) {
        if(src->elements[i].id == id) {
            
            for(int j = i; j < (src->size - 1); j++){
                copyEvidence(&(src->elements[j]), &(src->elements[j+1]));
            }
            // Decrease size of array by 1
            src->size -= 1;
            return C_OK;
        }
    }

    return C_NOK;
    
}

/*  
  Function: Print EvidenceArray
  Purpose:  Prints all evidence stored in the given EvidenceArray structure, formatted and with headers.

  Parameters:
  Input: EvidenceArray* evArr  - a pointer to an EvidenceArray structure to print the evidence in its elements attribute 

  Returns: void, no return
*/
void printEvidenceArray(EvidenceArray* evArr) {
    // Headers
    printf("\n%4s | %16s | %8s | %16s | %9s\n", "ID", "Room", "Device", "Value", "Timestamp");
    
    // Prints information of each EvidenceType 
    for(int i = 0; i < evArr->size; i++){
        printEvidence(&(evArr->elements[i]));
    }
}

/*  
  Function: Cleanup EvidenceArray
  Purpose:  Deallocates the dynamically allocated memory in the given EvidenceArray.

  Parameters:
  Output: EvidenceArray* evArr  - a pointer to an EvidenceArray structure to deallocate the memory of its elements attribute

  Returns: void, no return
*/
void cleanupEvidenceArray(EvidenceArray* evArr) {
    free(evArr->elements);
}

/*  
  Function: Print Value
  Purpose:  Prints and formats the given value with a conditional indication if it matches requirements from the given device.

  Parameters:
  Input: char* device  - the type of device used
  Input: float value   - the reading from the device

  Returns: void, no return
*/
void printValue(char* device, float value){ 

    // Prints value and indicates if it is high
    if(strcmp(device, "EMF") == 0) {
        if(value > TOO_HIGH) {
            printf("%9.1f%-s", value, " (HIGH) | ");
        } else {
            printf("%16.1f%-s", value, " | ");
        }
    
    // Prints value and indicates if it is cold
    } else if (strcmp(device, "THERMAL") == 0) {
        if(value < TOO_COLD) {
            printf("%9.2f%-s", value, " (COLD) | ");
        } else {
            printf("%16.2f%-s", value, " | ");
        }

    // Prints value and indicates the level of sound if it is high/low enough
    } else if (strcmp(device, "SOUND") == 0) {
        if(value < TOO_QUIET){
            printf("%6.1f%-s", value, " (WHISPER) | ");
        } else if(value > TOO_LOUD) {
            printf("%7.1f%-s", value, " (SCREAM) | ");
        } else {
            printf("%16.1f%-s", value, " | ");
        }
    }
}