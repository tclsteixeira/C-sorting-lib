################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bubblesort.c \
../src/bubblesortll.c \
../src/bucketsort.c \
../src/combsort.c \
../src/countingsort.c \
../src/heapsort.c \
../src/insertionsort.c \
../src/insertionsortll.c \
../src/introsort.c \
../src/linkedlist.c \
../src/llsort.c \
../src/main.c \
../src/mergesort.c \
../src/mergesortll.c \
../src/quicksort.c \
../src/quicksortll.c \
../src/radixsortlsd.c \
../src/radixsortmsd.c \
../src/radixsortstr.c \
../src/selectionsort.c \
../src/shellsort.c \
../src/sort.c \
../src/timsort.c \
../src/treesort.c \
../src/twayquicksort.c 

C_DEPS += \
./src/bubblesort.d \
./src/bubblesortll.d \
./src/bucketsort.d \
./src/combsort.d \
./src/countingsort.d \
./src/heapsort.d \
./src/insertionsort.d \
./src/insertionsortll.d \
./src/introsort.d \
./src/linkedlist.d \
./src/llsort.d \
./src/main.d \
./src/mergesort.d \
./src/mergesortll.d \
./src/quicksort.d \
./src/quicksortll.d \
./src/radixsortlsd.d \
./src/radixsortmsd.d \
./src/radixsortstr.d \
./src/selectionsort.d \
./src/shellsort.d \
./src/sort.d \
./src/timsort.d \
./src/treesort.d \
./src/twayquicksort.d 

OBJS += \
./src/bubblesort.o \
./src/bubblesortll.o \
./src/bucketsort.o \
./src/combsort.o \
./src/countingsort.o \
./src/heapsort.o \
./src/insertionsort.o \
./src/insertionsortll.o \
./src/introsort.o \
./src/linkedlist.o \
./src/llsort.o \
./src/main.o \
./src/mergesort.o \
./src/mergesortll.o \
./src/quicksort.o \
./src/quicksortll.o \
./src/radixsortlsd.o \
./src/radixsortmsd.o \
./src/radixsortstr.o \
./src/selectionsort.o \
./src/shellsort.o \
./src/sort.o \
./src/timsort.o \
./src/treesort.o \
./src/twayquicksort.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/bubblesort.d ./src/bubblesort.o ./src/bubblesortll.d ./src/bubblesortll.o ./src/bucketsort.d ./src/bucketsort.o ./src/combsort.d ./src/combsort.o ./src/countingsort.d ./src/countingsort.o ./src/heapsort.d ./src/heapsort.o ./src/insertionsort.d ./src/insertionsort.o ./src/insertionsortll.d ./src/insertionsortll.o ./src/introsort.d ./src/introsort.o ./src/linkedlist.d ./src/linkedlist.o ./src/llsort.d ./src/llsort.o ./src/main.d ./src/main.o ./src/mergesort.d ./src/mergesort.o ./src/mergesortll.d ./src/mergesortll.o ./src/quicksort.d ./src/quicksort.o ./src/quicksortll.d ./src/quicksortll.o ./src/radixsortlsd.d ./src/radixsortlsd.o ./src/radixsortmsd.d ./src/radixsortmsd.o ./src/radixsortstr.d ./src/radixsortstr.o ./src/selectionsort.d ./src/selectionsort.o ./src/shellsort.d ./src/shellsort.o ./src/sort.d ./src/sort.o ./src/timsort.d ./src/timsort.o ./src/treesort.d ./src/treesort.o ./src/twayquicksort.d ./src/twayquicksort.o

.PHONY: clean-src

