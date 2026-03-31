#ifndef CROSSARRAY_HPP
#define CROSSARRAY_HPP

namespace sjtu {
    class CrossArray {
    private:
        struct ArrayInfo {
            int* data;
            int size;

            ArrayInfo() : data(nullptr), size(0) {}
        };

        ArrayInfo* arrays;
        int maxLines;
        int currentCount;

    public:
        explicit CrossArray(int lines) : maxLines(lines), currentCount(0) {
            arrays = new ArrayInfo[maxLines];
        }

        CrossArray(const CrossArray& o) : maxLines(o.maxLines), currentCount(o.currentCount) {
            arrays = new ArrayInfo[maxLines];
            for (int i = 0; i < currentCount; i++) {
                if (o.arrays[i].data != nullptr) {
                    arrays[i].size = o.arrays[i].size;
                    arrays[i].data = new int[arrays[i].size];
                    for (int j = 0; j < arrays[i].size; j++) {
                        arrays[i].data[j] = o.arrays[i].data[j];
                    }
                }
            }
        }

        CrossArray& WhichGreater(CrossArray& o) {
            int thisCount = 0;
            int oCount = 0;

            for (int i = 0; i < currentCount; i++) {
                thisCount += arrays[i].size;
            }

            for (int i = 0; i < o.currentCount; i++) {
                oCount += o.arrays[i].size;
            }

            if (thisCount >= oCount) {
                return *this;
            } else {
                return o;
            }
        }

        bool IsSame(const CrossArray& o) {
            return arrays == o.arrays;
        }

        bool InsertArrays(const int* Input, int size) {
            if (currentCount >= maxLines) {
                return false;
            }

            arrays[currentCount].size = size;
            arrays[currentCount].data = new int[size];
            for (int i = 0; i < size; i++) {
                arrays[currentCount].data[i] = Input[i];
            }
            currentCount++;
            return true;
        }

        void AppendArrays(const int* Input, int Line, int size) {
            int oldSize = arrays[Line].size;
            int newSize = oldSize + size;

            int* newData = new int[newSize];

            for (int i = 0; i < oldSize; i++) {
                newData[i] = arrays[Line].data[i];
            }

            for (int i = 0; i < size; i++) {
                newData[oldSize + i] = Input[i];
            }

            delete[] arrays[Line].data;
            arrays[Line].data = newData;
            arrays[Line].size = newSize;
        }

        void DoubleCrossLength() {
            int newMaxLines = maxLines * 2;
            ArrayInfo* newArrays = new ArrayInfo[newMaxLines];

            for (int i = 0; i < currentCount; i++) {
                newArrays[i].data = arrays[i].data;
                newArrays[i].size = arrays[i].size;
            }

            delete[] arrays;
            arrays = newArrays;
            maxLines = newMaxLines;
        }

        const int* AtArray(int i) {
            return arrays[i].data;
        }

        int& At(int i, int j) {
            return arrays[i].data[j];
        }

        ~CrossArray() {
            for (int i = 0; i < currentCount; i++) {
                if (arrays[i].data != nullptr) {
                    delete[] arrays[i].data;
                }
            }
            delete[] arrays;
        }
    };
}

#endif
