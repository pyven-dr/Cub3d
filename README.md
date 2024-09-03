# Cub3D
## My first RayCaster with miniLibX
### This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.
## Screenshots
![Screenshot from 2024-09-03 21-32-12](https://github.com/user-attachments/assets/f3706fb2-d724-4330-91ac-be61d96c78e7)
![Screenshot from 2024-09-03 21-33-33](https://github.com/user-attachments/assets/a8c19681-b19f-406b-857d-49a41579b139)

## How to use

Clone the project
```bash
git clone https://github.com/pyven-dr/fdf.git
```

Compile
```bash
make
```

Launch with a map
```bash
./fdf map.fdf
```

## Map example

```bash
NO ./textures/BRICK_1A.xpm
SO ./textures/BRICK_2B.xpm
WE ./textures/BRICK_3D.xpm
EA ./textures/CONCRETE_3C.xpm
DO ./textures/door.xpm

F 254,254,255
C 100,10,10

        1111111111111111111111111
        1002000000110000000000001
        1011000001110000000000001
        1001000000200N00000000001
111111111011000001110000000000001
100000000011000001112111111111111
11112111111111211100000010001
11110111111111011101010010001
11000000110101011100000020001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110001                    11111
11110111 1110101 101111010001                    10001
11111111 1111111 111111111111                    11111
```

- `NO` North wall texture
- `SO` South wall texture
- `EA` East wall texture
- `WE` West wall texture
- `DO` Door texture
- `F` Floor color
- `C` Ceiling color

<br>

- `0` Empty space
- `1` Wall
- `2` Door

# Controls

| Key                   | Action                                   |
| :--------             | :-------                                 |
| `Arrows`              | `Rotate the view`                        |
| `WASD`                | `Move`                                   |
| `Left alt`            | `Enable the mouse`                       |
| `Space`               | `Move up (fly)`                          |
| `Ctrl`                | `Move down and crouch`                   |
| `Shift`               | `Open door`                              |
| `M`                   | `Open the map`                           |
| `C`                   | `Enable the balaclava`                   |
| `Esc`                 | `Close he game`                          |
| `Left click`          | `Primary use of the object`              |
| `Right click`         | `Secondary use of the object`            |


## Features

### Menu

<br>

When the game start a menu appears on the screen and disapear as soon as the player press a key (menu.xpm in the assets directory)

### Balaclava

<br>

The balaclava is enabled with `C` (hood.xpm in the assets directory)

<br>

![Screenshot from 2024-09-03 22-08-50](https://github.com/user-attachments/assets/a12b8a1e-e80e-4ae8-87e4-2818bab8f419)

### Map

<br>

The map appears when `M` is pressed and show the location of the player

![Screenshot from 2024-09-03 22-06-53](https://github.com/user-attachments/assets/85d92b1c-a61a-4ae7-8622-d15deb06c01b)


### Object

The object is composed of one idle frame when no button is pressed, three use frames that alternate when `Left click` is pressed and a secondary use frame when `Right click` is pressed

<br>

![Screenshot from 2024-09-03 22-12-46](https://github.com/user-attachments/assets/9724b2f4-0f10-4eb3-b251-72cdec0a5687)

<br>

![Screenshot from 2024-09-03 22-19-29](https://github.com/user-attachments/assets/ea5fb364-6a9c-461c-a435-084070794fe8)

<br>

![Screenshot from 2024-09-03 22-19-52](https://github.com/user-attachments/assets/40ec2914-f9a4-4003-9888-a1aac98146ec)





