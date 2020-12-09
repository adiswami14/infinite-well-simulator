# InfiniteWellSimulator

**Author**: Adithya Swaminathan - [`adithya9@illinois.edu`](mailto:example@illinois.edu)

[Imgur](https://imgur.com/MvYkqVt)
[img]https://i.imgur.com/MvYkqVt.mp4[/img]

### Overview
The Infinite Well Simulator is my version of the famous "particle in a box" simulation, the idea of which can be seen [here](https://chem.libretexts.org/Bookshelves/Physical_and_Theoretical_Chemistry_Textbook_Maps/Supplemental_Modules_(Physical_and_Theoretical_Chemistry)/Quantum_Mechanics/05.5%3A_Particle_in_Boxes/Particle_in_a_1-Dimensional_box). It allows the user full control over all the properties of the simulation, and then see the results of their actions on a quantum scale.

### Dependencies
Running Infinite Well Simulator will require:
- MacOS
- CMake
- Cinder v0.9.2 and above

### Get It Running
- If you do not have Cinder, download it [here](https://libcinder.org/download)
- Clone the repository using
```git clone https://github.com/uiuc-fa20-cs126/final-project-adiswami14.git```
- Build and run the project from CLion

### Documentation
This project follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) with Doxygen-style
documentation. Learn more about Doxygen [here](http://www.doxygen.nl/).

### How To Play
This simulation is fully keyboard based.

| Key            | Action                            |
|:--------------:|:---------------------------------:|
| SPACE          | Toggle instructions               |
| D              | Switch between light/dark modes   |
| UP / DOWN      | View simulation information       |
| LEFT / RIGHT   | Edit particle energy state        |
| PERIOD / COMMA | Edit particle mass                |
| A / S          | View expected values              |
- The user can also edit the length of the well itself by just positioning their cursor near one of the edges and dragging in either direction.
