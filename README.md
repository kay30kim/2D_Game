# 2D_Game

## Table of Contents

- [Part 1. Introduction](#part-1-introduction)
- [Part 2. Game Overview](#part-2-game-overview)
- [Part 3. Graphic Management](#part-3-graphic-management)
- [Part 4. Map Structure](#part-4-map-structure)
- [Part 5. Map Validity](#part-5-map-validity)
- [Part 6. Project Requirements](#part-6-project-requirements)

## Part 1. Introduction

This is a simple 2D game project, where you'll create a basic game using the MiniLibX library. The goal of the game is to collect collectibles on a map and reach the exit while avoiding obstacles. The project is written in C and should adhere to certain guidelines.

## Part 2. Game Overview

- The player's objective is to collect all the collectibles on the map and reach the exit.
- The game supports keyboard controls (W, A, S, D) for character movement.
- The character can move in four directions: up, down, left, and right.
- The player cannot move through walls.
- The number of movements is displayed in the shell.
- The game provides a 2D view (top-down or profile).
- It's not a real-time game, and you can customize the theme.

## Part 3. Graphic Management

- The game window displays the game's graphics.
- The window management is smooth and includes features like changing windows and minimizing.
- The game can be closed cleanly using the ESC key or by clicking the window's close button.

## Part 4. Map Structure

- The game map consists of walls, collectibles, and free spaces.
- The map is defined using the following characters:
  - 0 for an empty space
  - 1 for a wall
  - C for a collectible
  - E for the map exit
  - P for the player's starting position

## Part 5. Map Validity

- The map must contain at least one exit, one collectible, and a starting position to be valid.
- Duplicate characters for exit or starting position are not allowed.
- The map must be rectangular.
- It must be enclosed by walls, or an error will be displayed.
- The game checks for a valid path on the map.
- The program can parse various map formats as long as they adhere to the rules.

## Part 6. Project Requirements

- The project is written in C.
- It follows coding norms.
- The code does not result in unexpected errors.
- Memory management is handled properly to avoid memory leaks.
- A Makefile is provided to compile the source files.
- The project supports bonus features and includes a bonus Makefile.
- If applicable, you can use your own libft and should provide the associated Makefile.
- You're encouraged to create test programs for your project for testing and defense.
- The project is submitted to an assigned Git repository for grading.

Please refer to the project documentation for more details and specific guidelines.
