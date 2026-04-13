1. Coordinate Frame Transformation
Learning: I learned how to apply Linear Algebra to robotics. Specifically, how to use a Rotation Matrix to convert local camera data into a global "World Frame." I also practiced converting degrees to radians to interface with standard mathematical libraries.

Challenges: The main difficulty was ensuring the order of operations—applying the rotation to the local coordinates before adding the rover's global position. Reversing this order results in the object being placed in the wrong part of the map.

2. Morse Code Deciphering
Learning: This task taught me how to implement String Tokenization. I learned how to split a continuous signal into individual "tokens" (dots and dashes) and match those tokens against a Morse alphabet lookup table to reconstruct plain text.

Challenges: Handling the distinction between character spaces and word spaces was tricky. I had to ensure the logic was robust enough to handle the "/" symbol as a word delimiter without crashing the parsing loop.

3. Progressive Cipher Decoder
Learning: I explored the Progressive Caesar Cipher, where the shift value increases based on the letter's position. I learned how to use modular arithmetic to create a circular alphabet, ensuring that shifts correctly wrap around from 'A' to 'Z' and vice versa.

Challenges: The biggest challenge was handling negative results in modular arithmetic. I had to implement a specific mathematical "wrap-around" formula to ensure the character index always stayed within the valid 0-25 range.

4. Manipulator Arm Optimization
Learning: I implemented Dynamic Programming (DP) to solve a resource-constrained optimization problem. I learned to represent the rover arm's physical state and calculate the "Minimum Wear Cost" by comparing multiple possible moves across a sequence of targets.

Challenges: Managing the stability constraints (like the allowed difference between the inner and outer segments) while simultaneously minimizing cost was complex. I had to use a state-tracking table to avoid redundant calculations and find the globally optimal path.

5. Planetary Rover Navigation Logic
Learning: I learned about Rigid Body Transformations in 3D space. This involved understanding how a camera mounted rigidly on a chassis inherits the rover's movement, and how to mathematically chain these transforms together to maintain an accurate world map.

Challenges: Visualizing the three-dimensional relationship between the camera lens, the rover body, and the Martian surface was difficult. It required careful verification of the sine and cosine functions to ensure the rover's orientation (yaw) was correctly applied.

6. System Automation & Logging (Bash)
Learning: I learned Linux System Administration and automation. I practiced directory management, file permissions, text processing with filters, and how to automate system tasks like logging internal errors and scheduling power-saving shutdowns.

Challenges: Using "Here-Documents" (EOF) to write multi-line logs within a script was a new concept. I had to be precise with the shell syntax to ensure the automation didn't stop prematurely or write data to the wrong directory.
