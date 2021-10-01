## Floyd Cycle Detection Algorithm in Linked list

To find whether a linked list contains a cycle or not, we use the Floyd Cycle Detection Algo.
It is a 2 Pointer approach (`fast` and `slow` or hare and tortoise)

Initially, we place both the pointers at the head of the linked list.
Then we increment the `fast` pointer by two steps and the `slow` pointer by one step.

If a cycle exists, both the pointers will meet because before the meeting, `fast` is 1 places **_behind_** `slow` (so that when `fast` moves ahead 2 places and `slow` moves ahead 1 place, they meet).
This is only possible when a cycle exists.

The approach is highlighted in the attached code file with null check conditions.