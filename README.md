<h1 align="center" id="title">Cub3D</h1>

<p id="description">Recreate a Wolfenstein 2.5D game using raycasting and a low level graphics library</p>

<img src="https://github.com/tcampbel22/cub3d/blob/main/assets/ezgif-367baacdd0097.gif?raw=true" width="800" height="600" align="center">
  
<h2>🧐 Features</h2>

Here're some of the project's best features:

*   2.5D Raycasting
*   Animated Sprites
*   Minimap
*   Doors
*   Score

<h2>🛠️ Installation Steps</h2>

<p>1. Download</p>

```
git clone "this repository"
```

<p>2. Compile</p>

```
make bonus
```

<p>3. Run</p>

```
./cub3D map/lvl15.cub
```

<h2>About</h2>

This is project from the 42 Curriculum where myself and @Welhox built a 2.5D Raycasting game in C. 
The idea was to use low level programming to create the game from scratch and recreate the vibes of DOOM or the original Wolfenstein 3D. 
We created and parse different maps rendered textures created a dynamic minimap animated sprites and doors. 
The raycasting is made by using the DDA algorithm to render pixel by pixel each texture the result is a 3D looking world built on top of a 2D map.
As we added extra textures for both floors walls and ceilings we decided to multi thread in order keep the game smooth and playable. 

In the map provided in the instructions you have to catch the ducks in cages. 
You have a score in the bottom right of the screen but please note the ducks are hidden and can't be seen on the minimap so you need to find them yourself ;)

<h2>Controls</h2>

### Forward

```W or Up Arrow```

### Strafe

```A and D```

### Back

```S or Down Arrow```

### Pan

```Left or Right Arrow or use the mouse```

### Activate Door/Catch Duck

```E or left mouse click```

### Exit

```esc```

  
  
<h2>💻 Built with</h2>

Technologies used in the project:

*   MLX42/SFML
*   C

<h2>Addtional Screenshots</h2>

lvl1.cub
![Screenshot from 2024-09-17 11-22-27](https://github.com/user-attachments/assets/20db01ef-53dc-46bc-84a5-9f5453018080)
![Screenshot from 2024-09-17 11-23-03](https://github.com/user-attachments/assets/275fc002-77ea-45b3-a1c7-f1b4ef856118)

lvl2.cub
![Screenshot from 2024-09-17 11-23-16](https://github.com/user-attachments/assets/bc96a387-bfd7-4c94-866f-4c277f3fe88f)
![Screenshot from 2024-09-17 11-23-24](https://github.com/user-attachments/assets/6369a370-480a-4c3b-8411-8cdc2f076d2a)
![Screenshot from 2024-09-17 11-24-02](https://github.com/user-attachments/assets/0f58a78f-4313-4b27-a84f-cccdb71945bc)
![Screenshot from 2024-09-17 11-24-17](https://github.com/user-attachments/assets/bf6dcab3-be83-4bf1-97d1-719d45c0d7b5)

lvl3.cub
![Screenshot from 2024-09-17 11-24-41](https://github.com/user-attachments/assets/e939044e-7efc-4501-bf92-02cddeecc4ca)
![Screenshot from 2024-09-17 11-25-02](https://github.com/user-attachments/assets/65e435c5-feab-4445-a8e9-e1c4feca22a2)

lvl4.cub
![Screenshot from 2024-09-17 11-25-26](https://github.com/user-attachments/assets/dbd2a92d-a3bc-4d8d-ac70-d70351fdaa8d)
![Screenshot from 2024-09-17 11-25-41](https://github.com/user-attachments/assets/84ef99cb-3725-4b7f-a1a6-96565764f129)
![Screenshot from 2024-09-17 11-26-06](https://github.com/user-attachments/assets/28f41d57-d14c-4bd2-8c9a-b56103c98bcf)

lvl5.cub
![Screenshot from 2024-09-17 11-26-20](https://github.com/user-attachments/assets/c7dae9ea-266f-4679-8553-15d679d8761f)
![Screenshot from 2024-09-17 11-26-47](https://github.com/user-attachments/assets/53cb655c-0540-400f-a682-d6771ca516c8)
![Screenshot from 2024-09-17 11-26-53](https://github.com/user-attachments/assets/1bd015e8-df36-4029-99ae-785e0513984c)

lvl6.cub
![Screenshot from 2024-09-17 11-27-08](https://github.com/user-attachments/assets/c0eac689-43ba-4aca-9aa9-f652eff9d01d)
![Screenshot from 2024-09-17 11-27-16](https://github.com/user-attachments/assets/fe9213bb-f1e6-4770-bb92-66ca4a6f093b)
![Screenshot from 2024-09-17 11-27-35](https://github.com/user-attachments/assets/8ff0b2c0-9ee2-4aa7-9a24-e160363b350a)




