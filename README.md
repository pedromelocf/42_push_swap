<div align="center">

# 42_push_swap

<h5>
 This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.
</h5>

<img src="https://github.com/pedromelocf/42_utilities/blob/master/push_swape.png" />

![](https://komarev.com/ghpvc/?username=pedromelocf)


 In push swap project, we are deply introduced to very important topics in software development as:
  
• Time complexity in sorting algorithms;

• Data structures as LIFO (last in first out) and FIFO (first in first out). In our case, the two stacks that we are allowed to use are FIFO.

• Binary trees;

• Abstract hability to create and improve algorithms.

</br>

<h2> Project Rules </h2>

<div align="justify">

Basically, our program will be executed as follows:

./push_swap 87 98 0 12

It can take n arguments:

You have 2 stacks named a and b.
• At the beginning:

◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.

◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a with least moviments as possible. To do so you have the following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time 

</div>

</br>

<h2> Grade </h2>

<img src="https://github.com/pedromelocf/utilities/blob/master/100_grade.png" />

<h2> Score and Stack Ordering Visualizer </h2>

<p align="justify"> 100 elements in stack A with 200 possibilites:</p>

![100 elements](https://github.com/pedromelocf/42_utilities/blob/master/100elements.png)

<br>

<p align="justify"> 500 elements in stack A with 200 possibilites:</p>

![500 elements](https://github.com/pedromelocf/42_utilities/blob/master/500elements.png)

<br>

<p align="justify"> 500 elements in push swap visualizer:</p>

![Movements GIF](https://github.com/pedromelocf/42_utilities/blob/master/movements.gif)

<br>

<h2> Curious about my algorithm? Send me hello! </h2>

</div>
