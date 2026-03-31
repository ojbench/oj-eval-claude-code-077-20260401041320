# CrossArray Implementation - Problem 077

## Solution Summary

Successfully implemented a 2D jagged array (CrossArray) class in C++ that manages dynamic arrays of varying lengths.

## Final Score: 100/100

All test groups passed:
- ✓ Constructor, Destructor, InsertArrays (30%)
- ✓ At function (10%)
- ✓ Copy Constructor (15%)
- ✓ AppendArrays (15%)
- ✓ WhichGreater & IsSame (10%)
- ✓ AtArray (5%)
- ✓ DoubleCrossLength (15%)

## Key Implementation Details

### Data Structure
- Used a struct `ArrayInfo` to store each 1D array's pointer and size
- Main class stores an array of `ArrayInfo` objects
- Tracked `maxLines` (capacity) and `currentCount` (current number of arrays)

### Important Functions
1. **Constructor**: Allocates array of ArrayInfo with all data pointers initialized to nullptr
2. **Copy Constructor**: Deep copy of all arrays and their elements
3. **InsertArrays**: Adds new array, returns false if capacity exceeded
4. **AppendArrays**: Extends existing array by allocating new memory, copying old data, then new data
5. **WhichGreater**: Counts total elements in both objects, returns the larger one (or current if equal)
6. **IsSame**: Compares array pointers to check if same memory space
7. **DoubleCrossLength**: Allocates new ArrayInfo array with 2x capacity, transfers pointers
8. **AtArray**: Returns const pointer to array at index
9. **At**: Returns reference to element at [i][j]
10. **Destructor**: Properly frees all allocated memory

### Memory Management
- Used `new[]` and `delete[]` for dynamic arrays
- Ensured no memory leaks by tracking all allocations
- In DoubleCrossLength, only deleted the ArrayInfo array (not the data arrays) since pointers were transferred

## Submission Notes

**Important Discovery**: This OJ problem requires direct code submission with `language: "cpp"`, not git submission.
The `language: "git"` submission type did not work properly for this problem - it treated the git URL as literal code content.

## Files in Repository
- `src.hpp` / `CrossArray.hpp`: Main implementation file
- `test.cpp`: Local test file for validation
- `.gitignore`: Prevents build artifacts from being committed

## Submission ID
Final successful submission: 767038
