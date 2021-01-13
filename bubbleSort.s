@*****************************************************************************
@Name:      Jacob Tredwell
@Program:   bubbleSort.s
@Class:     CS 3B
@Date:      12/12/2020 
@Purpose: Sorts integers using BubbleSort Algorithm

@1) +bubbleSort
	@ Returns sorted array  
	@ R0: Contains pointer that points to the array of 200,000 integers
	@ R1: Contains the number of integers in array
	@ LR: Contains the return address



/*****************************bubbleSort***********************************************************************/
	.data
	.text

	.global	bubbleSort

bubbleSort:
	
	@Preserve AAPCS Required Registers
	push	{r4-r8, r10, r11}
	push 	{sp}
	push	{lr}


	mov	r4, #0		@i	
	mov	r5, #0   	@j
	mov   	r8, #0   	@temp
	

outerloop:

	cmp 	r4, r1		
	beq	endloop
	
	mov	r9, #0		@resets r9 (4x holder) to 0
	mov	r5, #0		@resets j to zero

innerloop:

	sub	r6, r1, r4	@r6 = length - i
	sub	r6, r6, #1	@r6= length - i -1

	cmp	r5, r6		@compare r5 and r6
	addge 	r4, r4, #1	@i++
	bge	outerloop	@branch to outer loop if J >= length - i - 1

	
	

	ldr	r8, [r0,r9]	@r8 = a[j] and temp
	add	r9, r9, #4	@r9 holds multiple of 4
	ldr	r7, [r0,r9]	@r7 = a[j+1]

	add 	r5, r5, #1	@j++

	cmp	r7, r8		@compare r7 and r8(a[j+1] and a[j]
	blt	swap		@if a[j+1] < a[j] then swap

	
	
	b 	innerloop	@branch back to inner loop

swap:
	sub	r9, r9, #4	@decrement multiple by 4
	str 	r7, [r0,r9]	@a[j] = a[j+1]
	add	r9, r9, #4	@re-increment by 4
	str	r8, [r0,r9]	@a[j+1] = temp

	
	b	innerloop	@branch back to innerloop

endloop:

	@Restoring our AAPCS mandated Registers
	pop	{lr}
	pop 	{sp}
	pop	{r4-r8, r10, r11}


	bx 	lr


	.end



