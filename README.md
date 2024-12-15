## **Asteroid Attack: Rocket Survival Game**

![Untitled video - Made with Clipchamp](https://github.com/user-attachments/assets/57e908f2-7d57-4a41-b311-8d9188e71022)


Asteroid Attack is a **2D arcade-style game** developed using **C++** and **SFML**. The player controls a space rocket that must shoot projectiles to destroy falling asteroids while avoiding collisions. The game features dynamic difficulty scaling, score tracking, and a restart mechanism, offering an engaging and challenging experience.

---

**Features**

1. **Rocket Movement**: Smooth left/right movement with boundary checks to keep the rocket within the screen.  
2. **Projectile Shooting**: Controlled projectile shooting with cooldown mechanics for balanced gameplay.  
3. **Asteroid Spawning and Movement**: Randomized asteroid spawning with increasing speed based on score.  
4. **Collision Detection**:  
   - **Projectile vs. Asteroid**: Increases score when a hit occurs.  
   - **Rocket vs. Asteroid**: Ends the game when a collision happens.  
5. **Score Tracking**: Real-time score updates displayed on the screen.  
6. **Game Over and Restart**: A "Game Over" screen with an option to restart by pressing the `R` key.  
7. **Scalable Difficulty**: Asteroids progressively fall faster as the player’s score increases.  

---

 # **Directory Structure**

![image](https://github.com/user-attachments/assets/927b73f0-5dad-4ba2-b328-be0f98a82003)

---

# **Installation**

Step 1: Clone the Repository  
Clone the project repository to your local system:  

`git clone https://github.com/your-username/SpaceRocketGame.git
`cd SpaceRocketGame


Step 2: Create a Build Directory  
Navigate to the project directory and create a build directory:  

`mkdir build
`cd build

Step 3: Configure the Build Using CMake  
Run the following commands to configure and build the project:

`cmake ..
`make


Step 4: Run the Game  
Execute the compiled game:

`./SpaceRocketGame


---

# **How the Game Works**

1. **Rocket Controls**  
   - Move the rocket using the left and right arrow keys.  
   - Shoot projectiles by pressing the spacebar (with cooldown).

2. **Game Mechanics**  
   - Asteroids spawn randomly at the top and move downward.  
   - Use projectiles to destroy asteroids and earn points.  
   - Avoid collisions with asteroids to keep playing.  
   - The game ends when your rocket collides with an asteroid.

3. **Restarting the Game**  
   - Press the R key after the game ends to restart.

---

# **Code Structure and Design**

1. **Core Features**  
   - **Texture and Sprite Management**: Handles loading and rendering of game assets like rocket and asteroid sprites.  
   - **Game Loop**: A continuous loop to process user inputs, update game states, and render graphics.  
   - **Projectile and Asteroid Management**: Efficient handling of movement and collision detection for projectiles and asteroids.  
   - **Score Tracking and UI**: Displays the player’s score on the screen using SFML’s `sf::Text`.

2. **Collision Detection**  
   - Uses `getGlobalBounds()` to check overlapping bounding boxes for accurate collision detection.

3. **Difficulty Scaling**  
   - Asteroid speed increases with the player’s score, making the game progressively harder.

4. **Game Over and Restart**  
   - Clears all active projectiles and asteroids.  
   - Resets the score and game state for a fresh start.

---

# **Challenges and Solutions**

1. **Collision Detection**  
   - Implemented bounding box collision checks using `getGlobalBounds()`.  
   - Ensured proper game state reset when restarting.

2. **Performance Optimization**  
   - Removed off-screen projectiles and destroyed asteroids to conserve memory.  
   - Limited the frame rate to 60 FPS for consistent gameplay.

3. **Difficulty Scaling**  
   - Dynamically adjusted asteroid speed based on the player’s score to enhance gameplay challenge.

---

# **Future Improvements**

- **Power-Ups**: Introduce features like shields, multi-shot projectiles, or speed boosts.  
- **Sound Effects**: Add sounds for shooting, collisions, and explosions.  
- **Main Menu**: Create a main menu with options for starting the game, adjusting settings, and viewing high scores.  
- **Level System**: Implement a system where levels increase with progressively harder challenges.

---

# **Why I Chose This Project**

This project was an opportunity to:  
- Apply C++ and game development principles in a practical setting.  
- Gain experience with SFML, a powerful library for 2D game development.  
- Explore topics like collision detection, object management, and user input handling.  
- Build an interactive, fun, and scalable game from scratch.

---

# **Acknowledgements**

- **SFML Library**: For its easy-to-use APIs for graphics, audio, and input handling.  
- **CMake**: For simplifying the build process across different platforms.  
- **YouTube/GameDev Resources**: For inspiration and guidance on 2D game development techniques.
