@*****************************************************************************
@Name:      Jacob Tredwell
@Program:   insertionSort.s
@Class:     CS 3B
@Date:      12/12/2020 
@Purpose: Sorts integers using insertionSort Algorithm

@1) +insertionSort
	@ Returns sorted array  
	@ R0: Contains pointer that points to the array of 200,000 integers
	@ R1: Contains the number of integers in array
	@ LR: Contains the return address



/*****************************insertionSort***********************************************************************/
	.data
	.text

	.global	insertionSort

insertionSort:
	
	@Preserve AAPCS Required Registers
	push	{r4-r8, r10, r11}
	push 	{sp}
	push	{lr}

	@----------------------------------------------------
	
	
isort:

	mov 	r4, #1 			@ i = 1

iloop: @ for-loop as while loop

	cmp 	r4, r1 			@ i - n
	bge 	iloopend 		@ i >= n => loopend

@Searching and Sorting

	add	r10, r0, r4, LSL #2 	@ temp = &array[4*i]
	ldr 	r10, [r10] 		@ temp = array[4*i]
	sub 	r5, r4, #1 		@ j = i - 1

jloop: @ while-loop

	cmp 	r5, #0 			@ j >= 0 ?
	blt 	jloopend
	add 	r11, r0, r5, LSL #2 	@ r9 <- &array[4*j]
	ldr 	r11, [r11] 		@ r9 <- array[4*j]
	cmp 	r10, r11 		@ temp < array[4*j] 
	bge 	jloopend
	add 	r8, r0, r5, LSL #2
	add 	r8, r8, #4 		@ r8 <- &array[4*(j+1)]
	str 	r11, [r8] 		@ a[j+1] <- a[j]
	sub 	r5, r5, #1 		@ j <- j - 1
	b 	jloop

@ end jloop


jloopend:
	add 	r5, r5, #1 		@ j <- j+1
	add 	r8, r0, r5, LSL #2 	@ r8 <- &array[4*(j+1)]
	str 	r10, [r8] 		@ a[j+1] <- temp
	add 	r4, r4, #1 		@ i++
	b 	iloop
		
@ end iloop
iloopend:





	@Restoring our AAPCS mandated Registers
	pop	{lr}
	pop 	{sp}
	pop	{r4-r8, r10, r11}


	bx 	lr


	.end


