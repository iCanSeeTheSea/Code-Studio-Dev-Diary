# My Dev Diary

#### yay! coding and stuff

---
### Contents

- [C++ basics](#c++-basics) `16/10/2023`
- [Classes and Pointers](#Classes-and-Pointers) `21/11/2023`
- [I Hate Vectors](#I-Hate-Vectors) `28/01/24`
- [A Single Button Game](#A-single-button-game...) `16/02/24`

---

## C++ Basics 
`16/10/2023`

> ### Hello World!
> ![script to print hello world in c++](/assets/c++basics/helloworld.png) 
> 
> My first ever C++ program! By looking at the c++ docs and a few basic code examples, I was able to figure out the very basic boilerplate syntax for a simple program. Having dabbled in C before, `#include <iostream>` was almost expected, being similar to `#include <stdio.h>` (a quick look at the template files for a c++ unreal project suggests that more things with header files will happen in the future :3).
> 
> Other than that, everything else was fairly straightforward (as expected from a hello world program), again, strictly typed functions were expected. 

> ### Sorting Bubbles
> ![simple bubble sort script in c++](/assets/c++basics/bubbles.png)
> 
> After conquering the very basics of "hello world", I decided to attempt a bubble sort program to try out using for loops, conditionals, and arrays.
> 
> The for loop and if statement structure is identical to both C and C#, so there was no trouble there - the new feature that I was introduced to in this was the syntax for static arrays in c++ (`type arr[n]`)  
> 
> I had a bit of trouble with array indexing, but some fiddling about with the for loops fixed it (I'm not 100% sure how I fixed it but it works so yay) - also for some reason in this one the compiler wanted me to use ```int main(){return 0;}```

> ### A Quick Refresher 
> Last week a friend sent me this image, with no context - so naturally I decided to code the correct solution in C++!
![simple task to fix wrong pseudocode](/assets/c++basics/pseudo.png)
> ![code written to fix pseudocode](/assets/c++basics/psuedo-trans.png)
>
> It's a simple program, but this was a couple of days after I did the other bits, so it was a good refresher of the basics

## Classes and Pointers 
`21/11/2023`

### Turing Interpreter
After watching the CT4TOGA videos up to pointers, I decided to revisit an [old project](https://replit.com/@iCanSeeTheSea/TuringInterpreter) that I had never managed to finish properly in Python, and try it again in C++. 
This was implementing a simple programming interface for a Turing machine. In the Python version, I used a list to represent the tape, and used a variable to store an index for the head, however, in c++ I wanted to try and use an array for the tape and a pointer to a position in the array as the head.

Note: the c++ project can be found [here](https://github.com/iCanSeeTheSea/TuringInterpreterV2)

Note 2: a file containing the code at the time of writing this can be found [here](/assets/Classes%20and%20Pointers/TuringInterpreter/TuringInterpreter.cpp)

> #### Input
> First, I decided to implement the input and output for the program. The format of the input should be `<variable declaration> : <script>` with a single space between each character, for example `y = 3 x = 4 : x + y` (or `: 3 + 4` if no variables are used). In Python, the input was done as simply `tape = [""] * 3 + input().split(" ")` - but the input in c++ was slightly more verbose...
> 
> ![code for writing user input to tape](/assets/Classes and Pointers/TuringInterpreter/tape-input.png)
> 
> One thing that this code achieves over the python version is ensuring that the input for each 'cell' of the tape is only three characters long, controlled by the for loop on line 118. I encountered a couple of problems when implementing this - the first of which was that when checking for the length of a block of characters, the code would attempt to access a value beyond the end of the string, which I fixed by adding `input += " "`(line 112). This meant that in a scenario when a value not indexed by the string would be accessed, a space character would be returned instead, causing the for loop to break and the program to continue as normal.
> 
> The second problem was when performing the comparison `input[i] != ' '`(line 120). Initially I had written it as `input[i] != " "`, however in C++ `" "` represents a value of type `char`, however input[i] is a pointer to a string, whose value cannot be compared to a `char` - so I had to use `' '` to represent a single character string instead.
> 
> I also learnt that to take a whole line as a string input, use of the function `getline()` is required.

> #### Output
> The output was fairly simple, all it consists of is reading each value of the tape and adding them to a string formatted in a way for the output to look like a 'tape', and drawing the head in the correct position.
> 
> ![code for outputting the contents of the tape](/assets/Classes%20and%20Pointers/TuringInterpreter/tape-output.png)
> 
> The function is passed a pointer to the start of the tape (`string* cell`) and a pointer representing the current position of the head (`string* head`). I used pointers here as to not create a copy of the whole array, and as the head was already stored as a pointer, using a pointer for getting each value from the array made it very easy to check where to put the `^` for the head
> 
> To write each cell in line 2, the data from the tape is padded to be centered correctly no matter how many characters long the cell is.

> #### Function Pointers
> In order to write a state transition function for the turing machine, I looked into how to use function pointers. The idea behind this was to have several functions - one for each possible state of the machine - that would all have the same parameter and return types, and to have a state transition function that could return the right function for the current state which could then be called using the same code for each function.
> 
> ![an example of function pointers in c++](/assets/Classes%20and%20Pointers/TuringInterpreter/function-pointers.png)
> 
> I tested that this code could be properly used with the following code:
> 
> ![an example of using function pointers in c++](/assets/Classes%20and%20Pointers/TuringInterpreter/function-pointers-use.png)
> 
> The syntax for this is a little complicated, so if I have to use it more than once I will probably use typedefs or type aliasing to simplify it a little.
> 
> I also haven't tested this how I want to use it, so I may end up using a different approach.

# I Hate Vectors
`28/01/24`

Taking a break from learning C++, for the Global Game Jam my team ([Dino Beans](https://globalgamejam.org/games/2024/greg-beach-8)) decided to use Unity create our game. As part of the game, I was tasked with creating a set of NPCs that would be able to play a game of Frisbee with each other.

> #### Chasing Frisbees
> 
> using Unity's inbuilt `Rigidbody.AddForce()` function made it easy to have the Frisbee thrown with a realistic arc. However, the challenge came in giving the Frisbee a random horizontal offset that it could be thrown in, and then having the catcher move to the correct place to catch the Frisbee.
> 
> In this diagram, `A` is the catcher, `B` is the thrower, and `C` is the point that the Frisbee should be caught at.
> ![a diagram of the vectors involved in calculating the point to catch the Frisbee](/assets/i%20hate%20vectors/vectordiagram.png)
> To calculate the vector to with which to translate A to point C, I knew I needed to calculate the vector of the horizontal range of the projectile from the distance and direction of the Frisbee's motion.
> 
> To calculate range (as a distance, not a vector) I used the equation for the horizontal range of a projectile: $R = \frac{v_{0}^{2}\cdot sin2\alpha}{g}$  
> where:  
>  $R$ is the horizontal range  
>  $v_{0}$ is the initial velocity  
>  $\alpha$ is the angle of the initial velocity from the horizontal plane (in radians as that's what Unity's trig functions take as parameters)  
>  $g$ is the acceleration due to gravity (I used `9.8`)
> 
> Which I implemented as follows:  
> ![code for the function to calculate horizontal range of a projectile](/assets/i%20hate%20vectors/flightrange.png)
> 
> The full function to calculate the initial velocity of the Frisbee and use the `AddForce` function to throw it is as follows:  
> ![function for throwing the frisbee](/assets/i%20hate%20vectors/throwfunction.png)
> 
> At first, I wasn't calculating the horizontal and vertical components of the velocity separately (lines 63-66) but just adding both the horizontal and vertical offsets to the same Vector. However, when using that method some maths was wrong, I believe it was to do with where I was normalising vectors before multiplying them by the impulse - so I split the calculations into the horizontal and vertical components, which fixed the problem.
> 
> The other major problem I encountered was calculating the vector **R**, in order to work out where to move the catcher to. Initially I was trying to work out the angle between the vector **b** - **a** and **R**, then using that angle and the magnitude of the vector (the horizontal distance travelled by the Frisbee) calculate **R**. After many hours of suffering in vector math hell (and after splitting the initial velocity calculation into its horizontal and vertical components), I realised that I didn't need to calculate another angle at all, as I already had a vector representing the direction that the Frisbee was thrown in, being the horizontal velocity: by normalising the horizontal velocity and multiplying that by the distance, I had the vector **R**.
>
> `Vector3 R = Vx.normalized * throwRange;`
> 
> Calculating the position vector for the catcher to move to was then as simple as adding **R** to the position vector of the thrower.
> 
> Here is an (extremely compressed) example of the game working.
> ![Video of working Frisbee game](/assets/i%20hate%20vectors/frisbeegame.gif)

# A Single Button Game...
`16/02/24`

> #### ... In a single line of code
> The game is hosted on [my GitHub Pages site](https://icanseethesea.github.io/)
![single line of code for the button game](/assets/single%20line/button%20game.png)
> Ok cool that's the code.
> 
> But slightly more seriously, I enjoy attempting to create small programs in one line as it forces me to learn new features of a language that I wouldn't have known about otherwise. For example, to set the text content and colour of the button and text I had to set a list of the variables I wanted to change to a list of the values to change them too, i.e. `[varA, varB, varC] = [valueA, valueB, valueC]`. This way, I was able to return multiple values from the anonymous function and set the variables all in one statement.
> 
> The only part that I don't fully understand how it works is this: `Object.entries(vars).forEach(v => document.documentElement.style.setProperty(v[0], v[1]))`. I understand that it's taking a dictionary`vars`, then setting the style properties specified by the keys to their respective values... Now I was going to write about how I didn't know what the `Object.entries()` syntax does, but as I was writing it I realised that JS objects and dictionaries are the same thing, and that the function would just be returning a 2D list of the key-value pairs for the foreach function to be called upon.
> 
> The other features that made this possible in a single line (obviously without using semicolons as delimiters because that would be cheating) were nested ternary operators and JavaScript's *absolutely wonderful* anonymous function syntax (I hate it so much).