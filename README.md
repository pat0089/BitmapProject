# Bitmap Project
This is a basic image manipulation program that I work on in some of my spare time.

This project will eventually act as a shell that can be used while viewing a bitmap image in another program

## Goals

 - I want this project to ultimately be as **simple** as it can be, while providing functionality that is useful for preprocessing/processing bitmap images
 - This project should be memory-efficient, using the smallest data types when possible
 - The methods in each class should be written for both time-efficiency and for clarity, trying to find a balance of both

## Potential questions 
>Why are you not implementing a GUI for this program?

 * I am not implementing a GUI simply because I don't have to, and it goes against one of the pillars of what this program is ultimately meant to be: simple.

## TODOS:
* Implement a Selection object to act as an indexable subspace within the PixelMap object to be able to do manipulation functions
* Implement manipulation functions as function pointers to be applied to all Pixels of a PixelMap or Selection in a PixelMap
* Implement Masks as a wrapper for modification & selection functionality, implemented as a stack ultimately in the main program for undo/redo functionality
* Implement a proper main Shell
* Implement shape drawing?
### Manipulation functions:
* Image Wobble (vertical and horizontal)
* Replace a color with transparent pixels
* Text stamp filter
* Stretch/shrink - will have to be made using a custom color-blender when adjusting size to be sma
* Brightness/contrast - to be implemented using the HSL class for adjustment
* Saturation - to be implemented using the HSL class for adjustment 
* Alpha adjustment
