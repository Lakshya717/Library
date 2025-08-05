## What are completely generic functions?

C is a strictly typed language and very basic design, and that's what makes it fast. However functions must be defined while keeping in mind of the data type being involved.

Let's say I need to swap values of two variables, regardless of their type (but both must have samy data type) It can be anything: `int`, `float`,`double` or even a `char`.

How should we proceed with such idea? Should we make functions for each dtype and fine tune for all the various data type or is there an even better approach?

 
**_The ANSI C Programming Language by Brian W. Kernighan, Dennis M. Ritchie_**

This book is considered THE reference for C, and answer to our question is in a simple section of this book;

![Section B.3(Page 228)](./Screenshot%202025-08-05%20004922.png)
Section B.3(Page 228)

This section shows some of the functions included with `string.h`. And with theese functions we can completely avoid dealing with data types. 

For example, here, for the swap function, We will directly deal with memory and copy-paste memory contents of one variable to another one.